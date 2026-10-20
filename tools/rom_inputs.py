"""Hash-bound shared read-only inputs; generated outputs remain workspace-local."""
import hashlib
import json
from pathlib import Path
import stat

USA_SHA1 = 'c7c3014c237900c8281289b8bc76a781969b6278'
BINDING = 'build/inputs.json'
LEGACY_BINDING = 'build/factory/inputs.json'


def digest(path, algorithm='sha256'):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, algorithm).hexdigest()


def binding(root):
    path = Path(root) / BINDING
    if not path.is_file():
        path = Path(root) / LEGACY_BINDING
    return json.loads(path.read_text()) if path.is_file() else None


def input_rom(root):
    document = binding(root)
    return Path(document['rom']) if document else Path(root) / 'extract/baserom_dqix_usa.nds'


def compiler_root(root):
    document = binding(root)
    return Path(document['compiler']) if document else Path(root) / 'tools/mwccarm'


def tool_path(root, relative):
    prefix = 'tools/mwccarm/'
    return compiler_root(root) / relative[len(prefix):] if relative.startswith(prefix) else Path(root) / relative


def validate(root, expected=None):
    document = binding(root)
    if expected is not None and document != expected:
        raise ValueError('Shared input binding changed')
    rom = input_rom(root)
    if rom.is_symlink() or not rom.is_file() or rom.stat().st_nlink != 1 or digest(rom, 'sha1') != USA_SHA1:
        raise ValueError('Original input must be a regular verified ROM')
    if document:
        pool = Path(document['pool']).resolve()
        paths = [rom, compiler_root(root)]
        if document.get('schema_version') != 1 or any(not p.resolve().is_relative_to(pool) for p in paths):
            raise ValueError('Shared inputs escape their bound pool')
        if rom.stat().st_mode & stat.S_IWRITE:
            raise ValueError('Shared ROM is writable')
        for relative, expected_hash in document['tools'].items():
            path = compiler_root(root) / relative
            if (not path.resolve().is_relative_to(pool) or path.is_symlink() or
                    not path.is_file() or path.stat().st_nlink != 1 or
                    path.stat().st_mode & stat.S_IWRITE or digest(path) != expected_hash):
                raise ValueError('Shared compiler changed: ' + relative)
    return document
