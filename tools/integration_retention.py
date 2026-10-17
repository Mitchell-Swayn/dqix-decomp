"""Capture one module's source-bound linker roots for a data transaction."""
import hashlib
import json
from pathlib import Path
from arm9_module import delinks_path
from linker_retention import retained_data_symbols


def capture_retention_policy(main, worker, module, manifest, data, sources):
    declared = manifest.get('retention_policy')
    if declared is None:
        if 'retention_policy_sha256' in manifest:
            raise ValueError('Retention hash without policy')
        return None
    relative = Path(delinks_path(module)).with_name('retained_data.json')
    if declared != relative.as_posix():
        raise ValueError('Retention dependency must be the selected module policy')
    main, worker = Path(main).resolve(), Path(worker).resolve()
    for root in (main, worker):
        path = root / relative
        if path.is_symlink() or not path.resolve().is_relative_to(root / 'config'):
            raise ValueError('Retention dependency escapes config')
    content = (worker / relative).read_bytes()
    if manifest.get('retention_policy_sha256') != hashlib.sha256(content).hexdigest():
        raise ValueError('Retention dependency hash mismatch')
    retained_data_symbols(worker, 'usa')
    before = (main / relative).read_bytes() if (main / relative).exists() else None
    old = json.loads(before) if before is not None else {'schema_version':1,'symbols':[]}
    new = json.loads(content)
    if new.get('schema_version') != 1 or old.get('schema_version') != 1:
        raise ValueError('Invalid retention dependency schema')
    old_rows = {row['name']: row for row in old['symbols']}
    new_rows = {row['name']: row for row in new['symbols']}
    if len(old_rows)!=len(old['symbols']) or len(new_rows)!=len(new['symbols']):
        raise ValueError('Duplicate retention dependency')
    if any(new_rows.get(name)!=row for name,row in old_rows.items()):
        raise ValueError('Retention dependency changes existing roots')
    additions = [row for name,row in new_rows.items() if name not in old_rows]
    if not additions:
        raise ValueError('Retention dependency must add selected data roots')
    selected = {row['name']:row for row in data}
    for row in additions:
        selected_row = selected.get(row['name'])
        if selected_row is None or row['source'] not in sources:
            raise ValueError('Retention root is outside selected data')
        address = selected_row.get('address', selected_row.get('addr'))
        if (int(row['address'],16)!=int(address,16) or row['size']!=int(selected_row['size']) or
                row['section']!=selected_row['section'] or
                row['source']!=selected_row['source'] or
                row['original_sha256']!=selected_row.get('sha256') or
                row['source_sha256']!=hashlib.sha256(sources[row['source']]).hexdigest()):
            raise ValueError('Retention root does not bind selected data extent/source')
    return {'path':relative.as_posix(),'before':before,'after':content}


def install_retention_policy(root, snapshot):
    if snapshot is not None:
        path = Path(root) / snapshot['path']
        current = path.read_bytes() if path.exists() else None
        if current != snapshot['before']:
            raise ValueError('Retention policy changed after capture')
        path.write_bytes(snapshot['after'])
        retained_data_symbols(root, 'usa')


def verify_retention_policy(root, snapshot):
    if snapshot is not None and (Path(root)/snapshot['path']).read_bytes()!=snapshot['after']:
        raise ValueError('Installed retention policy changed')


def restore_retention_policy(root, snapshot):
    if snapshot is not None:
        path=Path(root)/snapshot['path']
        if snapshot['before'] is None:
            path.unlink(missing_ok=True)
        else:
            path.write_bytes(snapshot['before'])
