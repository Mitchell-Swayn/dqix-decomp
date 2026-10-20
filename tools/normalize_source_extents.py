"""Preserve reviewed compiler-tail inventory labels without changing code.

Reads only compiler output and a source/compiler-hash-bound policy. No target
objects, original bytes, or comparison scores influence the transformation.
"""
import hashlib,json,struct,sys
from pathlib import Path
from normalize_source_member_aliases import elf,digest

def normalize(path,source,profile_path,root=None,compiler=None):
    root=Path(root or Path(__file__).resolve().parents[1]);path=Path(path)
    policy=json.loads((root/profile_path).read_text())["sources"][str(source)]
    if digest(root/source)!=policy["source_sha256"]: raise ValueError("Source hash mismatch")
    if digest(Path(compiler) if compiler else root/policy["executable"])!=policy["executable_sha256"]: raise ValueError("Compiler hash mismatch")
    original=path.read_bytes();data=bytearray(original)
    pos,stride,sections,si,entries,name=elf(original)
    strings=sections[sections[si][6]];names=bytearray(original[strings[4]:strings[4]+strings[5]])
    changes=[]
    for spec in policy["function_extents"]:
        found=[e for e in entries if name(e)==spec["name"]]
        if len(found)!=1: raise ValueError("Missing/ambiguous function")
        fn=found[0];secidx=fn[5]
        if secidx==0 or secidx>=len(sections): raise ValueError("Undefined function")
        sec=sections[secidx];start=fn[1]
        if fn[3]&15!=2 or sec[1]!=1 or not sec[2]&4 or start%4 or fn[2]!=spec["compiled_size"] or start+fn[2]>sec[5]: raise ValueError("Unexpected compiled extent")
        # These entries partition one emitted function, preserving every byte.
        cursor=spec["size"]
        if cursor<=0 or cursor%4 or cursor>=fn[2]: raise ValueError("Invalid primary extent")
        aliases=[]
        for alias in spec["aliases"]:
            if alias["offset"]!=cursor or alias["size"]!=4 or alias["kind"]!="unreachable_arm_return": raise ValueError("Unsupported/noncontiguous compiler tail")
            if any(name(e)==alias["name"] for e in entries): raise ValueError("Alias already exists")
            offset=sec[4]+start+cursor
            if data[offset:offset+4]!=bytes.fromhex("1eff2fe1"): raise ValueError("Tail is not ARM bx lr")
            aliases.append([len(names),start+cursor,4,18,0,secidx]);names.extend(alias["name"].encode()+b"\0");cursor+=4
        if cursor!=fn[2]: raise ValueError("Tail partition does not cover emitted extent")
        changes.append(dict(name=spec["name"],compiled_size=fn[2],primary_size=spec["size"],aliases=spec["aliases"]))
        fn[2]=spec["size"];entries.extend(aliases)
    data.extend(bytes((-len(data))%4));strings[4],strings[5]=len(data),len(names);data.extend(names)
    data.extend(bytes((-len(data))%4));symbols=sections[si];symbols[4],symbols[5]=len(data),len(entries)*16
    for entry in entries: data.extend(struct.pack("<IIIBBH",*entry))
    for index in (si,sections[si][6]): struct.pack_into("<10I",data,pos+index*stride,*sections[index])
    for sec in sections:
        if sec[1] not in (0,2,3,8):
            start,size=sec[4:6]
            if original[start:start+size]!=data[start:start+size]: raise ValueError("Payload/relocations changed")
    receipt=dict(source=str(source),source_sha256=policy["source_sha256"],compiler_sha256=policy["executable_sha256"],before_sha256=hashlib.sha256(original).hexdigest(),after_sha256=hashlib.sha256(data).hexdigest(),payloads_and_relocations_unchanged=True,changes=changes)
    path.with_suffix(path.suffix+".unnormalized").write_bytes(original);path.write_bytes(data)
    path.with_suffix(path.suffix+".source-extents.json").write_text(json.dumps(receipt,indent=2)+"\n")
    return receipt

if __name__=="__main__": normalize(sys.argv[1],sys.argv[2],sys.argv[3],compiler=sys.argv[4] if len(sys.argv)>4 else None)
