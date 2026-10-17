"""Run dsd ROM configuration and preserve the mtime of byte-identical output.

The ROM build separately depends on the linked ARM9 ELF. Restatting this metadata
therefore avoids recompiling unchanged ARM7 source, never repackaging ARM9 code.
"""
import argparse
import os
from pathlib import Path
import subprocess


def generate(dsd, elf, config, output):
    output = Path(output)
    if output.is_symlink():
        raise ValueError('ROM configuration must not be a symlink')
    before = output.read_bytes() if output.exists() else None
    info = output.stat() if before is not None else None
    subprocess.run([str(dsd), 'rom', 'config', '--elf', str(elf),
                    '--config', str(config)], check=True)
    if output.is_symlink() or not output.is_file():
        raise ValueError('ROM configuration was not generated as a regular file')
    if before is not None and output.read_bytes() == before:
        os.utime(output, ns=(info.st_atime_ns, info.st_mtime_ns))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('dsd', 'elf', 'config', 'output'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    generate(args.dsd, args.elf, args.config, args.output)


if __name__ == '__main__':
    main()
