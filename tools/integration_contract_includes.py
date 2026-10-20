"""Explicit existing-header insertions and authenticated compiler dependencies.

Only the existing reviewed contract preparation calls this helper. Header files
remain immutable; expected worker depfiles are evidence, never installed output.
"""
from pathlib import Path
import json
import re
import shlex
import stat

from integration_dependencies import safe_path
from integration_mixed_recovery import digest
from match_unit import object_paths

HEADER_SUFFIXES={'.h','.hpp','.hh','.hxx','.inl','.ipp'}
INCLUDE=re.compile(r'#include\s+(?:<([^<>"\n]+)>|"([^<>"\n]+)")')


def safe_header(root,relative):
    path=safe_path(root,relative)
    if not relative.startswith(('src/','include/','libs/')) or path.suffix not in HEADER_SUFFIXES or not path.is_file():raise ValueError('Include requires an existing project header')
    current=root
    for part in Path(relative).parts:
        current=current/part
        if current.is_symlink():raise ValueError('Symlinked canonical header path')
    return path


def include_roots(root):
    return [root/'include']+sorted(p for p in (root/'libs').rglob('include') if p.is_dir())


def resolve(root,name,including):
    operand=Path(name)
    if operand.is_absolute() or operand.as_posix()!=name or '..' in operand.parts or not name:raise ValueError('Noncanonical include operand')
    candidates={p.relative_to(root).as_posix() for directory in [safe_path(root,including).parent]+include_roots(root) if (p:=directory/operand).is_file()}
    if len(candidates)!=1:raise ValueError('Include must resolve to one canonical project header: '+name)
    relative=next(iter(candidates));safe_header(root,relative)
    return relative


def literals(content):
    result=[]
    for line in content.decode().splitlines():
        if not re.match(r'\s*#\s*include',line):continue
        match=INCLUDE.fullmatch(line.strip())
        if not match:raise ValueError('Header dependency closure requires literal include directives')
        result.append(match[1] or match[2])
    return result


def closure(root,roots):
    result={};pending=list(roots)
    while pending:
        relative=pending.pop()
        if relative in result:continue
        content=safe_header(root,relative).read_bytes();result[relative]=digest(content)
        pending.extend(resolve(root,name,relative) for name in literals(content))
    return result


def depfile(root,config,source):
    units=[u for u in config['units'] if u.get('metadata',{}).get('source_path')==source]
    if len(units)!=1 or units[0].get('metadata',{}).get('complete') is not True:raise ValueError('Include insertion needs one complete existing source TU')
    _,base=object_paths(root,units[0]);return base.with_suffix('.d').relative_to(root).as_posix(),base.relative_to(root).as_posix()


def dependencies(root,content,target,source):
    text=content.decode().replace('\\\n',' ');head,separator,body=text.partition(':')
    if not separator or head.strip()!=target:raise ValueError('Compiler depfile target differs from canonical source object')
    paths=set()
    for value in shlex.split(body):
        if value.startswith('/bench/project/'):value=value[len('/bench/project/'):]
        candidate=Path(value)
        if candidate.is_absolute():
            if not candidate.is_relative_to(root):raise ValueError('Unknown compiler dependency root')
            value=candidate.relative_to(root).as_posix()
        safe_path(root,value)
        if value!=source:safe_header(root,value)
        paths.add(value)
    if source not in paths:raise ValueError('Compiler depfile omits selected source')
    return paths


def fresh(root,relative,paths,source,source_root=None):
    path=safe_path(source_root or root,relative)
    if not path.is_file():raise ValueError('Missing compiler dependency file')
    stamp=path.stat().st_mtime_ns
    for dependency in paths:
        target=safe_path(source_root or root,dependency) if dependency==source else safe_header(root,dependency)
        if target.stat().st_mtime_ns>stamp:raise ValueError('Stale compiler dependency file: '+relative)


def insert(before,directives):
    """Insert only after unique pre-existing literal includes, outside conditions."""
    expected=before.decode();original=expected.splitlines();anchors=set();added=set()
    for row in directives:
        from integration_source_contracts import exact_keys
        exact_keys(row,('after','directive','header'),'include insertion')
        anchor=row['after'];directive=row['directive']
        if not INCLUDE.fullmatch(anchor) or not INCLUDE.fullmatch(directive) or original.count(anchor)!=1 or anchor in anchors or directive in original or directive in added:raise ValueError('Ambiguous, duplicate or already present include insertion')
        depth=0;continued=False
        for line in original:
            if line==anchor:
                if continued:raise ValueError('Include anchor cannot be a macro continuation')
                break
            directive_line=continued or bool(re.match(r'\s*#',line))
            continued=directive_line and line.endswith('\\')
            if re.match(r'\s*#\s*(?:if|ifdef|ifndef)\b',line):depth+=1
            elif re.match(r'\s*#\s*endif\b',line):depth-=1
        if depth:raise ValueError('Include anchor must be outside conditional directives')
        pattern=re.compile(r'(?m)^'+re.escape(anchor)+r'(\r?\n)')
        if len(list(pattern.finditer(expected)))!=1:raise ValueError('Include anchor needs one complete source line')
        expected=pattern.sub(lambda m:anchor+m[1]+directive+m[1],expected,count=1)
        anchors.add(anchor);added.add(directive)
    return expected


def protected_records(text):
    records=[];pending=[]
    for line in text.splitlines():
        if pending or re.match(r'\s*#',line):
            pending.append(line)
            if not line.endswith('\\'):records.append(tuple(pending));pending=[]
        elif re.match(r'\s*(?://\s*Original:.*|ARM|THUMB)\s*$',line) or '_Pragma' in line:records.append((line,))
    if pending:raise ValueError('Unterminated preprocessor continuation')
    return records


def protected(before,after,directives):
    lines=after.decode().splitlines(keepends=True)
    for row in directives:
        matches=[i for i,line in enumerate(lines) if line.rstrip('\r\n')==row['directive']]
        if len(matches)!=1:raise ValueError('Added include directive count differs')
        del lines[matches[0]]
    for row in directives:
        actual=after.decode().splitlines();anchor=actual.index(row['after']) if actual.count(row['after'])==1 else -1
        if anchor<0 or anchor+1>=len(actual) or actual[anchor+1]!=row['directive']:raise ValueError('Added include placement differs from declared anchor')
    if protected_records(before.decode())!=protected_records(''.join(lines)):raise ValueError('Contract cannot change other directives or original identity lines')


def capture(root,worker,source,before,after,block,config):
    from integration_source_contracts import exact_keys
    exact_keys(block,('directives','headers_sha256','before_depfile_sha256','after_depfile_sha256'),'include additions')
    if Path(source).suffix not in ('.c','.cpp') or not block['directives']:raise ValueError('Include additions require an existing source TU')
    relative,target=depfile(root,config,source);before_path=safe_path(root,relative);after_path=safe_path(worker,relative)
    before_deps=before_path.read_bytes();after_deps=after_path.read_bytes()
    if digest(before_deps)!=block['before_depfile_sha256'] or digest(after_deps)!=block['after_depfile_sha256'] or before_deps==after_deps:raise ValueError('Include dependency pre/postimage hash mismatch')
    old=dependencies(root,before_deps,target,source);new=dependencies(root,after_deps,target,source)
    fresh(root,relative,old,source);fresh(root,relative,new,source,worker)
    roots=[]
    for row in block['directives']:
        match=INCLUDE.fullmatch(row['directive'])
        if not match:raise ValueError('Include insertion must be one literal directive')
        header=resolve(root,match[1] or match[2],source)
        if header!=row['header'] or header in old or header in roots:raise ValueError('Canonical include differs, repeats or is already a dependency')
        roots.append(header)
    graph=closure(root,roots);expected=old|set(graph)
    if new!=expected:raise ValueError('Compiler dependencies differ from complete declared include closure')
    hashes={p:digest(safe_header(root,p).read_bytes()) for p in expected-{source}}
    if block['headers_sha256']!=hashes:raise ValueError('Include header hash membership/bytes differ')
    modes={p:stat.S_IMODE(safe_header(root,p).stat().st_mode) for p in hashes}
    audit=dict(source=source,depfile=relative,target=target,directives=block['directives'],closure_sha256=graph,header_modes=modes,depfile_mode=stat.S_IMODE(before_path.stat().st_mode),
               before=dict(depfile_sha256=digest(before_deps),source_sha256=digest(before),paths=sorted(old),headers_sha256={p:hashes[p] for p in old-{source}}),
               after=dict(depfile_sha256=digest(after_deps),source_sha256=digest(after),paths=sorted(new),headers_sha256=hashes))
    return insert(before,block['directives']),audit,after_deps


def verify(root,rows,phase):
    for row in rows:
        expected=row[phase];path=safe_path(root,row['depfile']);content=path.read_bytes()
        if digest(content)!=expected['depfile_sha256'] or digest(safe_path(root,row['source']).read_bytes())!=expected['source_sha256'] or stat.S_IMODE(path.stat().st_mode)!=row['depfile_mode']:raise ValueError('Compiled include dependency bytes/source/mode differ')
        actual=dependencies(root,content,row['target'],row['source'])
        if actual!=set(expected['paths']):raise ValueError('Compiled include dependency membership differs')
        fresh(root,row['depfile'],actual,row['source'])
        for directive in row['directives']:
            match=INCLUDE.fullmatch(directive['directive'])
            if resolve(root,match[1] or match[2],row['source'])!=directive['header']:raise ValueError('Canonical include resolution changed')
        if closure(root,[d['header'] for d in row['directives']])!=row['closure_sha256']:raise ValueError('Include dependency closure changed')
        for header,value in {**row['closure_sha256'],**expected['headers_sha256']}.items():
            path=safe_header(root,header)
            if digest(path.read_bytes())!=value or stat.S_IMODE(path.stat().st_mode)!=row['header_modes'][header]:raise ValueError('Pinned include header bytes/mode changed')


def metadata(root,worker,source,directives):
    """Build declared pins; caller holds integration_guard for the accepted root."""
    config=json.loads((root/'objdiff.json').read_text());relative,target=depfile(root,config,source)
    before=safe_path(root,relative).read_bytes();after=safe_path(worker,relative).read_bytes()
    old=dependencies(root,before,target,source)
    roots=[]
    for row in directives:
        match=INCLUDE.fullmatch(row['directive'])
        if not match:raise ValueError('Include insertion must be one literal directive')
        roots.append(resolve(root,match[1] or match[2],source))
    headers=(old-{source})|set(closure(root,roots))
    block=dict(directives=directives,headers_sha256={p:digest(safe_header(root,p).read_bytes()) for p in sorted(headers)},before_depfile_sha256=digest(before),after_depfile_sha256=digest(after))
    capture(root,worker,source,safe_path(root,source).read_bytes(),safe_path(worker,source).read_bytes(),block,config)
    return block
