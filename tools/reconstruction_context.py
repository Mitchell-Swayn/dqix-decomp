#!/usr/bin/env python3
"""Evidence-backed reconstruction context, readiness and bounded worker packages."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

KINDS = ('signature', 'type', 'layout', 'global', 'interface', 'note')
STATES = ('known', 'partial', 'unresolved')
DEFAULT_LEDGER = 'config/reconstruction-context.json'


def digest(data):
    return hashlib.sha256(data).hexdigest()


def local(root, value):
    path = (root / value).resolve()
    if not path.is_relative_to(root.resolve()):
        raise ValueError('Context path leaves workspace: ' + str(value))
    return path


def empty():
    return {'schema_version': 1, 'resources': {}, 'functions': {}}


def load(root, path=None):
    path = local(root, path or DEFAULT_LEDGER)
    raw = path.read_bytes() if path.exists() else None
    data = json.loads(raw) if raw else empty()
    if data.get('schema_version') != 1:
        raise ValueError('Unsupported context ledger version')
    for rid, resource in data['resources'].items():
        if resource['kind'] not in KINDS or resource['state'] not in STATES:
            raise ValueError('Invalid context resource: ' + rid)
        if not 1 <= resource.get('importance', 1) <= 5:
            raise ValueError('Context importance must be 1..5: ' + rid)
        validate_refs(root, resource.get('evidence', []))
    for fid, entry in data['functions'].items():
        if not isinstance(entry.get('reviewed', False), bool):
            raise ValueError('Invalid reviewed flag: ' + fid)
        for key in ('requires', 'provides'):
            if len(entry.get(key, [])) != len(set(entry.get(key, []))):
                raise ValueError('Duplicate context references: ' + fid)
        validate_refs(root, entry.get('evidence', []))
    return data, digest(raw) if raw else None


def validate_refs(root, refs):
    for ref in refs:
        local(root, ref['path'])
        if not re.fullmatch('[0-9a-f]{64}', ref['sha256']):
            raise ValueError('Invalid evidence hash')
        if ref.get('line', 1) < 1:
            raise ValueError('Evidence lines start at 1')


def refs_current(root, refs):
    return bool(refs) and all(local(root, r['path']).is_file() and
                              digest(local(root, r['path']).read_bytes()) == r['sha256'] for r in refs)


def resource_status(root, ledger, rid):
    resource = ledger['resources'].get(rid)
    if resource is None:
        return {'id': rid, 'state': 'unresolved', 'importance': 1, 'reason': 'not recorded', 'evidence': []}
    result = dict(resource, id=rid)
    if resource['state'] != 'unresolved' and not refs_current(root, resource.get('evidence', [])):
        result.update(state='unresolved', reason='evidence missing or changed')
    return result


def required_ids(graph, fid, ledger):
    # A matched body never implicitly proves its interface contract.
    calls = {e['target'] for e in graph['edges'] if e['source'] == fid}
    return sorted(set(ledger['functions'].get(fid, {}).get('requires', [])) |
                  {'signature:' + callee for callee in calls})


def context_metrics(root, graph, metrics, ledger):
    incoming = {}
    for e in graph['edges']:
        incoming.setdefault(e['target'], set()).add(e['source'])
    outgoing = {}
    for e in graph['edges']:
        outgoing.setdefault(e['source'], set()).add(e['target'])
    requirements = {n['id']: sorted(set(ledger['functions'].get(n['id'], {}).get('requires', [])) |
                                   {'signature:' + c for c in outgoing.get(n['id'], set())}) for n in graph['nodes']}
    consumers = {}
    statuses = {rid: resource_status(root, ledger, rid) for rid in {rid for ids in requirements.values() for rid in ids}}
    for fid, ids in requirements.items():
        if metrics[fid]['matched_source']:
            continue
        for rid in ids:
            if statuses[rid]['state'] != 'known':
                consumers.setdefault(rid, set()).add(fid)
    result = {}
    for n in graph['nodes']:
        fid = n['id']; entry = ledger['functions'].get(fid, {})
        assessed = entry.get('reviewed', False) and refs_current(root, entry.get('evidence', []))
        resources = [statuses[rid] for rid in requirements[fid]]
        blockers = [r for r in resources if r['state'] != 'known']
        burden = sum(r.get('importance', 1) * (1 if r['state'] == 'partial' else 2) for r in blockers)
        unlocks = set(incoming.get(fid, set()))
        for rid in entry.get('provides', []):
            unlocks.update(consumers.get(rid, set()))
        unlocks.discard(fid)
        unlocks = {x for x in unlocks if not metrics[x]['matched_source']}
        ready = bool(assessed and not blockers and metrics[fid]['callees_ready'])
        result[fid] = dict(context_assessed=bool(assessed), context_ready=ready,
                           context_status='ready' if ready else 'blocked' if assessed else 'unassessed',
                           context_requirements=requirements[fid], context_blockers=[r['id'] for r in blockers],
                           context_blocker_weight=burden, context_known=sum(r['state']=='known' for r in resources),
                           context_partial=sum(r['state']=='partial' for r in resources),
                           context_unresolved=sum(r['state']=='unresolved' for r in resources),
                           context_unlocks=len(unlocks), context_unlock_ids=sorted(unlocks))
    return result


def source_owners(root, report, graph):
    from dependency_rank import source_ranges
    ranges = source_ranges(root); result = {}
    by_name = {}
    for n in graph['nodes']:
        if n.get('matched_source'):
            by_name.setdefault(n['name'], []).append(n)
    for unit in report['units']:
        source = unit.get('metadata', {}).get('source_path', '').replace('\\', '/')
        for f in unit.get('functions', []):
            if f.get('fuzzy_match_percent') != 100:
                continue
            for n in by_name.get(f['name'], []):
                if int(f['size']) == n['size'] and any(
                        mod == n['module'] and start <= n['address'] and n['address'] + n['size'] <= end
                        for mod, start, end in ranges.get(source, [])):
                    result[n['id']] = source
    arm7 = root / 'build/usa/arm7/report.json'
    if arm7.exists():
        for unit in json.loads(arm7.read_text()).get('units', []):
            for n in graph['nodes']:
                if n.get('matched_source') and n['module'] == 'arm7/' + unit.get('autoload', '') and unit.get('symbols', {}).get(n['name']) == n['address']:
                    result[n['id']] = unit['source']
    return result


def included_headers(root, paths, limit=24):
    queue = list(paths); seen = set(); result = []
    while queue and len(result) < limit:
        name = queue.pop(0)
        if name in seen:
            continue
        seen.add(name); p = local(root, name)
        if not p.is_file():
            continue
        for target in re.findall(r'^\s*#\s*include\s*[<"]([^>"\n]+)', p.read_text(errors='replace'), re.M):
            for candidate in (p.parent / target, root / 'include' / target):
                if candidate.resolve().is_relative_to(root.resolve()) and candidate.is_file():
                    rel = candidate.relative_to(root).as_posix()
                    if rel not in seen and rel not in result:
                        result.append(rel); queue.append(rel)
                    break
    return result[:limit]


def relocation_rows(root, row, cache):
    # Use exact symbol-relative relocation offsets, never literal-pool names.
    obj = root / 'build/usa/delinks' / (row['fallback_unit'] + '.o')
    if not obj.is_file():
        return {'status': 'unavailable', 'reason': 'original target object absent', 'path': str(obj.relative_to(root))}
    key = str(obj)
    if key not in cache:
        try:
            syms = subprocess.run(['readelf', '-sW', str(obj)], capture_output=True, text=True, check=True).stdout
            rels = subprocess.run(['readelf', '-rW', str(obj)], capture_output=True, text=True, check=True).stdout
            cache[key] = (syms, rels)
        except (OSError, subprocess.CalledProcessError) as error:
            cache[key] = {'status': 'unavailable', 'reason': str(error)}
    found = cache[key]
    if isinstance(found, dict):
        return found
    syms, rels = found
    symbol = next((line.split() for line in syms.splitlines() if len(line.split()) >= 8 and line.split()[7] == row['name']), None)
    if not symbol or symbol[3] != 'FUNC' or int(symbol[2]) != row['size']:
        return {'status': 'unavailable', 'reason': 'symbol boundary differs or is absent'}
    start = int(symbol[1], 16); section = symbol[6]
    # readelf -SW maps section number to name; avoid mixing equal offsets in other sections.
    try:
        sections = subprocess.run(['readelf', '-SW', str(obj)], capture_output=True, text=True, check=True).stdout
    except (OSError, subprocess.CalledProcessError) as error:
        return {'status': 'unavailable', 'reason': str(error)}
    match = re.search(r'\[\s*' + re.escape(section) + r'\]\s+(\S+)', sections)
    if not match:
        return {'status': 'unavailable', 'reason': 'symbol section not found'}
    active = False; rows = []
    for line in rels.splitlines():
        heading = re.match(r"Relocation section '([^']+)'", line)
        if heading:
            active = heading[1] in ('.rel' + match[1], '.rela' + match[1])
        fields = line.split()
        if active and len(fields) >= 5 and re.fullmatch('[0-9a-fA-F]+', fields[0]):
            offset = int(fields[0], 16)
            if start <= offset < start + row['size']:
                rows.append({'function_offset': offset-start, 'type': fields[2], 'target': fields[4], 'entry': line.strip()})
    return {'status': 'available', 'object': str(obj.relative_to(root)), 'object_sha256': digest(obj.read_bytes()), 'entries': rows}


def packages(root, report, graph, rows, output, ledger_path=None, db=None):
    ledger, ledger_hash = load(root, ledger_path)
    owners = source_owners(root, report, graph)
    nodes = {n['id']: n for n in graph['nodes']}; cache = {}; index = []
    output.mkdir(parents=True, exist_ok=True)
    relocations = {r['function_id']: relocation_rows(root,r,cache) for r in rows}
    symbols = {e['target'] for rel in relocations.values() for e in rel.get('entries', [])}
    symbol_refs = {symbol: [] for symbol in symbols}
    if symbols:
        pattern = re.compile(r'(?<![A-Za-z0-9_])(' + '|'.join(re.escape(x) for x in sorted(symbols)) + r')(?![A-Za-z0-9_])')
        for directory in ('src','include'):
            for path in sorted((root/directory).rglob('*')):
                if path.is_file() and path.suffix in ('.c','.cpp','.h','.hpp'):
                    for line_number,line in enumerate(path.read_text(errors='replace').splitlines(),1):
                        for hit in pattern.finditer(line):
                            refs=symbol_refs[hit[1]]
                            if len(refs)<8:
                                refs.append({'path':path.relative_to(root).as_posix(),'line':line_number})
    for row in rows:
        fid = row['function_id']; entry = ledger['functions'].get(fid, {})
        required = required_ids(graph, fid, ledger)
        resources = [resource_status(root, ledger, rid) for rid in required]
        callees = sorted({e['target'] for e in graph['edges'] if e['source'] == fid})
        paths = sorted({owners[c] for c in callees if c in owners} |
                       {ref['path'] for r in resources for ref in r.get('evidence', [])} |
                       {ref['path'] for ref in entry.get('evidence', [])})
        discovered = [ref for e in relocations[fid].get('entries', []) for ref in symbol_refs.get(e['target'], [])]
        paths += sorted({ref['path'] for ref in discovered} - set(paths))
        paths += [p for p in included_headers(root, paths) if p not in paths]
        snippets = []; budget = 48000
        for name in paths:
            p = local(root, name)
            if not p.is_file():
                snippets.append({'path': name, 'missing': True}); continue
            raw = p.read_bytes(); lines = raw.decode(errors='replace').splitlines()
            starts = [ref.get('line', 1) for r in resources for ref in r.get('evidence', []) if ref['path'] == name]
            starts += [ref['line'] for ref in discovered if ref['path']==name]
            for c in callees:
                if owners.get(c)==name:
                    for line_number,line in enumerate(lines,1):
                        if ('func_' + f"{nodes[c]['address']:08x}") in line or nodes[c]['name'] in line:
                            starts.append(line_number); break
            start = min(starts, default=1)
            excerpts=[]
            for anchor in sorted(set(starts or [1]))[:4]:
                excerpts.append({'start_line':max(1,anchor-7), 'text':'\n'.join(lines[max(0,anchor-8):anchor+65])})
            text='\n\n'.join(f"// {name}:{e['start_line']}\n{e['text']}" for e in excerpts)
            clip = text[:min(6000, max(0, budget))]; budget -= len(clip)
            snippets.append({'path': name, 'sha256': digest(raw), 'start_line': max(1,start-7),
                             'excerpt': clip, 'truncated': len(clip)<len(text) or len(lines)>start+100,
                             'availability_is_not_reviewed_context': True})
        package = {'schema_version': 1, 'function': row, 'context_ledger_sha256': ledger_hash,
                   'report_sha256': graph['metadata'].get('report_sha256'),
                   'requirements_reviewed': row.get('context_assessed', False), 'resources': resources,
                   'callees': [{'id': c, 'name': nodes[c]['name'], 'matched_source': nodes[c].get('matched_source', False),
                                'source_path': owners.get(c)} for c in callees],
                   'files': snippets, 'relocations': relocations[fid],
                   'symbol_reference_hints': discovered,
                   'unknowns': {'unresolved_calls':row.get('unresolved_callees'), 'ambiguous_calls':row.get('ambiguous_callees')},
                   'limits': 'Local include discovery is a hint, not proof of type/layout recovery. Excerpts are bounded; use hashed full paths when truncated.'}
        if db is not None:
            original = db.execute('SELECT assembly,original_sha256 FROM functions WHERE id=?',(fid,)).fetchone()
            if original is None or original['original_sha256']!=row['original_sha256']:
                raise ValueError('Context package original identity differs')
            package['original_assembly']=original['assembly']
        name = fid.replace('/', '_').replace(':', '_') + '.json'
        data = (json.dumps(package, indent=2)+'\n').encode(); (output/name).write_bytes(data)
        row['context_package'] = str((output/name).resolve())
        index.append({'function_id':fid,'path':name,'sha256':digest(data)})
    (output/'index.json').write_text(json.dumps({'schema_version':1,'packages':index},indent=2)+'\n')
    return index


def snapshot_refs(root, values):
    refs = []
    for value in values:
        name, sep, line = value.rpartition(':')
        if not sep or not line.isdigit(): name, line = value, '1'
        p = local(root, name)
        refs.append({'path':p.relative_to(root).as_posix(),'line':int(line),'sha256':digest(p.read_bytes())})
    validate_refs(root, refs)
    return refs


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--project',type=Path,default=Path('.'));p.add_argument('--ledger',default=DEFAULT_LEDGER)
    sub=p.add_subparsers(dest='command',required=True)
    r=sub.add_parser('resource');r.add_argument('id');r.add_argument('--kind',choices=KINDS,required=True);r.add_argument('--state',choices=STATES,required=True);r.add_argument('--importance',type=int,default=1);r.add_argument('--evidence',action='append',default=[]);r.add_argument('--note',required=True)
    f=sub.add_parser('function');f.add_argument('id');f.add_argument('--requires',action='append',default=[]);f.add_argument('--provides',action='append',default=[]);f.add_argument('--evidence',action='append',default=[]);f.add_argument('--reviewed',action='store_true');f.add_argument('--note',default='')
    a=p.parse_args(argv)
    try:
        root=a.project.resolve();ledger,_=load(root,a.ledger);refs=snapshot_refs(root,a.evidence)
        if a.command=='resource':
            if not 1<=a.importance<=5:raise ValueError('Importance must be 1..5')
            if a.state!='unresolved' and not refs:raise ValueError('Known/partial context requires evidence')
            ledger['resources'][a.id]={'kind':a.kind,'state':a.state,'importance':a.importance,'evidence':refs,'note':a.note}
        else:
            if a.reviewed and not refs:raise ValueError('Reviewed function requirements require evidence')
            if any(r not in ledger['resources'] for r in a.requires+a.provides):raise ValueError('Record referenced resources first')
            ledger['functions'][a.id]={'reviewed':a.reviewed,'requires':sorted(set(a.requires)),'provides':sorted(set(a.provides)),'evidence':refs,'note':a.note}
        path=local(root,a.ledger);path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(ledger,indent=2)+'\n')
        print(json.dumps({'status':'recorded','ledger':str(path),'id':a.id}));return 0
    except (OSError,ValueError,KeyError,TypeError) as error:
        print(json.dumps({'status':'error','error':str(error)}));return 2


if __name__=='__main__':sys.exit(main())
