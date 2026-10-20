#!/usr/bin/env python3
"""Strict ARM9 BSS source audit; no zero-byte substitutes or code credit."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile
from match_unit import summarize
from arm9_module import module_section


def number(value):
    return value if isinstance(value, int) else int(value, 16)


def read_elf(path, selected, section_filter=None):
    blob = Path(path).read_bytes()
    if len(blob) < 52 or blob[:7] != b'\x7fELF\x01\x01\x01':
        raise ValueError('Expected ELF32 little-endian version 1')
    header = struct.unpack_from('<16sHHIIIIIHHHHHH', blob)
    if header[2] != 40 or header[11] != 40 or not header[12]:
        raise ValueError('Expected ARM ELF with standard section headers')
    offset, count, names_index = header[6], header[12], header[13]
    if offset + count * 40 > len(blob) or names_index >= count:
        raise ValueError('Invalid ELF section table')
    raw = [struct.unpack_from('<10I', blob, offset + i * 40) for i in range(count)]
    def contents(section):
        if section[1] == 8:
            return b''
        start, size = section[4:6]
        if start + size > len(blob):
            raise ValueError('Section outside ELF file')
        return blob[start:start + size]
    for section in raw:
        contents(section)
    strings = contents(raw[names_index])
    def name(table, position):
        if position >= len(table) or b'\0' not in table[position:]:
            raise ValueError('Invalid ELF string')
        return table[position:table.index(0, position)].decode()
    sections = [dict(name=name(strings, s[0]), type=s[1], flags=s[2], address=s[3],
                     size=s[5], alignment=s[8], payload=contents(s).hex()) for s in raw]
    owners={i for i,item in enumerate(sections) if item['name']==section_filter} if section_filter else None
    if owners is not None and len(owners)!=1:raise ValueError('Expected one selected ELF module section')
    symbols = {}
    for section in raw:
        if section[1] != 2:
            continue
        if section[9] != 16 or section[5] % 16 or section[6] >= count or raw[section[6]][1] != 3:
            raise ValueError('Invalid ELF symbol table')
        names = contents(raw[section[6]])
        entries = contents(section)
        for position in range(0, len(entries), 16):
            label, value, size, info, other, index = struct.unpack_from('<IIIBBH', entries, position)
            label = name(names, label)
            if index >= count and index < 0xff00:
                raise ValueError('Invalid symbol section')
            if label not in selected or index == 0 or (owners is not None and index not in owners and index != 0xfff1):
                continue
            if label in symbols:
                raise ValueError('Duplicate selected symbol: ' + label)
            symbols[label] = dict(value=value, size=size, type=info & 15, binding=info >> 4, section=index)
    return dict(type=header[1], sections=sections, symbols=symbols)


def object_layout(path, rows, declared=None):
    parsed = read_elf(path, {row['name'] for row in rows})
    if parsed['type'] != 1:
        raise ValueError('BSS source/target must be relocatable objects')
    indices = [i for i, section in enumerate(parsed['sections']) if section['name'] == '.bss']
    if len(indices) != 1:
        raise ValueError('Expected one .bss section')
    index = indices[0]
    section = parsed['sections'][index]
    if section['type'] != 8 or section['flags'] & ~0x20000000 != 3 or section['alignment'] not in (1, 2, 4, 8, 16, 32):
        raise ValueError('BSS must be writable allocated SHT_NOBITS with valid alignment')
    if section['size'] != sum(int(row['size']) for row in rows):
        raise ValueError('BSS section must contain exactly the owned extents')
    # A POD-only source definition must not emit code, constructors, initialized
    # data or another BSS reservation. Debug/symbol/string tables are not allocated.
    allocated = [s for s in parsed['sections'] if s['flags'] & 2 and s['size']]
    if declared is None:
        if len(allocated) != 1:
            raise ValueError('BSS-only unit contains another allocated section or initializer')
    else:
        if len({r['section'] for r in declared}) != len(declared):
            raise ValueError('Duplicate declared object section')
        expected = {r['section']: number(r['end']) - number(r['start']) for r in declared}
        if any(size <= 0 for size in expected.values()) or {name:sum(s['size'] for s in allocated if s['name']==name) for name in {s['name'] for s in allocated}} != expected:
            raise ValueError('Allocated object sections differ from declared payload')
    intervals = []
    for row in rows:
        symbol = parsed['symbols'].get(row['name'])
        if not symbol or symbol['type'] != 1 or symbol['binding'] != row.get('binding', 1) or symbol['section'] != index:
            raise ValueError('Expected global object symbol in .bss: ' + row['name'])
        start = symbol['value'] - section['address']
        end = start + symbol['size']
        if symbol['size'] != int(row['size']) or start < 0 or end > section['size']:
            raise ValueError('BSS symbol size/extent differs: ' + row['name'])
        if any(start < right and left < end for left, right in intervals):
            raise ValueError('Overlapping object BSS extents')
        intervals.append((start, end))
    normalized = {name: dict(offset=value['value'] - section['address'], size=value['size'], type=value['type'], binding=value['binding']) for name, value in parsed['symbols'].items()}
    canonical=[]
    for name in sorted({item['name'] for item in allocated}):
        parts=[item for item in allocated if item['name']==name]
        allowed_flags={'.text':(6,),'.init':(6,),'.data':(3,),'.rodata':(2,),'.ctor':(2,3),'.bss':(3,)}
        if name not in allowed_flags or any(item['flags'] & ~0x20000000 not in allowed_flags[name] or item['type']!=(8 if name=='.bss' else 1) for item in parts):
            raise ValueError('Unexpected allocated section type/flags')
        canonical.append(dict(name=name,size=sum(item['size'] for item in parts),payload='' if name in ('.text','.init') else ''.join(item['payload'] for item in parts)))
    normalized_section={k:v for k,v in section.items() if k != 'flags'}
    return dict(section=normalized_section, symbols=normalized, allocated=canonical)


def original_bounds(path, module='main'):
    if module in ('itcm','dtcm'):
        text=Path(path).read_text();values={}
        for key in ('base_address','code_size','bss_size'):
            matches=re.findall(r'^'+key+r':\s*([0-9]+)\s*$',text,re.MULTILINE)
            if len(matches)!=1:raise ValueError('Expected one autoload metadata value: '+key)
            values[key]=int(matches[0])
        if values['code_size']<=0 or values['bss_size']<=0:raise ValueError('Invalid autoload BSS bounds')
        start=values['base_address']+values['code_size']
        return dict(base_address=values['base_address'],bss_start=start,bss_end=start+values['bss_size'])
    if module != 'main':
        blocks=re.split(r'^- id:\s*',Path(path).read_text(),flags=re.MULTILINE)[1:]
        entries=[block for block in blocks if int(block.splitlines()[0])==int(module[2:])]
        if len(entries)!=1:raise ValueError('Expected one original overlay metadata row')
        row={}
        for key in ('base_address','code_size','bss_size'):
            values=re.findall(r'^  '+key+r':\s*([0-9]+)\s*$',entries[0],re.MULTILINE)
            if len(values)!=1:raise ValueError('Expected one overlay metadata value: '+key)
            row[key]=int(values[0])
        start=row['base_address']+row['code_size']
        if not row['code_size'] or not row['bss_size']:raise ValueError('Invalid overlay BSS bounds')
        return dict(base_address=row['base_address'],bss_start=start,bss_end=start+row['bss_size'])
    text = Path(path).read_text()
    result = {}
    for key in ('base_address', 'bss_start', 'bss_end'):
        values = re.findall(r'^' + key + r':\s*(0x[0-9a-fA-F]+|[0-9]+)\s*$', text, re.MULTILINE)
        if len(values) != 1:
            raise ValueError('Expected one original metadata value: ' + key)
        result[key] = int(values[0], 0)
    if not result['base_address'] < result['bss_start'] < result['bss_end']:
        raise ValueError('Invalid original BSS bounds')
    return result


def audit(project, manifest, elf, original_config, original_module, generated_module, objdiff, objdiff_tool=None):
    project = Path(project).resolve()
    rows = [row for row in manifest['data'] if row['section'] == '.bss']
    module=manifest.get('module','main');section_name=module_section(module)
    if not rows:
        raise ValueError('This audit requires ARM9 BSS rows')
    if len({row['name'] for row in rows}) != len(rows):
        raise ValueError('Duplicate BSS names')
    bounds = original_bounds(original_config,module)
    expected_hash = manifest['original_bss_metadata_sha256']
    if hashlib.sha256(Path(original_config).read_bytes()).hexdigest() != expected_hash:
        raise ValueError('Original BSS metadata hash differs')
    if Path(original_module).samefile(generated_module):
        raise ValueError('Original/generated module must be independent files')
    original, generated = Path(original_module).read_bytes(), Path(generated_module).read_bytes()
    if original != generated or len(original) != bounds['bss_start'] - bounds['base_address']:
        raise ValueError('Module bytes/extent differ from original before BSS')
    from integration_data_aliases import selected_aliases, verify_deferred_objects, audit_linked_aliases
    deferred_aliases = selected_aliases(project,module,manifest)
    names = {row['name'] for row in rows} | {section_name+'_BSS_START', section_name+'_BSS_END'} | {a['name'] for a in deferred_aliases}
    linked = read_elf(elf, names,section_name)
    indices = [i for i, section in enumerate(linked['sections']) if section['name'] == section_name]
    if len(indices) != 1 or linked['sections'][indices[0]]['address'] != bounds['base_address']:
        raise ValueError('Wrong linked ARM9 module section')
    index = indices[0]
    for name, key in [(section_name+'_BSS_START', 'bss_start'), (section_name+'_BSS_END', 'bss_end')]:
        symbol = linked['symbols'].get(name)
        if not symbol or symbol['value'] != bounds[key] or symbol['section'] not in (index, 0xfff1):
            raise ValueError('Linked BSS boundary differs: ' + name)
    audit_linked_aliases(linked, deferred_aliases, index)
    intervals, units = [], {}
    for row in rows:
        start, size = number(row['address']), int(row['size'])
        if row.get('module', module) != module or size <= 0 or not bounds['bss_start'] <= start < start + size <= bounds['bss_end']:
            raise ValueError('BSS row outside original bounds')
        if any(start < right and left < start + size for left, right in intervals):
            raise ValueError('Overlapping linked BSS extents')
        intervals.append((start, start + size))
        symbol = linked['symbols'].get(row['name'])
        if not symbol or (symbol['value'], symbol['size'], symbol['type'], symbol['binding'], symbol['section']) != (start, size, 1, row.get('binding',1), index):
            raise ValueError('Linked BSS object layout differs: ' + row['name'])
        source = (project / row['source']).resolve()
        if not source.is_relative_to(project / 'src') or hashlib.sha256(source.read_bytes()).hexdigest() != manifest['source_hashes'][row['source']]:
            raise ValueError('Source location/hash differs')
        units.setdefault(str(Path(row['source']).with_suffix('')), []).append(row)
    for path, expected in manifest.get('dependency_hashes', {}).items():
        dependency = (project / path).resolve()
        if not dependency.is_relative_to(project) or hashlib.sha256(dependency.read_bytes()).hexdigest() != expected:
            raise ValueError('Source dependency hash differs: ' + path)
    document = json.loads(Path(objdiff).read_text())
    for name, owned in units.items():
        entries = [unit for unit in document['units'] if unit['name'] == name]
        if len(entries) != 1:
            raise ValueError('Expected one objdiff source unit: ' + name)
        unit = entries[0]
        if unit.get('metadata', {}).get('source_path') != owned[0]['source'] or not unit['metadata'].get('complete'):
            raise ValueError('BSS unit is not complete source-owned')
        paths = [(project / unit[key]).resolve() for key in ('target_path', 'base_path')]
        if any(not path.is_relative_to(project / 'build') for path in paths) or paths[0].samefile(paths[1]):
            raise ValueError('Original/candidate objects must be independent build files')
        unit_aliases = [a for a in deferred_aliases if str(Path(a['source']).with_suffix('')) == name]
        if unit_aliases:
            verify_deferred_objects(paths[0], paths[1], unit_aliases)
        declared=manifest.get('unit_sections',{}).get(owned[0]['source'])
        target, candidate = [object_layout(path, owned,declared) for path in paths]
        if declared is not None:
            for extent in declared:
                start,end=number(extent['start']),number(extent['end'])
                if extent['section']=='.bss':
                    if (start,end)!=(min(number(row['address']) for row in owned),max(number(row['address'])+int(row['size']) for row in owned)):
                        raise ValueError('Declared BSS section differs from linked owned extent')
                    for row in owned:
                        if start+candidate['symbols'][row['name']]['offset']!=number(row['address']):
                            raise ValueError('BSS relative symbol placement differs')
                elif not bounds['base_address']<=start<end<=bounds['bss_start']:
                    raise ValueError('Declared initialized section outside original module')
                parts=[item for item in read_elf(paths[1],set())['sections'] if item['name']==extent['section'] and item['flags']&2 and item['size']]
                if any(item['alignment'] not in (1,2,4,8,16,32) or start%item['alignment'] for item in parts):
                    raise ValueError('Declared section violates candidate alignment')
            # Relocation-aware whole-unit comparison checks every symbol in the
            # code/initializer payload; section declarations forbid extra storage.
            hashes=[hashlib.sha256(path.read_bytes()).hexdigest() for path in paths]
            with tempfile.TemporaryDirectory() as directory:
                output=Path(directory)/'diff.json'
                subprocess.run([str(objdiff_tool or project/'objdiff-cli'),'diff','-1',str(paths[0]),'-2',str(paths[1]),'-o',str(output),'--format','json'],check=True,capture_output=True)
                comparisons=summarize(json.loads(output.read_text()))
                if not comparisons or any(not row['paired'] or row['match_percent']!=100 for row in comparisons):
                    raise ValueError('Mixed BSS unit whole-object comparison differs')
            if hashes != [hashlib.sha256(path.read_bytes()).hexdigest() for path in paths]:
                raise ValueError('Object changed during BSS comparison')
        # DSD gives split target sections byte alignment; compiler type alignment
        # is enforced against each actual linked reservation.
        for row in owned:
            if number(row['address']) % candidate['section']['alignment']:
                raise ValueError('Linked BSS address violates source alignment')
        target['section'].pop('alignment');candidate['section'].pop('alignment')
        if target != candidate:
            raise ValueError('Original/candidate BSS metadata differ')
    return dict(match=True, linked_aliases_audited=sorted(a['name'] for a in deferred_aliases), bss_symbols=len(rows), bss_bytes=sum(int(row['size']) for row in rows),
                initialized_data_bytes=0, bss_start=bounds['bss_start'], bss_end=bounds['bss_end'],
                original_bss_metadata_sha256=expected_hash, rom_acceptance=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--elf', type=Path, required=True)
    parser.add_argument('--original-config', type=Path, required=True)
    parser.add_argument('--original-module', type=Path, required=True)
    parser.add_argument('--generated-module', type=Path, required=True)
    parser.add_argument('--objdiff', type=Path, default=Path('objdiff.json'))
    parser.add_argument('--objdiff-tool',type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    try:
        result = audit(args.project, json.loads(args.manifest.read_text()), args.elf, args.original_config,
                       args.original_module, args.generated_module, args.objdiff,args.objdiff_tool)
        if args.output:
            args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps(result))
        return 0
    except (OSError, ValueError, KeyError, TypeError, struct.error, subprocess.CalledProcessError) as error:
        result = dict(match=False, error=str(error))
        if args.output:
            args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps(result))
        return 2


if __name__ == '__main__':
    raise SystemExit(main())
