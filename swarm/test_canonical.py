"""Tooling-only tests; isolated DB/tree and the configured matching compiler."""
import contextlib
import io
from pathlib import Path
import tempfile
import unittest
from types import SimpleNamespace
from unittest.mock import patch

import canonical
from state import Project
import verify
import swarm


class CanonicalTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.project = Project(self.tmp.name)
        for directory in ('src', 'include', 'config'):
            (self.project.root / directory).mkdir()
        self.db = self.project.connect(create=True)
        self.addCleanup(self.db.close)
        self.owner = self.project.root / 'src/owner.cpp'
        self.owner.write_text('extern "C" int Callee(int x) { return x; }\n')
        self.db.execute('INSERT INTO decls VALUES(?,?,?)', ('Callee', 'extern "C" void Callee(void*);', 'stale.h:1'))
        self.task = dict(id='arm9/main:02000000', module='arm9/main', name='Old', address=0x2000000,
                         size=4, mode='arm', original=b'\x1e\xff\x2f\xe1')
        self.good = 'extern "C" int Callee(int);\nextern "C" void Candidate(void) {}\n'

    def audit(self, text, suffix='.cpp', include_dir=None, profile='default'):
        with canonical.accepted_read(self.project):
            state = canonical.snapshot(self.project, self.db)
        return canonical.audit(self.project, text, suffix, include_dir, profile, state, verify.compile_source)

    def test_compiler_conflict_and_owning_over_cache(self):
        self.assertEqual(self.audit(self.good)['status'], 'ok')
        bad = self.good.replace('int Callee(int)', 'void Callee(void*)')
        review = self.audit(bad)
        self.assertEqual(review['status'], 'conflict', review)
        self.assertEqual(review['declarations'][0]['path'], 'src/owner.cpp:1')
        with patch.object(verify, '_check_object', return_value={'status': 'match'}) as obj:
            self.assertEqual(verify.check(self.project, self.db, self.task, bad)['status'], 'canonical_conflict')
            obj.assert_not_called()
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'match')
            obj.assert_called_once()

    def test_real_object_still_matches_when_compatible(self):
        self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'match')
        # Isolated compilation succeeds with the wrong unused prototype too.
        bad = self.good.replace('int Callee(int)', 'void Callee(void*)')
        self.assertIsNotNone(verify.compile_source(self.project, bad)[0])
        self.assertEqual(verify.check(self.project, self.db, self.task, bad)['status'], 'canonical_conflict')

    def test_alias_block_and_c_forms(self):
        self.db.execute('INSERT INTO renames VALUES(?,?,?)', ('arm9/main', 'Raw', 'Callee'))
        for text, suffix in [('extern "C" {\nint Raw(int);\n}\n', '.cpp'),
                             ('extern "C" { int Raw(int); }\n', '.cpp'),
                             ('int Callee(int);\n', '.c')]:
            self.assertEqual(self.audit(text, suffix)['status'], 'ok')
            self.assertEqual(self.audit(text.replace('int);', 'void*);'), suffix)['status'], 'conflict')
        self.owner.write_text('extern "C" {\nint Callee(int x) { return x; }\n}\n')
        self.assertEqual(self.audit(self.good)['declarations'][0]['authority'], 'owning-definition')

    def test_cpp_overload_is_not_compatibility(self):
        self.owner.write_text('int Callee(int x) { return x; }')
        self.assertEqual(self.audit('int Callee(int);\n')['status'], 'ok')
        self.assertEqual(self.audit('void Callee(void*);\n')['status'], 'conflict')
        self.assertEqual(self.audit('extern "C" int Callee(int);\n')['status'], 'conflict')

    def test_include_profile_and_missing_context(self):
        self.owner.write_text('extern "C" Known* Callee(Known* x) { return x; }')
        self.assertEqual(self.audit(self.good)['status'], 'context_required')
        local = self.project.root / 'local'
        local.mkdir()
        (local / 'types.h').write_text('struct Known {};\n#define CALL\n')
        text = '#include "types.h"\nextern "C" Known* CALL Callee(Known*);\n'
        self.assertEqual(self.audit(text, include_dir=Path('local'), profile='O4p')['status'], 'ok')
        with patch.object(verify, 'compile_source', return_value=(b'object', '')) as compiler:
            self.audit(text, '.cpp', Path('local'), 'O4p')
            self.assertEqual(compiler.call_args.args[2:], ('.cpp', Path('local'), 'O4p'))

    def test_publication_and_changed_state_fail_closed(self):
        marker = self.project.root / 'build/progress/integration.lock'
        marker.parent.mkdir(parents=True, exist_ok=True)
        marker.touch()
        self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'canonical_retry')
        marker.unlink()
        def changed(*args):
            self.owner.write_text('extern "C" void Callee(void*) {}')
            return dict(status='match', problems=[], warnings=[])
        with patch.object(verify, '_check_object', side_effect=changed):
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'canonical_retry')

    def test_exclusive_integration_lock_and_coordinator_path(self):
        import fcntl
        lock = self.project.root / 'build/progress/integration-process.lock'
        lock.parent.mkdir(parents=True, exist_ok=True)
        with lock.open('a') as stream:
            fcntl.flock(stream, fcntl.LOCK_EX)
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'canonical_retry')
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good,
                                          integration_locked=True)['status'], 'match')

    def test_index_reuses_across_process_cache_and_invalidates_edits(self):
        import os
        first = canonical.snapshot(self.project, self.db)
        canonical._MEMORY_INDEX.clear()  # fresh CLI process reads the persisted index
        with patch.object(canonical, '_file_record', wraps=canonical._file_record) as read:
            self.assertEqual(canonical.snapshot(self.project, self.db)[0], first[0])
            read.assert_not_called()
            stamp = self.owner.stat()
            self.owner.write_text(self.owner.read_text().replace('int x', 'int y'))
            os.utime(self.owner, ns=(stamp.st_atime_ns, stamp.st_mtime_ns))
            changed = canonical.snapshot(self.project, self.db)
            self.assertNotEqual(changed[0], first[0])
            self.assertEqual(read.call_count, 1)
        header = self.project.root / 'include/new.h'
        header.write_text('typedef int Added;')
        added = canonical.snapshot(self.project, self.db)[0]
        self.assertNotEqual(added, changed[0])
        header.unlink()
        self.assertNotEqual(canonical.snapshot(self.project, self.db)[0], added)
        replacement = self.owner.with_suffix('.tmp')
        replacement.write_bytes(self.owner.read_bytes())
        replacement.replace(self.owner)
        self.assertNotEqual(canonical.snapshot(self.project, self.db)[0], changed[0])

    def test_index_db_and_config_invalidation_without_queue_churn(self):
        first = canonical.snapshot(self.project, self.db)[0]
        self.db.execute("INSERT INTO events VALUES(0,NULL,NULL,'check','{}')")
        self.assertEqual(canonical.snapshot(self.project, self.db)[0], first)
        self.db.execute("UPDATE decls SET decl='extern \"C\" int Callee(int);'")
        second = canonical.snapshot(self.project, self.db)[0]
        self.assertNotEqual(second, first)
        self.db.execute("INSERT INTO renames VALUES('arm9/main','Raw','Callee')")
        third = canonical.snapshot(self.project, self.db)[0]
        self.assertNotEqual(third, second)
        (self.project.root / 'config/profile.json').write_text('{}')
        self.assertNotEqual(canonical.snapshot(self.project, self.db)[0], third)

    def test_index_mid_read_edit_and_corrupt_cache(self):
        original = canonical._file_record
        def raced(root, relative, stamp):
            record = original(root, relative, stamp)
            self.owner.write_text(self.owner.read_text() + '\n')
            return record
        with patch.object(canonical, '_file_record', side_effect=raced):
            with self.assertRaises(canonical.StateUnavailable):
                canonical.snapshot(self.project, self.db)
        self.assertFalse((self.project.state / 'canonical-index.cache').exists())
        canonical.snapshot(self.project, self.db)
        (self.project.state / 'canonical-index.cache').write_text('{broken')
        canonical._MEMORY_INDEX.clear()
        with patch.object(canonical, '_file_record', wraps=canonical._file_record) as read:
            canonical.snapshot(self.project, self.db)
            self.assertGreater(read.call_count, 0)

    def test_cache_builder_contention_and_atomic_publication(self):
        import fcntl
        self.project.state.mkdir(parents=True, exist_ok=True)
        with (self.project.state / 'canonical-index.lock').open('a') as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            with self.assertRaises(canonical.StateUnavailable):
                canonical.snapshot(self.project, self.db)
        original = canonical.os.replace
        observations = []
        def publish(temporary, destination):
            observations.append((Path(destination).exists(), Path(temporary).is_file()))
            original(temporary, destination)
        with patch.object(canonical.os, 'replace', side_effect=publish):
            canonical.snapshot(self.project, self.db)
        self.assertEqual(observations, [(False, True)])
        self.assertFalse(list(self.project.state.glob('canonical-index-*.tmp')))

    def test_header_edit_during_compile_and_symlink_target(self):
        header = self.project.root / 'include/type.h'
        header.write_text('typedef int Value;')
        before = canonical.snapshot(self.project, self.db)[0]
        def compiler(*args):
            header.write_text('typedef short Value;')
            return dict(status='match', problems=[], warnings=[])
        with patch.object(verify, '_check_object', side_effect=compiler):
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'canonical_retry')
        self.assertNotEqual(canonical.snapshot(self.project, self.db)[0], before)
        target = self.project.root / 'external.h'
        target.write_text('typedef int Linked;')
        (self.project.root / 'include/link.h').symlink_to(target)
        linked = canonical.snapshot(self.project, self.db)[0]
        target.write_text('typedef long Linked;')
        self.assertNotEqual(canonical.snapshot(self.project, self.db)[0], linked)

    def test_real_header_context_capture_preserves_candidate_types(self):
        (self.project.root / 'include/owner.h').write_text(
            'typedef void Opaque;\n#undef ARG\n#define ARG void*\n')
        self.owner.write_text('#include <owner.h>\nextern "C" Opaque* Callee(Opaque* x) { return x; }')
        review = self.audit('extern "C" void* Callee(void*);\n')
        self.assertEqual(review['status'], 'ok', review)
        self.assertEqual(review['context_resolution'], 'owning-headers-with-captured-candidate-types')
        bad = '#define ARG int\nextern "C" void* Callee(ARG);\n'
        review = self.audit(bad)
        self.assertEqual(review['status'], 'conflict', review)
        self.assertTrue(review['context_attempted'])
        self.assertEqual(review['proof'], 'compiler-declaration-incompatibility')

    def test_context_probe_inside_c_linkage_and_local_nominal_type(self):
        (self.project.root / 'include/owner.h').write_text('struct Nominal {};\n')
        self.owner.write_text('#include <owner.h>\nextern "C" void Callee(Nominal*) {}')
        review = self.audit('extern "C" { void Callee(void*); }\n')
        self.assertEqual(review['status'], 'conflict', review)
        self.assertNotIn('illegal linkage', '\n'.join(review['messages']))
        self.owner.write_text('struct Private {};\nextern "C" void Callee(Private*) {}')
        review = self.audit('extern "C" void Callee(void*);\n')
        self.assertEqual(review['status'], 'context_required', review)
        self.assertIn('Private', review['declarations'][0]['local_type_names'])

    def test_declaration_db_change_during_compile_and_failed_preflight_race(self):
        def changed(*args):
            self.db.execute("INSERT INTO renames VALUES('arm9/main','Raw','Callee')")
            return dict(status='match', problems=[], warnings=[])
        with patch.object(verify, '_check_object', side_effect=changed):
            self.assertEqual(verify.check(self.project, self.db, self.task, self.good)['status'], 'canonical_retry')
        original = verify.compile_source
        def preflight(*args):
            result = original(*args)
            self.owner.write_text(self.owner.read_text() + '\n')
            return result
        with patch.object(verify, 'compile_source', side_effect=preflight):
            bad = self.good.replace('int Callee(int)', 'void Callee(void*)')
            self.assertEqual(verify.check(self.project, self.db, self.task, bad)['status'], 'canonical_retry')

    def test_owning_header_overload_cannot_satisfy_capture(self):
        (self.project.root / 'include/owner.h').write_text(
            'typedef void Opaque;\nvoid* Callee(void*);\n')
        self.owner.write_text('#include <owner.h>\nOpaque* Callee(Opaque* x) { return x; }')
        review = self.audit('void* Callee(int);\n')
        self.assertEqual(review['status'], 'conflict', review)
        self.assertTrue(review['context_attempted'])
        (self.project.root / 'include/owner.h').write_text('typedef void Opaque;\n')
        self.owner.write_text('#include <owner.h>\nextern "C" Opaque* Callee(Opaque* x) { return x; }')
        review = self.audit('extern "C" { void* Callee(void*); }\n')
        self.assertEqual(review['status'], 'ok', review)

    def test_submit_rechecks_and_preserves_lease_source(self):
        self.db.execute('INSERT INTO tasks(id,module,name,address,size,mode,original,listing,referenced,status,worker,lease_until,source) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?)',
                        (*[self.task[k] for k in ('id','module','name','address','size','mode','original')], '', 0, 'leased', 'worker', 9999999999, 'previous'))
        candidate = self.project.root / 'candidate.cpp'
        candidate.write_text(self.good.replace('int Callee(int)', 'void Callee(void*)'))
        args = SimpleNamespace(task=self.task['id'], worker='worker', file=str(candidate), symbol=None,
                               profile='default', subsystem=None, note=None)
        before = dict(self.db.execute('SELECT * FROM tasks').fetchone())
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(swarm.cmd_submit(self.project, args), 1)
        after = dict(self.db.execute('SELECT * FROM tasks').fetchone())
        self.assertEqual(before, after)
        candidate.write_text(self.good)
        original_check = swarm.run_check
        def raced(*a):
            result = original_check(*a)
            self.owner.write_text('extern "C" void Callee(void*) {}')
            return result
        with patch.object(swarm, 'run_check', side_effect=raced), contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(swarm.cmd_submit(self.project, args), 1)
        row = self.db.execute('SELECT * FROM tasks').fetchone()
        for key in ('source', 'status', 'lease_until'):
            self.assertEqual(row[key], before[key])


if __name__ == '__main__':
    unittest.main()
