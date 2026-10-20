"""Opt-in mixed source transaction, invoked only by integrate_verified_subset.py.

No standalone CLI: the existing wrapper owns the integration guard before reads.
"""
import json
import hashlib
from pathlib import Path
import shlex
import subprocess
import time
import stat
import datetime
from arm9_module import delinks_path, verify_measures
from integrate_batch import parse_delinks, validate_ranges
from integration_bookkeeping import Bookkeeping, atomic_write, json_bytes
from mixed_integration_dependencies import install_mixed_dependencies as install_dependencies, verify_mixed_dependencies as verify_dependencies
from integration_sources import capture_sources, verify_sources
from function_naming import validate_new_functions
from mixed_module_plan import source_only_plan, unique_captures
import integration_mixed_recovery as recovery

REPORT='build/usa/report.json'
ARM7='build/usa/arm7/report.json'
CONFIGURE='python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8 --keep-symbol func_020dc008 --keep-symbol func_020dc020'
FULL='ninja -j 2 rom check report sha1'


def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()


def container(root,folder,command,log):
    with (folder/log).open('w') as output:
        subprocess.run(['sudo','-n','docker','run','--rm','--user','1000:1000','-v',str(root)+':/bench/project','-v','/home/swayn/.local/share/factory-inputs/dqix:/inputs:ro','-w','/bench/project','factory-dqix:0.1','bash','-c',command],cwd=root,check=True,stdout=output,stderr=subprocess.STDOUT)


def workflow(root,folder,label,phase):
    with (folder/('work-'+phase+'.log')).open('w') as output:
        subprocess.run(['python3','tools/work_batch.py',phase,label]+(['--attempts','1','--notes','Mixed source transaction; individual reconstruction evidence remains in worker artifacts.'] if phase=='finish' else []),cwd=root,check=True,stdout=output)


def module_measures(root,report):
    """Assign every report unit from explicit ownership or exact fallback names."""
    import re
    owners={}
    config=root/'config/usa/arm9'
    for path in config.rglob('delinks.txt'):
        module='main' if path.parent==config else path.parent.name
        document=parse_delinks(path.read_text(),allow_empty_sections=module!='main')
        for source in document.blocks:
            name=str(Path(source).with_suffix(''))
            if name in owners and owners[name]!=module:raise ValueError('Ambiguous module owner: '+name)
            owners[name]=module
    keys=('total_functions','total_code','total_data','matched_functions','matched_code','matched_data')
    totals={}
    for unit in report['units']:
        name=unit['name'];module=owners.get(name)
        if module is None:
            match=re.fullmatch(r'(main|itcm|dtcm|ov\d{3})_\d+',name)
            if not match:raise ValueError('Report unit lacks module owner: '+name)
            module=match[1]
        values=totals.setdefault(module,{key:0 for key in keys})
        for key in keys:values[key]+=int(unit.get('measures',{}).get(key,0))
    return totals


def prepare(root,worker,manifest,review_path=None,additions=False):
    if additions:
        if review_path is None:raise ValueError('Contract additions require independent review')
        from integration_source_additions import prepare as prepare_additions
        return prepare_additions(root,worker,manifest,review_path)
    if review_path is not None:
        from integration_source_contracts import prepare as prepare_contract
        return prepare_contract(root,worker,manifest,review_path)
    if manifest.get('schema')=='arm9-source-contract-v1' or 'source_contracts' in manifest:raise ValueError('Source contracts require independent review mode')
    plan=source_only_plan(manifest)
    if not 40 <= plan['expected_functions'] <= 50:raise ValueError('Mixed source gate requires 40 to 50 selected functions')
    expected_units=[str(Path(row['source']).with_suffix('')) for row in manifest['functions']]
    if len(manifest.get('units',[]))!=len(expected_units) or set(manifest['units'])!=set(expected_units):
        raise ValueError('Mixed compared units differ from source functions')
    snapshots,audit=capture_sources(worker,[r['source'] for r in manifest['functions']],manifest)
    from mixed_integration_dependencies import capture_mixed_dependencies
    dependencies=capture_mixed_dependencies(root,worker,manifest)
    changes={s:content for s,content in snapshots.items()}
    # Retain per-module capture hooks even though source-only proposals cannot
    # append data, relocation or retention policy. Future changes fail closed.
    from integration_relocations import capture_relocations
    from integration_symbols import capture_symbols
    from integration_retention import capture_retention_policy
    maps={}
    all_owned={s for path in (root/'config/usa/arm9').rglob('delinks.txt') for s in parse_delinks(path.read_text(),allow_empty_sections=path.parent!=root/'config/usa/arm9').blocks}
    for module,part in plan['modules'].items():
        validate_new_functions(root,worker,part,module)
        relative=delinks_path(module);original=(root/relative).read_text()
        main=parse_delinks(original,allow_empty_sections=module!='main')
        staged=parse_delinks((worker/relative).read_text(),allow_empty_sections=module!='main')
        selected={r['source'] for r in part['functions']}
        for source in selected:
            if source in all_owned or (root/source).exists() or (root/source).is_symlink():raise ValueError('Mixed source is not new: '+source)
            if source not in staged.blocks:raise ValueError('Missing staged source block: '+source)
            from integrate_batch import RANGE
            block=staged.blocks[source]
            extents=[RANGE.fullmatch(line) for line in block.splitlines()[1:] if line.strip().startswith('.')]
            row=next(r for r in part['functions'] if r['source']==source)
            if 'complete' not in [line.strip() for line in block.splitlines()[1:]] or len(extents)!=1 or not extents[0]:raise ValueError('Mixed source must own exactly one complete code extent')
            section,start,end=extents[0].groups()
            if section not in ('.text','.init') or int(start,16)!=int(row['address'],16) or int(end,16)!=int(row['address'],16)+row['size']:raise ValueError('Mixed delink extent differs from selected function')
            main.blocks[source]=block
        validate_ranges(main,allow_empty_sections=module!='main')
        maps[relative.as_posix()]=(main.header+'\n\n'+'\n\n'.join(main.blocks.values())+'\n').encode()
        if capture_relocations(root,worker,module,part) or capture_symbols(root,worker,module,part) or capture_retention_policy(root,worker,module,part,[],snapshots):
            raise ValueError('Unexpected non-source mixed capture')
    dependencies=unique_captures([dependencies])
    for row in dependencies:
        if row['path'] in changes or row['path'] in maps:raise ValueError('Dependency conflicts with selected source/map')
        changes[row['path']]=row['after']
    changes.update(maps)
    owner_context={}
    for module in plan['modules']:
        for filename in ('symbols.txt','relocs.txt','retained_data.json'):
            relative=delinks_path(module).with_name(filename).as_posix()
            if relative not in changes:changes[relative]=recovery.read(root,relative)
            owner_context[relative]=recovery.digest(changes[relative])
    audit['owner_context_sha256']=owner_context
    audit['map_modes']={relative:stat.S_IMODE((root/relative).stat().st_mode) for relative in maps}
    audit['owner_context_modes']={relative:stat.S_IMODE((root/relative).stat().st_mode) if (root/relative).exists() else None for relative in owner_context}
    return plan,snapshots,dependencies,maps,changes,audit


def generated_paths(root,receipts,label):
    folder=receipts/label
    return [REPORT,ARM7,'build/usa/arm7-report.json',
            str((receipts/'checkpoint.json').relative_to(root)),
            'build/progress/index.html','build/workflow/'+label+'/start.json',
            'build/workflow/'+label+'/finish.json',str((folder/'receipt.json').relative_to(root))]


def check_reports(root,before,arm7,per_module,plan,manifest):
    report=json.loads((root/REPORT).read_text())
    contract=manifest.get('schema')=='arm9-source-contract-v1'
    credit=plan.get('credit_functions',[] if contract else manifest['functions'])
    verify_measures(before,report['measures'],credit,[])
    if recovery.digest((root/ARM7).read_bytes())!=recovery.digest(arm7):raise ValueError('ARM7 report byte SHA256 changed')
    after_modules=module_measures(root,report)
    if set(after_modules)!=set(per_module):raise ValueError('Report module set changed')
    for module,measures in per_module.items():
        rows=[r for r in credit if r['module']==module] if 'credit_functions' in plan else [] if contract else plan['modules'].get(module,{}).get('functions',[])
        verify_measures(measures,after_modules[module],rows,[])
    units={u['name']:u for u in report['units']}
    if len(units)!=len(report['units']):raise ValueError('Duplicate report unit')
    for row in manifest['functions']:
        unit=units.get(str(Path(row['source']).with_suffix('')), {})
        matches=[f for f in unit.get('functions',[]) if f['name']==row['name']]
        if len(matches)!=1 or matches[0].get('fuzzy_match_percent')!=100 or int(matches[0]['size'])!=row['size']:
            raise ValueError('Mixed selected function not exact in report: '+row['name'])
    return report['measures'],after_modules


def success_command(root,folder,plan):
    receipt=folder.relative_to(root).as_posix()
    command=('umask 022 && ' if plan.get('source_contract_additions') else '')+CONFIGURE+' && ninja -j 2 objdiff delink build/usa/arm9.lcf && python3 tools/compile_verify_batch.py --manifest '+shlex.quote(receipt+'/manifest.json')+' --jobs 2 --compare-jobs 4 --verify-manifest-sources > '+shlex.quote(receipt+'/comparison.json')+' && '+FULL
    for module in plan['modules']:
        command+=' && python3 tools/audit_link_layout.py '+shlex.quote(receipt+'/module-'+module+'.json')+' --elf build/usa/arm9.o --module '+shlex.quote(module)+' --output '+shlex.quote(receipt+'/layout-'+module+'.json')
    return command


def validate_artifacts(folder,plan,manifest):
    comparison=json.loads((folder/'comparison.json').read_text())
    if comparison.get('match') is not True or comparison.get('units')!=len(manifest['units']) or comparison.get('matched')!=len(manifest['units']) or comparison.get('errors',0) or comparison.get('mismatched',0):
        raise ValueError('Mixed object comparison incomplete')
    for module,part in plan['modules'].items():
        layout=json.loads((folder/('layout-'+module+'.json')).read_text())
        if layout.get('match') is not True or layout.get('functions')!=len(part['functions']) or layout.get('differences'):
            raise ValueError('Mixed module layout incomplete: '+module)


def rollback(root,folder,journal,before,arm7,bookkeeping,transaction,gate=container,per_module=None):
    receipt=folder/'receipt.json'
    rejected=receipt.read_bytes() if receipt.exists() else None
    recovery.restore(root,folder,journal)
    if rejected is not None:
        quarantine=folder/'rolled-back-receipt.json'
        if quarantine.exists() and quarantine.read_bytes()!=rejected:raise ValueError('Rollback receipt quarantine collision')
        atomic_write(quarantine,rejected)
    if bookkeeping is not None:bookkeeping.rollback()
    gate(root,folder,CONFIGURE+' && ninja -j 2 objdiff delink rom check report sha1','rollback-validation.log')
    if json.loads((root/REPORT).read_text())['measures']!=before or recovery.digest((root/ARM7).read_bytes())!=recovery.digest(arm7):
        raise ValueError('Mixed rollback reports differ from baseline')
    if per_module is not None and module_measures(root,json.loads((root/REPORT).read_text()))!=per_module:raise ValueError('Mixed rollback module measures differ')
    for row in journal['entries']:
        if not row['generated']:
            path=root/row['path']
            mode=stat.S_IMODE(path.stat().st_mode) if path.exists() else None
            if recovery.digest(recovery.read(root,row['path']))!=row['before_sha256'] or mode!=row['mode']:raise ValueError('Rollback validation changed restored source/config: '+row['path'])
    if 'contract_baseline' in journal:
        from integration_source_contracts import verify_baseline
        verify_baseline(root,journal['contract_baseline'])
    atomic_write(folder/'failure.json',json_bytes(dict(accepted=False,restored=True,finish=now())))
    transaction.release_publication()


def run(args,transaction,gate=container,work=workflow,bookkeeping_type=Bookkeeping):
    """Caller must hold the project guard; no project reads occur before this."""
    if transaction.stream is None:raise ValueError('Mixed route requires held integration guard')
    root=args.project.resolve();worker=args.worker.resolve();receipts=args.receipts.resolve();folder=receipts/args.label
    if not receipts.is_relative_to(root/'build') or folder.is_symlink():raise ValueError('Unsafe mixed receipt destination')
    if args.recover_failed or args.restore_interrupted:
        return recover(args,transaction,gate)
    if args.preimage_tree is not None:raise ValueError('Preimage tree applies only to recovery')
    manifest_bytes=(worker/args.manifest).read_bytes();manifest=json.loads(manifest_bytes)
    plan,snapshots,dependencies,maps,changes,audit=prepare(root,worker,manifest,getattr(args,'contract_review',None),getattr(args,'source_contract_additions',False))
    report=json.loads((root/REPORT).read_text());before=report['measures'];arm7=(root/ARM7).read_bytes();per_module=module_measures(root,report)
    generated=generated_paths(root,receipts,args.label)
    for relative in generated:
        if relative in changes:raise ValueError('Generated path conflicts with source capture')
        changes[relative]=None
    folder.mkdir(parents=True,exist_ok=False)
    atomic_write(folder/'manifest.json',manifest_bytes)
    if audit.get('contract'):
        atomic_write(folder/'contract-review.json',audit['review_bytes'])
        for index,content in enumerate(audit['evidence'].values()):atomic_write(folder/('contract-evidence-%04d.bin'%index),content)
    for module,part in plan['modules'].items():atomic_write(folder/('module-'+module+'.json'),json_bytes(part))
    baseline=dict(before=before,arm7_sha256=recovery.digest(arm7),per_module=per_module)
    if audit.get('contract'):baseline['contract_review_sha256']=recovery.digest(audit['review_bytes'])
    atomic_write(folder/'mixed-baseline.json',json_bytes(baseline))
    journal=recovery.make_journal(root,folder,manifest_bytes,changes,set(generated),audit.get('immutable_paths',()))
    if audit.get('contract'):
        journal['contract_review_sha256']=recovery.digest(audit['review_bytes'])
        journal['contract_baseline']=__import__('integration_source_contracts').baseline(audit)
        atomic_write(folder/'mixed-journal.json',json_bytes(journal))
    bookkeeping=bookkeeping_type(root,receipts,args.label)
    timing=dict(start=now(),role=args.role,modules=list(plan['modules']),source_only=True,source_hashes=audit['source_hashes'],owner_context_sha256=audit['owner_context_sha256'],arm7_report_sha256_before=recovery.digest(arm7))
    started=time.monotonic();transaction.begin_changes()
    try:
        if audit.get('contract'):
            from integration_source_contracts import verify_preimages
            verify_preimages(root,audit,journal)
        install_dependencies(root,dependencies)
        work(root,folder,args.label,'start')
        if audit.get('contract'):
            for relative in audit['install_paths']:
                atomic_write(root/relative,changes[relative]);(root/relative).chmod(audit['modes'][relative])
        else:
            for source,content in snapshots.items():atomic_write(root/source,content)
        for relative,content in maps.items():
            atomic_write(root/relative,content)
            (root/relative).chmod(audit['map_modes'][relative])
        gate_started=time.monotonic();gate(root,folder,success_command(root,folder,plan),'validation.log');timing['validation_seconds']=time.monotonic()-gate_started
        validate_artifacts(folder,plan,manifest)
        verify_sources(root,snapshots);verify_dependencies(root,dependencies)
        for relative,content in maps.items():
            if (root/relative).read_bytes()!=content or stat.S_IMODE((root/relative).stat().st_mode)!=audit['map_modes'][relative]:raise ValueError('Installed module map content or mode changed')
        for relative,digest in audit['owner_context_sha256'].items():
            if recovery.digest(recovery.read(root,relative))!=digest:raise ValueError('Module owner context changed: '+relative)
            mode=stat.S_IMODE((root/relative).stat().st_mode) if (root/relative).exists() else None
            if mode!=audit['owner_context_modes'][relative]:raise ValueError('Module owner context mode changed: '+relative)
        if audit.get('contract'):
            from integration_source_contracts import verify as verify_contract,check_report
            verify_contract(root,audit);check_report(root,audit)
        after,after_modules=check_reports(root,before,arm7,per_module,plan,manifest)
        work(root,folder,args.label,'finish')
        timing.update(accepted=True,finish=now(),elapsed_seconds=time.monotonic()-started,
                      functions=plan['expected_functions'],code_bytes=plan['expected_code_bytes'],data_bytes=0,bss_bytes=0,
                      before=before,after=after,arm7_report_sha256_after=recovery.digest((root/ARM7).read_bytes()),module_measures_before=per_module,module_measures_after=after_modules)
        if audit.get('contract'):
            timing.update(source_contract=True,refined_functions=len(manifest['functions']),c_instruction_credit=0,
                          contract_proposal_sha256=__import__('integration_source_contracts').proposal_sha256(manifest),
                          contract_review_sha256=recovery.digest(audit['review_bytes']),
                          original_targets_sha256=audit['original_targets_sha256'])
            if audit.get('adding'):
                timing.pop('c_instruction_credit')
                timing.update(source_contract_additions=True,refined_functions=len(manifest['functions'])-plan['expected_functions'])
        bookkeeping.prepare(timing,after,now())
        # Persist every new publication snapshot before it can be installed, so
        # interrupted recovery cannot delete unrelated snapshot history.
        for staged in (bookkeeping.stage/'snapshots').glob('*.json'):
            target=root/'build/progress/snapshots'/staged.name
            if staged.is_symlink() or target.exists() or target.is_symlink():raise ValueError('Mixed publication snapshot collision')
            relative=target.relative_to(root).as_posix()
            journal['entries'].append(dict(path=relative,before_sha256=None,after_sha256=recovery.digest(staged.read_bytes()),backup=None,mode=None,generated=True))
        atomic_write(folder/'mixed-journal.json',json_bytes(journal))
        bookkeeping.publish()
        transaction.release_publication()
        return timing
    except BaseException:
        try:
            from integration_failure_evidence import capture
            capture(root,folder)
        except Exception as evidence_error:
            atomic_write(folder/'failure-evidence-error.json',json_bytes(dict(error=repr(evidence_error),rollback_still_required=True)))
        rollback(root,folder,journal,before,arm7,bookkeeping,transaction,gate,per_module)
        raise


def recover(args,transaction,gate=container):
    """Reconstruct all config postimages from independent preimages, then restore."""
    if not transaction.changed or not transaction.publication.exists() or args.preimage_tree is None:
        raise ValueError('Mixed recovery requires retained publication ownership and independent preimage tree')
    root=args.project.resolve();worker=args.worker.resolve();receipts=args.receipts.resolve();folder=receipts/args.label;preimages=args.preimage_tree.resolve()
    manifest_bytes=(worker/args.manifest).read_bytes()
    if (folder/'manifest.json').is_symlink() or (folder/'manifest.json').read_bytes()!=manifest_bytes:raise ValueError('Mixed recovery manifest changed')
    manifest=json.loads(manifest_bytes)
    plan,snapshots,dependencies,maps,changes,audit=prepare(preimages,worker,manifest,getattr(args,'contract_review',None),getattr(args,'source_contract_additions',False))
    generated=generated_paths(root,receipts,args.label)
    for relative in generated:changes[relative]=None
    # Snapshot additions are authenticated by their staged publication payload;
    # they must be absent in the independent preimage tree.
    stage=folder/'publication/snapshots'
    recorded=json.loads((folder/'mixed-journal.json').read_text())
    recorded_paths={row['path'] for row in recorded['entries']}
    if stage.exists():
        for path in stage.glob('*.json'):
            if path.is_symlink():raise ValueError('Symlinked publication snapshot')
            relative='build/progress/snapshots/'+path.name
            if recovery.read(preimages,relative) is not None:raise ValueError('Existing snapshot cannot be recovered as new')
            if relative not in recorded_paths:
                if recovery.read(root,relative) is not None:raise ValueError('Unjournaled publication snapshot exists')
                continue
            changes[relative]=path.read_bytes();generated.append(relative)
    journal=recovery.authenticate(folder,manifest_bytes,changes,set(generated),preimages,audit.get('immutable_paths',()))
    if audit.get('contract'):
        if journal.get('contract_baseline')!=__import__('integration_source_contracts').baseline(audit):raise ValueError('Interrupted contract baseline authentication failed')
        review=folder/'contract-review.json'
        if review.is_symlink() or review.read_bytes()!=audit['review_bytes'] or journal.get('contract_review_sha256')!=recovery.digest(audit['review_bytes']):raise ValueError('Interrupted contract review authentication failed')
        for index,content in enumerate(audit['evidence'].values()):
            saved=folder/('contract-evidence-%04d.bin'%index)
            if saved.is_symlink() or saved.read_bytes()!=content:raise ValueError('Interrupted contract evidence authentication failed')
    baseline=json.loads((folder/'mixed-baseline.json').read_text())
    independent=json.loads((preimages/REPORT).read_text())
    expected_baseline=dict(before=independent['measures'],arm7_sha256=recovery.digest((preimages/ARM7).read_bytes()),per_module=module_measures(preimages,independent))
    if audit.get('contract'):expected_baseline['contract_review_sha256']=recovery.digest(audit['review_bytes'])
    if baseline!=expected_baseline:
        raise ValueError('Mixed recovery baseline authentication failed')
    rollback(root,folder,journal,baseline['before'],(preimages/ARM7).read_bytes(),None,transaction,gate,baseline['per_module'])
    return dict(accepted=False,recovered_rollback=True)
