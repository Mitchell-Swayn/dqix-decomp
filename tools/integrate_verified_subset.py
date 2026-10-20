import sys,json,subprocess,time,datetime,argparse,shlex,hashlib
from pathlib import Path
parser=argparse.ArgumentParser(description="Integrate an explicitly verified ARM9 subset under one shared transaction lock.")
parser.add_argument('--project',type=Path,default=Path(__file__).resolve().parents[1])
parser.add_argument('--worker',type=Path,required=True)
parser.add_argument('--manifest',required=True)
parser.add_argument('--receipts',type=Path,required=True)
parser.add_argument('--label',required=True)
parser.add_argument('--role',default='coordinator')
parser.add_argument('--recover-failed',action='store_true',help='Verify an already restored unpublished subset while the current owner retains its publication gate')
parser.add_argument('--restore-interrupted',action='store_true',help='Restore authenticated interrupted new-function preimages and verify accepted checkpoint')
parser.add_argument('--preimage-tree',type=Path,help='Independent preimage tree bound to original dependency before hashes')
parser.add_argument('--source-contract-additions',action='store_true',help='Atomically add reviewed new owners and refine existing caller contracts')
parser.add_argument('--source-contract-only',action='store_true',help='Reviewed, zero-credit corrections to existing owned source contracts; uses the mixed transaction')
parser.add_argument('--contract-review',type=Path,help='Independent hash-bound review outside the worker; required for source contracts')
parser.add_argument('--mixed-source-only',action='store_true',help='Opt-in atomic mixed-module new-source transaction; default single-module behavior is unchanged')
parser.add_argument('--module',default='main',help='Single ARM9 module: main, itcm, dtcm, ov000..ov034')
args=parser.parse_args()
M=args.project.resolve();W=args.worker.resolve();R=args.receipts.resolve();role=args.role;manifest=args.manifest;label=args.label
if not label.replace('-','').replace('_','').isalnum():parser.error('label must contain only letters, digits, hyphens or underscores')
if not R.is_relative_to(M/'build'):parser.error('receipts must be inside project build/')
sys.path.insert(0,str(M/'tools'))
from integrate_batch import parse_delinks,validate_ranges
from integration_lock import integration_guard
from integration_bookkeeping import Bookkeeping, atomic_write, json_bytes
from integration_sources import capture_sources, install_source, verify_sources
from integration_relocations import capture_relocations, install_relocations, verify_relocations, restore_relocations
from integration_symbols import capture_symbols, install_symbols, verify_symbols, restore_symbols
from integration_data_aliases import capture_data_aliases, install_data_aliases, verify_data_aliases, restore_data_aliases
from integration_retention import capture_retention_policy, install_retention_policy, verify_retention_policy, restore_retention_policy
from integration_dependencies import capture_dependencies, install_dependencies, verify_dependencies, restore_dependencies
from integration_source_refinements import capture_refinements, install_refinement, verify_refinements, restore_refinements
import runtime_support
from arm9_module import delinks_path, manifest_rows, verify_measures, module_binaries, module_section, split_data
if sum((args.mixed_source_only,args.source_contract_only,args.source_contract_additions))>1:parser.error('Select one source transaction mode')
if bool(args.contract_review)!=bool(args.source_contract_only or args.source_contract_additions):parser.error('Source contracts require an independent --contract-review and vice versa')
if args.mixed_source_only or args.source_contract_only or args.source_contract_additions:
 if args.recover_failed and args.restore_interrupted:parser.error('Select one mixed recovery mode')
 with integration_guard(M,recovery=args.recover_failed or args.restore_interrupted) as transaction:
  from integrate_verified_mixed_subset import run as run_mixed
  run_mixed(args,transaction)
elif args.restore_interrupted:
 if args.recover_failed or args.preimage_tree is None:parser.error('Interrupted restore requires preimage tree and excludes recover-failed')
 with integration_guard(M,recovery=True) as transaction:
  from integration_recovery import restore_interrupted
  restore_interrupted(M,W,R,label,args.module,args.preimage_tree.resolve(),transaction)
elif args.recover_failed:
 with integration_guard(M,recovery=True) as transaction:
  from integration_recovery import recover
  recover(M,W,R,label,args.module,transaction)
else:
 with integration_guard(M) as transaction:
  R.mkdir(parents=True,exist_ok=True)
  D=R/label;D.mkdir(exist_ok=False)
  now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
  t0=time.monotonic(); timing={'start':now()}; m=json.loads((W/manifest).read_text()); functions,data,paths=manifest_rows(m,args.module); m['functions']=functions; initialized,bss=split_data(data,args.module); p=delinks_path(args.module);
  main=parse_delinks((M/p).read_text(),allow_empty_sections=args.module!='main'); worker=parse_delinks((W/p).read_text(),allow_empty_sections=args.module!='main');refining=bool(m.get('source_refinements'))
  for s in paths:
   if not s.startswith("src/") or not (M/s).resolve().is_relative_to(M/"src") or not (W/s).resolve().is_relative_to(W/"src"):raise ValueError("Source must be inside the assigned source tree")
   if refining:
    assert s in main.blocks and worker.blocks.get(s)==main.blocks[s] and (M/s).is_file(),s
   else:
    assert not any(any(line.rstrip()==s+':' for line in q.read_text().splitlines()) for q in (M/'config/usa/arm9').rglob('delinks.txt')),s
    assert s not in main.blocks and s in worker.blocks and not (M/s).exists(),s
   if m.get('runtime_replacement'):
    old=str(Path(s).with_suffix('.s'));assert old in main.blocks and old not in worker.blocks and (M/old).is_file(),old
  snapshots,source_audit=capture_sources(W,paths,m);timing.update(source_audit)
  refinements=capture_refinements(M,W,m)
  from function_naming import validate_new_functions
  validate_new_functions(M,W,m,args.module)
  dependencies=capture_dependencies(M,W,args.module,m)
  timing['dependencies']=[dict(path=r['path'],before_sha256=hashlib.sha256(r['before']).hexdigest() if r['before'] is not None else None,after_sha256=hashlib.sha256(r['after']).hexdigest()) for r in dependencies]
  relocation_map=capture_relocations(M,W,args.module,m)
  symbol_map=capture_symbols(M,W,args.module,m)
  data_aliases=capture_data_aliases(M,W,args.module,m)
  if data_aliases:
   timing['data_alias_dependency']={'path':data_aliases['path'],'before_sha256':hashlib.sha256(data_aliases['before']).hexdigest() if data_aliases['before'] is not None else None,'after_sha256':hashlib.sha256(data_aliases['after']).hexdigest(),'aliases':[a['name'] for a in data_aliases['aliases']]}
   atomic_write(D/'data-alias-preimage.json',json_bytes(dict(path=data_aliases['path'],existed=data_aliases['before'] is not None,before_hex=data_aliases['before'].hex() if data_aliases['before'] is not None else None)))
   if data_aliases.get('profiles'):
    pins=data_aliases['profiles'];timing['data_alias_dependency']['absolute_profile_pins']={'path':pins['path'],'before_sha256':hashlib.sha256(pins['before']).hexdigest(),'after_sha256':hashlib.sha256(pins['after']).hexdigest(),'sources':pins['sources']}
    atomic_write(D/'data-alias-profile-preimage.json',json_bytes(dict(path=pins['path'],before_sha256=hashlib.sha256(pins['before']).hexdigest(),before_hex=pins['before'].hex())))
  retention=capture_retention_policy(M,W,args.module,m,data,snapshots)
  runtime_policy=runtime_support.capture(M,W,m)
  before=json.loads((M/'build/usa/report.json').read_text())['measures']; backup={}
  arm7_before=json.loads((M/'build/usa/arm7/report.json').read_text())
  for q in [p,Path('build/usa/report.json'),Path('build/usa/arm7/report.json'),Path('build/usa/arm7-report.json')]:
   if (M/q).exists(): backup[str(q)]=(M/q).read_bytes();(D/(str(q).replace('/','_')+'.before')).write_bytes(backup[str(q)])
  copied=[];replaced_sources={}
  bookkeeping=Bookkeeping(M,R,label)
  transaction.begin_changes()
  try:
   install_dependencies(M,dependencies)
   install_relocations(M,relocation_map)
   install_symbols(M,symbol_map)
   install_data_aliases(M,data_aliases)
   subprocess.run(['python3','tools/work_batch.py','start',label],cwd=M,check=True,stdout=open(D/'work-start.log','w'))
   for s in paths:
    if m.get('runtime_replacement'):
     old=str(Path(s).with_suffix('.s'));replaced_sources[old]=(M/old).read_bytes();(D/(Path(old).name+'.before')).write_bytes(replaced_sources[old]);(M/old).unlink();del main.blocks[old]
    if refining:install_refinement(M,s,refinements['sources'][s])
    else:install_source(M,s,snapshots[s],copied)
    main.blocks[s]=worker.blocks[s]
   runtime_support.install(M,runtime_policy)
   validate_ranges(main,allow_empty_sections=args.module!='main');(M/p).write_text(main.header+'\n\n'+'\n\n'.join(main.blocks.values())+'\n');install_retention_policy(M,retention);atomic_write(D/'manifest.json',json_bytes(m))
   receipt_path=str(D.relative_to(M)); cmd='python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8 --keep-symbol func_020dc008 --keep-symbol func_020dc020 && ninja -j 2 objdiff delink build/usa/arm9.lcf && python3 tools/compile_verify_batch.py --manifest '+shlex.quote(receipt_path+'/manifest.json')+' --jobs 2 --compare-jobs 4 --verify-manifest-sources > '+shlex.quote(receipt_path+'/comparison.json')+' && ninja -j 2 rom check report sha1'
   if functions:cmd+=' && python3 tools/audit_link_layout.py '+shlex.quote(receipt_path+'/manifest.json')+' --elf build/usa/arm9.o --module '+shlex.quote(args.module)+' --output '+shlex.quote(receipt_path+'/layout.json')
   if initialized:
    atomic_write(D/'initialized-data-manifest.json',json_bytes(dict(m,data=initialized)))
    original,generated=module_binaries(args.module)
    cmd+=' && python3 tools/audit_data_layout.py '+shlex.quote(receipt_path+'/initialized-data-manifest.json')+' --elf build/usa/arm9.o --section '+module_section(args.module)+' --original '+shlex.quote(str(original))+' --generated '+shlex.quote(str(generated))+' --output '+shlex.quote(receipt_path+'/data-layout.json')
   if bss:
    original,generated=module_binaries(args.module)
    original_config='extract/usa/arm9/arm9.yaml' if args.module=='main' else ('extract/usa/arm9/'+args.module+'.yaml' if args.module in ('itcm','dtcm') else 'extract/usa/arm9_overlays/overlays.yaml')
    cmd+=' && python3 tools/audit_bss_layout.py '+shlex.quote(receipt_path+'/manifest.json')+' --elf build/usa/arm9.o --objdiff-tool /inputs/objdiff-cli --original-config '+shlex.quote(original_config)+' --original-module '+shlex.quote(str(original))+' --generated-module '+shlex.quote(str(generated))+' --output '+shlex.quote(receipt_path+'/bss-layout.json')
   t=time.monotonic();subprocess.run(['sudo','-n','docker','run','--rm','--user','1000:1000','-v',str(M)+':/bench/project','-v','/home/swayn/.local/share/factory-inputs/dqix:/inputs:ro','-w','/bench/project','factory-dqix:0.1','bash','-c',cmd],cwd=M,check=True,stdout=open(D/'validation.log','w'),stderr=subprocess.STDOUT);timing['validation_seconds']=time.monotonic()-t
   verify_data_aliases(M,data_aliases,json.loads((D/'bss-layout.json').read_text()) if data_aliases else None)
   verify_relocations(M,relocation_map)
   verify_dependencies(M,dependencies)
   verify_refinements(M,refinements)
   verify_sources(M,snapshots);verify_symbols(M,symbol_map);verify_retention_policy(M,retention)
   runtime_support.verify(M,runtime_policy)
   after=json.loads((M/'build/usa/report.json').read_text())['measures']; aliases=runtime_support.report_aliases(M,runtime_policy)
   verify_measures(before,after,[] if m.get('runtime_replacement') or refining else functions+aliases,data)
   if json.loads((M/'build/usa/arm7/report.json').read_text())!=arm7_before:raise ValueError('ARM7 report changed during ARM9 integration')
   report_units={u['name']:u for u in json.loads((M/'build/usa/report.json').read_text()).get('units',[])}
   for row in functions:
    unit=report_units.get(str(Path(row['source']).with_suffix('')),{});matches=[f for f in unit.get('functions',[]) if f['name']==row['name']]
    if len(matches)!=1 or matches[0].get('fuzzy_match_percent')!=100:raise ValueError('Selected function is not 100% in report: '+row['name'])
   appended=bool(runtime_policy and runtime_policy.get('mode')=='append')
   if appended:
    import audit_assembly
    audit=audit_assembly.audit(M,M/'build/usa/report.json');atomic_write(D/'assembly-audit.json',json_bytes(audit))
    expected_classes={r['name']:runtime_support.evidence_class(r) for r in json.loads(runtime_policy['after'])['functions'] if r['name'] in runtime_policy['appended']}
    if not set(runtime_policy['appended'])<={r['symbol'] for r in audit['runtime_reviews'] if r['evidence_class']==expected_classes.get(r['symbol']) and r['c_instruction_credit']==0}:raise ValueError('Authenticated appended assembly is absent from the assembly audit')
   subprocess.run(['python3','tools/work_batch.py','finish',label,'--attempts','1','--notes','Main integration verified; reconstruction attempts recorded in worker artifacts.']+(['--runtime-assembly-functions',str(len(runtime_policy['appended'])),'--runtime-assembly-bytes',str(runtime_policy['appended_bytes'])] if appended else []),cwd=M,check=True,stdout=open(D/'work-finish.log','w'))
   timing.update(finish=now(),elapsed_seconds=time.monotonic()-t0,accepted=True,functions=0 if m.get('runtime_replacement') or appended else len(m['functions']),code_bytes=0 if m.get('runtime_replacement') or appended else sum(int(f['size']) for f in m['functions']),runtime_assembly_functions=len(runtime_policy['appended']) if appended else 0,runtime_assembly_bytes=runtime_policy['appended_bytes'] if appended else 0,runtime_replacement=bool(m.get('runtime_replacement')),runtime_functions_replaced=len(replaced_sources),before=before,after=after,role=role,module=args.module,data_bytes=sum(int(f['size']) for f in initialized),bss_bytes=sum(int(f['size']) for f in bss))
   if appended:timing['c_instruction_credit']=0
   if refining:timing.update(functions=0,code_bytes=0,refined_functions=len(functions),source_refinement=True)
   bookkeeping.prepare(timing,after,now());bookkeeping.publish()
   print(json.dumps({k:timing[k] for k in ['accepted','functions','code_bytes','data_bytes','bss_bytes','elapsed_seconds']}))
   transaction.release_publication()
  except Exception:
   if not transaction.changed:transaction.begin_changes()
   for s in copied:
    if (M/s).exists():(M/s).unlink()
   for old,content in replaced_sources.items():(M/old).write_bytes(content)
   for q,b in backup.items():(M/q).write_bytes(b)
   restore_data_aliases(M,data_aliases)
   restore_relocations(M,relocation_map)
   restore_retention_policy(M,retention);restore_symbols(M,symbol_map)
   restore_dependencies(M,dependencies)
   restore_refinements(M,refinements)
   runtime_support.restore(M,runtime_policy)
   recovery='python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8 --keep-symbol func_020dc008 --keep-symbol func_020dc020 && ninja -j 2 objdiff delink rom check report sha1'
   subprocess.run(['sudo','-n','docker','run','--rm','--user','1000:1000','-v',str(M)+':/bench/project','-v','/home/swayn/.local/share/factory-inputs/dqix:/inputs:ro','-w','/bench/project','factory-dqix:0.1','bash','-c',recovery],cwd=M,check=True,stdout=open(D/'rollback-validation.log','w'),stderr=subprocess.STDOUT)
   restored=json.loads((M/'build/usa/report.json').read_text())['measures'];assert restored==before
   assert json.loads((M/'build/usa/arm7/report.json').read_text())==arm7_before
   bookkeeping.rollback()
   timing.update(finish=now(),accepted=False,elapsed_seconds=time.monotonic()-t0);atomic_write(D/'failure.json',json_bytes(timing))
   transaction.release_publication();raise
