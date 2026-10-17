"""Canonicalize declared source-member aliases in compiler ELF metadata only.

No target object or target comparison is read. A pinned C owner, layout header,
and actual source-owned BSS object bound every alias. Executable/data payloads
remain unchanged. Undefined SDK member symbols become owner-base relocations
with the declared member offset added, preserving their resolved address.
"""
import hashlib,json,struct,sys
from pathlib import Path

def digest(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def elf(data):
    if data[:7]!=b'\x7fELF\x01\x01\x01': raise ValueError('Expected ELF32 little-endian')
    if struct.unpack_from('<HH',data,16)!=(1,40): raise ValueError('Expected relocatable ARM ELF')
    pos=struct.unpack_from('<I',data,32)[0];stride,count=struct.unpack_from('<HH',data,46)
    if stride!=40 or pos+count*stride>len(data): raise ValueError('Invalid sections')
    sections=[list(struct.unpack_from('<10I',data,pos+i*stride)) for i in range(count)]
    for section in sections:
        if section[1]!=8 and section[4]+section[5]>len(data): raise ValueError('Section exceeds object bounds')
    symbol_tables=[i for i,s in enumerate(sections) if s[1]==2]
    if len(symbol_tables)!=1: raise ValueError('Expected one symbol table')
    si=symbol_tables[0];sym=sections[si]
    if sym[6]>=len(sections): raise ValueError('Invalid symbol string table')
    if sym[9]!=16 or sym[5]%16: raise ValueError('Invalid symbol table')
    st=sections[sym[6]];names=data[st[4]:st[4]+st[5]]
    entries=[list(struct.unpack_from('<IIIBBH',data,o)) for o in range(sym[4],sym[4]+sym[5],16)]
    def name(e):
        if e[0]>=len(names) or b'\0' not in names[e[0]:]: raise ValueError('Invalid symbol string')
        return names[e[0]:].split(b'\0',1)[0].decode()
    return pos,stride,sections,si,entries,name

def normalize(path,source,profile_path,root=None,compiler=None):
    root=Path(root or Path(__file__).resolve().parents[1]);path=Path(path)
    policy=json.loads((root/profile_path).read_text())['sources'][str(source)]
    if digest(root/source)!=policy['source_sha256']: raise ValueError('Candidate source hash mismatch')
    if digest(Path(compiler) if compiler else root/policy['executable'])!=policy['executable_sha256']: raise ValueError('Compiler hash mismatch')
    original=path.read_bytes();data=bytearray(original)
    pos,stride,sections,si,entries,name=elf(original);changes=[]
    names=bytearray(original[sections[sections[si][6]][4]:sections[sections[si][6]][4]+sections[sections[si][6]][5]])
    for alias in policy['member_aliases']:
        for file_key,hash_key in [('owner_source','owner_source_sha256'),('layout_header','layout_header_sha256'),('layout_source','layout_source_sha256')]:
            if digest(root/alias[file_key])!=alias[hash_key]: raise ValueError('Owner/layout source hash mismatch')
        owner=(root/alias['owner_object']).read_bytes();_,_,owner_sections,_,owner_entries,owner_name=elf(owner)
        matches=[e for e in owner_entries if owner_name(e)==alias['base']]
        if len(matches)!=1: raise ValueError('Missing/ambiguous owning object symbol')
        base=matches[0];offset=int(alias['offset'],16);extent=int(alias['member_size'],16)
        if base[5]==0 or base[5]>=len(owner_sections) or owner_sections[base[5]][1]!=8 or base[2]!=alias['owner_size'] or offset<0 or extent<=0 or offset+extent>base[2]:
            raise ValueError('Alias exceeds actual source-owned BSS range')
        if offset%alias['member_alignment']: raise ValueError('Member alignment mismatch')
        layout=(root/alias['layout_object']).read_bytes();_,_,layout_sections,_,layout_entries,layout_name=elf(layout)
        layout_defs=[e for e in layout_entries if layout_name(e)==alias['layout_symbol']]
        if len(layout_defs)!=1 or layout_defs[0][5]==0 or layout_defs[0][2]!=12:
            raise ValueError('Missing compiler-proven member layout')
        le=layout_defs[0];ls=layout_sections[le[5]];lo=ls[4]+le[1]
        if struct.unpack_from('<III',layout,lo)!=(base[2],offset,extent):
            raise ValueError('Declared alias differs from compiler-proven field offset/size')

        refs=[i for i,e in enumerate(entries) if name(e)==alias['name']]
        if len(refs)!=1 or entries[refs[0]][5]!=0: raise ValueError('Alias must be one undefined compiler symbol')
        index=refs[0];count=0
        for section in sections:
            if section[1] not in (4,9): continue
            if section[6]!=si or section[1]!=4 or section[9]!=12: raise ValueError('Only explicit ELF RELA supported')
            for rpos in range(section[4],section[4]+section[5],12):
                roff,info,addend=struct.unpack_from('<IIi',data,rpos)
                if info>>8!=index: continue
                if info&255!=2: raise ValueError('Alias reference must be R_ARM_ABS32')
                before=int(alias['base_address'],16)+offset+addend
                after=int(alias['base_address'],16)+(addend+offset)
                if before!=after or not 0<=after<=0xffffffff: raise ValueError('Resolved alias address changed')
                struct.pack_into('<i',data,rpos+8,addend+offset);count+=1
                changes.append(dict(alias=alias['name'],base=alias['base'],member_offset=offset,relocation_offset=roff,old_addend=addend,new_addend=addend+offset,resolved_before=hex(before),resolved_after=hex(after)))
        if count==0: raise ValueError('Alias has no relocations')
        entries[index][0]=len(names);names.extend(alias['base'].encode()+b'\0')
    # Append replacement string table; original section bytes remain untouched.
    string_index=sections[si][6];data.extend(bytes((-len(data))%4));sections[string_index][4]=len(data);sections[string_index][5]=len(names);data.extend(names)
    for i,e in enumerate(entries): struct.pack_into('<IIIBBH',data,sections[si][4]+i*16,*e)
    struct.pack_into('<10I',data,pos+string_index*stride,*sections[string_index])
    payloads=[]
    for sec in sections:
        if sec[1]!=1: continue
        start,size=sec[4:6]
        if data[start:start+size]!=original[start:start+size]: raise ValueError('Executable/data payload changed')
        payloads.append(dict(offset=start,size=size,sha256=hashlib.sha256(original[start:start+size]).hexdigest()))
    receipt=dict(source=str(source),source_sha256=policy['source_sha256'],owner_source_hashes={a['owner_source']:a['owner_source_sha256'] for a in policy['member_aliases']},compiler_sha256=policy['executable_sha256'],before_sha256=hashlib.sha256(original).hexdigest(),after_sha256=hashlib.sha256(data).hexdigest(),payloads_unchanged=True,payloads=payloads,changes=changes)
    path.with_suffix(path.suffix+'.unnormalized').write_bytes(original)
    path.write_bytes(data);path.with_suffix(path.suffix+'.member-aliases.json').write_text(json.dumps(receipt,indent=2)+'\n')
    return receipt

if __name__=='__main__': normalize(sys.argv[1],sys.argv[2],sys.argv[3],compiler=sys.argv[4] if len(sys.argv)>4 else None)
