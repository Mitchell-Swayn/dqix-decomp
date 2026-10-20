"""Rebuild the pinned LCF-only DSD acceleration in ignored build/."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shlex
import shutil
import subprocess


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def build(root, docker='sudo -n docker'):
    root = Path(root).resolve()
    from lcf_tool import profile
    data, destination, patch, _ = profile(root, root / 'config/usa/arm9/config.yaml')
    if digest(patch) != data['patch_sha256']:
        raise ValueError('DSD acceleration patch hash mismatch')
    work = root / 'build/tools/dsd-lcf-build'
    work.mkdir(parents=True, exist_ok=True)
    source = work / 'source'
    if source.exists():
        raise ValueError('Build source already exists; use a fresh workspace for a reproducible rebuild')
    subprocess.run(['git', 'clone', '--no-checkout', 'https://github.com/AetiasHax/ds-decomp.git', str(source)], check=True)
    subprocess.run(['git', 'checkout', '--detach', data['source_commit']], cwd=source, check=True)
    actual = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=source, text=True).strip()
    if actual != data['source_commit'] or digest(source / 'Cargo.lock') != data['cargo_lock_sha256']:
        raise ValueError('DSD source pin mismatch')
    subprocess.run(['git', 'apply', '--check', str(patch)], cwd=source, check=True)
    subprocess.run(['git', 'apply', str(patch)], cwd=source, check=True)
    command = shlex.split(docker) + ['run', '--rm', '--user', f'{os.getuid()}:{os.getgid()}',
        '-e', 'CARGO_HOME=/source/.cargo', '-v', f'{source}:/source', '-w', '/source', data['image']]
    with (work / 'build.log').open('w') as log:
        for cargo in [['cargo', 'test', '--locked', '-p', 'ds-decomp-cli', '--lib', 'fast_order_tests'],
                      ['cargo', 'build', '--locked', '--release', '-p', 'ds-decomp-cli']]:
            subprocess.run(command + cargo, stdout=log, stderr=subprocess.STDOUT, check=True)
    binary = source / 'target/release/dsd'
    if digest(binary) != data['binary_sha256']:
        raise ValueError('Rebuilt DSD binary hash mismatch')
    destination.parent.mkdir(parents=True, exist_ok=True)
    temporary = destination.with_suffix('.tmp')
    if temporary.is_symlink():
        raise ValueError('Temporary tool output must not be a symlink')
    shutil.copyfile(binary, temporary)
    temporary.chmod(0o755)
    os.replace(temporary, destination)
    return {'binary': str(destination.relative_to(root)), 'sha256': digest(destination)}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--docker', default='sudo -n docker')
    args = parser.parse_args()
    print(json.dumps(build(args.project, args.docker), indent=2))
