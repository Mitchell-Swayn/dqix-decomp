"""Rank current fallback candidates using a condensed static call DAG.

Completion is derived from the selected worktree, never inventory snapshots.
Caller -> callee edges include possible targets, with uncertainty preserved.
"""
import hashlib
import json
from pathlib import Path
import re

from lineage_depth import annotate

CRITERIA = ('context', 'unlocks', 'readiness', 'downstream', 'callers', 'size', 'depth')
DEFAULT_RANK = 'context,readiness,unlocks,size,downstream,depth'


def parse_policy(value):
    names = value.split(',')
    if not names or len(names) != len(set(names)) or any(n not in CRITERIA for n in names):
        raise ValueError('rank-by must contain unique criteria from: ' + ','.join(CRITERIA))
    return names


def load_graph(db):
    nodes = [dict(r) for r in db.execute(
        'SELECT id,module_id AS module,name,address,size,mode,original_sha256 FROM functions ORDER BY id')]
    edges = [dict(source=r['caller_id'], target=r['callee_id'], kind=r['kind'],
                  ambiguous=bool(r['ambiguous'])) for r in db.execute(
        'SELECT caller_id,callee_id,kind,ambiguous FROM relationships ORDER BY caller_id,callee_id,kind,ambiguous')]
    indirect = [dict(source=r['caller_id'], site=r['instruction_address']) for r in db.execute(
        'SELECT caller_id,instruction_address FROM unresolved_calls WHERE caller_id IS NOT NULL')]
    graph = dict(nodes=nodes, edges=edges, indirect=indirect, unresolved=[])
    graph['metadata'] = {'edge_direction': 'caller -> callee',
                         'completion_source': 'current worktree report and source ownership; inventory completion ignored',
                         'limitations': ['Known static calls and tail transfers only; indirect targets may be missing.',
                                         'Ambiguous possible targets are included conservatively.',
                                         'Inventory scope may be incomplete, especially ARM7.',
                                         'Matched source is a readiness proxy, not proof of recovered types or semantics.']}
    annotate(graph)
    identity = [(n['id'], n['original_sha256']) for n in nodes], edges, indirect
    graph['metadata']['graph_sha256'] = hashlib.sha256(json.dumps(identity, sort_keys=True).encode()).hexdigest()
    graph['metadata']['inventory_created_utc'] = db.execute(
        "SELECT value FROM metadata WHERE key='created_utc'").fetchone()[0]
    return graph


def source_ranges(root):
    result = {}
    for path in sorted((root / 'config/usa/arm9').rglob('delinks.txt')):
        module = 'arm9/' + ('main' if path.parent == root / 'config/usa/arm9' else path.parent.name)
        owner = None
        for line in path.read_text().splitlines():
            if line and not line[0].isspace() and line.endswith(':'):
                owner = line[:-1].replace('\\', '/')
            match = re.search(r'\.(?:text|init)\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)', line)
            if owner and match:
                result.setdefault(owner, []).append((module, int(match[1], 16), int(match[2], 16)))
    return result


def current_completion(root, report, nodes):
    """Resolve current source units to module-qualified original identities."""
    by_name = {}
    for n in nodes:
        by_name.setdefault(n['name'], []).append(n)
    ranges = source_ranges(root)
    completed = set()
    for unit in report['units']:
        meta = unit.get('metadata', {})
        source = meta.get('source_path', '').replace('\\', '/')
        if meta.get('auto_generated') or Path(source).suffix.lower() not in ('.c', '.cpp', '.cc', '.cxx', '.s'):
            continue
        # Require the declared source to exist in this checkout.
        if not (root / source).is_file():
            continue
        for f in unit.get('functions', []):
            if f.get('fuzzy_match_percent') != 100:
                continue
            matches = [n for n in by_name.get(f['name'], []) if n['size'] == int(f['size']) and any(
                module == n['module'] and start <= n['address'] and n['address'] + n['size'] <= end
                for module, start, end in ranges.get(source, []))]
            if len(matches) == 1:
                completed.add(matches[0]['id'])
    # ARM7 completion requires its own current verified source build report.
    path = root / 'build/usa/arm7/report.json'
    if path.exists():
        arm7 = json.loads(path.read_text())
        if arm7.get('module_check_passed') and arm7.get('source_symbol_checks_passed'):
            for unit in arm7.get('units', []):
                if not unit.get('module_check_passed') or not unit.get('symbol_check_passed'):
                    continue
                if Path(unit.get('source', '')).suffix.lower() not in ('.c', '.cpp'):
                    continue
                if not (root / unit['source']).is_file():
                    continue
                for name, address in unit.get('symbols', {}).items():
                    for n in by_name.get(name, []):
                        if n['module'] == 'arm7/' + unit['autoload'] and n['address'] == address:
                            completed.add(n['id'])
    return completed


def graph_metrics(graph, completed):
    groups = graph['dependency_groups']  # Already dependency-first by lineage.
    index = {g['id']: i for i, g in enumerate(groups)}
    nodes = {n['id']: n for n in graph['nodes']}
    outgoing = {n: set() for n in nodes}
    ambiguous = {n: set() for n in nodes}
    for e in graph['edges']:
        outgoing[e['source']].add(e['target'])
        if e.get('ambiguous'):
            ambiguous[e['source']].add(e['target'])
    # Exact reachability sets represented as bitsets: shared descendants counted once.
    descendants, ancestors = [0] * len(groups), [0] * len(groups)
    for i, g in enumerate(groups):
        for dep in g['dependencies']:
            j = index[dep]
            descendants[i] |= descendants[j] | (1 << j)
    for i in reversed(range(len(groups))):
        for dep in groups[i]['dependencies']:
            j = index[dep]
            ancestors[j] |= ancestors[i] | (1 << i)
    sizes = [len(g['members']) for g in groups]
    # Most groups are single functions; only add extra weights for SCCs.
    extra = [(i, size - 1) for i, size in enumerate(sizes) if size > 1]

    def function_count(bits):
        return bits.bit_count() + sum(weight for i, weight in extra if bits & (1 << i))

    metrics = {}
    for n in graph['nodes']:
        l = n['lineage']; i = index[l['group']]
        callees = outgoing[n['id']] - {n['id']}
        matched = callees & completed
        missing = callees - completed
        uncertain = l['unresolved_callees'] or bool(ambiguous[n['id']])
        metrics[n['id']] = dict(
            lineage_depth=l['layer'], dependency_group_id=l['group'],
            dependency_group_size=l['group_size'], recursive=l['recursive'],
            downstream_dependencies=function_count(descendants[i]),
            transitive_callers=function_count(ancestors[i]),
            direct_callees=len(callees), matched_callees=len(matched), unmatched_callees=len(missing),
            callee_completion_ratio=len(matched) / len(callees) if callees else 1.0,
            callees_ready=not missing and not uncertain and not l['recursive'],
            unresolved_callees=l['unresolved_callees'], ambiguous_callees=len(ambiguous[n['id']]),
            unresolved_downstream=l['unresolved_downstream'], ambiguous_downstream=l['ambiguous_downstream'],
            remaining_callee_ids=sorted(missing),
            matched_source=n['id'] in completed)
    for i, g in enumerate(groups):
        g.update(downstream_dependencies=function_count(descendants[i]),
                 transitive_callers=function_count(ancestors[i]),
                 matched_members=sum(n in completed for n in g['members']))
    return metrics


def ranked_queue(db, root, report, candidates, policy=DEFAULT_RANK, context_path=None):
    from runtime_support import excluded
    runtime = excluded(root)
    criteria = parse_policy(policy)
    graph = load_graph(db)
    completed = current_completion(root, report, graph['nodes'])
    metrics = graph_metrics(graph, completed)
    from reconstruction_context import load, context_metrics
    ledger, context_hash = load(root, context_path)
    context = context_metrics(root, graph, metrics, ledger)
    for fid, values in context.items():
        metrics[fid].update(values)
    graph['metadata']['context_ledger_sha256'] = context_hash
    originals = {(n['module'], n['address']): n for n in graph['nodes']}
    rows = []
    for row in candidates:
        module = row['module'] if '/' in row['module'] else 'arm9/' + row['module']
        if (module, int(row['address'], 16)) in runtime:
            continue
        n = originals.get((module, int(row['address'], 16)))
        if not n or (n['name'], n['size']) != (row['name'], row['size']):
            raise ValueError('Candidate differs from original inventory: ' + row['name'])
        if row.get('function_id', n['id']) != n['id'] or row.get('original_sha256', n['original_sha256']) != n['original_sha256']:
            raise ValueError('Candidate identity differs from original inventory: ' + row['name'])
        rows.append(dict(row, function_id=n['id'], original_sha256=n['original_sha256'], **metrics[n['id']]))

    def key(row):
        values = {
            'context': (0 if row['context_ready'] else 1 if row['context_assessed'] else 2,
                        row['context_blocker_weight'] if row['context_assessed'] else 0,
                        row['context_unresolved'] if row['context_assessed'] else 0,
                        row['context_partial'] if row['context_assessed'] else 0),
            'unlocks': (-row['context_unlocks'],),
            'readiness': (not row['callees_ready'], -row['callee_completion_ratio'],
                          row['unresolved_callees'], row['ambiguous_callees'], row['unmatched_callees']),
            'downstream': (-row['downstream_dependencies'],),
            'callers': (-row['transitive_callers'],),
            'size': (row['size'],), 'depth': (row['lineage_depth'],)}
        return tuple(value for criterion in criteria for value in values[criterion]) + (row['function_id'],)

    rows.sort(key=key)
    for rank, row in enumerate(rows, 1):
        row['rank'] = rank
    for n in graph['nodes']:
        n.update(metrics[n['id']])
    graph['metadata']['ranking'] = dict(criteria=criteria, matched_source_functions=len(completed),
                                      eligible_candidates=len(rows), dynamic_batch_readiness=False, context_assessed_functions=sum(v['context_assessed'] for v in metrics.values()),
                                      context_ready_functions=sum(v['context_ready'] for v in metrics.values()))
    return rows, graph


def write_dag(graph, path):
    """Export condensed DAG plus per-function metrics, without binary contents."""
    path.parent.mkdir(parents=True, exist_ok=True)
    document = dict(schema_version=1, metadata=graph['metadata'],
                    groups=graph['dependency_groups'], functions=graph['nodes'],
                    call_edges=graph['edges'])
    path.write_text(json.dumps(document, separators=(',', ':')) + '\n')
