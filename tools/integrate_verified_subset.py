import sys,json,subprocess,time,datetime,argparse,shlex
from pathlib import Path
parser=argparse.ArgumentParser(description="Integrate an explicitly verified ARM9 subset under one shared transaction lock.")
parser.add_argument('--project',type=Path,default=Path(__file__).resolve().parents[1])
parser.add_argument('--worker',type=Path,required=True)
parser.add_argument('--manifest',required=True)
parser.add_argument('--receipts',type=Path,required=True)
parser.add_argument('--label',required=True)
parser.add_argument('--role',default='coordinator')
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
from integration_retention import capture_retention_policy, install_retention_policy, verify_retention_policy, restore_retention_policy
import runtime_support
from arm9_module import delinks_path, manifest_rows, verify_measures, module_binaries, module_section, split_data
with integration_guard(M) as transaction:
 R.mkdir(parents=True,exist_ok=True)
 D=R/label;D.mkdir(exist_ok=False)
 now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()
 t0=time.monotonic(); timing={'start':now()}; m=json.loads((W/manifest).read_text()); functions,data,paths=manifest_rows(m,args.module); m['functions']=functions; initialized,bss=split_data(data,args.module); p=delinks_path(args.module);
 main=parse_delinks((M/p).read_text(),allow_empty_sections=args.module!='main'); worker=parse_delinks((W/p).read_text(),allow_empty_sections=args.module!='main')
 for s in paths:
  if not s.startswith("src/") or not (M/s).resolve().is_relative_to(M/"src") or not (W/s).resolve().is_relative_to(W/"src"):raise ValueError("Source must be inside the assigned source tree")
  assert not any(any(line.rstrip()==s+':' for line in q.read_text().splitlines()) for q in (M/'config/usa/arm9').rglob('delinks.txt')),s
  assert s not in main.blocks and s in worker.blocks and not (M/s).exists(),s
  if m.get('runtime_replacement'):
   old=str(Path(s).with_suffix('.s'));assert old in main.blocks and old not in worker.blocks and (M/old).is_file(),old
 snapshots,source_audit=capture_sources(W,paths,m);timing.update(source_audit)
 from function_naming import validate_new_functions
 validate_new_functions(M,W,m,args.module)
 relocation_map=capture_relocations(M,W,args.module,m)
 symbol_map=capture_symbols(M,W,args.module,m)
 retention=capture_retention_policy(M,W,args.module,m,data,snapshots)
 runtime_policy=runtime_support.capture(M,W,m)
 before=json.loads((M/'build/usa/report.json').read_text())['measures']; backup={}
 for q in [p,Path('build/usa/report.json'),Path('build/usa/arm7/report.json'),Path('build/usa/arm7-report.json')]:
  if (M/q).exists(): backup[str(q)]=(M/q).read_bytes();(D/(str(q).replace('/','_')+'.before')).write_bytes(backup[str(q)])
 copied=[];replaced_sources={}
 bookkeeping=Bookkeeping(M,R,label)
 transaction.begin_changes()
 try:
  install_relocations(M,relocation_map)
  install_symbols(M,symbol_map)
  subprocess.run(['python3','tools/work_batch.py','start',label],cwd=M,check=True,stdout=open(D/'work-start.log','w'))
  for s in paths:
   if m.get('runtime_replacement'):
    old=str(Path(s).with_suffix('.s'));replaced_sources[old]=(M/old).read_bytes();(D/(Path(old).name+'.before')).write_bytes(replaced_sources[old]);(M/old).unlink();del main.blocks[old]
   install_source(M,s,snapshots[s],copied);main.blocks[s]=worker.blocks[s]
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
  verify_relocations(M,relocation_map)
  verify_sources(M,snapshots);verify_symbols(M,symbol_map);verify_retention_policy(M,retention)
  runtime_support.verify(M,runtime_policy)
  after=json.loads((M/'build/usa/report.json').read_text())['measures']; aliases=runtime_support.report_aliases(M,runtime_policy)
  verify_measures(before,after,[] if m.get('runtime_replacement') else functions+aliases,data)
  appended=bool(runtime_policy and runtime_policy.get('mode')=='append')
  if appended:
   import audit_assembly
   audit=audit_assembly.audit(M,M/'build/usa/report.json');atomic_write(D/'assembly-audit.json',json_bytes(audit))
   expected_classes={r['name']:runtime_support.evidence_class(r) for r in json.loads(runtime_policy['after'])['functions'] if r['name'] in runtime_policy['appended']}
   if not set(runtime_policy['appended'])<={r['symbol'] for r in audit['runtime_reviews'] if r['evidence_class']==expected_classes.get(r['symbol']) and r['c_instruction_credit']==0}:raise ValueError('Authenticated appended assembly is absent from the assembly audit')
  subprocess.run(['python3','tools/work_batch.py','finish',label,'--attempts','1','--notes','Main integration verified; reconstruction attempts recorded in worker artifacts.']+(['--runtime-assembly-functions',str(len(runtime_policy['appended'])),'--runtime-assembly-bytes',str(runtime_policy['appended_bytes'])] if appended else []),cwd=M,check=True,stdout=open(D/'work-finish.log','w'))
  timing.update(finish=now(),elapsed_seconds=time.monotonic()-t0,accepted=True,functions=0 if m.get('runtime_replacement') or appended else len(m['functions']),code_bytes=0 if m.get('runtime_replacement') or appended else sum(int(f['size']) for f in m['functions']),runtime_assembly_functions=len(runtime_policy['appended']) if appended else 0,runtime_assembly_bytes=runtime_policy['appended_bytes'] if appended else 0,runtime_replacement=bool(m.get('runtime_replacement')),runtime_functions_replaced=len(replaced_sources),before=before,after=after,role=role,module=args.module,data_bytes=sum(int(f['size']) for f in initialized),bss_bytes=sum(int(f['size']) for f in bss))
  if appended:timing['c_instruction_credit']=0
  bookkeeping.prepare(timing,after,now());bookkeeping.publish()
  print(json.dumps({k:timing[k] for k in ['accepted','functions','code_bytes','data_bytes','bss_bytes','elapsed_seconds']}))
  transaction.release_publication()
 except Exception:
  if not transaction.changed:transaction.begin_changes()
  for s in copied:
   if (M/s).exists():(M/s).unlink()
  for old,content in replaced_sources.items():(M/old).write_bytes(content)
  for q,b in backup.items():(M/q).write_bytes(b)
  restore_relocations(M,relocation_map)
  restore_retention_policy(M,retention);restore_symbols(M,symbol_map)
  runtime_support.restore(M,runtime_policy)
  recovery='python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8 --keep-symbol func_020dc008 --keep-symbol func_020dc020 && ninja -j 2 objdiff delink rom check report sha1'
  subprocess.run(['sudo','-n','docker','run','--rm','--user','1000:1000','-v',str(M)+':/bench/project','-v','/home/swayn/.local/share/factory-inputs/dqix:/inputs:ro','-w','/bench/project','factory-dqix:0.1','bash','-c',recovery],cwd=M,check=True,stdout=open(D/'rollback-validation.log','w'),stderr=subprocess.STDOUT)
  restored=json.loads((M/'build/usa/report.json').read_text())['measures'];assert restored==before
  bookkeeping.rollback()
  timing.update(finish=now(),accepted=False,elapsed_seconds=time.monotonic()-t0);atomic_write(D/'failure.json',json_bytes(timing))
  transaction.release_publication();raise
