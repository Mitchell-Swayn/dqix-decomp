import hashlib
import json
from pathlib import Path
from unittest.mock import patch
import unittest

from test_dependency_rank import RankingIntegration
from dependency_rank import ranked_queue
from reconstruction_context import digest
from reconstruction_session import create, next_batch, accept, verify_acceptance


class SessionTests(RankingIntegration):
    def setUp(self):
        super().setUp()
        self.report['measures']={'total_code':100,'total_data':50,'total_functions':4}
        rows,_=ranked_queue(self.db,self.root,self.report,self.candidates)
        self.state=create(self.root,self.report,rows,3,1,'readiness,downstream,size,depth','build/usa/report.json',None)
        self.directory=self.root/'build/session'
        p=self.root/'build/usa/report.json';p.parent.mkdir(parents=True);p.write_text(json.dumps(self.report))

    def next(self):
        with patch('reconstruction_session.packages'):
            return next_batch(self.root,self.db,self.state,self.directory)

    def complete_b(self):
        (self.root/'src/B.cpp').write_text('void B() {}')
        config=self.root/'config/usa/arm9/delinks.txt';config.write_text(config.read_text()+'src/B.cpp:\n    .text start:0x20 end:0x2c\n')
        self.report['units'].append(dict(name='src/B',metadata=dict(source_path='src/B.cpp',auto_generated=False),
                                         functions=[dict(name='B',size=12,fuzzy_match_percent=100)]))
        (self.root/'build/usa/report.json').write_text(json.dumps(self.report))

    def test_pending_batch_is_retained_and_next_reranks_new_readiness(self):
        self.next();self.assertEqual(self.state['pending']['ids'],['B'])
        self.assertEqual(self.next()['status'],'pending')
        self.complete_b()
        with patch('reconstruction_session.verify_acceptance',return_value={'ids':['B']}):accept(self.root,self.state,'m','c')
        self.next();self.assertEqual(self.state['pending']['ids'],['A'])
        self.assertEqual(self.state['completed_ids'],['B'])

    def test_failed_acceptance_does_not_drop_pending_or_credit_progress(self):
        self.next()
        with patch('reconstruction_session.verify_acceptance',side_effect=ValueError('ROM mismatch')):
            with self.assertRaises(ValueError):accept(self.root,self.state,'m','c')
        self.assertEqual(self.state['completed_ids'],[]);self.assertEqual(self.state['pending']['ids'],['B'])

    def test_denominator_change_and_external_completion_rejected(self):
        self.complete_b()
        with self.assertRaisesRegex(ValueError,'outside session'):self.next()
        self.report['measures']['total_code']=90
        (self.root/'build/usa/report.json').write_text(json.dumps(self.report))
        with self.assertRaisesRegex(ValueError,'denominators'):self.next()

    def acceptance_fixture(self):
        self.next();self.complete_b()
        manifest=json.loads((self.root/self.state['pending']['manifest']).read_text());manifest['units']=['src/B']
        (self.root/'build/manifest.json').write_text(json.dumps(manifest))
        artifact=self.root/'build/matching/test';u=artifact/'unit-0000';u.mkdir(parents=True)
        source=self.root/'src/B.cpp';(u/'candidate.cpp').write_bytes(source.read_bytes())
        target=self.root/'build/usa/delinks/src/B.o';candidate=self.root/'build/usa/src/B.o';target.parent.mkdir(parents=True);candidate.parent.mkdir(parents=True);target.write_bytes(b'target');candidate.write_bytes(b'candidate')
        unit={'name':'src/B','metadata':{'source_path':'src/B.cpp'},'target_path':'build/usa/delinks/src/B.o','base_path':'build/usa/src/B.o'}
        (self.root/'objdiff.json').write_text(json.dumps({'units':[unit]}))
        result={'unit':'src/B','artifacts':'build/matching/test/unit-0000','match':True,'object_match':True,
                'target_sha256_before':digest(target.read_bytes()),'candidate_sha256_before':digest(candidate.read_bytes())}
        (artifact/'units.json').write_text(json.dumps([result]))
        (u/'bytes.json').write_text(json.dumps({'functions':[{'raw_match':None,'relocations_present':True}]}))
        (self.root/'build/comparison.json').write_text(json.dumps({'status':'compared','match':True,'errors':0,'artifacts':'build/matching/test'}))
        (self.root/'dqix_usa.nds').write_bytes(b'rom')
        return u

    def test_acceptance_checks_current_sources_raw_bytes_and_rom(self):
        u=self.acceptance_fixture()
        with patch('reconstruction_session.audit',return_value={'match':True}),patch('reconstruction_session.ROM_SHA1',hashlib.sha1(b'rom').hexdigest()):
            self.assertEqual(verify_acceptance(self.root,self.state,'build/manifest.json','build/comparison.json')['ids'],['B'])
            (u/'bytes.json').write_text(json.dumps({'functions':[{'raw_match':False,'relocations_present':True}]}))
            with self.assertRaisesRegex(ValueError,'Raw mismatch'):verify_acceptance(self.root,self.state,'build/manifest.json','build/comparison.json')
            (u/'bytes.json').write_text(json.dumps({'functions':[{'raw_match':None,'relocations_present':False}]}))
            with self.assertRaisesRegex(ValueError,'inconclusive'):verify_acceptance(self.root,self.state,'build/manifest.json','build/comparison.json')
            (u/'bytes.json').write_text(json.dumps({'functions':[{'raw_match':True}]}))
            (self.root/'src/B.cpp').write_text('void B(int x) {}')
            with self.assertRaisesRegex(ValueError,'Source changed'):verify_acceptance(self.root,self.state,'build/manifest.json','build/comparison.json')

    def test_fixed_scope_size_and_batch_limits(self):
        with self.assertRaises(ValueError):create(self.root,self.report,self.state['scope'],3,21,'size','report',None)
        with self.assertRaises(ValueError):create(self.root,self.report,self.state['scope'],4,1,'size','report',None)


if __name__=='__main__':unittest.main()
