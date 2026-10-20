"""Freeze selected ARM9 source bytes before a transaction changes the project."""
import hashlib
from pathlib import Path


def digest(content):
    return hashlib.sha256(content).hexdigest()


def canonical_source(root, source):
    relative = Path(source)
    if (relative.is_absolute() or relative.as_posix() != source or
            '..' in relative.parts or not source.startswith('src/')):
        raise ValueError('Source path must be canonical and inside src/: ' + source)
    target = Path(root) / relative
    if target.is_symlink() or not target.resolve().is_relative_to(Path(root).resolve() / 'src'):
        raise ValueError('Source path escapes its source tree: ' + source)
    return target


def capture_sources(worker, paths, manifest):
    paths = list(paths)
    if len(paths) != len(set(paths)):
        raise ValueError('Duplicate selected source path')
    declared = manifest.get('source_hashes')
    pinned = 'source_hashes' in manifest
    if pinned:
        if not isinstance(declared, dict) or set(declared) != set(paths):
            raise ValueError('source_hashes must cover exactly the selected source paths')
        for value in declared.values():
            if (not isinstance(value, str) or len(value) != 64 or
                    any(character not in '0123456789abcdef' for character in value)):
                raise ValueError('source_hashes must contain lowercase SHA256 hashes')
    snapshots = {source: canonical_source(worker, source).read_bytes() for source in paths}
    hashes = {source: digest(content) for source, content in snapshots.items()}
    if pinned and declared != hashes:
        raise ValueError('Worker source hash differs from manifest')
    return snapshots, {'source_hashes': hashes,
                       'source_hash_authority': 'manifest' if pinned else 'captured-legacy-unpinned'}


def install_source(root, source, content, copied):
    target = canonical_source(root, source)
    if target.exists():
        raise ValueError('Source already exists: ' + source)
    target.parent.mkdir(parents=True, exist_ok=True)
    copied.append(source)  # Register before writing, including partial-write failure.
    target.write_bytes(content)


def verify_sources(root, snapshots):
    for source, content in snapshots.items():
        if canonical_source(root, source).read_bytes() != content:
            raise ValueError('Installed source changed: ' + source)
