import unittest
from lineage_depth import annotate


def graph(names, edges):
    return dict(nodes=[dict(id=n,name=n,module='test',address=16*i,size=16) for i,n in enumerate(names)],
                edges=[dict(source=a,target=b) for a,b in edges],indirect=[],unresolved=[])


class Layers(unittest.TestCase):
    def test_chain(self):
        g=graph('XYZ',[('X','Y'),('Y','Z')]); annotate(g)
        self.assertEqual([n['lineage']['layer'] for n in g['nodes']],[3,2,1])

    def test_all_callees_must_precede_caller(self):
        g=graph('ABCD',[('A','D'),('A','B'),('B','C'),('C','D')]); annotate(g)
        self.assertEqual(g['nodes'][0]['lineage']['layer'],4)

    def test_recursive_group(self):
        g=graph('ABCD',[('A','B'),('B','A'),('B','C'),('D','A')]); annotate(g)
        ls=[n['lineage'] for n in g['nodes']]
        self.assertEqual([l['layer'] for l in ls],[2,2,1,3])
        self.assertTrue(ls[0]['recursive']); self.assertEqual(ls[0]['group'],ls[1]['group'])
        self.assertTrue(ls[3]['reaches_cycle']); self.assertFalse(ls[3]['recursive'])

    def test_self_recursion(self):
        g=graph('A',[('A','A')]); annotate(g)
        self.assertEqual(g['nodes'][0]['lineage']['layer'],1)
        self.assertTrue(g['nodes'][0]['lineage']['recursive'])

    def test_uncertainty_propagates(self):
        g=graph('ABC',[('A','B')]); g['indirect']=[dict(source='B',site=16)]
        g['edges'][0]['ambiguous']=True; annotate(g)
        self.assertTrue(g['nodes'][0]['lineage']['unresolved_downstream'])
        self.assertTrue(g['nodes'][0]['lineage']['ambiguous_downstream'])
        self.assertFalse(g['nodes'][2]['lineage']['unresolved_downstream'])

    def test_deep_graph(self):
        names=[str(i) for i in range(3000)]; g=graph(names,list(zip(names,names[1:])))
        annotate(g); self.assertEqual(g['nodes'][0]['lineage']['layer'],3000)


if __name__=='__main__': unittest.main()
