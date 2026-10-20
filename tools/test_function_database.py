import sqlite3
import unittest

from function_database import SCHEMA, disassemble, source_function


class FunctionDatabaseTests(unittest.TestCase):
    def test_literals_are_not_instructions(self):
        raw=bytes.fromhex('00009fe51eff2fe1ecef0f02')
        text=disassemble(raw,0x0202AE18,'arm')
        self.assertIn('ldr',text)
        self.assertIn('.word    0x020FEFEC ; PC-relative literal data',text)
        self.assertNotIn('andeq',text)

    def test_conditional_return_preserves_fallthrough(self):
        raw=bytes.fromhex('0000a0b31080bdb80100a0e31080bde8')
        text=disassemble(raw,0x02000000,'arm')
        self.assertIn('02000008: mov',text)
        self.assertIn('0200000C: pop',text)

    def test_unclassified_bytes_remain_explicit(self):
        raw=bytes.fromhex('1eff2fe100000000')
        text=disassemble(raw,0x02000000,'arm')
        self.assertIn('unclassified data or unreachable code',text)
        self.assertNotIn('andeq',text)

    def test_source_braces_in_strings_and_comments(self):
        text='// context\nint example(void) {\n const char* s="}"; /* { */\n if(s) { return 1; }\n return 0;\n}\nint other(void) {return 2;}\n'
        result=source_function(text,2)
        self.assertEqual(result[1:],(2,6))
        self.assertNotIn('other',result[0])

    def test_declaration_does_not_capture_next_definition(self):
        self.assertIsNone(source_function('int example(void);\nint other(void) {return 2;}\n',1))

    def test_schema_rejects_dangling_relationships(self):
        db=sqlite3.connect(':memory:'); db.executescript(SCHEMA)
        with self.assertRaises(sqlite3.IntegrityError):
            db.execute('INSERT INTO relationships(caller_id,callee_id,kind,ambiguous) VALUES(?,?,?,?)',('missing','missing','call',0))
        db.close()


if __name__=='__main__': unittest.main()
