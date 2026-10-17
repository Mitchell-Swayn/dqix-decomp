import json
import shutil
import subprocess
from pathlib import Path
import unittest

from test_dependency_rank import RankingIntegration
from dependency_rank import ranked_queue
from reconstruction_context import digest, packages, snapshot_refs, relocation_rows, main as record


class ContextTests(RankingIntegration):
    def ledger(self, function=None, resources=None):
        path=self.root/'config/reconstruction-context.json'
        refs=snapshot_refs(self.root,['src/C.cpp'])
        data={'schema_version':1,'resources':resources or {},'functions':function or {}}
        path.write_text(json.dumps(data))
        return refs

    def reviewed(self, requires=(), provides=()):
        return {'reviewed':True,'requires':list(requires),'provides':list(provides),
                'evidence':snapshot_refs(self.root,['src/C.cpp'])}

    def resource(self,state='known',importance=1):
        return {'kind':'signature','state':state,'importance':importance,
                'evidence':snapshot_refs(self.root,['src/C.cpp'])}

    def test_matched_body_does_not_prove_signature_or_context(self):
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        b=next(r for r in rows if r['name']=='B')
        self.assertTrue(b['callees_ready']);self.assertFalse(b['context_ready'])
        self.assertEqual(b['context_status'],'unassessed')
        self.assertIn('signature:C',b['context_blockers'])

    def test_known_context_precedes_larger_reach_and_stales_on_edit(self):
        self.ledger({'B':self.reviewed()}, {'signature:C':self.resource()})
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        self.assertEqual(rows[0]['name'],'B');self.assertTrue(rows[0]['context_ready'])
        (self.root/'src/C.cpp').write_text('void C(int x) {}')
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        b=next(r for r in rows if r['name']=='B')
        self.assertFalse(b['context_assessed']);self.assertFalse(b['context_ready'])
        self.assertIn('signature:C',b['context_blockers'])

    def test_shared_layout_and_importance_affect_readiness_and_unlocks(self):
        self.ledger({'B':self.reviewed(['layout:shared']), 'D':self.reviewed(provides=['layout:shared'])},
                    {'signature:C':self.resource(), 'layout:shared':dict(self.resource('partial',5),kind='layout')})
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        b=next(r for r in rows if r['name']=='B');d=next(r for r in rows if r['name']=='D')
        self.assertFalse(b['context_ready']);self.assertEqual(b['context_blocker_weight'],5)
        self.assertEqual(d['context_unlock_ids'],['B']);self.assertEqual(rows[0]['name'],'D')

    def test_missing_evidence_never_gives_known_credit(self):
        self.ledger({'B':self.reviewed()}, {'signature:C':dict(self.resource(),evidence=[])})
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        b=next(r for r in rows if r['name']=='B');self.assertFalse(b['context_ready'])
        self.assertEqual(b['context_unresolved'],1)

    def test_packages_include_matched_sources_headers_and_evidence_hashes(self):
        (self.root/'include').mkdir();(self.root/'include/C.h').write_text('void C();')
        (self.root/'src/C.cpp').write_text('#include <C.h>\nvoid C() {}')
        self.ledger({'B':self.reviewed()}, {'signature:C':self.resource()})
        rows,g=ranked_queue(self.db,self.root,self.report,self.candidates)
        out=self.root/'build/packages';index=packages(self.root,self.report,g,[rows[0]],out)
        p=out/index[0]['path'];data=json.loads(p.read_text())
        self.assertEqual(index[0]['sha256'],digest(p.read_bytes()))
        self.assertEqual(data['callees'][0]['source_path'],'src/C.cpp')
        self.assertEqual({f['path'] for f in data['files']},{'src/C.cpp','include/C.h'})
        self.assertEqual(data['relocations']['status'],'unavailable')
        self.assertEqual(data['resources'][0]['state'],'known')

    def test_ledger_rejects_workspace_escape(self):
        r=self.resource();r['evidence'][0]['path']='../outside.cpp'
        self.ledger(resources={'signature:C':r})
        with self.assertRaisesRegex(ValueError,'leaves workspace'):
            ranked_queue(self.db,self.root,self.report,self.candidates)

    @unittest.skipUnless(shutil.which('cc') and shutil.which('readelf'), 'ELF fixture tools unavailable')
    def test_relocations_use_exact_symbol_range_and_section(self):
        directory=self.root/'build/usa/delinks';directory.mkdir(parents=True)
        obj=directory/'main_0.o'
        assembly='.section .text.one,"ax"\n.globl A\n.type A,@function\nA: .long external_a\n.size A,.-A\n.globl B\n.type B,@function\nB: .long external_b\n.size B,.-B\n.section .text.two,"ax"\n.globl C\n.type C,@function\nC: .long external_c\n.size C,.-C\n'
        subprocess.run(['cc','-x','assembler','-c','-o',str(obj),'-'],input=assembly,text=True,check=True,capture_output=True)
        row={'fallback_unit':'main_0','name':'A','size':4}
        result=relocation_rows(self.root,row,{})
        self.assertEqual(result['status'],'available')
        self.assertEqual([r['target'] for r in result['entries']],['external_a'])
        self.assertEqual(result['entries'][0]['function_offset'],0)
        self.assertEqual(relocation_rows(self.root,dict(row,size=8),{})['status'],'unavailable')

    def test_cli_requires_evidence_and_records_hashed_facts(self):
        prefix=['--project',str(self.root)]
        self.assertEqual(record(prefix+['resource','type:Widget','--kind','type','--state','known','--note','reviewed']),2)
        self.assertEqual(record(prefix+['resource','type:Widget','--kind','type','--state','known','--evidence','src/C.cpp:1','--note','reviewed']),0)
        self.assertEqual(record(prefix+['function','B','--requires','type:Widget','--reviewed','--evidence','src/C.cpp']),0)
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        self.assertIn('type:Widget',next(r for r in rows if r['name']=='B')['context_requirements'])


if __name__=='__main__':unittest.main()
