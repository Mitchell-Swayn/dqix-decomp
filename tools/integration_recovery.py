"""Fail-closed validation of an already restored, unpublished ARM9 subset.

This path never installs candidate source/config. It authenticates the saved
preimages, invalidates stale build timestamps and reruns the unchanged full gate.
"""
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess

from arm9_module import delinks_path
from integration_bookkeeping import atomic_write,json_bytes
from integration_dependencies import capture_dependencies,safe_path


def verify_rollback_state(main,worker,folder,module):
    manifest=json.loads((folder/'manifest.json').read_text())
    if manifest.get('module',module)!=module or any(manifest.get(k) for k in ('source_refinements','data','runtime_support','runtime_append','runtime_replacement')):
        raise ValueError('Recovery supports only unpublished new-function subsets')
    if any((folder/name).exists() for name in ('publication','receipt.json','rolled-back-receipt.json')):
        raise ValueError('Publication state requires its original bookkeeping snapshots')
    relative=delinks_path(module)
    if (main/relative).read_bytes()!=(folder/(relative.as_posix().replace('/','_')+'.before')).read_bytes():
        raise ValueError('Restored delink map differs from transaction preimage')
    paths={relative.as_posix()}
    for row in manifest['functions']:
        if safe_path(main,row['source']).exists():raise ValueError('Rejected source remains installed')
    dependencies=capture_dependencies(main,worker,module,manifest)
    paths.update(row['path'] for row in dependencies)
    before=json.loads((folder/'build_usa_report.json.before').read_text())['measures']
    arm7=json.loads((folder/'build_usa_arm7_report.json.before').read_text())
    return manifest,sorted(paths),before,arm7


def recover(main,worker,receipts,label,module,transaction):
    folder=receipts/label
    if not transaction.changed or not transaction.publication.exists():
        raise ValueError('Recovery needs the retained publication gate and process owner')
    manifest,paths,before,arm7=verify_rollback_state(main,worker,folder,module)
    page=main/'build/progress/index.html';checkpoint=receipts/'checkpoint.json'
    preserved={p:p.read_bytes() for p in (page,checkpoint) if p.exists()}
    # Content is authenticated above. Touch only restored dependency paths so
    # incremental compilation cannot reuse rejected objects with newer mtimes.
    for relative in paths:os.utime(main/relative,None)
    command='python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8 --keep-symbol func_020dc008 --keep-symbol func_020dc020 && ninja -j 2 objdiff delink rom check report sha1'
    with (folder/'recovery-validation.log').open('w') as output:
        subprocess.run(['sudo','-n','docker','run','--rm','--user','1000:1000','-v',str(main)+':/bench/project','-v','/home/swayn/.local/share/factory-inputs/dqix:/inputs:ro','-w','/bench/project','factory-dqix:0.1','bash','-c',command],cwd=main,check=True,stdout=output,stderr=subprocess.STDOUT)
    verify_rollback_state(main,worker,folder,module)
    restored=json.loads((main/'build/usa/report.json').read_text())['measures']
    if restored!=before or json.loads((main/'build/usa/arm7/report.json').read_text())!=arm7:
        raise ValueError('Recovered reports differ from accepted baseline')
    if any(path.read_bytes()!=content for path,content in preserved.items()):
        raise ValueError('Unpublished recovery changed accepted dashboard/checkpoint')
    workflow=main/'build/workflow'/label
    start=json.loads((workflow/'start.json').read_text())
    if any(str(before[key])!=str(value) for key,value in start['snapshot']['arm9'].items()):
        raise ValueError('Workflow start does not authenticate this baseline')
    if (workflow/'finish.json').exists():raise ValueError('Unexpected finished workflow')
    (workflow/'start.json').unlink()
    record=dict(accepted=False,recovered_rollback=True,finish=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                before=before,after=restored,invalidated_dependencies=paths,
                reason='Restored source/config preimages matched; stale generated objects invalidated after old-mtime restoration.',
                rom_sha1=start['snapshot']['rom_sha1'],arm7_unchanged=True)
    atomic_write(folder/'failure.json',json_bytes(record))
    atomic_write(folder/'recovered-rollback.json',json_bytes(record))
    transaction.release_publication()
    print(json.dumps({'recovered_rollback':True,'label':label,'accepted':False}),flush=True)


def restore_interrupted(main, worker, receipts, label, module, preimages, transaction):
    """Restore only authenticated transaction paths, then rerun the full gate.

    Candidate success before cancellation is never acceptance. Preimages must
    independently match the original manifest's before hashes before any write.
    """
    from integration_dependencies import restore_dependencies
    from integration_sources import capture_sources
    from integrate_batch import parse_delinks, validate_ranges
    folder=receipts/label
    if not transaction.changed or not transaction.publication.exists():
        raise ValueError('Interrupted restore requires recovery ownership')
    manifest=json.loads((folder/'manifest.json').read_text())
    if manifest.get('module')!=module or any(manifest.get(k) for k in ('source_refinements','data','runtime_support','runtime_append','runtime_replacement','relocation_map','symbol_map','retention_policy')):
        raise ValueError('Interrupted restore supports only new-function/dependency subsets')
    if any((folder/name).exists() for name in ('publication','receipt.json','rolled-back-receipt.json')):
        raise ValueError('Published transaction needs original bookkeeping recovery')
    if (main/'build/workflow'/label/'finish.json').exists():
        raise ValueError('Finished workflow needs original bookkeeping recovery')
    relative=delinks_path(module)
    saved=(folder/(relative.as_posix().replace('/','_')+'.before')).read_bytes()
    if safe_path(preimages,relative.as_posix()).read_bytes()!=saved:
        raise ValueError('Interrupted delink preimage hash mismatch')
    dependencies=capture_dependencies(preimages,worker,module,manifest)
    paths=[row['source'] for row in manifest['functions']]
    sources,audit=capture_sources(worker,paths,manifest)
    baseline=parse_delinks(saved.decode(),allow_empty_sections=module!='main')
    staged=parse_delinks((worker/relative).read_text(),allow_empty_sections=module!='main')
    for name in paths:
        if safe_path(preimages,name).exists() or name in baseline.blocks or name not in staged.blocks:
            raise ValueError('Interrupted source is not new to authenticated baseline')
        target=safe_path(main,name)
        if target.exists() and target.read_bytes()!=sources[name]:
            raise ValueError('Interrupted source after hash mismatch: '+name)
        baseline.blocks[name]=staged.blocks[name]
    validate_ranges(baseline,allow_empty_sections=module!='main')
    installed=(baseline.header+'\n\n'+'\n\n'.join(baseline.blocks.values())+'\n').encode()
    if (main/relative).read_bytes() not in (saved,installed):
        raise ValueError('Interrupted delink after hash mismatch')
    for row in dependencies:
        target=main/row['path'];current=target.read_bytes() if target.exists() else None
        if current not in (row['before'],row['after']):
            raise ValueError('Interrupted dependency after hash mismatch: '+row['path'])
    before=json.loads((folder/'build_usa_report.json.before').read_text())['measures']
    start=json.loads((main/'build/workflow'/label/'start.json').read_text())
    if any(str(before[key])!=str(value) for key,value in start['snapshot']['arm9'].items()):
        raise ValueError('Interrupted workflow baseline mismatch')
    atomic_write(folder/'interrupted-restore-intent.json',json_bytes(dict(accepted=False,
        manifest_sha256=hashlib.sha256((folder/'manifest.json').read_bytes()).hexdigest(),
        dependencies=[dict(path=row['path'],before_sha256=hashlib.sha256(row['before']).hexdigest() if row['before'] is not None else None) for row in dependencies],
        reason='Cancelled before atomic publication; restore authenticated preimages and verify original accepted checkpoint.')))
    for name in paths:(main/name).unlink(missing_ok=True)
    restore_dependencies(main,dependencies)
    atomic_write(main/relative,saved)
    for name in ('build/usa/report.json','build/usa/arm7/report.json','build/usa/arm7-report.json'):
        backup=folder/(name.replace('/','_')+'.before')
        if backup.exists():atomic_write(main/name,backup.read_bytes())
    recover(main,worker,receipts,label,module,transaction)
