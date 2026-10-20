"""Hash-bound journal for the opt-in mixed source transaction.

Only the existing integration wrapper calls recovery, under its project guard.
Interrupted recovery requires independently retained preimages and restages the
proposal against them before any restoration. Unknown edits fail closed.
"""
import hashlib
import json
from pathlib import Path
import stat
from integration_bookkeeping import atomic_write, json_bytes
from integration_dependencies import safe_path


def digest(data):
    return hashlib.sha256(data).hexdigest() if data is not None else None


def read(root, relative):
    target=safe_path(Path(root),relative)
    return target.read_bytes() if target.exists() else None


def make_journal(root, folder, manifest_bytes, changes, generated, immutable=()):
    folder=Path(folder)
    entries=[]
    for index,(relative,after) in enumerate(changes.items()):
        target=safe_path(root,relative);before=read(root,relative)
        backup='preimage-%04d.bin'%index
        if before is not None:atomic_write(folder/backup,before)
        entries.append(dict(path=relative,before_sha256=digest(before),after_sha256=digest(after),
                            backup=backup if before is not None else None,
                            mode=stat.S_IMODE(target.stat().st_mode) if before is not None else None,
                            generated=relative in generated))
        if relative in immutable:
            if before is None or before!=after or relative in generated:raise ValueError('Immutable journal path must be unchanged existing input')
            entries[-1]['immutable']=True
    journal=dict(schema='arm9-mixed-journal-v1',manifest_sha256=digest(manifest_bytes),entries=entries)
    atomic_write(folder/'mixed-journal.json',json_bytes(journal))
    return journal


def backups(folder,journal):
    result={}
    for index,row in enumerate(journal['entries']):
        expected='preimage-%04d.bin'%index if row['before_sha256'] is not None else None
        if row['backup']!=expected:raise ValueError('Noncanonical journal backup')
        path=Path(folder)/expected if expected else None
        if path and path.is_symlink():raise ValueError('Symlinked journal backup')
        content=path.read_bytes() if path else None
        if digest(content)!=row['before_sha256']:raise ValueError('Corrupt journal preimage: '+row['path'])
        if row['path'] in result:raise ValueError('Duplicate journal path')
        result[row['path']]=content
    return result


def authenticate(folder,manifest_bytes,expected_changes,generated,preimages,immutable=()):
    path=Path(folder)/'mixed-journal.json'
    if path.is_symlink():raise ValueError('Symlinked mixed journal')
    journal=json.loads(path.read_text())
    if journal.get('schema')!='arm9-mixed-journal-v1' or journal.get('manifest_sha256')!=digest(manifest_bytes):
        raise ValueError('Mixed journal manifest authentication failed')
    content=backups(folder,journal)
    if set(content)!=set(expected_changes):raise ValueError('Mixed journal path set differs from authenticated proposal')
    for row in journal['entries']:
        relative=row['path']
        if row['generated']!=(relative in generated) or bool(row.get('immutable',False))!=(relative in immutable):raise ValueError('Changed journal path class')
        if row.get('immutable') and (row['before_sha256']!=row['after_sha256'] or row['generated']):raise ValueError('Changed immutable journal input')
        if row['after_sha256']!=digest(expected_changes[relative]):raise ValueError('Changed journal postimage')
        if read(preimages,relative)!=content[relative]:raise ValueError('Independent preimage differs: '+relative)
        target=safe_path(preimages,relative)
        mode=stat.S_IMODE(target.stat().st_mode) if target.exists() else None
        if row['mode']!=mode:raise ValueError('Independent preimage mode differs')
    return journal


def restore(root,folder,journal):
    content=backups(folder,journal)
    # Authenticate EVERY current configuration/source before the first write.
    for row in journal['entries']:
        current=read(root,row['path'])
        if row.get('immutable'):
            path=safe_path(root,row['path'])
            mode=stat.S_IMODE(path.stat().st_mode) if path.exists() else None
            if row['generated'] or row['before_sha256']!=row['after_sha256'] or digest(current)!=row['before_sha256'] or mode!=row['mode']:raise ValueError('Unrecognized dirty immutable transaction path: '+row['path'])
        if not row['generated'] and digest(current) not in (row['before_sha256'],row['after_sha256']):
            raise ValueError('Unrecognized dirty transaction path: '+row['path'])
    for row in reversed(journal['entries']):
        if row.get('immutable'):continue
        path=safe_path(root,row['path']);before=content[row['path']]
        if before is None:path.unlink(missing_ok=True)
        else:
            atomic_write(path,before)
            path.chmod(row['mode'])
            # Fresh timestamp invalidates candidate objects after rollback.
    for relative,before in content.items():
        if read(root,relative)!=before:raise ValueError('Rollback preimage differs: '+relative)
