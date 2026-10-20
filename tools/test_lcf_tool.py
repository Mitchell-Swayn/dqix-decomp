import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from lcf_tool import resolve_lcf_tool, dependencies


class ProfileTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.old = self.root / 'original-cli'
        self.new = self.root / 'build/tools/objdiff'
        self.patch = self.root / 'tools/patches/fix.patch'
        self.policy = self.root / 'config/usa/arm9/lcf_tool.json'
        for p in [self.old, self.new, self.patch, self.policy]:
            p.parent.mkdir(parents=True, exist_ok=True)
        self.old.write_bytes(b'original')
        self.new.write_bytes(b'repaired')
        self.patch.write_bytes(b'upstream patch')
        digest = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
        self.data = dict(schema_version=1, executable='build/tools/objdiff',
                         patch='tools/patches/fix.patch', configured_sha256=digest(self.old),
                         binary_sha256=digest(self.new), patch_sha256=digest(self.patch))
        self.save()

    def save(self):
        self.policy.write_text(json.dumps(self.data))

    def test_no_policy_preserves_configured(self):
        self.policy.unlink()
        self.assertEqual(resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old), str(self.old))

    def test_valid_and_already_repaired(self):
        for configured in [self.old, self.new]:
            self.assertEqual(resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', configured), str(self.new))

    def test_rejects_changed_input_binary(self):
        self.old.write_bytes(b'unreviewed')
        with self.assertRaisesRegex(ValueError, 'Configured'):
            resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old)

    def test_rejects_changed_repaired_binary(self):
        self.new.write_bytes(b'unreviewed')
        with self.assertRaisesRegex(ValueError, 'Accelerated'):
            resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old)

    def test_rejects_changed_patch(self):
        self.patch.write_bytes(b'unreviewed')
        with self.assertRaisesRegex(ValueError, 'patch hash'):
            resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old)

    def test_rejects_path_escape(self):
        self.data['executable'] = '../outside'
        self.save()
        with self.assertRaisesRegex(ValueError, 'paths'):
            resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old)


    def test_dependencies_track_policy_binary_and_patch(self):
        paths = dependencies(self.root, self.root / 'config/usa/arm9/config.yaml')
        self.assertEqual(set(paths), {'build/tools/objdiff', 'tools/patches/fix.patch',
                                     'config/usa/arm9/lcf_tool.json'})

    def test_rejects_schema_change(self):
        self.data['schema_version'] = 2
        self.save()
        with self.assertRaisesRegex(ValueError, 'Unsupported'):
            resolve_lcf_tool(self.root, self.root / 'config/usa/arm9/config.yaml', self.old)

if __name__ == '__main__':
    unittest.main()
