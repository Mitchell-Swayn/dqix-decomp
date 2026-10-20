#!/usr/bin/env python3
"""Report naming/placement debt per subsystem chunk and emit chunk work packets; never renames code."""
import argparse
import bisect
import collections
import json
from pathlib import Path
import re
import sqlite3

SYMBOL = re.compile(r'^(\S+) kind:function\((\w+),size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)')
TEXT = re.compile(r'\.(?:text|init)\s+start:0x([0-9a-f]+)\s+end:0x([0-9a-f]+)', re.IGNORECASE)
LOAD = re.compile(r'from:0x([0-9a-f]+) kind:load to:0x([0-9a-f]+) module:(\S+)')
ADDRESS_ONLY = re.compile(r'(?:^|_)(?:func|Func)_?(?:ov\d{3}_)?[0-9a-fA-F]{8}$')
# Names that describe storage layout rather than behaviour (offsets, raw record kinds, numbered states).
MECHANICAL = re.compile(r'(Offset|Field|At)[0-9A-F]{2,}|_[0-9A-Fa-f]{8}$|Record(Type)?[0-9A-F]+(?=$|_|[A-Z][a-z])|StateTo[A-Z]'
                        r'|Type(One|Two|Three|Four|Five|Six|Seven|Eight|Nine|Ten|Eleven|Twelve|Fifteen|\d+)(Record|Entry)')
COLUMNS = ('functions', 'named', 'mechanical', 'address_only', 'undecompiled', 'undecompiled_bytes', 'unclassified_dir')


def module_dirs(root):
    cfg = root / 'config/usa/arm9'
    dirs = {'arm9/main': cfg, 'arm9/itcm': cfg / 'itcm'}
    dirs.update({f'arm9/{d.name}': d for d in sorted((cfg / 'overlays').iterdir())})
    return dirs


def inventory(root):
    functions = []
    for module, d in module_dirs(root).items():
        ranges = []
        source = None
        for line in (d / 'delinks.txt').read_text().splitlines() if (d / 'delinks.txt').exists() else []:
            if line.startswith(('src/', 'build/')):
                source = line.rstrip(':')
            elif (m := TEXT.search(line)) and source:
                ranges.append((int(m[1], 16), int(m[2], 16), source))
        ranges.sort()
        starts = [r[0] for r in ranges]
        for line in (d / 'symbols.txt').read_text().splitlines():
            m = SYMBOL.match(line)
            if not m:
                continue
            name, mode, size, address = m[1], m[2], int(m[3], 16), int(m[4], 16)
            if module == 'arm9/main' and address < 0x02000400 and mode == 'thumb' and size <= 8:
                continue  # BIOS call stubs
            i = bisect.bisect_right(starts, address) - 1
            path = ranges[i][2] if i >= 0 and address < ranges[i][1] else None
            subsystem = path.split('/')[1] if path and path.startswith('src/') else None
            decompiled = bool(path) and subsystem != 'AssemblyFallback'
            debt = ('undecompiled' if not decompiled else 'address_only' if ADDRESS_ONLY.search(name)
                    else 'mechanical' if MECHANICAL.search(name) and not name.startswith(('_Z', '__sinit_')) else 'named')
            functions.append(dict(id=f'{module}:{address:08x}', module=module, name=name, address=address,
                                  size=size, source=path, source_subsystem=subsystem, debt=debt))
    return functions


def assign_chunks(functions, chunk_map):
    ranges = collections.defaultdict(list)
    for chunk in chunk_map['chunks']:
        for r in chunk['ranges']:
            ranges[r['module']].append((int(r['start'], 16), int(r['end'], 16), chunk['id']))
    for module in ranges:
        ranges[module].sort()
    for f in functions:
        rs = ranges.get(f['module'], [])
        i = bisect.bisect_right([r[0] for r in rs], f['address']) - 1
        f['chunk'] = rs[i][2] if i >= 0 and f['address'] < rs[i][1] else 'UNMAPPED'


def folder_for(root, module, address, chunk_map=None):
    """Preferred feature directory owning module:address, or None."""
    chunk_map = chunk_map or json.loads((Path(root) / 'docs/subsystem-map-usa.json').read_text())
    for chunk in chunk_map['chunks']:
        for r in chunk['ranges']:
            if r['module'] == module and int(r['start'], 16) <= address < int(r['end'], 16):
                return chunk.get('source_directory') or chunk['folder']
    return None


def summarize(functions, chunk_map):
    rows = collections.OrderedDict((c['id'], dict(chunk=c['id'], subsystem=c['subsystem'], title=c['title'], source_directory=c.get('source_directory'),
                                                  modules=[], **dict.fromkeys(COLUMNS, 0))) for c in chunk_map['chunks'])
    for f in functions:
        row = rows.setdefault(f['chunk'], dict(chunk=f['chunk'], subsystem='-', title='-', source_directory=None, modules=[], **dict.fromkeys(COLUMNS, 0)))
        if f['module'] not in row['modules']:
            row['modules'].append(f['module'])
        row['functions'] += 1
        row[f['debt']] += 1
        if f['debt'] == 'undecompiled':
            row['undecompiled_bytes'] += f['size']
        elif f['source_subsystem'] == 'Unclassified':
            row['unclassified_dir'] += 1
    return list(rows.values())


def referenced_strings(root, functions):
    """Map function id -> C-string literals loaded through its literal pool (ROM data, not source)."""
    import yaml
    extract = root / 'extract/usa'
    images = {'main': (0x02000000, (extract / 'arm9/arm9.bin').read_bytes())}
    for o in yaml.safe_load((extract / 'arm9_overlays/overlays.yaml').read_text())['overlays']:
        images[f'overlay({o["id"]})'] = (o['base_address'], (extract / 'arm9_overlays' / o['file_name']).read_bytes())
    by_module = collections.defaultdict(list)
    for f in functions:
        by_module[f['module']].append(f)
    result = collections.defaultdict(list)
    for module, d in module_dirs(root).items():
        fs = sorted(by_module[module], key=lambda f: f['address'])
        starts = [f['address'] for f in fs]
        for line in (d / 'relocs.txt').read_text().splitlines() if (d / 'relocs.txt').exists() else []:
            m = LOAD.match(line)
            if not m or m[3] not in images:
                continue
            base, data = images[m[3]]
            offset = int(m[2], 16) - base
            end = data.find(b'\0', offset, offset + 200) if 0 <= offset < len(data) else -1
            raw = data[offset:end] if end - offset >= 4 else b''
            if not raw or not all(32 <= c < 127 for c in raw) or not re.search(rb'[A-Za-z]{3}', raw):
                continue
            i = bisect.bisect_right(starts, int(m[1], 16)) - 1
            if i >= 0 and raw.decode() not in result[fs[i]['id']]:
                result[fs[i]['id']].append(raw.decode())
    return result


def packet(root, functions, chunk_id):
    members = {f['id']: f for f in functions if f['chunk'] == chunk_id}
    names = {f['id']: f for f in functions}
    calls_out, calls_in = collections.defaultdict(set), collections.defaultdict(set)
    db = sqlite3.connect(root / 'inventory/functions.sqlite')
    for caller, callee in db.execute('SELECT caller_id, callee_id FROM relationships WHERE ambiguous = 0'):
        if caller in members and callee in names:
            calls_out[caller].add(callee)
        if callee in members and caller in names:
            calls_in[callee].add(caller)
    strings = referenced_strings(root, functions)
    def ref(i):
        return dict(id=i, name=names[i]['name'], chunk=names[i]['chunk'])
    entries = [dict(f, strings=strings.get(i, []), callees=[ref(c) for c in sorted(calls_out[i])],
                    callers=[ref(c) for c in sorted(calls_in[i])]) for i, f in sorted(members.items())]
    external = collections.Counter(c['chunk'] for e in entries for c in e['callees'] + e['callers'] if c['chunk'] != chunk_id)
    return dict(chunk=chunk_id, functions=entries, neighbouring_chunks=dict(external.most_common()),
                caveat='Call edges come from inventory/functions.sqlite (ROM-derived, static, ambiguous overlay targets excluded, incomplete for '
                       'indirect calls). Membership is a proposal; confirm boundaries from complete bodies.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--map', type=Path, help='chunk map (default docs/subsystem-map-usa.json)')
    parser.add_argument('--output', type=Path, help='write the summary (or packet) JSON here')
    parser.add_argument('--packet', metavar='CHUNK', help='emit a work packet for one chunk')
    args = parser.parse_args()
    root = args.project.resolve()
    chunk_map = json.loads((args.map or root / 'docs/subsystem-map-usa.json').read_text())
    functions = inventory(root)
    assign_chunks(functions, chunk_map)
    if args.packet:
        result = packet(root, functions, args.packet)
        print(json.dumps(dict(chunk=args.packet, functions=len(result['functions']),
                              neighbouring_chunks=result['neighbouring_chunks'])))
    else:
        rows = summarize(functions, chunk_map)
        result = dict(scope='ARM9 main, ITCM and overlays; ARM7 excluded', chunks=rows,
                      totals={c: sum(r[c] for r in rows) for c in COLUMNS})
        print(f"{'chunk':14}{'fn':>6}{'named':>6}{'mech':>6}{'addr':>6}{'undec':>6}{'uncl':>6}  title")
        for r in rows:
            print(f"{r['chunk']:14}{r['functions']:6}{r['named']:6}{r['mechanical']:6}{r['address_only']:6}"
                  f"{r['undecompiled']:6}{r['unclassified_dir']:6}  {r['title']}")
        print('totals', json.dumps(result['totals']))
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=1) + '\n')


if __name__ == '__main__':
    main()
