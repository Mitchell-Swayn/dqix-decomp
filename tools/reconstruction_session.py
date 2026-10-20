#!/usr/bin/env python3
"""Select small reconstruction batches, accepting verified work before reranking."""
import argparse
import hashlib
import json
from pathlib import Path
import sys
import sqlite3

from dependency_rank import DEFAULT_RANK, ranked_queue, current_completion
from evidence_store import connect
from reconstruction_context import digest, local, packages
from select_candidates import select
from audit_link_layout import audit

ROM_SHA1 = 'c7c3014c237900c8281289b8bc76a781969b6278'


def write(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    temp=path.with_suffix(path.suffix+'.tmp');temp.write_text(json.dumps(data,indent=2)+'\n');temp.replace(path)


def report_snapshot(root, name):
    p=local(root,name);raw=p.read_bytes();return json.loads(raw),digest(raw)


def denominators(report):
    return {k:int(report['measures'][k]) for k in ('total_code','total_data','total_functions')}


def create(root, report, scope, total, batch_size, policy, report_path, context_path):
    if not 1<=batch_size<=20 or not 1<=total<=len(scope):
        raise ValueError('Batch size must be 1..20; total must fit the scope')
    ids=[f['function_id'] for f in scope]
    if len(ids)!=len(set(ids)):raise ValueError('Duplicate scope IDs')
    return {'schema_version':1,'scope':scope,'total':total,'batch_size':batch_size,'policy':policy,
            'report':report_path,'context_ledger':context_path,'denominators':denominators(report),
            'completed_ids':[],'history':[],'pending':None}


def next_batch(root, db, state, directory):
    report,report_hash=report_snapshot(root,state['report'])
    if denominators(report)!=state['denominators']:raise ValueError('Coverage denominators changed')
    if state['pending']:
        return {'status':'pending','manifest':state['pending']['manifest'],'functions':len(state['pending']['ids'])}
    remaining=state['total']-len(state['completed_ids'])
    if remaining==0:return {'status':'complete','verified_functions':len(state['completed_ids'])}
    scope=[r for r in state['scope'] if r['function_id'] not in state['completed_ids']]
    rows,graph=ranked_queue(db,root,report,scope,state['policy'],state['context_ledger'])
    # External completion must be explicitly reconciled, never silently credited.
    if any(r['matched_source'] for r in rows):raise ValueError('Scope changed outside session; reconcile externally completed functions')
    rows=rows[:min(remaining,state['batch_size'])]
    graph['metadata']['report_sha256']=report_hash
    number=len(state['history'])+1;batch=directory/f'batch-{number:03d}'
    packages(root,report,graph,rows,batch/'context',state['context_ledger'],db)
    manifest=batch/'assignment.json'
    write(manifest,{'schema_version':3,'report_sha256':report_hash,'graph_sha256':graph['metadata']['graph_sha256'],
                    'context_ledger_sha256':graph['metadata']['context_ledger_sha256'],
                    'ranking':dict(graph['metadata']['ranking'],dynamic_batch_readiness=True),'functions':rows})
    state['pending']={'ids':[r['function_id'] for r in rows],'manifest':str(manifest.relative_to(root)),
                      'report_sha256':report_hash}
    return {'status':'selected','functions':len(rows),'manifest':str(manifest),'context':str(batch/'context')}


def verify_acceptance(root, state, manifest_path, comparison_path):
    pending=state['pending'];assignment=json.loads(local(root,pending['manifest']).read_text())['functions']
    manifest=json.loads(local(root,manifest_path).read_text())
    rows=manifest['functions'];expected={r['function_id']:r for r in assignment}
    if len(rows)!=len(expected) or {r['function_id'] for r in rows}!=set(expected):raise ValueError('Acceptance manifest differs from pending assignment')
    for r in rows:
        if any(r.get(k)!=expected[r['function_id']].get(k) for k in ('name','address','size','module')):
            raise ValueError('Accepted function boundary differs')
    summary=json.loads(local(root,comparison_path).read_text())
    if not summary.get('match') or summary.get('errors',0) or summary.get('status')!='compared':raise ValueError('Comparison did not pass')
    artifacts=local(root,summary['artifacts']);units=json.loads((artifacts/'units.json').read_text())
    if len(units)!=len(manifest['units']) or {u['unit'] for u in units}!=set(manifest['units']):raise ValueError('Compared units differ from acceptance manifest')
    objdiff=json.loads((root/'objdiff.json').read_text());lookup={u['name']:u for u in objdiff['units']}
    from match_unit import object_paths
    for u in units:
        if not u.get('object_match') or not u.get('match'):raise ValueError('Object match missing')
        unit=lookup[u['unit']];source=local(root,unit['metadata']['source_path']);evidence=local(root,u['artifacts'])
        snapshot=evidence/('candidate'+source.suffix)
        if snapshot.read_bytes()!=source.read_bytes():raise ValueError('Source changed since comparison')
        target,candidate=object_paths(root,unit)
        if digest(target.read_bytes())!=u['target_sha256_before'] or digest(candidate.read_bytes())!=u['candidate_sha256_before']:
            raise ValueError('Object changed since comparison')
        raw=json.loads((evidence/'bytes.json').read_text())
        if not raw.get('functions'):raise ValueError('Missing raw function evidence')
        for f in raw['functions']:
            if f.get('raw_match') is not True and not (f.get('raw_match') is None and f.get('relocations_present')):
                raise ValueError('Raw mismatch or unexplained inconclusive bytes')
    report,report_hash=report_snapshot(root,state['report'])
    if denominators(report)!=state['denominators']:raise ValueError('Coverage denominators changed')
    if report_hash==pending['report_sha256']:raise ValueError('Report not refreshed after integration')
    nodes=[dict(id=r['function_id'],name=r['name'],module=r['module'] if '/' in r['module'] else 'arm9/'+r['module'],
                address=int(r['address'],16),size=r['size']) for r in rows]
    completed=current_completion(root,report,nodes)
    if completed!=set(expected):raise ValueError('Integrated report does not match every pending function')
    modules={r['module'] for r in rows}
    if modules!={'main'} and modules!={'arm9/main'}:raise ValueError('Session integrated acceptance currently supports ARM9 main only')
    layout=audit(root/'build/usa/arm9.o',rows)
    if not layout['match']:raise ValueError('Linked layout differs')
    rom=local(root,'dqix_usa.nds')
    with rom.open('rb') as f:
        sha=hashlib.sha1()
        for block in iter(lambda:f.read(1024*1024),b''):sha.update(block)
    if sha.hexdigest()!=ROM_SHA1:raise ValueError('ROM SHA1 differs')
    return {'ids':sorted(expected),'report_sha256':report_hash,'comparison_sha256':digest(local(root,comparison_path).read_bytes()),
            'layout':layout,'rom_sha1':sha.hexdigest()}


def accept(root,state,manifest,comparison):
    if not state['pending']:raise ValueError('No pending batch')
    receipt=verify_acceptance(root,state,manifest,comparison)
    state['completed_ids']+=receipt['ids'];state['history'].append(receipt);state['pending']=None
    return {'status':'accepted','verified_functions':len(state['completed_ids']),'remaining':state['total']-len(state['completed_ids'])}


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--project',type=Path,default=Path('.'));p.add_argument('--db',default='build/evidence/functions.sqlite');p.add_argument('--session',required=True)
    sub=p.add_subparsers(dest='command',required=True)
    n=sub.add_parser('next');n.add_argument('--scope',help='Optional fixed assignment; all its functions remain required');n.add_argument('--total',type=int,default=100);n.add_argument('--batch-size',type=int,default=20);n.add_argument('--module',default='main');n.add_argument('--min-bytes',type=int,default=8);n.add_argument('--max-bytes',type=int,default=512);n.add_argument('--rank-by',default=DEFAULT_RANK);n.add_argument('--report',default='build/usa/report.json');n.add_argument('--context-ledger')
    a=sub.add_parser('accept');a.add_argument('--manifest',required=True);a.add_argument('--comparison',required=True)
    sub.add_parser('status');args=p.parse_args(argv)
    try:
        root=args.project.resolve();directory=local(root,args.session);path=directory/'session.json'
        if path.exists():state=json.loads(path.read_text())
        elif args.command!='next':raise ValueError('Session not created')
        else:
            report,_=report_snapshot(root,args.report)
            if args.scope:
                scope=json.loads(local(root,args.scope).read_text())['functions'];total=len(scope)
            else:
                if args.module!='main':raise ValueError('Sessions currently support ARM9 main only')
                scope=select(root,report,args.module,None,args.min_bytes,args.max_bytes);total=args.total
                with connect(local(root,args.db),True) as db:scope,_=ranked_queue(db,root,report,scope,args.rank_by,args.context_ledger)
            state=create(root,report,scope,total,args.batch_size,args.rank_by,args.report,args.context_ledger)
        if args.command=='next':
            with connect(local(root,args.db),True) as db:result=next_batch(root,db,state,directory)
            write(path,state)
        elif args.command=='accept':result=accept(root,state,args.manifest,args.comparison);write(path,state)
        else:result={k:state[k] for k in ('total','batch_size','completed_ids','pending')}
        print(json.dumps(result));return 0
    except (OSError,ValueError,KeyError,TypeError,sqlite3.Error) as error:
        print(json.dumps({'status':'error','error':str(error)}));return 2


if __name__=='__main__':sys.exit(main())
