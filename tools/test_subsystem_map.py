import tempfile
import unittest
from pathlib import Path
from subsystem_map import inventory, MECHANICAL


class InventoryOwnershipTests(unittest.TestCase):
    def test_record_words_do_not_look_like_hex_identifiers(self):
        for name in ['MenuScript_SetRecordConfirmCallback', 'ZoneState_UpdateRecordByKey',
                     'BattleAI_SelectActorWithoutRecordBit24']:
            self.assertIsNone(MECHANICAL.search(name), name)
        for name in ['Resource_SetRecord4CValue', 'Type15Record_IgnoreTouchCallbacks',
                     'Menu_SetParameterAtA4']:
            self.assertIsNotNone(MECHANICAL.search(name), name)

    def test_init_and_uppercase_ranges_keep_source_ownership(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            cfg = root / 'config/usa/arm9'
            (cfg / 'itcm').mkdir(parents=True)
            (cfg / 'overlays').mkdir()
            (cfg / 'itcm/symbols.txt').write_text('')
            (cfg / 'symbols.txt').write_text(
                '__sinit_020e5afc kind:function(arm,size=0x10) addr:0x020e5afc\n'
                'Combat_Test kind:function(arm,size=0x18) addr:0x020e5b0c\n')
            (cfg / 'delinks.txt').write_text(
                'src/World/InitializeCache.cpp:\n    .init start:0x020E5AFC end:0x020E5B0C\n'
                'src/Combat/Test.cpp:\n    .text start:0x020e5b0c end:0x020E5B24\n')
            rows = inventory(root)
            self.assertEqual([r['source_subsystem'] for r in rows], ['World', 'Combat'])
            self.assertEqual([r['debt'] for r in rows], ['named', 'named'])


if __name__ == '__main__':
    unittest.main()
