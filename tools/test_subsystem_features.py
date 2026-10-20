import json
import re
from pathlib import Path
import unittest
from subsystem_map import assign_chunks, folder_for, inventory

ROOT = Path(__file__).resolve().parents[1]


class FeatureMapTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.mapping = json.loads((ROOT/'docs/subsystem-map-usa.json').read_text())
        cls.functions = inventory(ROOT)
        assign_chunks(cls.functions, cls.mapping)

    def test_every_function_has_one_feature_owner(self):
        self.assertEqual(len(self.functions), len({f['id'] for f in self.functions}))
        self.assertNotIn('UNMAPPED', {f['chunk'] for f in self.functions})
        spans = {}
        for chunk in self.mapping['chunks']:
            self.assertFalse(chunk['id'].startswith('OV'))
            for span in chunk['ranges']:
                spans.setdefault(span['module'], []).append((int(span['start'],16), int(span['end'],16), chunk['id']))
        for f in self.functions:
            owners = {cid for start,end,cid in spans[f['module']] if start <= f['address'] < end}
            self.assertEqual(owners, {f['chunk']}, f['id'])

    def test_battle_menu_owners_share_the_feature_directory(self):
        menus = [f for f in self.functions if f['name'].startswith('BattleMenu_')]
        self.assertTrue(menus)
        for f in menus:
            self.assertEqual(f['chunk'], 'BATTLE-MENUS', f['id'])
            if f['source']:
                self.assertTrue(f['source'].startswith('src/Combat/BattleMenu/'), f['source'])

    def test_source_tree_has_no_overlay_directories(self):
        remaining = [str(p.relative_to(ROOT)) for p in (ROOT/'src').rglob('*')
                     if p.is_dir() and re.fullmatch(r'ov\d{3}', p.name)]
        self.assertEqual(remaining, [])

    def test_features_cross_overlay_boundaries(self):
        modules = {f['module'] for f in self.functions if f['chunk']=='CHARACTER-CREATION'}
        self.assertTrue({'arm9/ov009','arm9/ov021','arm9/ov023'} <= modules)
        features = {f['chunk'] for f in self.functions if f['module']=='arm9/ov004'}
        self.assertTrue({'QUESTS','TITLES','TREASURE-MAP-MENU','STATUS-MENU'} <= features)

    def test_feature_directory_is_independent_of_module(self):
        bestiary = next(f for f in self.functions if f['chunk']=='BESTIARY')
        self.assertEqual(folder_for(ROOT, bestiary['module'], bestiary['address'], self.mapping), 'Menu/Bestiary')
        for chunk in self.mapping['chunks']:
            directory=chunk.get('source_directory')
            if directory:
                self.assertTrue(directory.startswith(chunk['folder']+'/'), chunk['id'])


if __name__ == '__main__':
    unittest.main()
