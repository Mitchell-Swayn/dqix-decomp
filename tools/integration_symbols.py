"""Carry explicitly declared new module symbols inside source acceptance transactions."""
import re
from arm9_module import delinks_path

def capture_symbols(main, worker, module, manifest):
    declarations=manifest.get('symbol_additions',manifest.get('symbol_map_additions',[]))
    refinement=manifest.get('symbol_size_dependency')
    data_refinements=manifest.get('symbol_refinements',[])
    if not declarations and not refinement and not data_refinements:return None
    relative=delinks_path(module).with_name('symbols.txt')
    if any('path' in x and x['path']!=relative.as_posix() for x in declarations):raise ValueError('Symbol declaration outside selected module')
    before=(main/relative).read_bytes();worker_lines=(worker/relative).read_text().splitlines()
    selected={row['name']:row for row in manifest.get('functions',[])+manifest.get('data',[])}
    seen=set();added=[];refined=before.decode()
    if refinement:
        if refinement['path']!=relative.as_posix():raise ValueError('Symbol refinement outside selected module')
        for item in refinement['refinements']:
            row=selected.get(item['name']);kind=item['kind']
            match=re.fullmatch(r'bss\(size=0x([0-9a-fA-F]+)\)',kind)
            if not row or row.get('section')!='.bss' or not match or int(match[1],16)!=int(row['size']):raise ValueError('Refinement must bind exact selected BSS extent')
            old_lines=[x for x in refined.splitlines() if re.match(re.escape(item['name'])+r'\s',x)]
            if len(old_lines)!=1:raise ValueError('Refinement needs one existing BSS symbol')
            old=old_lines[0];old_match=re.fullmatch(re.escape(item['name'])+r' kind:bss addr:0x([0-9a-fA-F]+)',old)
            if not old_match or int(old_match[1],16)!=int(row['address'],16):raise ValueError('Refinement changes original address or kind')
            new=old.replace('kind:bss ', 'kind:'+kind+' ')
            if new not in worker_lines:raise ValueError('Refinement differs from frozen worker map')
            refined=refined.replace(old,new)
        before_for_append=refined.encode()
    else:before_for_append=before
    refined_data_names=set()
    for item in data_refinements:
        if item['path']!=relative.as_posix():raise ValueError('Data refinement outside selected module')
        old,new=item['before'],item['after'];name=old.split()[0];row=selected.get(name)
        # DSD array counts are elements, whereas source manifests record bytes.
        # Support only reviewed primitive widths; never infer an opaque span.
        match=re.fullmatch(re.escape(name)+r' kind:data\((byte|word)\[([0-9]+)\]\) addr:0x([0-9a-fA-F]+)',new)
        if not row or row.get('section') not in ('.data','.rodata','.ctor') or not match:raise ValueError('Data refinement must bind exact selected initialized extent')
        width={'byte':1,'word':4}[match[1]];count=int(match[2]);address=int(match[3],16)
        if count<=0 or count*width!=row['size'] or address!=int(row['address'],16) or address%width:raise ValueError('Data refinement must bind exact selected initialized extent')
        if name in refined_data_names:raise ValueError('Duplicate initialized data refinement')
        refined_data_names.add(name)
        lines=before_for_append.decode().splitlines(keepends=True)
        named_lines=[line for line in lines if re.match(r'\s*'+re.escape(name)+r'\s',line)]
        if old!=name+' kind:data(any) addr:0x'+match[3] or len(named_lines)!=1 or named_lines[0].rstrip('\r\n')!=old or new not in worker_lines:raise ValueError('Data refinement changes original address or kind')
        # Replace one complete symbol line, never text in comments or prefixes.
        before_for_append=''.join(new+line[len(old):] if line.rstrip('\r\n')==old else line for line in lines).encode()
    for declaration in declarations:
        if 'path' in declaration and declaration['path']!=relative.as_posix():raise ValueError('Symbol declaration outside selected module')
        line=declaration.get('line')
        if line is None:line=f"{declaration['name']} kind:{declaration['kind']} addr:{declaration['address']}"
        match=re.fullmatch(r'([A-Za-z_]\w*) kind:(data\([^)]*\)|function\([^)]*\)) addr:0x([0-9a-fA-F]+)',line)
        if not match:raise ValueError('Invalid new symbol declaration')
        name,kind,address=match.groups();row=selected.get(name)
        if row is None or name in seen:raise ValueError('Symbol must belong to unique selected source extent')
        seen.add(name)
        if int(address,16)!=int(row['address'],16):raise ValueError('Symbol address differs from selected extent')
        if line not in worker_lines:raise ValueError('Declared symbol is absent from frozen worker map')
        if any(re.match(re.escape(name)+r'\s',x) for x in before.decode().splitlines()):raise ValueError('Cannot replace existing symbol')
        if not any(x['name']==name for x in manifest.get('data',[])) or not kind.startswith('data('):raise ValueError('Only new selected data symbols are supported')
        added.append(line)
    after=before_for_append+(b'' if not before_for_append or before_for_append.endswith(b'\n') else b'\n')+(('\n'.join(added)+'\n').encode() if added else b'')
    return dict(path=relative.as_posix(),before=before,after=after)

def install_symbols(root,snapshot):
    if snapshot:
        path=root/snapshot['path']
        if path.read_bytes()!=snapshot['before']:raise ValueError('Main symbol map changed after capture')
        path.write_bytes(snapshot['after'])

def verify_symbols(root,snapshot):
    if snapshot and (root/snapshot['path']).read_bytes()!=snapshot['after']:raise ValueError('Installed symbols changed')

def restore_symbols(root,snapshot):
    if snapshot:(root/snapshot['path']).write_bytes(snapshot['before'])
