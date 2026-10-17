"""Partially link declared source-owned references to absolute linker constants.

Only R_ARM_ABS32 RELA entries within compiler-declared data mappings are resolved.
No target binary/object, original bytes, or comparison scores are read. Every
other byte of program code/data and every unrelated relocation remains intact.
"""
import hashlib,json,struct,sys
from pathlib import Path
from normalize_source_member_aliases import elf,digest

def normalize(path,source,profile_path,root=None,compiler=None):
 root=Path(root or Path(__file__).resolve().parents[1]);path=Path(path)
 profile=json.loads((root/profile_path).read_text())['sources'][str(source)]
 if digest(root/source)!=profile['source_sha256']:raise ValueError('Source hash mismatch')
 if digest(Path(compiler) if compiler else root/profile['executable'])!=profile['executable_sha256']:raise ValueError('Compiler hash mismatch')
 spec=profile['absolute_linker_symbols'];linker_path=root/spec['policy']
 if digest(linker_path)!=spec['policy_sha256']:raise ValueError('Linker policy hash mismatch')
 linker=json.loads(linker_path.read_text());wanted=spec['symbols']
 if not wanted or len(wanted)!=len(set(wanted)):raise ValueError('Expected unique absolute symbols')
 values={}
 for label in wanted:
  if label not in linker or not isinstance(linker[label],str):raise ValueError('Symbol is not an absolute linker constant')
  value=int(linker[label],0)
  if not 0<=value<=0xffffffff:raise ValueError('Absolute constant exceeds ELF32')
  values[label]=value
 original=path.read_bytes();data=bytearray(original);pos,stride,sections,si,entries,name=elf(original)
 indices={}
 for label in wanted:
  found=[(i,e) for i,e in enumerate(entries) if name(e)==label]
  if len(found)!=1 or found[0][1][5]!=0:raise ValueError('Expected one undefined absolute symbol')
  indices[found[0][0]]=label
 mappings={}
 for e in entries:
  if name(e) in ('$a','$t','$d'):mappings.setdefault(e[5],[]).append((e[1]&~1,name(e)))
 changes=[];seen=set();allowed=set();reloc_changes={}
 for ri,rel in enumerate(sections):
  if rel[1] not in (4,9):continue
  if rel[6]!=si or rel[7]>=len(sections):raise ValueError('Invalid relocation links')
  stride_r=12 if rel[1]==4 else 8
  if rel[9]!=stride_r or rel[5]%stride_r:raise ValueError('Invalid relocation table')
  target=sections[rel[7]];kept=[]
  for off in range(rel[4],rel[4]+rel[5],stride_r):
   record=original[off:off+stride_r];offset,info=struct.unpack_from('<II',record)
   if info>>8 not in indices:kept.append(record);continue
   label=indices[info>>8]
   if rel[1]!=4 or info&255!=2:raise ValueError('Only explicit R_ARM_ABS32 RELA supported')
   if target[1]!=1 or offset%4 or offset+4>target[5]:raise ValueError('Invalid absolute relocation extent')
   mapping=[m for m in mappings.get(rel[7],[]) if m[0]<=offset]
   if not mapping or max(mapping)[1]!='$d':raise ValueError('Absolute relocation must be in mapped data')
   addend=struct.unpack_from('<i',record,8)[0];value=(values[label]+addend)&0xffffffff;patch=target[4]+offset
   if any(i in allowed for i in range(patch,patch+4)):raise ValueError('Overlapping absolute relocations')
   struct.pack_into('<I',data,patch,value);allowed.update(range(patch,patch+4));seen.add(label)
   changes.append(dict(symbol=label,section=rel[7],offset=offset,absolute_value=values[label],addend=addend,resolved=value))
  if len(kept)*stride_r!=rel[5]:reloc_changes[ri]=b''.join(kept)
 if seen!=set(wanted):raise ValueError('Declared absolute symbol has no relocation')
 # LCF remains the sole owner of absolute definitions. These original UND
 # entries have no remaining references, so preserve the symbol table verbatim.
 # Preserve original payloads except the actual relocation destinations.
 for sec in sections:
  if sec[1]==1:
   for off in range(sec[4],sec[4]+sec[5]):
    if off not in allowed and data[off]!=original[off]:raise ValueError('Unrelated payload changed')
 for ri,payload in reloc_changes.items():
  data.extend(bytes((-len(data))%4));sections[ri][4],sections[ri][5]=len(data),len(payload);data.extend(payload)
 for i,e in enumerate(entries):struct.pack_into('<IIIBBH',data,sections[si][4]+i*16,*e)
 for ri in reloc_changes:struct.pack_into('<10I',data,pos+ri*stride,*sections[ri])
 receipt=dict(source=str(source),source_sha256=profile['source_sha256'],compiler_sha256=profile['executable_sha256'],linker_policy_sha256=spec['policy_sha256'],before_sha256=hashlib.sha256(original).hexdigest(),after_sha256=hashlib.sha256(data).hexdigest(),changes=changes,only_declared_absolute_relocations_resolved=True)
 path.with_suffix(path.suffix+'.before-absolute-link').write_bytes(original);path.write_bytes(data);path.with_suffix(path.suffix+'.absolute-link.json').write_text(json.dumps(receipt,indent=2)+'\n');return receipt
if __name__=='__main__':normalize(sys.argv[1],sys.argv[2],sys.argv[3],compiler=sys.argv[4] if len(sys.argv)>4 else None)
