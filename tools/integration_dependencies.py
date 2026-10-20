"""Hash-bound, narrowly derived dependencies for a verified function subset.

Existing source may change identifiers only. Compiler profiles, naming records,
linker roots and the owning symbol map are derived from the selected functions;
no arbitrary staged configuration or callee type edits are transferred.
"""
import hashlib
import json
import os
from pathlib import Path
import re
import stat

from arm9_module import delinks_path
from integration_bookkeeping import atomic_write


def sha(content):
    return hashlib.sha256(content).hexdigest() if content is not None else None


def renamed(text, renames):
    if not renames:
        return text
    pattern = re.compile(r'(?<![\w$])(' + '|'.join(map(re.escape, renames)) + r')(?![\w$])')
    return ''.join(line if re.match(r'\s*//\s*Original:', line) else
                   pattern.sub(lambda m: renames[m[1]], line)
                   for line in text.splitlines(keepends=True))


def renamed_configure_roots(text, renames):
    """Only selected identifiers in the one explicit linker-root assignment."""
    pattern = re.compile(r'(?m)^(active_function_name[ \t]*=[ \t]*")(-force_active [A-Za-z_]\w*(?:,[A-Za-z_]\w*)*)("[ \t]*)$')
    matches = list(pattern.finditer(text))
    if len(matches) != 1:
        raise ValueError('Configure linker root assignment is ambiguous or unsupported')
    match = matches[0]
    return text[:match.start(2)] + renamed(match[2], renames) + text[match.end(2):]


def safe_path(root, relative):
    path = Path(relative)
    if path.is_absolute() or '..' in path.parts or path.as_posix() != relative:
        raise ValueError('Noncanonical dependency path')
    target = root / path
    if target.is_symlink() or not target.resolve().is_relative_to(root.resolve()):
        raise ValueError('Dependency path escapes tree')
    return target


def capture_dependencies(main, worker, module, manifest):
    declarations = manifest.get('dependencies', [])
    if not declarations:
        if manifest.get('function_renames'):
            raise ValueError('Function renames require hash-bound dependencies')
        return []
    rows = manifest['functions']
    selected = {r['name']: r for r in rows}
    rename_rows = manifest.get('function_renames', [])
    renames = {}
    symbols_path = delinks_path(module).with_name('symbols.txt').as_posix()
    symbol_text = (main / symbols_path).read_text() if rename_rows else ''
    for item in rename_rows:
        old, new = item['old'], item['new']
        row = selected.get(new)
        if not row or old in renames or new in renames.values() or old == new:
            raise ValueError('Rename must select a unique new function')
        if not all(re.fullmatch(r'[A-Za-z_]\w*', n) for n in (old, new)):
            raise ValueError('Invalid function rename')
        pattern = rf'(?m)^{re.escape(old)} kind:function\([^\n]*\) addr:0x{int(row["address"],16):08x}\b[^\n]*$'
        matches = re.findall(pattern, symbol_text)
        if len(matches) != 1 or re.search(rf'(?m)^{re.escape(new)}\s', symbol_text):
            raise ValueError('Rename does not bind one original module symbol')
        renames[old] = new
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
        elif relative == symbols_path:
            expected = before.decode()
            for old, new in renames.items():
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
                              mtime_ns=metadata.st_mtime_ns if metadata else None))
    if renames:
        expected_paths.update((symbols_path, 'config/usa/function_names.json'))
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


def install_dependencies(root, snapshots):
    # Check every preimage before the first mutation; rollback also covers a
    # partially written final file and newly created policy files.
    for row in snapshots:
        path = root / row['path']
        if (path.read_bytes() if path.exists() else None) != row['before']:
            raise ValueError('Dependency changed after capture: '+row['path'])
    for row in snapshots:
        atomic_write(root/row['path'], row['after'])
        if row['mode'] is not None:(root/row['path']).chmod(row['mode'])


def verify_dependencies(root, snapshots):
    for row in snapshots:
        if (root/row['path']).read_bytes() != row['after']:
            raise ValueError('Installed dependency changed: '+row['path'])


def restore_dependencies(root, snapshots):
    for row in reversed(snapshots):
        path = root/row['path']
        if row['before'] is None:
            path.unlink(missing_ok=True)
        else:
            atomic_write(path,row['before'])
            path.chmod(row['mode'])
            # Keep the fresh replacement timestamp: Ninja must rebuild objects
            # compiled from the rejected identifier/configuration version.
