"""Preserve reviewed interior BSS labels as linker aliases, never storage/code.

The declaration binds one module policy, original symbol addresses, frozen source
bytes and complete source-owned BSS extents. Unpaired object labels are deferred
only after exact NOBITS/base-object comparison; all addresses require link audit.
"""
import hashlib
import json
from pathlib import Path
import re
from arm9_module import delinks_path


def digest(content):
    return hashlib.sha256(content).hexdigest() if content is not None else None


def safe_path(root, relative):
    path = Path(relative)
    if path.is_absolute() or '..' in path.parts or path.as_posix() != relative:
        raise ValueError('Noncanonical data-alias policy')
    target = Path(root) / path
    if target.is_symlink() or not target.resolve().is_relative_to(Path(root).resolve() / 'config'):
        raise ValueError('Data-alias policy escapes config')
    return target


def bss_symbols(path):
    result = {}
    for line in Path(path).read_text().splitlines():
        match = re.fullmatch(r'([A-Za-z_]\w*) kind:bss(?:\(size=0x[0-9a-fA-F]+\))? addr:0x([0-9a-fA-F]+)(?: ambiguous)?', line)
        if match:
            if match[1] in result:
                raise ValueError('Duplicate original BSS symbol')
            result[match[1]] = int(match[2], 16)
    return result


def selected_aliases(root, module, manifest):
    spec = manifest.get('data_alias_dependency')
    if spec is None:
        return []
    if set(spec) != {'path', 'before_sha256', 'after_sha256', 'aliases'}:
        raise ValueError('Invalid data-alias dependency schema')
    relative = delinks_path(module).with_name('linker_symbols.json').as_posix()
    if spec['path'] != relative or manifest.get('module', module) != module:
        raise ValueError('Data-alias policy must belong to selected module')
    payload = safe_path(root, relative).read_bytes()
    if digest(payload) != spec['after_sha256']:
        raise ValueError('Stale data-alias policy hash')
    policy = json.loads(payload)
    if not isinstance(policy, dict):
        raise ValueError('Expected data-alias policy object')
    names = spec['aliases']
    if not names or len(names) != len(set(names)) or any(not re.fullmatch(r'[A-Za-z_]\w*', n) for n in names):
        raise ValueError('Expected unique declared data-alias names')
    rows = {r['name']: r for r in manifest.get('data', []) if r.get('section') == '.bss'}
    symbols = bss_symbols(Path(root) / delinks_path(module).with_name('symbols.txt'))
    aliases = []
    for name in names:
        value = policy.get(name)
        if not isinstance(value, dict) or set(value) != {'base', 'offset', 'object', 'section'}:
            raise ValueError('Invalid selected BSS linker alias')
        row = rows.get(value['base'])
        if row is None or value['section'] != '.bss' or name == value['base']:
            raise ValueError('Data alias must reference selected BSS base')
        if row.get('module', module) != module or value['object'] != Path(row['source']).with_suffix('.o').name:
            raise ValueError('Data alias has wrong module/source object')
        if not re.fullmatch(r'0x[0-9a-fA-F]+', value['offset']):
            raise ValueError('Invalid data-alias offset')
        offset = int(value['offset'], 16)
        address, size = int(row['address'], 16), int(row['size'])
        if not 0 < offset < size or symbols.get(row['name']) != address or symbols.get(name) != address + offset:
            raise ValueError('Alias differs from original BSS address/extent')
        source = Path(root) / row['source']
        if not row['source'].startswith('src/') or source.is_symlink() or not source.resolve().is_relative_to(Path(root).resolve() / 'src'):
            raise ValueError('Invalid data-alias source')
        if digest(source.read_bytes()) != manifest.get('source_hashes', {}).get(row['source']):
            raise ValueError('Stale data-alias owner source hash')
        following = [a for a in symbols.values() if address + offset < a < address + size]
        end = min(following, default=address + size)
        aliases.append(dict(name=name, base=row['name'], offset=offset, address=address+offset,
                            size=end-address-offset, source=row['source'], row=row))
    # Every original interior BSS label needs an explicit, independently audited
    # alias. Silently dropping one because its role is unknown is forbidden.
    for row in rows.values():
        start, size = int(row['address'], 16), int(row['size'])
        interior = {n for n, a in symbols.items() if start < a < start+size}
        selected = {a['name'] for a in aliases if a['base'] == row['name']}
        if selected and selected != interior:
            raise ValueError('Selected BSS object omits original interior aliases')
    return aliases


def capture_data_aliases(main, worker, module, manifest):
    if 'data_alias_dependency' not in manifest:
        return None
    spec = manifest['data_alias_dependency']
    aliases = selected_aliases(worker, module, manifest)
    path = safe_path(main, spec['path'])
    before = path.read_bytes() if path.exists() else None
    if digest(before) != spec['before_sha256']:
        raise ValueError('Stale original data-alias policy hash')
    after = safe_path(worker, spec['path']).read_bytes()
    old, new = json.loads(before) if before is not None else {}, json.loads(after)
    if not isinstance(old, dict) or any(new.get(name) != value for name, value in old.items()):
        raise ValueError('Data-alias dependency changes an existing entry')
    if set(new)-set(old) != set(spec['aliases']):
        raise ValueError('Data-alias dependency adds undeclared entries')
    symbols = bss_symbols(Path(main) / delinks_path(module).with_name('symbols.txt'))
    for alias in aliases:
        if symbols.get(alias['name']) != alias['address'] or symbols.get(alias['base']) != int(alias['row']['address'],16):
            raise ValueError('Data-alias dependency changes original symbol addresses')
    profiles = capture_absolute_profile_pins(main, spec['path'], digest(before), digest(after))
    return dict(path=spec['path'], before=before, after=after, aliases=aliases, profiles=profiles)


def install_data_aliases(root, snapshot):
    if snapshot:
        path = safe_path(root, snapshot['path'])
        current = path.read_bytes() if path.exists() else None
        if current != snapshot['before']:
            raise ValueError('Data-alias policy changed during transaction')
        profiles = snapshot.get('profiles')
        if profiles and safe_path(root, profiles['path']).read_bytes() != profiles['before']:
            raise ValueError('Compiler profile pins changed during data-alias transaction')
        from integration_bookkeeping import atomic_write
        atomic_write(path, snapshot['after'])
        if profiles:
            atomic_write(safe_path(root, profiles['path']), profiles['after'])


def verify_data_aliases(root, snapshot, receipt=None):
    if snapshot:
        if safe_path(root, snapshot['path']).read_bytes() != snapshot['after']:
            raise ValueError('Installed data-alias policy differs')
        profiles = snapshot.get('profiles')
        if profiles and safe_path(root, profiles['path']).read_bytes() != profiles['after']:
            raise ValueError('Installed absolute compiler profile pins differ')
        if receipt is not None:
            wanted = sorted(a['name'] for a in snapshot['aliases'])
            if receipt.get('match') is not True or sorted(receipt.get('linked_aliases_audited', [])) != wanted:
                raise ValueError('Missing mandatory linked data-alias audits')


def restore_data_aliases(root, snapshot):
    if snapshot:
        path = safe_path(root, snapshot['path'])
        from integration_bookkeeping import atomic_write
        if snapshot['before'] is None:
            path.unlink(missing_ok=True)
        else:
            atomic_write(path, snapshot['before'])
        profiles = snapshot.get('profiles')
        if profiles:
            atomic_write(safe_path(root, profiles['path']), profiles['before'])


def verify_deferred_objects(target_path, candidate_path, aliases):
    """Audit actual compiler storage and original alias metadata before deferral."""
    from audit_bss_layout import object_layout, read_elf
    rows = list({a['base']: a['row'] for a in aliases}.values())
    target = object_layout(target_path, rows)
    candidate = object_layout(candidate_path, rows)
    for record in (target, candidate):
        record['section'].pop('alignment')
    if target != candidate:
        raise ValueError('Deferred BSS aliases lack exact source-owned base storage')
    names = {a['name'] for a in aliases}
    left, right = read_elf(target_path, names), read_elf(candidate_path, names)
    for alias in aliases:
        symbol = left['symbols'].get(alias['name'])
        if not symbol or (symbol['value'], symbol['size'], symbol['type'], symbol['binding']) != (alias['offset'], alias['size'], 1, 1):
            raise ValueError('Original deferred alias metadata differs')
        if alias['name'] in right['symbols']:
            raise ValueError('Deferred linker alias unexpectedly defined by candidate')
    return sorted(names)


def audit_linked_aliases(linked, aliases, section_index):
    for alias in aliases:
        symbol = linked['symbols'].get(alias['name'])
        if not symbol or (symbol['value'],symbol['size'],symbol['type'],symbol['binding'],symbol['section']) != (alias['address'],0,0,1,section_index):
            raise ValueError('Linked deferred BSS alias differs: '+alias['name'])
    return sorted(a['name'] for a in aliases)



def capture_absolute_profile_pins(root, policy_path, before_hash, after_hash):
    """Derive only existing absolute-link pins affected by an append-only policy.

    Called after capture authenticates the original policy and proves every old
    entry unchanged. No worker compiler-profile edits are imported.
    """
    relative = 'config/usa/compiler_profiles.json'
    path = safe_path(root, relative)
    if not path.exists():
        return None
    before = path.read_bytes()
    document = json.loads(before)
    if not isinstance(document, dict) or not isinstance(document.get('sources'), dict):
        raise ValueError('Invalid compiler profiles for data-alias pin refresh')
    updated = []
    for source, profile in document['sources'].items():
        if not isinstance(profile, dict):
            raise ValueError('Invalid compiler source profile')
        spec = profile.get('absolute_linker_symbols')
        if not isinstance(spec, dict) or spec.get('policy') != policy_path:
            continue
        if before_hash is None or spec.get('policy_sha256') != before_hash:
            raise ValueError('Stale absolute compiler-profile policy pin')
        spec['policy_sha256'] = after_hash
        updated.append(source)
    if not updated:
        return None
    after = (json.dumps(document, indent=2)+'\n').encode()
    return dict(path=relative, before=before, after=after, sources=sorted(updated))
