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
 def test_prefix_patch_requires_exact_hash_and_final_source(self):
  original=b'.map(|x| x.as_slice())\n'
  empty=b'.map(|x| if x.is_empty() { &fallback_mappings } else { x.as_slice() })\n'
  final=empty+b'// reviewed prefix repair\n'
  archive=self.root/'source.tar.gz'
  with tarfile.open(archive,'w:gz') as tar:
   for name,data in [('objdiff-core/src/arch/arm.rs',original),('Cargo.lock',b'locked')]:
    entry=tarfile.TarInfo('objdiff-2.7.1/'+name);entry.size=len(data);tar.addfile(entry,io.BytesIO(data))
  prefix=self.root/'prefix.patch'
  import difflib
  prefix.write_text(''.join(difflib.unified_diff(empty.decode().splitlines(True),final.decode().splitlines(True),fromfile='a/objdiff-core/src/arch/arm.rs',tofile='b/objdiff-core/src/arch/arm.rs')))
  digest=lambda b:hashlib.sha256(b).hexdigest()
  policy=dict(empty_map_source_sha256=digest(empty),patched_source_sha256=digest(final),cargo_lock_sha256=digest(b'locked'),prefix_patch='tools/patches/prefix.patch',prefix_patch_sha256=digest(prefix.read_bytes()))
  with self.assertRaisesRegex(ValueError,'Missing pinned'):prepare_source(archive,self.root,policy)
  source=prepare_source(archive,self.root,policy,prefix)
  self.assertEqual((source/'objdiff-core/src/arch/arm.rs').read_bytes(),final)
  prefix.write_bytes(b'tampered')
  with self.assertRaisesRegex(ValueError,'SHA256'):prepare_source(archive,self.root,policy,prefix)
if __name__=='__main__':unittest.main()
