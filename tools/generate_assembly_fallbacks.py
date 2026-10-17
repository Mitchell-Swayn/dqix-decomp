#!/usr/bin/env python3
"""Materialize original function disassembly as browsable CodeWarrior inline assembly.

These reference includes are not compiled or linked and earn no reconstruction
credit. Original bytes and identities are hash-bound; unidentified ARM7 ranges
are never fabricated into functions. Existing C/C++ remains authoritative.
"""
import argparse, hashlib, json, pathlib, re, sqlite3, sys
ROOT=pathlib.Path(__file__).resolve().parents[1]

def sha(data):return hashlib.sha256(data).hexdigest()
def symbol_maps(root):
 maps={}
 for path in (root/'config/usa/arm9').rglob('symbols.txt'):
  module='arm9/'+('main' if path.parent.name=='arm9' else path.parent.name);mapping={}
  for line in path.read_text().splitlines():
   match=re.fullmatch(r'(\S+) kind:function\(([^)]*)\) addr:0x([0-9a-fA-F]+)',line.strip())
   if match:mapping[match[1]]=(int(match[3],16),match[2].split(',')[0])
  maps[module]=mapping
 return maps

def selected_functions(root,db):
 maps=symbol_maps(root);report=json.loads((root/'build/usa/report.json').read_text());selected={};excluded=[]
 for unit in report['units']:
  for fn in unit.get('functions',[]):
   if fn.get('fuzzy_match_percent')==100:continue
   candidates=[(m,*s[fn['name']]) for m,s in maps.items() if fn['name'] in s]
   if len(candidates)>1:
    module='arm9/'+unit['name'].split('_')[0];candidates=[r for r in candidates if r[0]==module]
   if len(candidates)!=1:
    excluded.append(dict(unit=unit['name'],name=fn['name'],reason='Report entry is not a unique configured function; data/interior labels are not invented functions.'));continue
   module,address,mode=candidates[0];row=db.execute('select * from functions where module_id=? and address=?',(module,address)).fetchone()
   if row is None:raise ValueError('Missing original function inventory: '+fn['name'])
   row=dict(row);row['name']=fn['name'];row['partial_source']=unit.get('metadata',{}).get('source_path');selected[row['id']]=row
 config=json.loads((root/'config/usa/arm7/source_units.json').read_text())
 for record in db.execute('select * from functions where module_id like "arm7/%"'):
  row=dict(record);autoload=row['module_id'].split('/')[1]
  if any(u.get('autoload')==autoload and u['runtime_address']<=row['address'] and row['address']+row['size']<=u['runtime_address']+u['size'] for u in config['units']):continue
  selected[row['id']]=row
 return selected,excluded,maps

_payload_cache={}
def original_module_bytes(root,row):
 module=row['module_id'];address=row['address'];size=row['size'];processor,part=module.split('/')
 if processor=='arm9':
  if part=='main':p=root/'extract/usa/arm9/arm9.bin';base=0x02000000
  elif part in ('itcm','dtcm'):
   p=root/f'extract/usa/arm9/{part}.bin';base=int(re.search(r'base_address:\s*(\d+)',(root/f'extract/usa/arm9/{part}.yaml').read_text())[1])
  else:
   p=root/f'extract/usa/arm9_overlays/{part}.bin';base=_module_bases[module]
  if p not in _payload_cache:_payload_cache[p]=p.read_bytes()
  return _payload_cache[p][address-base:address-base+size]
 config=json.loads((root/'config/usa/arm7/source_units.json').read_text())
 baseline=json.loads((root/'config/usa/arm7/baseline.json').read_text());payload=(root/'extract/usa/arm7/arm7.bin').read_bytes()
 if part=='startup':offset=address-baseline['load_address']
 else:
  load=next(u for u in config['autoloads'] if u['name']==part);offset=load['payload_offset']+address-load['runtime_address']
 return payload[offset:offset+size]

def render(row,targets):
 address=row['address'];end=address+row['size'];entries=[]
 for line in row['assembly'].splitlines():
  match=re.match(r'^([0-9a-fA-F]{8}):\s*(.*)',line)
  if match:entries.append((int(match[1],16),match[2]))
 if not entries:raise ValueError('Empty assembly: '+row['id'])
 out=[f"// UNRECONSTRUCTED ASSEMBLY REFERENCE — no C/C++ reconstruction credit.",f"// Original: {row['module_id']} @ 0x{address:08X}; symbol: {row['name']}; size: 0x{row['size']:X}.",f"// Original bytes SHA-256: {row['original_sha256']}","// Not compiled or linked; function signature and relocation expressions are not recovered.","// The void entry declaration binds the assembly symbol, not an inferred C++ signature.",f"#pragma thumb {'on' if row['mode']=='thumb' else 'off'}",f'extern "C" asm void {row["name"]}()',"{"]
 for at,code in entries:
  code=code.replace(';','//');code=re.sub(r'\b(ip|fp|sb|sl)\b',lambda m:{'ip':'r12','fp':'r11','sb':'r9','sl':'r10'}[m[1]],code)
  code=re.sub(r'^\.word\b','dcd',code);code=re.sub(r'^\.(?:hword|short)\b','dcw',code);code=re.sub(r'^\.byte\b','dcb',code)
  branch=re.match(r'^(b(?:l|lx)?(?:eq|ne|cs|cc|hs|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?)(\s+)#?(0x[0-9a-fA-F]+)(.*)$',code)
  if branch:
   target=int(branch[3],16);name=(f'loc_{target:08X}' if address<=target<end else targets.get((row['module_id'],target)) or targets.get(('arm9/main',target)) or 'address_'+f'{target:08X}')
   code=branch[1]+branch[2]+name+branch[4]+f' // Original target 0x{target:08X}'
  out.extend((f'loc_{at:08X}:',f'    {code}'))
 out.append('}');return '\n'.join(out)+'\n'

def generate(root,output):
 global _module_rows,_module_bases
 db=sqlite3.connect(f'file:{root/"inventory/functions.sqlite"}?mode=ro',uri=True);db.row_factory=sqlite3.Row
 selected,excluded,maps=selected_functions(root,db);_module_rows={};_module_bases={}
 for r in db.execute('select * from modules'):
  d=dict(r);_module_bases[d['id']]=d.get('base_address',d.get('address'))
 for row in selected.values():_module_rows.setdefault(row['module_id'],[]).append(row)
 targets={(module,addr):name for module,symbols in maps.items() for name,(addr,_) in symbols.items()};records=[]
 for row in sorted(selected.values(),key=lambda r:(r['module_id'],r['address'])):
  raw=bytes(row['original_bytes'])
  if len(raw)!=row['size'] or sha(raw)!=row['original_sha256'] or original_module_bytes(root,row)!=raw:raise ValueError('Original evidence mismatch: '+row['id'])
  source=f'src/AssemblyFallback/{row["module_id"]}/{row["name"]}.inc';text=render(row,targets);path=root/source if output is None else output/source
  if path.exists():raise FileExistsError('Refusing to overwrite assembly source: '+str(path))
  path.parent.mkdir(parents=True,exist_ok=True);path.write_text(text)
  records.append(dict(function_id=row['id'],module=row['module_id'],name=row['name'],address=f'0x{row["address"]:08X}',size=row['size'],mode=row['mode'],source=source,source_sha256=sha(text.encode()),original_sha256=sha(raw),partial_source=row.get('partial_source'),compiled=False,linked=False,c_instruction_credit=0))
 result=dict(schema_version=1,status='unreconstructed_reference',build_integration=False,c_instruction_credit=0,functions=records,non_function_report_entries=excluded,limitations=['ARM7 function inventory is incomplete outside the identified startup/wram functions. Unidentified ranges remain original binary fallback.','Reference syntax and relocation expressions are not compiler-verified; the existing ROM build remains unchanged.'])
 return result

if __name__=='__main__':
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--root',type=pathlib.Path,default=ROOT);parser.add_argument('--output',type=pathlib.Path,required=True);args=parser.parse_args();r=generate(args.root.resolve(),args.output)
 path=(args.output or args.root)/'config/usa/assembly_fallbacks.json';path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({'functions':len(r['functions']),'assembly_bytes':sum(x['size'] for x in r['functions']),'excluded_data_entries':len(r['non_function_report_entries'])}))
