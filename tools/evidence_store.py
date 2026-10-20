#!/usr/bin/env python3
"""Indexed original evidence plus separately versioned, lazy Ghidra analysis.

Completion in the imported inventory is historical. Queue selection uses the
current worktree report. Ghidra output is analysis, never matched-source credit.
"""
import argparse
from contextlib import contextmanager
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import sqlite3
import sys
import time

from inspect_functions import fingerprint, inspect
from select_candidates import select
from dependency_rank import DEFAULT_RANK, ranked_queue, write_dag


def sha(data):
    return hashlib.sha256(data).hexdigest()


@contextmanager
def connect(path, readonly=False):
    db = sqlite3.connect('file:' + str(path.resolve()) + '?mode=' + ('ro' if readonly else 'rw'), uri=True)
    db.row_factory = sqlite3.Row
    try:
        yield db
    finally:
        db.close()


def prepare(source, destination):
    if destination.exists():
        raise ValueError('Refusing to overwrite evidence store')
    destination.parent.mkdir(parents=True, exist_ok=True)
    with connect(source, True) as original:
        if original.execute('PRAGMA integrity_check').fetchone()[0] != 'ok':
            raise ValueError('Inventory integrity check failed')
        for row in original.execute('SELECT id,size,original_bytes,original_sha256 FROM functions'):
            if len(row['original_bytes']) != row['size'] or sha(row['original_bytes']) != row['original_sha256']:
                raise ValueError('Invalid original function bytes: ' + row['id'])
        db = sqlite3.connect(destination)
        original.backup(db)
    db.executescript('''
    CREATE TABLE evidence_provenance(key TEXT PRIMARY KEY,value TEXT NOT NULL);
    CREATE TABLE ghidra_analysis(
      function_id TEXT NOT NULL REFERENCES functions(id),fingerprint TEXT NOT NULL,
      original_sha256 TEXT NOT NULL,imported_utc TEXT NOT NULL,document TEXT NOT NULL,
      PRIMARY KEY(function_id,fingerprint,original_sha256));
    CREATE INDEX ghidra_by_program ON ghidra_analysis(fingerprint);
    ''')
    db.execute('INSERT INTO evidence_provenance VALUES(?,?)', ('inventory_sha256', sha(source.read_bytes())))
    db.execute('INSERT INTO evidence_provenance VALUES(?,?)', ('created_utc', datetime.now(timezone.utc).isoformat()))
    db.commit(); db.close()


def function(db, row):
    module = row['module']
    module = 'arm9/' + module if '/' not in module else module
    found = db.execute('SELECT * FROM functions WHERE module_id=? AND address=?',
                       (module, int(str(row['address']), 16))).fetchone()
    if not found or found['name'] != row['name'] or found['size'] != int(row['size']):
        raise ValueError('Manifest differs from original inventory: ' + row['name'])
    return found


def import_analysis(db, document):
    identity = document['program_fingerprint']
    if len(identity) != 64:
        raise ValueError('Missing program fingerprint')
    imported = 0
    with db:
        for row in document['functions']:
            if row.get('status') != 'inspected':
                continue
            original = function(db, row)
            db.execute('INSERT OR REPLACE INTO ghidra_analysis VALUES(?,?,?,?,?)',
                       (original['id'], identity, original['original_sha256'],
                        datetime.now(timezone.utc).isoformat(), json.dumps(row)))
            imported += 1
    return imported


def cached(db, row, identity):
    original = function(db, row)
    item = db.execute('SELECT document FROM ghidra_analysis WHERE function_id=? AND fingerprint=? AND original_sha256=?',
                      (original['id'], identity, original['original_sha256'])).fetchone()
    return json.loads(item[0]) if item else None


def fetch(db, rows, server, identity, output):
    if fingerprint(server) != identity:
        raise ValueError('Active Ghidra program differs from requested cache identity')
    # This MCP exposes only the active ARM9 program. Overlapping overlay addresses
    # require a separate verified program fingerprint; never reuse ARM9 analysis.
    if any(row['module'] not in ('main', 'itcm', 'arm9/main', 'arm9/itcm') for row in rows):
        raise ValueError('Active-program fetch supports ARM9 main/ITCM only')
    hits = [cached(db, row, identity) for row in rows]
    missing = [row for row, hit in zip(rows, hits) if hit is None]
    if missing:
        document = inspect(server, missing, identity)
        if any(row['status'] != 'inspected' for row in document['functions']):
            raise ValueError('Ghidra inspection failed; no incomplete batch is returned')
        import_analysis(db, document)
    if fingerprint(server) != identity:
        raise ValueError('Active Ghidra program changed during cache fetch')
    result = {'schema_version': 1, 'program_fingerprint': identity,
              'cache_hits': len(rows)-len(missing), 'cache_misses': len(missing),
              'functions': [dict(cached(db, row, identity), **{k: row[k] for k in row if k in (
                  'name','address','size','mode','module','fallback_unit','function_id','original_sha256',
                  'lineage_depth','dependency_group_id','dependency_group_size','recursive',
                  'downstream_dependencies','transitive_callers','direct_callees','matched_callees',
                  'unmatched_callees','callee_completion_ratio','callees_ready','unresolved_callees',
                  'ambiguous_callees','unresolved_downstream','ambiguous_downstream',
                  'remaining_callee_ids','matched_source','rank','context_assessed','context_ready',
                  'context_status','context_requirements','context_blockers','context_blocker_weight',
                  'context_known','context_partial','context_unresolved','context_unlocks','context_unlock_ids','context_package')}) for row in rows]}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2)+'\n')
    return {'functions': len(rows), 'cache_hits': result['cache_hits'], 'cache_misses': len(missing), 'artifacts': str(output)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--db', type=Path, default=Path('build/evidence/functions.sqlite'))
    commands = parser.add_subparsers(dest='command', required=True)
    p=commands.add_parser('prepare');p.add_argument('--inventory',type=Path,default=Path('inventory/functions.sqlite'))
    p=commands.add_parser('import');p.add_argument('inspection',type=Path)
    p=commands.add_parser('fetch');p.add_argument('manifest',type=Path);p.add_argument('--server',required=True);p.add_argument('--fingerprint',required=True);p.add_argument('--output',type=Path,required=True)
    p=commands.add_parser('get');p.add_argument('id');p.add_argument('--fingerprint');p.add_argument('--neighbors',type=int,default=10)
    p=commands.add_parser('queue');p.add_argument('--project',type=Path,default=Path('.'));p.add_argument('--report',default='build/usa/report.json');p.add_argument('--module',default='main');p.add_argument('--limit',type=int,default=100);p.add_argument('--min-bytes',type=int,default=8);p.add_argument('--max-bytes',type=int,default=24);p.add_argument('--output',type=Path,required=True)
    p.add_argument('--rank-by',default=DEFAULT_RANK,help='Ordered criteria: context,readiness,unlocks,size,downstream,callers,depth')
    p.add_argument('--dag-output',type=Path,help='Export all functions and the condensed call DAG with current metrics')
    p.add_argument('--context-ledger',help='Workspace-relative reviewed context ledger')
    p.add_argument('--context-output',type=Path,help='Write bounded worker context packages for selected functions')
    commands.add_parser('stats')
    args=parser.parse_args(); start=time.monotonic()
    try:
        if args.command=='prepare':
            prepare(args.inventory,args.db);result={'status':'prepared'}
        else:
            with connect(args.db,args.command in ('get','queue','stats')) as db:
                if args.command=='import':result={'imported':import_analysis(db,json.loads(args.inspection.read_text()))}
                elif args.command=='fetch':result=fetch(db,json.loads(args.manifest.read_text())['functions'],args.server,args.fingerprint,args.output)
                elif args.command=='stats':
                    result={table:db.execute('SELECT count(*) FROM '+table).fetchone()[0] for table in ('modules','functions','relationships','ghidra_analysis')}
                    result['inventory_is_historical']=True
                elif args.command=='queue':
                    if not 1<=args.limit<=1000 or not 0<args.min_bytes<=args.max_bytes:raise ValueError('Invalid selection limits')
                    root=args.project.resolve();path=root/args.report
                    report_bytes=path.read_bytes();report=json.loads(report_bytes)
                    candidates=select(root,report,args.module,None,args.min_bytes,args.max_bytes)
                    rows,graph=ranked_queue(db,root,report,candidates,args.rank_by,args.context_ledger)
                    if path.read_bytes()!=report_bytes:raise ValueError('Coverage report changed during selection; retry with a stable report')
                    graph['metadata']['report_sha256']=sha(report_bytes)
                    if args.dag_output:write_dag(graph,args.dag_output)
                    rows=rows[:args.limit]
                    if args.context_output:
                        from reconstruction_context import packages
                        packages(root,report,graph,rows,args.context_output,args.context_ledger,db)
                    document={'schema_version':2,'report_sha256':graph['metadata']['report_sha256'],
                              'graph_sha256':graph['metadata']['graph_sha256'],
                              'context_ledger_sha256':graph['metadata']['context_ledger_sha256'],
                              'ranking':graph['metadata']['ranking'],'functions':rows}
                    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(document,indent=2)+'\n')
                    result={'selected':len(rows),'eligible':len(candidates),'ranking':args.rank_by,
                            'artifacts':str(args.output),'dag_artifacts':str(args.dag_output) if args.dag_output else None}
                else:
                    if not 0<=args.neighbors<=100:raise ValueError('Neighbors must be 0..100')
                    f=db.execute('SELECT * FROM functions WHERE id=?',(args.id,)).fetchone()
                    if not f:raise ValueError('Unknown module-qualified function ID')
                    result=dict(f);result['original_bytes']=f['original_bytes'].hex()
                    result['inventory_is_historical']=True
                    result['ghidra_analysis']=None
                    if args.fingerprint:
                        entry=db.execute('SELECT document FROM ghidra_analysis WHERE function_id=? AND fingerprint=? AND original_sha256=?',(f['id'],args.fingerprint,f['original_sha256'])).fetchone()
                        if entry:result['ghidra_analysis']=json.loads(entry[0])
                    for direction,a,b in [('callers','callee_id','caller_id'),('callees','caller_id','callee_id')]:
                        result[direction]=[dict(r) for r in db.execute('SELECT f.id,f.name,r.kind,r.ambiguous FROM relationships r JOIN functions f ON f.id=r.'+b+' WHERE r.'+a+'=? LIMIT ?',(f['id'],args.neighbors))]
        result['elapsed_seconds']=time.monotonic()-start
        print(json.dumps(result));return 0
    except (OSError,ValueError,KeyError,sqlite3.Error) as error:
        print(json.dumps({'status':'error','error':str(error)}));return 2


if __name__=='__main__':sys.exit(main())
