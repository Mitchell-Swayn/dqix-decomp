import json
from pathlib import Path
import sqlite3
import tempfile
import unittest
from unittest.mock import patch
import evidence_store as store


class EvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.path=Path(self.temp.name)/'original.sqlite'
        db=sqlite3.connect(self.path)
        db.executescript('CREATE TABLE functions(id TEXT PRIMARY KEY,module_id TEXT,name TEXT,address INTEGER,size INTEGER,original_bytes BLOB,original_sha256 TEXT);')
        db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?)',('arm9/main:02000000','arm9/main','example',0x2000000,4,b'abcd',store.sha(b'abcd')))
        db.commit();db.close()
        self.destination=Path(self.temp.name)/'evidence.sqlite'
        self.row={'module':'main','name':'example','address':'02000000','size':4,'status':'inspected','pseudocode':'return 1;'}

    def test_corrupt_original_rejected(self):
        db=sqlite3.connect(self.path);db.execute('UPDATE functions SET original_bytes=?',(b'bad!',));db.commit();db.close()
        with self.assertRaisesRegex(ValueError,'Invalid original'):store.prepare(self.path,self.destination)
        self.assertFalse(self.destination.exists())

    def test_cache_separates_program_identity_and_original_hash(self):
        store.prepare(self.path,self.destination)
        with store.connect(self.destination) as db:
            store.import_analysis(db,{'program_fingerprint':'a'*64,'functions':[self.row]})
            self.assertIsNotNone(store.cached(db,self.row,'a'*64))
            self.assertIsNone(store.cached(db,self.row,'b'*64))
            db.execute('UPDATE functions SET original_sha256=?',('c'*64,))
            self.assertIsNone(store.cached(db,self.row,'a'*64))

    def test_import_rolls_back_bad_boundary(self):
        store.prepare(self.path,self.destination)
        with store.connect(self.destination) as db:
            bad=dict(self.row,size=8)
            with self.assertRaises(ValueError):store.import_analysis(db,{'program_fingerprint':'a'*64,'functions':[self.row,bad]})
            self.assertEqual(db.execute('SELECT count(*) FROM ghidra_analysis').fetchone()[0],0)

    def test_fetch_refuses_changed_program_before_request(self):
        store.prepare(self.path,self.destination)
        with store.connect(self.destination) as db, patch('evidence_store.fingerprint',return_value='b'*64), patch('evidence_store.inspect') as inspect:
            with self.assertRaises(ValueError):store.fetch(db,[self.row],'server','a'*64,Path(self.temp.name)/'out.json')
            inspect.assert_not_called()


if __name__=='__main__':unittest.main()
