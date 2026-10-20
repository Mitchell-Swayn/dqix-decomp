"""Capture a source-only union once; never merge independently staged policy JSON.

Caller owns the integration guard, transaction, source/map gates and recovery.
Rows use short ARM9 modules (main, ov000, itcm, dtcm), as the existing gate does.
"""
import json
import re
import stat
from pathlib import Path
from arm9_module import delinks_path, module_section
from integration_dependencies import (sha, renamed, renamed_configure_roots, safe_path,
    install_dependencies, verify_dependencies, restore_dependencies)

FORBIDDEN = ('data', 'source_refinements', 'runtime_support', 'runtime_append',
             'runtime_replacement', 'symbol_additions', 'symbol_map_additions',
             'symbol_size_dependency', 'symbol_refinements', 'relocation_map', 'retention_policy')


def selected_rows(main, worker, manifest):
    if any(manifest.get(key) for key in FORBIDDEN):
        raise ValueError('Mixed dependencies support new source functions only')
    rows = manifest.get('functions', [])
    if not rows:
        raise ValueError('No selected functions')
    names, identities, sources, extents, provenance = set(), set(), set(), {}, []
    hashes = manifest.get('source_hashes', {})
    for row in rows:
        module = row['module']
        module_section(module)
        name, source = row['name'], row['source']
        path = safe_path(worker, source)
        if not source.startswith('src/') or path.suffix not in ('.c', '.cpp') or 'AssemblyFallback' in path.parts:
            raise ValueError('Selected row is not a new source function')
        address = int(row['address'], 16)
        size = row['size']
        if type(size) is not int or size <= 0 or address < 0 or address + size > 2**32:
            raise ValueError('Invalid function extent')
        identity = f'arm9/{module}:{address:08x}'
        if row.get('function_id', identity) != identity:
            raise ValueError('Selected module-qualified identity differs')
        if name in names or identity in identities or source in sources:
            raise ValueError('Duplicate selected symbol, identity or source')
        names.add(name); identities.add(identity); sources.add(source)
        extents.setdefault(module, []).append((address, address+size))
        digest = hashes.get(source)
        if not isinstance(digest, str) or not re.fullmatch('[0-9a-f]{64}', digest) or sha(path.read_bytes()) != digest:
            raise ValueError('Selected source hash mismatch')
        provenance.append(dict(function_id=identity, name=name, source=source, source_sha256=digest))
    if set(hashes) != sources:
        raise ValueError('Source hash set differs from selected union')
    for module, ranges in extents.items():
        ranges.sort()
        if any(a[1] > b[0] for a,b in zip(ranges, ranges[1:])):
            raise ValueError('Overlapping selected extents in '+module)
    return rows, sorted(provenance, key=lambda item: item['function_id'])


def capture_mixed_dependencies(main, worker, manifest):
    rows, provenance = selected_rows(main, worker, manifest)
    declarations = manifest.get('dependencies', [])
    if not declarations:
        if manifest.get('function_renames'):
            raise ValueError('Function renames require hash-bound dependencies')
        if any(r.get('profile', 'default') != 'default' for r in rows):
            raise ValueError('Missing compiler profile dependency')
        return []
    selected = {r['name']: r for r in rows}
    rename_rows = manifest.get('function_renames', [])
    renames = {}
    symbol_paths = {r['module']: delinks_path(r['module']).with_name('symbols.txt').as_posix() for r in rows}
    module_renames = {module: {} for module in symbol_paths}
    for item in rename_rows:
        old, new = item['old'], item['new']
        row = selected.get(new)
        if not row or old in renames or new in renames.values() or old == new:
            raise ValueError('Rename must select a unique new function')
        if not all(re.fullmatch(r'[A-Za-z_]\w*', n) for n in (old, new)):
            raise ValueError('Invalid function rename')
        module = row['module']
        if item.get('module', module) != module:
            raise ValueError('Rename module differs from selected identity')
        symbol_text = (main / symbol_paths[module]).read_text()
        pattern = rf'(?m)^{re.escape(old)} kind:function\([^\n]*\) addr:0x{int(row["address"],16):08x}\b[^\n]*$'
        matches = re.findall(pattern, symbol_text)
        if len(matches) != 1 or not re.search(rf'size=0x{row["size"]:x}\)', matches[0], re.I) or re.search(rf'(?m)^{re.escape(new)}\s', symbol_text):
            raise ValueError('Rename does not bind one original module symbol')
        # Source/root identifier replacement is global, so ambiguity anywhere
        # in current ARM9 declarations must fail closed, including unselected overlays.
        for path in (main/'config/usa/arm9').rglob('symbols.txt'):
            if path != main/symbol_paths[module] and re.search(rf'(?m)^{re.escape(old)}\s', path.read_text()):
                raise ValueError('Ambiguous original symbol across modules')
            if re.search(rf'(?m)^{re.escape(new)}\s', path.read_text()):
                raise ValueError('Renamed symbol already exists')
        renames[old] = new
        module_renames[module][old] = new
    expected_paths = set()
    snapshots = []
    seen = set()
    for item in declarations:
        relative = item['path']
        if relative in seen:
            raise ValueError('Duplicate dependency')
        seen.add(relative)
        target, staged = safe_path(main, relative), safe_path(worker, relative)
        before = target.read_bytes() if target.exists() else None
        after = staged.read_bytes()
        if sha(before) != item['before_sha256'] or sha(after) != item['after_sha256'] or before == after:
            raise ValueError('Dependency hash mismatch or unchanged dependency: ' + relative)
        if relative.startswith(('src/', 'include/')) and target.suffix in ('.c', '.cpp', '.h', '.hpp'):
            if before is None or 'AssemblyFallback' in target.parts or relative in {r['source'] for r in rows}:
                raise ValueError('Dependency must be an existing nonfallback reference source')
            if after.decode() != renamed(before.decode(), renames):
                raise ValueError('Existing source dependency changes more than selected identifiers')
        elif relative in symbol_paths.values():
            expected = before.decode()
            owning_module = next(module for module, path in symbol_paths.items() if path == relative)
            for old, new in module_renames[owning_module].items():
                expected, count = re.subn(rf'(?m)^{re.escape(old)}(?= kind:function\()', new, expected)
                if count != 1:
                    raise ValueError('Ambiguous symbol rename')
            if after.decode() != expected:
                raise ValueError('Symbol dependency changes original metadata')
        elif relative == 'config/usa/function_names.json':
            original = json.loads(before)
            changed = json.loads(after)
            additions = {}
            for old, new in renames.items():
                row = selected[new]
                module = row['module']
                identity = f'arm9/{module}:{int(row["address"],16):08x}'
                record = changed.get('functions', {}).get(identity, {})
                if record.get('function_id') != identity or record.get('module') != module or int(record.get('address','0'),16) != int(row['address'],16) or record.get('old_symbol') != old or record.get('new_symbol') != new or record.get('source') != row['source'] or not record.get('evidence',{}).get('note','').strip():
                    raise ValueError('Naming dependency lacks selected identity and behavior evidence')
                if identity in original['functions']:
                    raise ValueError('Cannot replace an existing naming record')
                additions[identity] = record
            original['functions'].update(additions)
            if changed != original:
                raise ValueError('Naming dependency changes unrelated records')
        elif relative == 'tools/configure.py':
            if before is None or after.decode() != renamed_configure_roots(before.decode(), renames):
                raise ValueError('Configure dependency changes more than selected linker root identities')
        elif relative == 'config/usa/keep_symbols.txt':
            original = renamed((before or b'').decode(), renames).splitlines()
            changed = after.decode().splitlines()
            if changed[:len(original)] != original or any(n not in selected for n in changed[len(original):]) or len(changed) != len(set(changed)):
                raise ValueError('Retention dependency changes unrelated roots')
        elif relative == 'config/usa/compiler_profiles.json':
            original, changed = json.loads(before), json.loads(after)
            config = json.loads((main/'swarm/config.json').read_text())
            for row in rows:
                profile = row.get('profile', 'default')
                if profile == 'default':
                    continue
                definition = config['profiles'][profile]
                executable = 'configured_default' if definition['version'] == '2.0/sp2p2' else f'tools/mwccarm/{definition["version"]}/mwccarm.exe'
                flags = [definition['opt'] if f == '-O2' else f for f in config['flags']]
                if not definition['interworking']:
                    flags = ['-nointerworking' if f == '-interworking' else f for f in flags]
                record = changed['sources'].get(row['source'], {})
                if set(record) != {'version','executable','executable_sha256','source','flags','origin'} or record.get('origin') != f'swarm profile {profile}; exact bytes and relocations verified':
                    raise ValueError('Compiler dependency contains unsupported fields')
                if row['source'] in original['sources'] or record.get('source') != row['source'] or record.get('version') != definition['version'] or record.get('executable') != executable or record.get('flags') != flags + ['-i','include']:
                    raise ValueError('Compiler dependency differs from selected approved profile')
                binary = Path(config['inputs']).expanduser()/config['compiler'] if executable == 'configured_default' else main/executable
                if record.get('executable_sha256') != sha(binary.read_bytes()):
                    raise ValueError('Compiler dependency executable hash mismatch')
                original['sources'][row['source']] = record
            if changed != original:
                raise ValueError('Compiler dependency changes unrelated policy')
        else:
            raise ValueError('Dependency path is not allowlisted: ' + relative)
        metadata=target.stat() if before is not None else None
        snapshots.append(dict(path=relative, before=before, after=after,
                              mode=stat.S_IMODE(metadata.st_mode) if metadata else None,
                              atime_ns=metadata.st_atime_ns if metadata else None,
                              mtime_ns=metadata.st_mtime_ns if metadata else None,
                              before_sha256=sha(before), after_sha256=sha(after),
                              selected_identities=provenance))
    if renames:
        expected_paths.add('config/usa/function_names.json')
        expected_paths.update(symbol_paths[module] for module, values in module_renames.items() if values)
        configure = main/'tools/configure.py'
        if configure.exists() and renamed_configure_roots(configure.read_text(), renames) != configure.read_text():
            expected_paths.add('tools/configure.py')
        for base in ('src','include'):
            for path in (main/base).rglob('*'):
                if path.is_file() and path.suffix in ('.c','.cpp','.h','.hpp') and 'AssemblyFallback' not in path.parts:
                    text = path.read_text()
                    if renamed(text, renames) != text:
                        expected_paths.add(path.relative_to(main).as_posix())
    if not expected_paths <= seen:
        raise ValueError('Missing rename dependencies: '+str(sorted(expected_paths-seen)))
    for row in rows:
        if row.get('profile','default') != 'default' and 'config/usa/compiler_profiles.json' not in seen:
            raise ValueError('Missing compiler profile dependency')
    return snapshots


def validate_captures(snapshots):
    """Reject duplicate writes and tampered capture bytes before any mutation."""
    seen = set()
    provenance = None
    for row in snapshots:
        if row['path'] in seen:
            raise ValueError('Duplicate/conflicting dependency write: '+row['path'])
        seen.add(row['path'])
        if sha(row['before']) != row['before_sha256'] or sha(row['after']) != row['after_sha256'] or row['before'] == row['after']:
            raise ValueError('Dependency snapshot hash mismatch')
        if not row['selected_identities']:
            raise ValueError('Missing selected identity provenance')
        if provenance is None:
            provenance = row['selected_identities']
        elif provenance != row['selected_identities']:
            raise ValueError('Conflicting selected identity provenance')


def install_mixed_dependencies(root, snapshots):
    validate_captures(snapshots)
    for row in snapshots:
        safe_path(root, row['path'])
    install_dependencies(root, snapshots)


def verify_mixed_dependencies(root, snapshots):
    validate_captures(snapshots)
    for row in snapshots:
        safe_path(root, row['path'])
    verify_dependencies(root, snapshots)


def restore_mixed_dependencies(root, snapshots):
    validate_captures(snapshots)
    for row in snapshots:
        safe_path(root, row['path'])
    restore_dependencies(root, snapshots)
