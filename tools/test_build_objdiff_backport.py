import io,hashlib,tempfile,tarfile,unittest
from pathlib import Path
from unittest.mock import patch
from build_objdiff_backport import acquire,checked,prepare_source
class BuilderPins(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
 def test_supplied_input_preserved(self):
  p=self.root/'input';p.write_bytes(b'pinned');h=hashlib.sha256(p.read_bytes()).hexdigest();out=acquire('unused',self.root/'copy',h,p);self.assertEqual(out.read_bytes(),b'pinned');self.assertEqual(p.read_bytes(),b'pinned')
 def test_bad_supplied_hash(self):
  p=self.root/'input';p.write_bytes(b'bad')
  with self.assertRaisesRegex(ValueError,'SHA256'):acquire('unused',self.root/'copy','0'*64,p)
  self.assertFalse((self.root/'copy').exists())
 def test_symlink_cache_rejected(self):
  original=self.root/'original';original.write_bytes(b'keep');out=self.root/'cache';out.symlink_to(original)
  with self.assertRaisesRegex(ValueError,'symlink'):acquire('unused',out,'0'*64)
  self.assertEqual(original.read_bytes(),b'keep')
 def test_cached_tamper_rejected(self):
  p=self.root/'cache';p.write_bytes(b'bad')
  with self.assertRaisesRegex(ValueError,'SHA256'):acquire('unused',p,'0'*64)
 def test_download_tamper_not_published(self):
  out=self.root/'cache'
  with patch('urllib.request.urlopen',return_value=io.BytesIO(b'bad')):
   with self.assertRaisesRegex(ValueError,'SHA256'):acquire('https://example.invalid/',out,'0'*64)
  self.assertFalse(out.exists())
 def test_archive_traversal_rejected(self):
  p=self.root/'bad.tar.gz'
  with tarfile.open(p,'w:gz') as t:
   entry=tarfile.TarInfo('../escape');entry.size=1;t.addfile(entry,io.BytesIO(b'x'))
  with self.assertRaisesRegex(ValueError,'Unsafe'):prepare_source(p,self.root,{})
  self.assertFalse((self.root.parent/'escape').exists())
 def test_symlink_archive_rejected(self):
  p=self.root/'bad.tar.gz'
  with tarfile.open(p,'w:gz') as t:
   entry=tarfile.TarInfo('objdiff-2.7.1/link');entry.type=tarfile.SYMTYPE;entry.linkname='/etc/passwd';t.addfile(entry)
  with self.assertRaisesRegex(ValueError,'Unsafe'):prepare_source(p,self.root,{})
if __name__=='__main__':unittest.main()
