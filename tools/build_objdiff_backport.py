"""Rebuild the hash-pinned objdiff2.7.1 ARM empty-map repair in ignored build/.

Original configured tools and ROM inputs are never modified. Requires the pinned
factory image and Docker access; all Rust/Cargo state stays workspace-local.
"""
import argparse,hashlib,json,os,shutil,subprocess,tarfile,tomllib,urllib.request
from pathlib import Path

SOURCE_URL='https://github.com/encounter/objdiff/archive/refs/tags/v2.7.1.tar.gz'
SOURCE_SHA='05f9510335dbfad26a18175abc8e3d5d316e5cd0fbd2b1033a5e8f4929688916'
RUSTUP_URL='https://static.rust-lang.org/rustup/archive/1.29.1/x86_64-unknown-linux-gnu/rustup-init'
RUSTUP_SHA='dda7234360b7f578ca8b0ddcb80145646fa61a67c1720a5abc7051b35c9fcb71'
MANIFEST_URL='https://static.rust-lang.org/dist/channel-rust-1.85.1.toml'
MANIFEST_SHA='1e7dae690cd12e27405a97e64704917489a27c650201bf47780a936055d67909'
IMAGE='sha256:fb6576a1df6a9aaa2ed39f913f083d725da63942b5fbf6ed1645141deaa43dde'
OLD='.map(|x| x.as_slice())'
NEW='.map(|x| if x.is_empty() { &fallback_mappings } else { x.as_slice() })'

def digest(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def checked(path,expected):
 if digest(path)!=expected:raise ValueError('SHA256 mismatch: '+str(path))
 return path

def acquire(url,target,expected,supplied=None):
 target=Path(target)
 if target.is_symlink():raise ValueError("Download cache must not be a symlink")
 if supplied:
  checked(supplied,expected);shutil.copyfile(supplied,target)
 elif not target.exists():
  with urllib.request.urlopen(url,timeout=120) as response:payload=response.read()
  if hashlib.sha256(payload).hexdigest()!=expected:raise ValueError('Download SHA256 mismatch: '+url)
  target.write_bytes(payload)
 return checked(target,expected)

def prepare_source(archive,work,policy):
 source=work/'objdiff-2.7.1'
 # Never reuse potentially edited source or target caches from another build.
 if source.exists():shutil.rmtree(source)
 with tarfile.open(archive) as tar:
  for member in tar.getmembers():
   path=Path(member.name)
   if path.is_absolute() or '..' in path.parts or not path.parts or path.parts[0]!='objdiff-2.7.1' or member.issym() or member.islnk():raise ValueError('Unsafe source archive member')
  tar.extractall(work,filter='data')
 arm=source/'objdiff-core/src/arch/arm.rs';text=arm.read_text()
 if text.count(OLD)!=1:raise ValueError('Unexpected upstream ARM mapping context')
 arm.write_text(text.replace(OLD,NEW))
 checked(arm,policy['patched_source_sha256']);checked(source/'Cargo.lock',policy['cargo_lock_sha256'])
 return source

def check_toolchain(work,channel):
 installed=work/'rustup/toolchains/1.85.1-x86_64-unknown-linux-gnu/lib/rustlib/multirust-channel-manifest.toml'
 actual=tomllib.loads(installed.read_text());expected=tomllib.loads(channel.read_text())
 if actual['date']!=expected['date']:raise ValueError('Installed Rust release date differs')
 for package in ('rustc','cargo','rust-std'):
  target='x86_64-unknown-linux-gnu'
  if any(actual['pkg'][package]['target'][target].get(k)!=expected['pkg'][package]['target'][target].get(k) for k in ('available','url','hash','xz_url','xz_hash')):raise ValueError('Installed Rust package pin differs: '+package)

def build(root,source_archive=None,rustup_installer=None,check_inputs=False,docker='docker'):
 root=Path(root).resolve();policy=json.loads((root/'config/usa/objdiff_tool.json').read_text());work=(root/'build/tools/objdiff-backport').resolve()
 if not work.is_relative_to(root/'build'):raise ValueError('Build workspace leaves ignored build directory')
 work.mkdir(parents=True,exist_ok=True)
 if policy['source_archive_sha256']!=SOURCE_SHA or policy['rust_toolchain']!='1.85.1-x86_64-unknown-linux-gnu':raise ValueError('Unexpected source/toolchain policy')
 patch=(root/policy['patch']).resolve()
 if not patch.is_relative_to(root/'tools'):raise ValueError('Patch leaves tools directory')
 checked(patch,policy['patch_sha256']);source=acquire(SOURCE_URL,work/'source.tar.gz',SOURCE_SHA,source_archive);installer=acquire(RUSTUP_URL,work/'rustup-init',RUSTUP_SHA,rustup_installer);channel=acquire(MANIFEST_URL,work/'channel.toml',MANIFEST_SHA)
 prepare_source(source,work,policy)
 if check_inputs:return {'inputs_verified':True,'work':str(work)}
 installer.chmod(0o755)
 # Pin the exact image ID used for the accepted binary, not a mutable tag.
 prefix=docker.split();subprocess.run(prefix+['image','inspect',IMAGE],check=True,stdout=subprocess.DEVNULL)
 command='set -e; export RUSTUP_HOME=/work/rustup CARGO_HOME=/work/cargo RUST_MIN_STACK=33554432; /work/rustup-init -y --no-modify-path --profile minimal --default-toolchain 1.85.1; cd /work/objdiff-2.7.1; /work/cargo/bin/cargo build --locked --release -p objdiff-cli -j8'
 with (work/'build.log').open('w') as log:subprocess.run(prefix+['run','--rm','--user',str(os.getuid())+':'+str(os.getgid()),'-v',str(work)+':/work','-w','/work',IMAGE,'bash','-c',command],check=True,stdout=log,stderr=subprocess.STDOUT)
 check_toolchain(work,channel);binary=work/'objdiff-2.7.1/target/release/objdiff-cli';checked(binary,policy['binary_sha256']);dest=(root/policy['executable']).resolve()
 if not dest.is_relative_to(root/'build'):raise ValueError('Output leaves ignored build directory')
 dest.parent.mkdir(parents=True,exist_ok=True);temp=dest.with_suffix('.tmp')
 if temp.is_symlink():raise ValueError('Temporary output must not be a symlink')
 shutil.copyfile(binary,temp);temp.chmod(0o755);checked(temp,policy['binary_sha256']);os.replace(temp,dest)
 receipt=dict(binary=str(dest.relative_to(root)),binary_sha256=digest(dest),source_sha256=SOURCE_SHA,patch_sha256=policy['patch_sha256'],rustup_installer_sha256=RUSTUP_SHA,rust_manifest_sha256=MANIFEST_SHA,build_image=IMAGE)
 (work/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');return receipt

if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--project',type=Path,default=Path(__file__).resolve().parents[1]);p.add_argument('--source-archive',type=Path);p.add_argument('--rustup-installer',type=Path);p.add_argument('--check-inputs',action='store_true');p.add_argument('--docker',default='sudo -n docker',help='Docker command prefix')
 a=p.parse_args();print(json.dumps(build(a.project,a.source_archive,a.rustup_installer,a.check_inputs,a.docker),indent=2))
