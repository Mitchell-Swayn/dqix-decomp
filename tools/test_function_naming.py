import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
from function_naming import POLICY, validate_new_functions


class NamingTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        policy = self.root/POLICY; policy.parent.mkdir(parents=True)
        policy.write_text(json.dumps({'enforce_new_functions': True}))
        self.source = self.root/'src/Test.cpp'; self.source.parent.mkdir()
        self.row = {'name':'ComputePageRowAndColumn','address':'0x0205bb04','source':'src/Test.cpp'}

    def check(self, text, name=None, module='main'):
        self.source.write_text(text)
        row = dict(self.row, name=name or self.row['name'])
        with patch('function_naming.readable_names', return_value=[row['name']]):
            validate_new_functions(self.root, self.root, {'functions':[row]}, module)

    def test_descriptive_name_and_correct_location(self):
        self.check('// Original: arm9/main @ 0x0205BB04; symbol: func_0205bb04; size: 0x80.\n')

    def test_address_placeholder_rejected_even_with_comment(self):
        with self.assertRaisesRegex(ValueError, 'descriptive'):
            self.check('// Original: arm9/main @ 0x0205BB04; symbol: func_0205bb04;\n', 'func_0205bb04')

    def test_wrong_module_or_address_rejected(self):
        for text in ('// Original: arm9/ov017 @ 0x0205BB04; symbol: old;\n',
                     '// Original: arm9/main @ 0x0205BB08; symbol: old;\n'):
            with self.assertRaisesRegex(ValueError, 'module/address'):
                self.check(text)

    def test_runtime_placeholder_also_requires_a_name(self):
        row = dict(self.row, name='func_0205bb04')
        self.source.write_text('// Runtime provenance.\n')
        with patch('function_naming.readable_names', return_value=[row['name']]):
            with self.assertRaisesRegex(ValueError, 'descriptive'):
                validate_new_functions(self.root, self.root,
                    {'functions':[row], 'runtime_support':{'functions':[row]}})

    def test_mangled_placeholder_rejected_after_demangling(self):
        self.source.write_text('')
        with patch('function_naming.readable_names', return_value=['Model3D::Func0207e2e0()']):
            with self.assertRaisesRegex(ValueError, 'descriptive'):
                validate_new_functions(self.root,self.root,{'functions':[self.row]})
