import json
from pathlib import Path
import sqlite3
import tempfile
import unittest

from dependency_rank import current_completion, graph_metrics, parse_policy, ranked_queue, write_dag
from lineage_depth import annotate


def graph(names, edges):
    g = dict(nodes=[dict(id=n, name=n, module='arm9/main', address=16*i, size=16)
                    for i, n in enumerate(names)],
             edges=[dict(source=a, target=b, ambiguous=False) for a, b in edges],
             indirect=[], unresolved=[])
    annotate(g)
    return g


class DependencyMetrics(unittest.TestCase):
    def test_diamond_counts_unique_downstream_and_upstream(self):
        g = graph('ABCD', [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'D')])
        m = graph_metrics(g, {'D'})
        self.assertEqual(m['A']['downstream_dependencies'], 3)
        self.assertEqual(m['D']['transitive_callers'], 3)
        self.assertEqual(m['A']['lineage_depth'], 3)
        self.assertTrue(m['B']['callees_ready'])
        self.assertFalse(m['A']['callees_ready'])
        self.assertEqual(m['A']['unmatched_callees'], 2)

    def test_recursive_group_is_condensed_and_not_ready(self):
        g = graph('ABCD', [('A', 'B'), ('B', 'A'), ('B', 'C'), ('D', 'A')])
        m = graph_metrics(g, {'C'})
        self.assertEqual(m['A']['dependency_group_id'], m['B']['dependency_group_id'])
        self.assertEqual(m['A']['lineage_depth'], 2)
        self.assertEqual(m['D']['downstream_dependencies'], 3)
        self.assertFalse(m['A']['callees_ready'])
        self.assertEqual(len(g['dependency_groups']), 3)

    def test_unknown_and_ambiguous_calls_do_not_appear_ready(self):
        g = graph('ABC', [('A', 'B')])
        g['edges'][0]['ambiguous'] = True
        g['indirect'] = [dict(source='C', site=32)]
        annotate(g)
        m = graph_metrics(g, {'B'})
        self.assertFalse(m['A']['callees_ready'])
        self.assertFalse(m['C']['callees_ready'])
        self.assertTrue(m['B']['callees_ready'])

    def test_deep_graph_avoids_recursion_limit(self):
        names = [str(i) for i in range(1500)]
        m = graph_metrics(graph(names, list(zip(names, names[1:]))), set())
        self.assertEqual(m['0']['lineage_depth'], 1500)
        self.assertEqual(m['0']['downstream_dependencies'], 1499)

    def test_policy_validation(self):
        for value in ['size,size', 'unknown', '']:
            with self.assertRaises(ValueError):
                parse_policy(value)


class RankingIntegration(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        config = self.root / 'config/usa/arm9'
        config.mkdir(parents=True)
        (config / 'symbols.txt').write_text('A kind:function(arm,size=0x8) addr:0x10\nB kind:function(arm,size=0xc) addr:0x20\nC kind:function(arm,size=0x10) addr:0x30\nD kind:function(arm,size=0x8) addr:0x40\n')
        (config / 'delinks.txt').write_text('src/C.cpp:\n    .text start:0x30 end:0x40\n')
        (self.root / 'src').mkdir()
        (self.root / 'src/C.cpp').write_text('void C() {}')
        self.db = sqlite3.connect(':memory:')
        self.addCleanup(self.db.close)
        self.db.row_factory = sqlite3.Row
        self.db.executescript('''
        CREATE TABLE functions(id TEXT,module_id TEXT,name TEXT,address INTEGER,size INTEGER,
                               mode TEXT,original_sha256 TEXT,completion_status TEXT);
        CREATE TABLE relationships(caller_id TEXT,callee_id TEXT,kind TEXT,ambiguous INTEGER);
        CREATE TABLE unresolved_calls(caller_id TEXT,instruction_address INTEGER);
        CREATE TABLE metadata(key TEXT,value TEXT);
        INSERT INTO metadata VALUES('created_utc','historical');
        ''')
        for name, address, size in [('A', 0x10, 8), ('B', 0x20, 12), ('C', 0x30, 16), ('D', 0x40, 8)]:
            self.db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?,?)',
                            (name, 'arm9/main', name, address, size, 'arm', 'hash-' + name, 'completed'))
        self.db.executemany('INSERT INTO relationships VALUES(?,?,?,?)',
                            [('A', 'B', 'call', 0), ('B', 'C', 'call', 0)])
        self.report = {'units': [dict(name='src/C', metadata=dict(source_path='src/C.cpp', auto_generated=False),
                                     functions=[dict(name='C', size=16, fuzzy_match_percent=100)])]}
        self.candidates = [dict(name=n, module='main', address=f'{a:08x}', size=s, mode='arm', fallback_unit='main_0')
                           for n, a, s in [('A', 0x10, 8), ('B', 0x20, 12), ('D', 0x40, 8)]]

    def test_current_report_overrides_historical_completion_and_updates_readiness(self):
        rows, g = ranked_queue(self.db, self.root, self.report, self.candidates)
        self.assertEqual([r['name'] for r in rows], ['B', 'D', 'A'])
        self.assertEqual(g['metadata']['ranking']['matched_source_functions'], 1)
        self.assertEqual(rows[0]['matched_callees'], 1)
        self.report['units'][0]['functions'][0]['fuzzy_match_percent'] = 99
        rows, g = ranked_queue(self.db, self.root, self.report, self.candidates)
        self.assertEqual(rows[0]['name'], 'D')
        self.assertEqual(g['metadata']['ranking']['matched_source_functions'], 0)

    def test_configurable_priority_and_dag_export(self):
        rows, g = ranked_queue(self.db, self.root, self.report, self.candidates, 'downstream,readiness,size,depth')
        self.assertEqual(rows[0]['name'], 'A')
        rows, _ = ranked_queue(self.db, self.root, self.report, self.candidates, 'size')
        self.assertEqual([r['name'] for r in rows], ['A', 'D', 'B'])
        p = self.root / 'dag.json'
        write_dag(g, p)
        d = json.loads(p.read_text())
        self.assertEqual(len(d['functions']), 4)
        self.assertEqual(len(d['groups']), 4)
        self.assertEqual(d['metadata']['edge_direction'], 'caller -> callee')

    def test_module_ownership_disambiguates_duplicate_names(self):
        nodes = [dict(id='main:C', name='C', module='arm9/main', address=0x30, size=16),
                 dict(id='overlay:C', name='C', module='arm9/ov000', address=0x30, size=16)]
        self.assertEqual(current_completion(self.root, self.report, nodes), {'main:C'})

    def test_rename_resolves_exact_original_identity_and_context_owner(self):
        from reconstruction_context import source_owners
        self.report['units'][0]['functions'][0]['name'] = 'RenamedC'
        (self.root/'config/usa/arm9/symbols.txt').write_text('RenamedC kind:function(arm,size=0x10) addr:0x30\n')
        rows, g = ranked_queue(self.db, self.root, self.report, self.candidates)
        self.assertEqual(g['metadata']['ranking']['matched_source_functions'], 1)
        self.assertEqual(source_owners(self.root, self.report, g), {'C': 'src/C.cpp'})
        self.assertTrue(next(r for r in rows if r['name'] == 'B')['callees_ready'])
        self.assertEqual(next(n for n in g['nodes'] if n['id'] == 'C')['name'], 'C')

    def test_current_symbol_boundary_module_source_and_match_fail_closed(self):
        from reconstruction_context import source_owners
        symbol = self.root/'config/usa/arm9/symbols.txt'
        for declaration in ['C kind:function(arm,size=0x10) addr:0x31',
                            'C kind:function(arm,size=0xf) addr:0x30', '']:
            symbol.write_text(declaration+'\n')
            _, g = ranked_queue(self.db, self.root, self.report, self.candidates)
            self.assertEqual(g['metadata']['ranking']['matched_source_functions'], 0)
            self.assertEqual(source_owners(self.root, self.report, g), {})
        symbol.write_text('C kind:function(arm,size=0x10) addr:0x30\n')
        for percent in [99.99, '100', None]:
            self.report['units'][0]['functions'][0]['fuzzy_match_percent'] = percent
            self.assertEqual(current_completion(self.root,self.report,[dict(id='C',name='C',module='arm9/main',address=0x30,size=16)]),set())
        self.report['units'][0]['functions'][0]['fuzzy_match_percent'] = 100
        (self.root/'src/C.cpp').unlink()
        _, g = ranked_queue(self.db, self.root, self.report, self.candidates)
        self.assertEqual(source_owners(self.root,self.report,g),{})

    def test_duplicate_overlay_current_names_disambiguate_by_owner(self):
        config=self.root/'config/usa/arm9/overlays/ov000';config.mkdir(parents=True)
        (config/'symbols.txt').write_text('C kind:function(arm,size=0x10) addr:0x30\n')
        nodes=[dict(id='main',name='oldMain',module='arm9/main',address=0x30,size=16),
               dict(id='overlay',name='oldOverlay',module='arm9/ov000',address=0x30,size=16)]
        self.assertEqual(current_completion(self.root,self.report,nodes),{'main'})
        (config/'delinks.txt').write_text('src/C.cpp:\n    .text start:0x30 end:0x40\n')
        self.assertEqual(current_completion(self.root,self.report,nodes),set())

    def test_generated_fallback_cannot_supply_source_credit(self):
        self.report['units'][0]['metadata']['auto_generated'] = True
        rows, g = ranked_queue(self.db, self.root, self.report, self.candidates)
        self.assertEqual(g['metadata']['ranking']['matched_source_functions'], 0)
        self.assertFalse(next(r for r in rows if r['name'] == 'B')['callees_ready'])


if __name__ == '__main__':
    unittest.main()
