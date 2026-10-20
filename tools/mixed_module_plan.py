"""Validate a source-only mixed-module proposal; never installs or accepts it.

The single-module gate remains authoritative. This helper is preparation for an
atomic driver, not permission to loop that gate or publish per-module receipts.
"""
from pathlib import PurePosixPath
from arm9_module import module_section

FORBIDDEN = ('data', 'source_refinements', 'runtime_support', 'runtime_append',
             'runtime_replacement', 'symbol_additions', 'symbol_map_additions',
             'symbol_size_dependency', 'symbol_refinements', 'relocation_map',
             'retention_policy', 'retention_policy_sha256', 'relocation_removals')


def source_only_plan(document):
    """Partition rows without losing identity or allowing ambiguous shared units."""
    if any(document.get(key) for key in FORBIDDEN):
        raise ValueError('Mixed proposal supports new source functions only')
    rows = document.get('functions', [])
    if not rows:
        raise ValueError('No selected functions')
    groups, names, identities, sources = {}, set(), set(), set()
    for row in rows:
        module = row.get('module')
        module_section(module)
        name, source = row['name'], row['source']
        path = PurePosixPath(source)
        if path.is_absolute() or '..' in path.parts or path.as_posix() != source or not source.startswith('src/'):
            raise ValueError('Noncanonical source path')
        address = int(row['address'], 16)
        if address < 0 or address >= 2**32 or type(row['size']) is not int or row['size'] <= 0 or address + row['size'] > 2**32:
            raise ValueError('Invalid function extent')
        identity = (module, address)
        if name in names or identity in identities or source in sources:
            raise ValueError('Duplicate symbol, identity or source unit')
        names.add(name); identities.add(identity); sources.add(source)
        groups.setdefault(module, []).append(dict(row))
    if len(groups) < 2:
        raise ValueError('Use unchanged single-module gate for one module')
    hashes = document.get('source_hashes', {})
    if set(hashes) != sources or any(not isinstance(h, str) or len(h) != 64 or any(c not in '0123456789abcdef' for c in h) for h in hashes.values()):
        raise ValueError('Exact source hashes required')
    for module, selected in groups.items():
        ordered = sorted(selected, key=lambda row: int(row['address'], 16))
        if any(int(a['address'],16)+a['size'] > int(b['address'],16) for a,b in zip(ordered,ordered[1:])):
            raise ValueError('Overlapping function extents in '+module)
    return dict(modules={module: dict(module=module, functions=selected,
                         source_hashes={r['source']:hashes[r['source']] for r in selected})
                         for module, selected in sorted(groups.items())},
                expected_functions=len(rows), expected_code_bytes=sum(r['size'] for r in rows),
                acceptance=False)


def unique_captures(groups):
    """Deduplicate identical shared snapshots, refuse lost-update pre/postimages.

    A caller must still validate the combined selected rename/profile edits.
    Merging arbitrary JSON or source text here would bypass existing allowlists.
    """
    selected = {}
    for captures in groups:
        for snapshot in captures:
            path = snapshot['path']
            if path in selected:
                old = selected[path]
                if old['before'] != snapshot['before'] or old['after'] != snapshot['after']:
                    raise ValueError('Shared dependency needs combined capture: '+path)
                if old != snapshot:
                    raise ValueError('Shared dependency metadata differs: '+path)
            else:
                selected[path] = dict(snapshot)
    return list(selected.values())
