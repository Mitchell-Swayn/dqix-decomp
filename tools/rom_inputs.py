"""Hash-bound shared read-only inputs; generated outputs remain workspace-local."""
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
import uuid

USA_SHA1 = 'c7c3014c237900c8281289b8bc76a781969b6278'
BINDING = 'build/factory/inputs.json'


def digest(path, algorithm='sha256'):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, algorithm).hexdigest()


def binding(root):
    path = Path(root) / BINDING
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


def _publish(source, destination, expected, algorithm='sha256'):
    destination.parent.mkdir(parents=True, exist_ok=True)
    if not destination.exists():
        temporary = destination.with_name(destination.name + '.' + uuid.uuid4().hex)
        try:
            shutil.copyfile(source, temporary)
            if digest(temporary, algorithm) != expected:
                raise ValueError('Shared input copy changed')
            temporary.chmod(stat.S_IREAD)
            try:
                os.rename(temporary, destination)
            except FileExistsError:
                pass
        finally:
            if temporary.exists():
                temporary.chmod(stat.S_IREAD | stat.S_IWRITE)
                temporary.unlink()
    if destination.is_symlink() or destination.stat().st_nlink != 1 or digest(destination, algorithm) != expected:
        raise ValueError('Shared input is not a verified independent pool file')
    destination.chmod(stat.S_IREAD)


def provision(root, workspace):
    """Older immutable candidate revisions retain their existing copy contract."""
    root, workspace = Path(root).resolve(), Path(workspace).resolve()
    validate(root)
    if not (workspace / 'tools/rom_inputs.py').is_file():
        destination = workspace / 'extract/baserom_dqix_usa.nds'
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(input_rom(root), destination)
        if destination.samefile(input_rom(root)) or digest(destination, 'sha1') != USA_SHA1:
            raise ValueError('Legacy input copy failed verification')
        return None
    existing = binding(root)
    if existing:
        document = existing
    else:
        pool = root / 'extract/shared-inputs'
        rom = pool / ('rom/' + USA_SHA1 + '.nds')
        _publish(input_rom(root), rom, USA_SHA1, 'sha1')
        profile = {}
        source_compiler = compiler_root(root)
        for path in sorted((source_compiler / '2.0/sp2p2').iterdir()):
            if path.is_file():
                profile[path.relative_to(source_compiler).as_posix()] = digest(path)
        if not all('2.0/sp2p2/' + name in profile for name in ('mwccarm.exe', 'mwldarm.exe')):
            raise ValueError('Pinned compiler is missing')
        identity = hashlib.sha256(json.dumps(profile, sort_keys=True).encode()).hexdigest()
        compiler = pool / 'compiler' / identity
        for relative, expected in profile.items():
            _publish(source_compiler / relative, compiler / relative, expected)
        document = dict(schema_version=1, pool=str(pool), rom=str(rom), rom_sha1=USA_SHA1,
                        compiler=str(compiler), tools=profile)
    path = workspace / BINDING
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(document, indent=2) + '\n')
    validate(workspace, document)
    return document
