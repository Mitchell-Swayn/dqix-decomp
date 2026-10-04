"""Export inventoried original functions, verified source and calls to SQLite.

The database is a snapshot, not reconstruction coverage or the work queue.
Run call_graph.py and full build checks first. Requires capstone/pyelftools.
"""
import argparse
from bisect import bisect_right
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
from rom_inputs import input_rom
import re
import sqlite3
import subprocess
import tempfile

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB, CS_GRP_CALL, CS_GRP_JUMP
from capstone.arm import ARM_CC_AL, ARM_CC_INVALID, ARM_OP_IMM, ARM_OP_MEM, ARM_OP_REG
from elftools.elf.elffile import ELFFile
from inventory import cartridge, delinks, TARGET_SHA1
from unit_source_views import views as unit_views

ROOT=Path(__file__).resolve().parents[1]
SCHEMA='''
PRAGMA foreign_keys=ON;
CREATE TABLE metadata(key TEXT PRIMARY KEY,value TEXT NOT NULL);
CREATE TABLE modules(id TEXT PRIMARY KEY,processor TEXT NOT NULL,base_address INTEGER NOT NULL,
 original_size INTEGER NOT NULL,original_sha256 TEXT NOT NULL);
CREATE TABLE dependency_groups(id TEXT PRIMARY KEY,lineage_depth INTEGER NOT NULL,
 recursive INTEGER NOT NULL,member_count INTEGER NOT NULL);
CREATE TABLE sources(path TEXT PRIMARY KEY,language TEXT NOT NULL,sha256 TEXT NOT NULL,content TEXT NOT NULL);
CREATE TABLE functions(
 id TEXT PRIMARY KEY,module_id TEXT NOT NULL REFERENCES modules(id),name TEXT NOT NULL,
 address INTEGER NOT NULL,size INTEGER NOT NULL,mode TEXT NOT NULL,
 assembly TEXT NOT NULL,original_bytes BLOB NOT NULL,original_sha256 TEXT NOT NULL,
 lineage_depth INTEGER NOT NULL,dependency_group_id TEXT NOT NULL REFERENCES dependency_groups(id),
 recursive INTEGER NOT NULL,unresolved_downstream INTEGER NOT NULL,ambiguous_downstream INTEGER NOT NULL,
 completion_status TEXT NOT NULL,match_percent REAL,source_path TEXT REFERENCES sources(path),
 source_start_line INTEGER,source_end_line INTEGER,source_scope TEXT,
 decompiled_c TEXT,source_extraction_note TEXT,assembly_note TEXT NOT NULL,
 UNIQUE(module_id,address),CHECK(size>=0),CHECK(lineage_depth>=1),
 CHECK(decompiled_c IS NULL OR completion_status='completed'));
CREATE INDEX functions_by_depth ON functions(lineage_depth,completion_status,module_id);
CREATE INDEX functions_by_name ON functions(name);
CREATE TABLE relationships(id INTEGER PRIMARY KEY,
 caller_id TEXT NOT NULL REFERENCES functions(id),callee_id TEXT NOT NULL REFERENCES functions(id),
 kind TEXT NOT NULL,ambiguous INTEGER NOT NULL,
 UNIQUE(caller_id,callee_id,kind,ambiguous));
CREATE INDEX relationships_by_callee ON relationships(callee_id);
CREATE TABLE call_sites(relationship_id INTEGER NOT NULL REFERENCES relationships(id),
 instruction_address INTEGER NOT NULL,PRIMARY KEY(relationship_id,instruction_address));
CREATE TABLE unresolved_calls(id INTEGER PRIMARY KEY,caller_id TEXT REFERENCES functions(id),
 module_id TEXT NOT NULL REFERENCES modules(id),instruction_address INTEGER NOT NULL,
 target_address INTEGER,instruction TEXT,reason TEXT NOT NULL);
CREATE VIEW decompilation_order AS
 SELECT id,module_id,name,address,lineage_depth,dependency_group_id,recursive,
 completion_status,unresolved_downstream,ambiguous_downstream FROM functions
 ORDER BY lineage_depth,dependency_group_id,id;
CREATE VIEW remaining_functions AS
 SELECT * FROM decompilation_order WHERE completion_status NOT IN ('completed','reviewed_assembly','completed_source_unextracted')
 ORDER BY lineage_depth,dependency_group_id,id;
CREATE VIEW named_relationships AS
 SELECT r.id,a.module_id AS caller_module,a.name AS caller,b.module_id AS callee_module,
 b.name AS callee,r.kind,r.ambiguous FROM relationships r
 JOIN functions a ON a.id=r.caller_id JOIN functions b ON b.id=r.callee_id;
'''


def masked_source(text):
    """Preserve offsets/newlines while masking comments and quoted literals."""
    pattern=r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\[\s\S]|[^"\\])*"|\'(?:\\[\s\S]|[^\'\\])*\''
    return re.sub(pattern,lambda m:''.join('\n' if c=='\n' else ' ' for c in m[0]),text)


def source_function(text,line):
    """Use compiler's declaration line; never invent recovered source."""
    lines=text.splitlines(keepends=True)
    if line<1 or line>len(lines): return None
    start=sum(map(len,lines[:line-1])); masked=masked_source(text)
    # A declaration rather than a definition cannot own a following function.
    brace=masked.find('{',start); semicolon=masked.find(';',start)
    if brace<0 or (0<=semicolon<brace): return None
    depth=0
    for pos in range(brace,len(masked)):
        if masked[pos]=='{': depth+=1
        elif masked[pos]=='}':
            depth-=1
            if depth==0:
                return text[start:pos+1].strip(),line,text.count('\n',0,pos)+1
    return None


def dwarf_definitions(path,root):
    """Map exact ELF symbol -> source location via MWCC debug relocations.

    MWCC emits ARM RELA debug records and duplicate empty .debug_line sections.
    Read unrelocated DWARF and resolve low_pc's relocation to its symbol rather
    than modifying the object or asking pyelftools to apply unsupported records.
    """
    definitions={}
    with path.open('rb') as stream:
        elf=ELFFile(stream)
        nonempty={}
        for section in elf.iter_sections():
            if section['sh_size']: nonempty.setdefault(section.name,section)
        lookup=elf.get_section_by_name
        elf.get_section_by_name=lambda name:nonempty.get(name) or lookup(name)
        if not elf.has_dwarf_info(): return definitions
        dwarf=elf.get_dwarf_info(relocate_dwarf_sections=False)
        relocations={}
        rel=elf.get_section_by_name('.rel.debug_info')
        if rel:
            symbols=elf.get_section(rel['sh_link'])
            for relocation in rel.iter_relocations():
                symbol=symbols.get_symbol(relocation['r_info_sym'])
                if symbol['st_info']['type']=='STT_FUNC':
                    relocations[relocation['r_offset']]=symbol.name
        for cu in dwarf.iter_CUs():
            try: program=dwarf.line_program_for_CU(cu)
            except Exception: program=None
            for die in cu.iter_DIEs():
                attrs=die.attributes
                if die.tag!='DW_TAG_subprogram' or 'DW_AT_low_pc' not in attrs: continue
                symbol=relocations.get(attrs['DW_AT_low_pc'].offset)
                if not symbol or not program or 'DW_AT_decl_line' not in attrs or 'DW_AT_decl_file' not in attrs: continue
                entry=program.header['file_entry'][attrs['DW_AT_decl_file'].value-1]
                filename=entry.name.decode(errors='replace')
                directory=program.header['include_directory'][entry.dir_index-1].decode(errors='replace') if entry.dir_index else str(root)
                source=Path(directory.replace('\\','/'))/filename
                if not source.is_absolute(): source=root/source
                source=source.resolve()
                if source.is_relative_to(root.resolve()) and source.exists():
                    definitions[symbol]=(source,attrs['DW_AT_decl_line'].value)
    return definitions


def disassemble(data,address,mode):
    """Decode reachable control flow; label PC-relative literals separately.

    Unreachable/unclassified bytes remain explicit rather than fake instructions.
    Runtime dispatch may reach code not discovered by this bounded traversal.
    """
    decoder=Cs(CS_ARCH_ARM,CS_MODE_THUMB if mode=='thumb' else CS_MODE_ARM); decoder.detail=True
    end=address+len(data); instructions={}; literals={}; pending=[address]
    while pending:
        pc=pending.pop()
        while address<=pc<end and pc not in instructions and pc not in literals:
            offset=pc-address; instruction=next(decoder.disasm(data[offset:offset+4],pc,count=1),None)
            if instruction is None: break
            instructions[pc]=instruction
            unconditional=instruction.cc in (ARM_CC_AL,ARM_CC_INVALID)
            for op in instruction.operands:
                if instruction.mnemonic.startswith('ldr') and op.type==ARM_OP_MEM and instruction.reg_name(op.mem.base)=='pc' and not op.mem.index:
                    base=((pc+4)&~3) if mode=='thumb' else pc+8
                    target=base+op.mem.disp
                    width=1 if instruction.mnemonic.startswith('ldrb') else 2 if instruction.mnemonic.startswith('ldrh') else 4
                    if address<=target and target+width<=end: literals[target]=width
            jump=instruction.group(CS_GRP_JUMP) and not instruction.group(CS_GRP_CALL)
            if jump:
                target=next((op.imm&~1 for op in instruction.operands if op.type==ARM_OP_IMM),None)
                if target is not None and address<=target<end: pending.append(target)
                if unconditional: break
            # Includes conditional returns: preserve the other execution path.
            regs=[instruction.reg_name(op.reg) for op in instruction.operands if op.type==ARM_OP_REG]
            returns=(instruction.mnemonic.startswith(('pop','ldm')) and 'pc' in regs)
            writes_pc=bool(regs and regs[0]=='pc' and instruction.mnemonic.startswith(('mov','ldr','add','sub')))
            if unconditional and (returns or writes_pc): break
            pc+=instruction.size
    output=[]; offset=0
    while offset<len(data):
        pc=address+offset
        if pc in instructions and pc not in literals:
            ins=instructions[pc]; output.append(f'{pc:08X}: {ins.mnemonic:8} {ins.op_str}'.rstrip()); offset+=ins.size
        elif pc in literals:
            size=literals[pc]; value=int.from_bytes(data[offset:offset+size],'little')
            directive={1:'.byte',2:'.hword',4:'.word'}[size]
            output.append(f'{pc:08X}: {directive:8} 0x{value:0{size*2}X} ; PC-relative literal data'); offset+=size
        else:
            size=min(4,len(data)-offset)
            while size>1 and any(pc+i in instructions or pc+i in literals for i in range(1,size)): size-=1
            chunk=data[offset:offset+size]
            output.append(f'{pc:08X}: .byte    '+', '.join(f'0x{x:02X}' for x in chunk)+' ; unclassified data or unreachable code'); offset+=size
    return '\n'.join(output)


def original_modules(root):
    rom=(input_rom(root)).read_bytes()
    if hashlib.sha1(rom).hexdigest()!=TARGET_SHA1: raise ValueError('Original USA ROM hash mismatch')
    records=cartridge(rom); del rom
    result={}
    for name in ('main','itcm','dtcm'):
        path=root/f"extract/usa/arm9/{'arm9' if name=='main' else name}.bin"
        if name=='main': base=0x02000000
        else: base=int(re.search(r'base_address: (\d+)',path.with_suffix('.yaml').read_text())[1])
        result['arm9/'+name]=(base,path.read_bytes())
    for overlay in records['overlays']['arm9']:
        name=f"ov{overlay['id']:03}"; result['arm9/'+name]=(overlay['load_address'],(root/f'extract/usa/arm9_overlays/{name}.bin').read_bytes())
    config=json.loads((root/'config/usa/arm7/source_units.json').read_text())
    data=(root/'extract/usa/arm7/arm7.bin').read_bytes()
    result['arm7/startup']=(0x02380000,data[:config['startup_size']])
    for part in config['autoloads']: result['arm7/'+part['name']]=(part['runtime_address'],data[part['payload_offset']:part['payload_offset']+part['size']])
    return result


def create_database(root,graph,destination):
    # Reject graph inputs that have drifted since its extraction.
    for name,digest in graph['metadata']['inputs_sha256'].items():
        if hashlib.sha256((root/name).read_bytes()).hexdigest()!=digest:
            raise ValueError(f'Stale graph input: {name}; regenerate call_graph.py first')
    modules=original_modules(root)
    report=json.loads((root/'build/usa/report.json').read_text())
    report_functions={}
    for unit in report['units']:
        source=unit.get('metadata',{}).get('source_path')
        if source:
            for function in unit.get('functions',[]): report_functions[(source,function['name'])]=(unit,function)
    compiled_views = unit_views(root)
    ownership={}
    for path in (root/'config/usa/arm9').rglob('delinks.txt'):
        module='arm9/'+('main' if path.parent==root/'config/usa/arm9' else path.parent.name)
        _,sources=delinks(path)
        ownership[module]=sources
    arm7=json.loads((root/'build/usa/arm7/report.json').read_text())
    if not arm7.get('module_check_passed') or not arm7.get('source_symbol_checks_passed'): raise ValueError('ARM7 build verification missing')
    a7units={(f"arm7/{unit['autoload']}",name):unit for unit in arm7['units'] for name in unit['symbols']}
    exceptions=set()
    for exc in json.loads((root/'config/usa/arm9/assembly_exceptions.json').read_text())['exceptions']:
        exceptions.update(('arm9',routine['symbol']) for routine in exc['routines'])
    definitions={}; source_cache={}; source_notes=[]
    def get_definitions(obj):
        if obj not in definitions:
            try: definitions[obj]=dwarf_definitions(obj,root)
            except Exception as error:
                definitions[obj]={}; source_notes.append(dict(object=str(obj.relative_to(root)),reason=str(error)))
        return definitions[obj]
    def source_text(path):
        if path not in source_cache: source_cache[path]=path.read_text(encoding='utf-8')
        return source_cache[path]
    destination.parent.mkdir(parents=True,exist_ok=True)
    handle,tempname=tempfile.mkstemp(prefix='functions-',suffix='.sqlite',dir=destination.parent); os.close(handle)
    temporary=Path(tempname)
    db=sqlite3.connect(temporary)
    try:
        db.executescript(SCHEMA)
        db.executemany('INSERT INTO modules VALUES(?,?,?,?,?)',[(name,name.split('/')[0],base,len(data),hashlib.sha256(data).hexdigest()) for name,(base,data) in modules.items()])
        db.executemany('INSERT INTO dependency_groups VALUES(?,?,?,?)',[(g['id'],g['layer'],g['recursive'],len(g['members'])) for g in graph['dependency_groups']])
        counts=Counter()
        for node in graph['nodes']:
            module=node['module']; base,data=modules[module]; offset=node['address']-base
            if offset<0 or offset+node['size']>len(data): raise ValueError('Function bounds outside original module: '+node['id'])
            raw=data[offset:offset+node['size']]; status='undecompiled'; percent=None
            source=None; obj=None; complete=False
            if module.startswith('arm9/'):
                owner=next((s for s in ownership[module] if any(r['start']<=node['address'] and node['address']+node['size']<=r['end'] and r['section'] in ('.text','.init') for r in s['ranges'])),None)
                if owner:
                    actual_source = compiled_views.get(owner['source'], {}).get('source_path', owner['source'])
                    source=root/actual_source; obj=root/'build/usa'/Path(owner['source']).with_suffix('.o')
                    pair=report_functions.get((actual_source,node['name']))
                    if pair:
                        unit,function=pair; percent=function.get('fuzzy_match_percent',0)
                        complete=owner['declared_complete'] and percent==100 and not unit.get('metadata',{}).get('auto_generated',True)
            else:
                unit=a7units.get((module,node['name']))
                if unit:
                    source=root/unit['source']; obj=root/f"build/usa/arm7/{unit['name']}/{unit['name']}.o"
                    if hashlib.sha1(source.read_bytes()).hexdigest()!=unit['source_sha1']: raise ValueError('Stale ARM7 source report: '+unit['source'])
                    complete=unit['module_check_passed'] and unit['symbol_check_passed']; percent=100 if complete else None
                    if unit.get('reviewed_assembly_bytes'): exceptions.add(('arm7',node['name']))
            excerpt=None; start_line=None; end_line=None; note=None; source_scope=None
            source_rel=None
            if source and source.exists():
                source=source.resolve(); source_rel=source.relative_to(root.resolve()).as_posix(); text=source_text(source)
                language={'.c':'c','.cpp':'cpp','.s':'assembly','.S':'assembly'}.get(source.suffix,'unknown')
                db.execute('INSERT OR IGNORE INTO sources VALUES(?,?,?,?)',(source_rel,language,hashlib.sha256(source.read_bytes()).hexdigest(),text))
                status='completed' if complete else 'source_incomplete'
                if complete:
                    location=get_definitions(obj).get(node['name']) if obj and obj.exists() else None
                    if location:
                        path,line=location
                        result=source_function(source_text(path),line)
                        if result:
                            excerpt,start_line,end_line=result; source_scope='function'
                            if path!=source:
                                source_rel=path.relative_to(root.resolve()).as_posix()
                                db.execute('INSERT OR IGNORE INTO sources VALUES(?,?,?,?)',(source_rel,language,hashlib.sha256(path.read_bytes()).hexdigest(),source_text(path)))
                    if excerpt is None:
                        # Keep actual complete translation-unit source available; do
                        # not substitute its whole text for a per-function definition.
                        status='completed_source_unextracted'; note='Verified source unit available in sources; exact per-function definition could not be isolated from compiler debug locations.'
                    if (module.split('/')[0],node['name']) in exceptions or language=='assembly':
                        status='reviewed_assembly'; excerpt=None; note='Reviewed assembly exception; owning source stored separately, not counted as decompiled C.'
                    elif excerpt and re.search(r'\b(?:__asm|asm)\b',masked_source(excerpt)):
                        status='mixed_source'; excerpt=None; note='Matching C/C++ with inline assembly; owning source stored separately.'
            l=node['lineage']; assembly=disassemble(raw,node['address'],node['mode'])
            columns=(node['id'],module,node['name'],node['address'],node['size'],node['mode'],assembly,raw,hashlib.sha256(raw).hexdigest(),l['layer'],l['group'],l['recursive'],l['unresolved_downstream'],l['ambiguous_downstream'],status,percent,source_rel,start_line,end_line,source_scope,excerpt,note,'Original module bytes; bounded reachable disassembly. PC-relative literal data separated; remaining bytes unclassified. Unknown inventory extents may be empty.')
            db.execute('INSERT INTO functions VALUES('+','.join('?' for _ in columns)+')',columns); counts[status]+=1
        for edge in graph['edges']:
            cursor=db.execute('INSERT INTO relationships(caller_id,callee_id,kind,ambiguous) VALUES(?,?,?,?)',(edge['source'],edge['target'],edge['kind'],edge['ambiguous']))
            db.executemany('INSERT INTO call_sites VALUES(?,?)',[(cursor.lastrowid,site) for site in sorted(set(edge['sites']))])
        by_module={}
        for node in graph['nodes']: by_module.setdefault(node['module'],[]).append(node)
        for module in by_module: by_module[module].sort(key=lambda n:n['address'])
        for site in graph['indirect']:
            node=next(n for n in graph['nodes'] if n['id']==site['source'])
            db.execute('INSERT INTO unresolved_calls(caller_id,module_id,instruction_address,instruction,reason) VALUES(?,?,?,?,?)',(node['id'],node['module'],site['site'],site['instruction'],'indirect target unknown'))
        for site in graph['unresolved']:
            candidates=by_module.get(site['module'],[]); starts=[n['address'] for n in candidates]; pos=bisect_right(starts,site['site'])-1
            caller=candidates[pos]['id'] if pos>=0 and site['site']<candidates[pos]['address']+candidates[pos]['size'] else None
            db.execute('INSERT INTO unresolved_calls(caller_id,module_id,instruction_address,target_address,reason) VALUES(?,?,?,?,?)',(caller,site['module'],site['site'],site['target'],site['reason']))
        meta=dict(schema_version=1,created_utc=datetime.now(timezone.utc).isoformat(),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=root,text=True).strip(),
                  source_tree_dirty=bool(subprocess.check_output(['git','status','--porcelain'],cwd=root,text=True).strip()),rom_sha1=TARGET_SHA1,
                  graph_metadata=graph['metadata'],source_extraction_diagnostics=source_notes,completion_counts=dict(counts),
                  arm9_report_sha256=hashlib.sha256((root/'build/usa/report.json').read_bytes()).hexdigest(),
                  arm7_report_sha256=hashlib.sha256((root/'build/usa/arm7/report.json').read_bytes()).hexdigest(),
                  completion_policy='ARM9: declared complete source range and report function match 100%; ARM7: source hash plus module/symbol verification. Assembly and mixed source tracked separately. NULL C means no verified isolated C/C++ definition.')
        db.executemany('INSERT INTO metadata VALUES(?,?)',[(key,json.dumps(value)) for key,value in meta.items()])
        db.commit()
        if db.execute('PRAGMA integrity_check').fetchone()[0]!='ok' or db.execute('PRAGMA foreign_key_check').fetchall(): raise ValueError('SQLite integrity check failed')
        summary=dict(functions=db.execute('SELECT count(*) FROM functions').fetchone()[0],relationships=db.execute('SELECT count(*) FROM relationships').fetchone()[0],
                     call_sites=db.execute('SELECT count(*) FROM call_sites').fetchone()[0],completion_counts=dict(counts),source_diagnostics=len(source_notes),database=str(destination))
        db.close(); os.replace(temporary,destination)
        return summary
    finally:
        db.close()
        if temporary.exists(): temporary.unlink()


def main():
    parser=argparse.ArgumentParser(); parser.add_argument('--graph',type=Path,default=ROOT/'build/call-graph/graph.json'); parser.add_argument('--output',type=Path,default=ROOT/'build/call-graph/functions.sqlite'); args=parser.parse_args()
    graph=json.loads(args.graph.read_text(encoding='utf-8'))
    print(json.dumps(create_database(ROOT,graph,args.output)))


if __name__=='__main__': main()
