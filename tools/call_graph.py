"""Build a ROM-derived call graph and offline viewer; no source-coverage credit.

Requires capstone and pyelftools in the project's Python environment.
"""
import argparse
from bisect import bisect_right
from collections import Counter
import hashlib
import json
from pathlib import Path
from rom_inputs import input_rom
import re
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_OP_IMM, ARM_OP_REG
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
SYMBOL = re.compile(r'^(\S+) kind:function\((arm|thumb),size=(0x[\da-fA-F]+).*?addr:(0x[\da-fA-F]+)', re.M)
RELOC = re.compile(r'from:(0x[\da-f]+) kind:(\w+) to:(0x[\da-f]+) module:(\S+)')


def build(root):
    nodes, edges, indirect, modules = {}, {}, [], {}
    provenance = {}
    def read(path):
        data = path.read_bytes()
        provenance[str(path.relative_to(root))] = hashlib.sha256(data).hexdigest()
        return data
    def add(module, name, address, size, mode, source=None):
        key = f'{module}:{address:08x}'
        nodes[key] = dict(id=key, name=name, module=module, address=address,
                          size=size, mode=mode, source=source)
        return key
    from inventory import cartridge, TARGET_SHA1
    rom = (input_rom(root)).read_bytes()
    rom_sha1 = hashlib.sha1(rom).hexdigest()
    if rom_sha1 != TARGET_SHA1:
        raise ValueError('Original ROM SHA-1 does not match USA target')
    overlays = {r['id']:r for r in cartridge(rom)['overlays']['arm9']}
    del rom
    config = root / 'config/usa/arm9'
    for path in sorted(config.rglob('symbols.txt')):
        rel = path.parent.relative_to(config)
        module = 'arm9/' + ('main' if str(rel) == '.' else rel.name)
        entries = SYMBOL.findall(read(path).decode())
        for name, mode, size, address in entries:
            add(module, name, int(address, 16), int(size, 16), mode)
        if module.endswith('/main'):
            binary, base = root/'extract/usa/arm9/arm9.bin', 0x02000000
        elif rel.name in ('itcm', 'dtcm'):
            binary = root/f'extract/usa/arm9/{rel.name}.bin'
            meta = read(binary.with_suffix('.yaml')).decode()
            base = int(re.search(r'base_address: (\d+)', meta)[1])
        else:
            binary = root/f'extract/usa/arm9_overlays/{rel.name}.bin'
            # Overlay load addresses come from the verified original ROM header/table.
            record = overlays[int(rel.name[2:])]
            base = record['load_address']
        modules[module] = dict(base=base, data=read(binary), relocs=path.with_name('relocs.txt'))
    a7 = json.loads(read(root/'config/usa/arm7/source_units.json'))
    payload = read(root/'extract/usa/arm7/arm7.bin')
    for part in a7['autoloads']:
        modules['arm7/'+part['name']] = dict(base=part['runtime_address'], data=payload[part['payload_offset']:part['payload_offset']+part['size']])
    modules['arm7/startup'] = dict(base=0x02380000, data=payload[:a7['startup_size']])
    add('arm7/startup', 'arm7_entry', 0x02380000, 0xe4, 'arm')
    add('arm7/startup', 'arm7_copy_autoloads', 0x02380118, 0x74, 'arm')
    add('arm7/startup', 'arm7_startup_helper', 0x0238018c, 0x78, 'arm')
    missing = []
    for unit in a7['units']:
        obj = root/f"build/usa/arm7/{unit['name']}/{unit['name']}.o"
        if not obj.exists():
            missing.append(unit['name']); continue
        read(obj)
        with obj.open('rb') as stream:
            elf = ELFFile(stream)
            for symbol in elf.get_section_by_name('.symtab').iter_symbols():
                if symbol['st_info']['type'] != 'STT_FUNC' or symbol.name not in unit['symbols']:
                    continue
                address = unit['symbols'][symbol.name] & ~1
                mode = 'thumb' if symbol['st_value'] & 1 else 'arm'
                add('arm7/'+unit['autoload'], symbol.name, address, symbol['st_size'], mode, unit['source'])
    indexes = {}
    for module in modules:
        ordered = sorted((n for n in nodes.values() if n['module']==module), key=lambda n:n['address'])
        indexes[module] = ([n['address'] for n in ordered], ordered)
    def owner(module, address):
        starts, ordered = indexes.get(module, ([], []))
        i = bisect_right(starts, address & ~1)-1
        if i >= 0 and address < ordered[i]['address']+ordered[i]['size']:
            return ordered[i]['id']
    def link(src, dst, site, kind, ambiguous=False):
        if not dst: return
        key = (src, dst, kind, ambiguous)
        edges.setdefault(key, dict(source=src, target=dst, kind=kind, ambiguous=ambiguous, sites=[]))['sites'].append(site)
    # Relocations retain overlay identity, including genuinely ambiguous targets.
    unresolved = []
    for module, info in modules.items():
        if 'relocs' not in info: continue
        for site, kind, target, target_module in RELOC.findall(read(info['relocs']).decode()):
            if 'call' not in kind and 'branch' not in kind: continue
            site, target = int(site,16), int(target,16)
            src = owner(module,site)
            if not src: unresolved.append(dict(module=module, site=site, target=target, reason='no inventoried caller')); continue
            if target_module.startswith('overlay'):
                candidates = ['arm9/ov'+f'{int(x):03}' for x in re.findall(r'\d+',target_module)]
            else: candidates = ['arm9/'+target_module]
            found = False
            for candidate in candidates:
                dst = owner(candidate,target)
                if dst:
                    link(src,dst,site,'call' if 'call' in kind else 'tail branch',len(candidates)>1); found=True
            if not found: unresolved.append(dict(module=module,site=site,target=target,reason='no inventoried target'))
    # Traverse reachable instructions rather than treating literal pools as code.
    # Supplement relocations with tail branches and register-indirect transfers.
    decoders = {mode:Cs(CS_ARCH_ARM, flag) for mode,flag in [('arm',CS_MODE_ARM),('thumb',CS_MODE_THUMB)]}
    for decoder in decoders.values(): decoder.detail=True
    for node in list(nodes.values()):
        info=modules[node['module']]; start=node['address']; end=start+node['size']
        pending=[start]; seen=set(); md=decoders[node['mode']]
        while pending:
            pc=pending.pop()
            while start <= pc < end and pc not in seen:
                seen.add(pc); offset=pc-info['base']
                ins=next(md.disasm(info['data'][offset:offset+4],pc,count=1),None)
                if not ins: break
                mnemonic=ins.mnemonic; ops=ins.operands
                call=mnemonic in ('bl','blx') or mnemonic.startswith('blx')
                branch=mnemonic in ('b','bx') or (mnemonic.startswith('b') and mnemonic[1:] in ('eq','ne','hi','ls','gt','lt','ge','le','cc','cs','mi','pl','vs','vc'))
                target=ops[0].imm & ~1 if ops and ops[0].type==ARM_OP_IMM else None
                if call or branch:
                    if target is not None:
                        if branch and start <= target < end: pending.append(target)
                        elif node['module'].startswith('arm7/') or branch:
                            candidates=[m for m in modules if m.startswith(node['module'].split('/')[0]+'/') and (m==node['module'] or not m.split('/')[-1].startswith('ov'))]
                            dsts=[owner(m,target) for m in candidates]; dsts=[d for d in dsts if d]
                            if dsts:
                                for dst in dsts: link(node['id'],dst,pc,'call' if call else 'tail branch',len(dsts)>1)
                            else: unresolved.append(dict(module=node['module'],site=pc,target=target,reason='uninventoried direct target'))
                    elif ops and ops[0].type==ARM_OP_REG and ins.reg_name(ops[0].reg) != 'lr':
                        indirect.append(dict(source=node['id'],site=pc,instruction=mnemonic+' '+ins.op_str))
                    if branch and mnemonic in ('b','bx'): break
                if (mnemonic in ('pop','ldm','ldmib','ldmda') and 'pc' in ins.op_str) or (mnemonic=='mov' and ins.op_str=='pc, lr'): break
                if mnemonic in ('ldr','mov') and ins.op_str.startswith('pc,'):
                    indirect.append(dict(source=node['id'],site=pc,instruction=mnemonic+' '+ins.op_str)); break
                pc+=ins.size
    graph = dict(nodes=list(nodes.values()),edges=list(edges.values()),indirect=indirect,unresolved=unresolved,
                metadata=dict(rom_sha1=rom_sha1, module_counts={module:sum(n['module']==module for n in nodes.values()) for module in modules},missing_arm7_objects=missing,
                limitations=['ARM7 inventory is incomplete; only header/startup and compiled source-unit function symbols are included.',
                'Register-indirect calls, callbacks and computed jumps have unknown targets. Static edges do not prove runtime feasibility.',
                'Multiple possible overlay targets are marked ambiguous. Uninventoried targets are recorded separately.',
                'Executable-like assets and external BIOS routines are outside this inventoried graph.'],inputs_sha256=provenance))
    from lineage_depth import annotate
    annotate(graph)
    return graph


def main():
    parser=argparse.ArgumentParser(); parser.add_argument('--output',type=Path,default=ROOT/'build/call-graph'); args=parser.parse_args()
    graph=build(ROOT); args.output.mkdir(parents=True,exist_ok=True)
    encoded=json.dumps(graph,separators=(',',':'))
    (args.output/'graph.json').write_text(encoded,encoding='utf-8')
    from lineage_depth import write_order
    write_order(graph,args.output/'decompilation-order.csv')
    template=(ROOT/'tools/call_graph_viewer.html').read_text(encoding='utf-8')
    (args.output/'index.html').write_text(template.replace('/*GRAPH_DATA*/',encoded.replace('</','<\\/')),encoding='utf-8')
    print(json.dumps(dict(functions=len(graph['nodes']),edges=len(graph['edges']),indirect_sites=len(graph['indirect']),unresolved_sites=len(graph['unresolved']),missing_arm7_objects=graph['metadata']['missing_arm7_objects'],viewer=str(args.output/'index.html'))))


if __name__=='__main__': main()
