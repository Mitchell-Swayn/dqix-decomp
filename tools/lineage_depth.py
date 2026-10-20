"""Earliest dependency layers, with recursive components treated as work groups.

An edge points from caller to callee. This is NOT shortest distance to a leaf:
all dependencies must precede their caller. Cyclic groups cannot be sequenced
internally using call dependencies alone. Uses iterative traversal for deep graphs.
"""
from bisect import bisect_right
from collections import Counter, deque
import csv
import json
from pathlib import Path


def annotate(graph):
    nodes = graph['nodes']
    index = {node['id']:i for i,node in enumerate(nodes)}
    outgoing = [set() for _ in nodes]
    incoming = [set() for _ in nodes]
    uncertain = [False]*len(nodes)
    ambiguity = [False]*len(nodes)
    for edge in graph['edges']:
        a, b = index[edge['source']], index[edge['target']]
        outgoing[a].add(b); incoming[b].add(a)
        ambiguity[a] |= edge.get('ambiguous',False)
    for site in graph.get('indirect',[]):
        uncertain[index[site['source']]] = True
    # Map unresolved direct transfers back to their inventoried caller.
    modules = {}
    for i,node in enumerate(nodes): modules.setdefault(node['module'],[]).append(i)
    for module, items in modules.items():
        items.sort(key=lambda i:nodes[i]['address'])
        modules[module] = ([nodes[i]['address'] for i in items],items)
    for site in graph.get('unresolved',[]):
        starts, items = modules.get(site['module'],([],[]))
        pos = bisect_right(starts,site['site'])-1
        if pos >= 0:
            i=items[pos]
            if site['site'] < nodes[i]['address']+nodes[i]['size']: uncertain[i]=True
    # Kosaraju: explicit DFS frames, then reverse-graph flood fill.
    visited=set(); finish=[]
    for root in range(len(nodes)):
        if root in visited: continue
        visited.add(root); stack=[(root,iter(sorted(outgoing[root])))]
        while stack:
            current, children = stack[-1]
            child=next(children,None)
            if child is None:
                finish.append(current); stack.pop()
            elif child not in visited:
                visited.add(child); stack.append((child,iter(sorted(outgoing[child]))))
    component=[-1]*len(nodes); groups=[]
    for root in reversed(finish):
        if component[root]>=0: continue
        cid=len(groups); members=[]; stack=[root]; component[root]=cid
        while stack:
            current=stack.pop(); members.append(current)
            for child in incoming[current]:
                if component[child]<0: component[child]=cid; stack.append(child)
        groups.append(sorted(members,key=lambda i:nodes[i]['id']))
    deps=[set() for _ in groups]; parents=[set() for _ in groups]
    cycles=[len(g)>1 or g[0] in outgoing[g[0]] for g in groups]
    unknown=[any(uncertain[i] for i in g) for g in groups]
    possible=[any(ambiguity[i] for i in g) for g in groups]
    for a in range(len(nodes)):
        for b in outgoing[a]:
            ca,cb=component[a],component[b]
            if ca!=cb: deps[ca].add(cb); parents[cb].add(ca)
    remaining=[len(d) for d in deps]; layers=[1]*len(groups)
    reach_cycle=cycles.copy(); reach_unknown=unknown.copy(); reach_ambiguous=possible.copy()
    pending=deque(i for i,d in enumerate(remaining) if d==0); processed=0
    while pending:
        child=pending.popleft(); processed+=1
        for parent in parents[child]:
            layers[parent]=max(layers[parent],layers[child]+1)
            reach_cycle[parent] |= reach_cycle[child]
            reach_unknown[parent] |= reach_unknown[child]
            reach_ambiguous[parent] |= reach_ambiguous[child]
            remaining[parent]-=1
            if not remaining[parent]: pending.append(parent)
    assert processed==len(groups)
    records=[]
    for cid,members in enumerate(groups):
        gid=nodes[members[0]]['id']
        records.append(dict(id=gid,layer=layers[cid],recursive=cycles[cid],members=[nodes[i]['id'] for i in members],
                            dependencies=sorted(nodes[groups[d][0]]['id'] for d in deps[cid])))
        for i in members:
            nodes[i]['lineage']=dict(layer=layers[cid],group=gid,group_size=len(members),recursive=cycles[cid],
                                      reaches_cycle=reach_cycle[cid],unresolved_callees=uncertain[i],
                                      unresolved_downstream=reach_unknown[cid],ambiguous_downstream=reach_ambiguous[cid])
    graph['dependency_groups']=sorted(records,key=lambda g:(g['layer'],g['id']))
    summary=dict(functions=len(nodes),groups=len(groups),recursive_groups=sum(cycles),
                 functions_in_cycles=sum(len(g) for g,c in zip(groups,cycles) if c),max_layer=max(layers,default=0),
                 functions_by_layer=dict(sorted(Counter(n['lineage']['layer'] for n in nodes).items())),
                 functions_with_unresolved_downstream=sum(n['lineage']['unresolved_downstream'] for n in nodes))
    graph.setdefault('metadata',{})['lineage']=dict(summary=summary,
        definition='Minimum dependency-safe layer: 1 + maximum callee-group layer; leaf groups are layer 1. Recursive components share a layer.',
        caveat='Computed from known static edges, including possible overlay targets. Unknown targets may change layers. Members of recursive groups require joint analysis; no internal dependency-safe order exists.')
    return summary


def write_order(graph, destination):
    with destination.open('w',newline='',encoding='utf-8') as stream:
        writer=csv.writer(stream)
        writer.writerow(['layer','module','function','address','group','group_size','recursive','unresolved_downstream','ambiguous_downstream'])
        for node in sorted(graph['nodes'],key=lambda n:(n['lineage']['layer'],n['lineage']['group'],n['id'])):
            l=node['lineage']; writer.writerow([l['layer'],node['module'],node['name'],f"0x{node['address']:08X}",l['group'],l['group_size'],l['recursive'],l['unresolved_downstream'],l['ambiguous_downstream']])


if __name__=='__main__':
    root=Path(__file__).resolve().parents[1]; directory=root/'build/call-graph'
    graph=json.loads((directory/'graph.json').read_text(encoding='utf-8'))
    print(json.dumps(annotate(graph)))
    (directory/'graph.json').write_text(json.dumps(graph,separators=(',',':')),encoding='utf-8')
    write_order(graph,directory/'decompilation-order.csv')
    template=(root/'tools/call_graph_viewer.html').read_text(encoding='utf-8')
    (directory/'index.html').write_text(template.replace('/*GRAPH_DATA*/',json.dumps(graph,separators=(',',':')).replace('</','<\\/')),encoding='utf-8')
