import json
from pathlib import Path
import tempfile
import unittest
from naming_inventory import inventory


class InventoryIdentityTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name)
        self.source='src/Unclassified/ov999/ArbitraryName.cpp'
        p=self.root/self.source;p.parent.mkdir(parents=True);p.write_text('// Original: arm9/ov002 @ 0x02158000; symbol: original; size: 4.\n')
        self.report=dict(units=[dict(name='unit',metadata=dict(source_path=self.source),functions=[dict(name='ReadValue',size='4',fuzzy_match_percent=100)])],measures={})
        for module in ['ov001','ov002']:
            d=self.root/'config/usa/arm9/overlays'/module;d.mkdir(parents=True)
            (d/'symbols.txt').write_text('ReadValue kind:function(arm,size=0x4) addr:0x02158000\n')
            (d/'delinks.txt').write_text(self.source+':\n' if module=='ov002' else '')

    def test_owning_map_overrides_misleading_basename_and_path(self):
        f=inventory(self.root,self.report)['units'][0]['functions'][0]
        self.assertEqual(f['function_id'],'arm9/ov002:02158000')
        self.assertEqual(f['original_symbol'],'original')

    def test_ambiguous_module_ownership_fails_closed(self):
        (self.root/'config/usa/arm9/overlays/ov001/delinks.txt').write_text(self.source+':\n')
        with self.assertRaisesRegex(ValueError,'one exact'):inventory(self.root,self.report)

    def test_unregistered_address_like_alias_is_not_invented(self):
        self.report['units'][0]['functions'][0]['name']='.L_02158000'
        with self.assertRaisesRegex(ValueError,'one exact'):inventory(self.root,self.report)

    def test_registered_runtime_alias_retains_coverage_identity(self):
        self.report['units'][0]['functions'][0]['name']='.L_02158000'
        p=self.root/'config/usa/arm9/runtime_support.json'
        p.write_text(json.dumps(dict(report_aliases=[dict(source=self.source,name='.L_02158000',size=4)])))
        f=inventory(self.root,self.report)['units'][0]['functions'][0]
        self.assertTrue(f['nested_runtime_alias'])

    def test_data_only_unit_remains_in_inventory(self):
        self.report['units'][0]['functions']=[]
        self.assertTrue(inventory(self.root,self.report)['units'][0]['data_only'])


class NominalScopeTests(unittest.TestCase):
    def test_argument_namespace_is_not_a_method_scope(self):
        from naming_inventory import qualified_scope
        self.assertIsNone(qualified_scope('MapList_Opcode_66(Script::Parameter*, int)'))

    def test_member_scope_does_not_depend_on_argument_type(self):
        from naming_inventory import qualified_scope
        self.assertEqual(qualified_scope('Object3D::SetPosition(Vector3<fix32> const&)'),'Object3D')
        self.assertEqual(qualified_scope('Object3D::operator=(Object3D const&)'),'Object3D')
