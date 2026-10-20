"""Validate source-bound roots retaining original executable fallback ranges.

Retention supplies linker roots only. These entries stay eligible for source
reconstruction and earn zero C/C++ or runtime-assembly coverage credit.
"""
import hashlib,re
from pathlib import Path

def retained_symbols(root,row,source_root=None,verify_original=True):
 spec=row.get('retained_fallback_code')
 if spec is None:return []
 root=Path(root);source_root=Path(source_root or root)
 if set(spec)!={'start','end','original_sha256','symbols','reason','c_instruction_credit','root_symbol'} or spec['c_instruction_credit']!=0 or not spec['reason']:raise ValueError('Invalid code retention policy')
 source=Path(row['source']);path=(source_root/source).resolve()
 if source.is_absolute() or not path.is_relative_to(source_root.resolve()/'src') or hashlib.sha256(path.read_bytes()).hexdigest()!=row['source_sha256']:raise ValueError('Code retention source hash mismatch')
 start,end=int(spec['start'],0),int(spec['end'],0)
 if row['module']!='arm9/main' or start!=int(row['address'],0)+row['size'] or end<=start:raise ValueError('Code retention must follow selected source extent')
 text=(source_root/'config/usa/arm9/delinks.txt').read_text();blocks=list(re.finditer(r'(?m)^(\S+\.(?:cpp|c|s)):\s*$',text));owned=[]
 for i,b in enumerate(blocks):
  if b[1]!=source.as_posix():continue
  block=text[b.end():blocks[i+1].start() if i+1<len(blocks) else len(text)]
  owned=re.findall(r'(?m)^\s+\.text\s+start:0x([\da-fA-F]+)\s+end:0x([\da-fA-F]+)',block)
 if len(owned)!=1 or tuple(int(v,16) for v in owned[0])!=(int(row['address'],0),int(row['address'],0)+row['size']):raise ValueError('Code retention trigger source does not own exact selected extent')
 symbols={}
 for name,mode,size,address in re.findall(r'(?m)^(\S+) kind:function\((arm|thumb),size=0x([\da-fA-F]+)\) addr:0x([\da-fA-F]+)',(root/'config/usa/arm9/symbols.txt').read_text()):symbols[name]=(int(address,16),int(size,16),mode)
 actual={n:v for n,v in symbols.items() if start<=v[0]<end};declared=spec['symbols']
 if not actual or len(declared)!=len({r['name'] for r in declared}) or set(actual)!={r['name'] for r in declared}:raise ValueError('Code retention symbol set differs from actual fallback range')
 if not any(v[0]==end for v in symbols.values()):raise ValueError('Code retention end is not an existing function boundary')
 blob=(root/'extract/usa/arm9/arm9.bin').read_bytes() if verify_original else None;offset=start-0x02000000
 if verify_original and (offset<0 or offset+end-start>len(blob) or hashlib.sha256(blob[offset:offset+end-start]).hexdigest()!=spec['original_sha256']):raise ValueError('Code retention original range hash mismatch')
 result=[]
 for symbol in declared:
  if set(symbol)!={'name','address','size','mode','original_sha256'} or not re.fullmatch(r'[A-Za-z_]\w*',symbol['name']):raise ValueError('Invalid retained code symbol')
  address,size,mode=actual[symbol['name']]
  if (int(symbol['address'],0),symbol['size'],symbol['mode'])!=(address,size,mode) or size<=0 or address+size>end:raise ValueError('Retained code symbol extent differs')
  begin=address-0x02000000
  if verify_original and hashlib.sha256(blob[begin:begin+size]).hexdigest()!=symbol['original_sha256']:raise ValueError('Retained code symbol bytes differ')
  result.append(symbol['name'])
 if spec['root_symbol'] not in result:raise ValueError('Retention root is not a validated existing code symbol')
 return [spec['root_symbol']]


def all_retained_symbols(root,verify_original=True):
 import json
 root=Path(root);policy=root/'config/usa/arm9/runtime_support.json'
 if not policy.exists():return []
 names=[]
 for row in json.loads(policy.read_text())['functions']:names.extend(retained_symbols(root,row,verify_original=verify_original))
 return list(dict.fromkeys(names))

if __name__=='__main__':
 import argparse
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--root',type=Path,required=True);parser.add_argument('--expected',default='');args=parser.parse_args()
 if all_retained_symbols(args.root)!=(args.expected.split(',') if args.expected else []):parser.exit(2,'Code retention roots changed: rerun configure\n')
