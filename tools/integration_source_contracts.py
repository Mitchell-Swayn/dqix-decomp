"""Reviewed, zero-credit source contracts for the existing mixed transaction.

The structural gate proves scope, ownership and artifact identity. Semantic
approval is a separate hash-bound review supplied by the integrator, not by the
worker manifest. This is deliberately limited to existing code-only source TUs.
"""
import json
from pathlib import Path
import re
import shlex
import stat

from arm9_module import delinks_path, module_section, verify_manifest_units
from integrate_batch import parse_delinks, RANGE
from integration_dependencies import safe_path
from integration_mixed_recovery import digest,read
from match_unit import object_paths

SCHEMA='arm9-source-contract-v1'
SOURCE_SUFFIXES={'.c','.cpp','.cc','.cxx','.C','.m','.mm'}
HEADER_SUFFIXES={'.h','.hpp','.hh','.hxx','.inl','.ipp'}


def exact_keys(row, keys, label):
    if not isinstance(row,dict) or set(row)!=set(keys):
        raise ValueError('Unexpected '+label+' fields')


def proposal_sha256(manifest):
    return digest(json.dumps(manifest,sort_keys=True,separators=(',',':'),ensure_ascii=True).encode())


def context_hashes(root):
    """Pin policy and executable validation/build scripts, including membership."""
    paths=[root/'objdiff.json']
    paths+=sorted(p for p in (root/'config').rglob('*') if p.is_file())
    paths+=sorted(p for p in (root/'tools').rglob('*.py') if '__pycache__' not in p.parts)
    return {p.relative_to(root).as_posix():digest(safe_path(root,p.relative_to(root).as_posix()).read_bytes()) for p in paths}


def source_files(root):
    return sorted(p for directory in ('src','include','libs') for p in (root/directory).rglob('*') if p.is_file() and b'\0' not in safe_path(root,p.relative_to(root).as_posix()).read_bytes())


def references(root, name, replacements=None):
    result={};pattern=re.compile(r'(?<![\w$])'+re.escape(name)+r'(?![\w$])')
    paths={p.relative_to(root).as_posix() for p in source_files(root)}|set(replacements or {})
    for relative in sorted(paths):
        content=(replacements or {}).get(relative)
        if content is None:content=safe_path(root,relative).read_bytes()
        if pattern.search(content.decode(errors='replace')):result[relative]=digest(content)
    return result


def owned_sources(root):
    result={}
    config=root/'config/usa/arm9'
    for path in sorted(config.rglob('delinks.txt')):
        module='main' if path.parent==config else path.parent.name
        module_section(module)
        for source,block in parse_delinks(path.read_text(),allow_empty_sections=module!='main').blocks.items():
            if source in result:raise ValueError('Ambiguous source ownership: '+source)
            result[source]=(module,block)
    return result


def editable(root, relative):
    path=safe_path(root,relative)
    if (not path.is_file() or not relative.startswith(('src/','include/')) or
            path.suffix not in ('.c','.cpp','.h','.hpp') or
            any(part in ('AssemblyFallback','RuntimeSupport') for part in path.parts)):
        raise ValueError('Contract edit must select existing ordinary source/header: '+relative)
    return path


def inventory(root, manifest, owners, config, report):
    """Every compared TU is existing, complete, exact, code-only, unchanged extent."""
    verify_manifest_units(manifest,config)
    units={u['name']:u for u in report['units']}
    if len(units)!=len(report['units']):raise ValueError('Duplicate original report unit')
    selected={r['source'] for r in manifest['functions']}
    expected=set();parts={}
    for source in selected:
        editable(root,source)
        if source not in owners:raise ValueError('Unowned contract source: '+source)
        module,block=owners[source]
        if 'complete' not in [line.strip() for line in block.splitlines()[1:]]:raise ValueError('Contract source is not complete')
        extents=[RANGE.fullmatch(line) for line in block.splitlines()[1:] if line.strip().startswith('.')]
        if not extents or any(not e or e[1] not in ('.text','.init') for e in extents):raise ValueError('Contract TUs must own code only')
        unit=units.get(str(Path(source).with_suffix('')),{})
        if not unit.get('functions') or any(s['name'] not in ('.text','.init') and int(s['size']) for s in unit.get('sections',[])):
            raise ValueError('Contract report TU must contain code only')
        part=parts.setdefault(module,dict(functions=[],units=[],source_hashes={}))
        part['units'].append(str(Path(source).with_suffix('')))
        part['source_hashes'][source]=manifest['source_hashes'][source]
        symbols=(root/delinks_path(module).with_name('symbols.txt')).read_text()
        for f in unit['functions']:
            if f.get('fuzzy_match_percent')!=100:raise ValueError('Contract preimage function is not exact')
            matches=re.findall(r'(?m)^'+re.escape(f['name'])+r' kind:function\([^\n]*\) addr:0x([0-9a-fA-F]+)\b[^\n]*$',symbols)
            if len(matches)!=1:raise ValueError('Contract function owner identity is ambiguous')
            address=int(matches[0],16);size=int(f['size'])
            if not any(int(e[2],16)<=address and address+size<=int(e[3],16) for e in extents):raise ValueError('Contract function exceeds owned extent')
            expected.add((source,module,f['name'],address,size))
    actual=set();names=set();identities=set()
    for row in manifest['functions']:
        exact_keys(row,('source','module','name','address','size'),'contract function')
        key=(row['source'],row['module'],row['name'],int(row['address'],16),int(row['size']))
        if key in actual or row['name'] in names or (row['module'],int(row['address'],16)) in identities:raise ValueError('Duplicate/aliased contract function')
        names.add(row['name']);identities.add((row['module'],int(row['address'],16)))
        actual.add(key)
        parts[owners[row['source']][0]]['functions'].append(row)
    if actual!=expected:raise ValueError('Contract function inventory differs from complete original TUs')
    return dict(modules=parts,expected_functions=0,expected_code_bytes=0),selected


def header_dependents(root, config, headers):
    """Use current compiler depfiles AND conservative transitive include closure."""
    if not headers:return set()
    files=source_files(root);included={};suffixes={}
    for path in files:
        relative=path.relative_to(root).as_posix()
        parts=Path(relative).parts
        for index in range(1,len(parts)):suffixes.setdefault('/'.join(parts[index:]),set()).add(relative)
    for path in files:
        relative=path.relative_to(root).as_posix()
        names=re.findall(r'^\s*#\s*include\s*[<"]([^>"\n]+)[>"]',path.read_text(errors='replace'),re.M)
        included[relative]=set().union(*(suffixes.get(name,set()) for name in names))
    reached=set(headers)
    while True:
        more={p for p,dependencies in included.items() if dependencies&reached}
        if more<=reached:break
        reached|=more
    affected={p for p in reached if Path(p).suffix in SOURCE_SUFFIXES}
    for unit in config['units']:
        source=unit.get('metadata',{}).get('source_path')
        if not source:continue
        _,base=object_paths(root,unit);depfile=base.with_suffix('.d')
        if depfile.is_symlink() or not depfile.is_file():raise ValueError('Header migration requires complete compiler depfiles: '+source)
        content=depfile.read_text().replace('\\\n',' ')
        dependencies=set()
        for value in shlex.split(content.partition(':')[2]):
            if value.startswith('/bench/project/'):value=value[len('/bench/project/'):]
            p=Path(value)
            if p.is_absolute():
                if not p.is_relative_to(root):raise ValueError('Unrecognized compiler dependency root')
                value=p.relative_to(root).as_posix()
            path=safe_path(root,value)
            if not path.is_file() or path.stat().st_mtime_ns>depfile.stat().st_mtime_ns:raise ValueError('Stale compiler depfile: '+source)
            dependencies.add(value)
        if source not in dependencies:raise ValueError('Compiler depfile omits source: '+source)
        if dependencies&headers:affected.add(source)
    return affected


def review_bytes(path, worker, manifest):
    path=Path(path)
    if path.is_symlink() or path!=path.resolve() or path.is_relative_to(worker):raise ValueError('Review must be canonical, nonsymlink, outside worker')
    content=path.read_bytes();review=json.loads(content)
    exact_keys(review,('schema','decision','reviewer','proposal_sha256','evidence_sha256'),'contract review')
    contracts=manifest['source_contracts']
    if (review['schema']!='arm9-source-contract-review-v1' or review['decision']!='approve' or
            not isinstance(review['reviewer'],str) or not review['reviewer'].strip() or review['reviewer']==manifest['preparer'] or
            review['proposal_sha256']!=proposal_sha256(manifest) or
            review['evidence_sha256']!={r['path']:r['sha256'] for r in contracts['evidence']}):
        raise ValueError('Independent contract review does not approve exact proposal/evidence')
    return content


def prepare(root,worker,manifest,review_path,_addition=None):
    adding=_addition is not None
    if not adding:exact_keys(manifest,('schema','preparer','functions','units','source_hashes','source_contracts'),'contract manifest')
    if (not adding and manifest['schema']!=SCHEMA) or not isinstance(manifest['preparer'],str) or not manifest['preparer'].strip():raise ValueError('Invalid contract schema/preparer')
    contracts=manifest['source_contracts']
    keys=('files','symbols','evidence','context_sha256')+(('dsd_sha256','original_inputs_sha256') if adding else ())
    exact_keys(contracts,keys,'source contracts')
    if not contracts['files'] or not contracts['symbols'] or not contracts['evidence']:raise ValueError('Empty contract proposal/evidence')
    if contracts['context_sha256']!=context_hashes(root):raise ValueError('Contract policy/tool context hash mismatch')
    review=review_bytes(review_path,worker,manifest)
    evidence={}
    for row in contracts['evidence']:
        exact_keys(row,('path','sha256'),'contract evidence')
        content=safe_path(worker,row['path']).read_bytes()
        if row['path'] in evidence or digest(content)!=row['sha256']:raise ValueError('Contract evidence hash mismatch/duplicate')
        evidence[row['path']]=content
    config=json.loads((root/'objdiff.json').read_text());report=json.loads((root/'build/usa/report.json').read_text());owners=owned_sources(root)
    existing=manifest
    if adding:
        selected_new=_addition['sources']
        existing=dict(manifest,functions=[r for r in manifest['functions'] if r['source'] not in selected_new],units=[u for u in manifest['units'] if u not in {str(Path(s).with_suffix('')) for s in selected_new}],source_hashes={s:h for s,h in manifest['source_hashes'].items() if s not in selected_new})
    plan,selected=inventory(root,existing,owners,config,report)
    if adding:
        if {r['owner'] for r in contracts['symbols']}!=selected_new:raise ValueError('Every new source must be a selected canonical contract owner')
        if set(selected)&selected_new:raise ValueError('New and existing source inventories overlap')
        selected|=selected_new
        expected_units={str(Path(s).with_suffix('')) for s in selected}
        if len(manifest['units'])!=len(expected_units) or set(manifest['units'])!=expected_units:raise ValueError('Additions comparison units differ from complete source union')
        for module,part in _addition['parts'].items():
            target=plan['modules'].setdefault(module,dict(functions=[],units=[],source_hashes={}))
            target['functions']+=part['functions'];target['units']+=[str(Path(r['source']).with_suffix('')) for r in part['functions']];target['source_hashes'].update(part['source_hashes'])
        plan.update(expected_functions=len(_addition['rows']),expected_code_bytes=sum(r['size'] for r in _addition['rows']),credit_functions=_addition['rows'],source_contract_additions=True)
    names={r['name'] for r in contracts['symbols']}
    if len(names)!=len(contracts['symbols']) or any(not re.fullmatch(r'[A-Za-z_]\w*',n) for n in names):raise ValueError('Contract symbols must have unique simple identities')
    snapshots=dict(_addition['snapshots']) if adding else {};changes=dict(snapshots);file_rows={};includes=[];include_depfiles={}
    for row in contracts['files']:
        keys=('path','before_sha256','after_sha256','edits')+(('include_additions',) if 'include_additions' in row else ())
        exact_keys(row,keys,'contract file')
        source=row['path'];path=editable(root,source);before=path.read_bytes();after=editable(worker,source).read_bytes()
        if source in changes or before==after or digest(before)!=row['before_sha256'] or digest(after)!=row['after_sha256']:raise ValueError('Contract source hash mismatch/duplicate/unchanged')
        expected=before.decode()
        if 'include_additions' in row:
            from integration_contract_includes import capture as capture_includes
            expected,include_audit,dep_after=capture_includes(root,worker,source,before,after,row['include_additions'],config)
            includes.append(include_audit);include_depfiles[include_audit['depfile']]=dep_after
        if not row['edits'] and 'include_additions' not in row:raise ValueError('Missing explicit contract edits')
        for edit in row['edits']:
            exact_keys(edit,('kind','symbol','before','after'),'contract edit')
            if edit['kind'] not in ('declaration','definition','dataflow','type') or edit['symbol'] not in names or not edit['before'] or edit['before']==edit['after'] or expected.count(edit['before'])!=1:raise ValueError('Ambiguous or unlisted contract edit')
            if 'include_additions' in row and any(re.search(r'(?m)^\s*#|_Pragma',value) for value in (edit['before'],edit['after'])):raise ValueError('Body edits cannot alter include or preprocessor directives')
            expected=expected.replace(edit['before'],edit['after'],1)
        if expected.encode()!=after:raise ValueError('Contract changes exceed explicit edits')
        protected=lambda text:re.findall(r'(?m)^\s*(?:#.*|//\s*Original:.*)$',text)
        if 'include_additions' in row:
            from integration_contract_includes import protected as protect_includes
            protect_includes(before,after,row['include_additions']['directives'])
        elif protected(before.decode())!=protected(after.decode()):raise ValueError('Contract cannot change preprocessor or original identity lines')
        changes[source]=after;file_rows[source]=row
        if path.suffix in ('.c','.cpp'):snapshots[source]=after
    if not snapshots or not set(snapshots)<=selected or set(manifest['source_hashes'])!=selected:raise ValueError('Changed contract sources must be selected owned TUs')
    for source in selected:
        content=changes[source] if source in changes else safe_path(root,source).read_bytes()
        if digest(content)!=manifest['source_hashes'][source]:raise ValueError('Contract compared source hash mismatch')
        snapshots[source]=content
    ref_audit={};before_reference_audit={};reference_paths=set()
    for contract in contracts['symbols']:
        exact_keys(contract,('name','owner','references'),'contract symbol')
        name=contract['name'];owner=contract['owner']
        if (owner not in _addition['sources'] if adding else owner not in owners) or owner not in selected or not any(r['name']==name and r['source']==owner for r in manifest['functions']):raise ValueError('Contract requires selected canonical owner function')
        # Scope excludes overloaded/member aliases; one unmangled external definition.
        owner_after=snapshots[owner].decode()
        if len(re.findall(r'(?m)^extern\s+"C"\s+[^;{}\n]+\b'+re.escape(name)+r'\s*\([^;{}]*\)\s*\{',owner_after))!=1:raise ValueError('Ambiguous canonical owning definition')
        before_refs=references(root,name);after_refs=references(root,name,changes)
        expected_refs=set(before_refs)|({s for s in _addition['sources'] if s in after_refs} if adding else set())
        if expected_refs!=set(after_refs):raise ValueError('Contract cannot add/remove unlisted symbol reference files')
        declared={}
        for row in contract['references']:
            exact_keys(row,('path','before_sha256','after_sha256','conformance','evidence'),'contract reference')
            source=row['path']
            if source in declared or row['before_sha256']!=before_refs.get(source) or row['after_sha256']!=after_refs.get(source):raise ValueError('Contract reference hash mismatch/duplicate')
            expected_kind='owner' if source==owner else 'introduced' if adding and source in _addition['sources'] else 'repaired' if source in file_rows else 'unchanged'
            if row['conformance']!=expected_kind or not row['evidence'] or not set(row['evidence'])<=set(evidence):raise ValueError('Contract caller conformance evidence missing')
            declared[source]=row;reference_paths.add(source)
        if set(declared)!=expected_refs:raise ValueError('Incomplete contract reference census')
        if not {p for p in expected_refs if Path(p).suffix in SOURCE_SUFFIXES}<=selected:raise ValueError('Contract omits source caller comparison units')
        ref_audit[name]=after_refs;before_reference_audit[name]=before_refs
    affected=header_dependents(root,config,{s for s in set(changes)|reference_paths if Path(s).suffix in HEADER_SUFFIXES})
    if not affected<=selected:raise ValueError('Contract omits header-dependent source TUs')
    if not set(changes)<=reference_paths:raise ValueError('Contract edits include unreferenced files')
    # Every affected/unchanged reference is captured into the same rollback journal.
    after_context=dict(contracts['context_sha256']);maps={}
    if adding:
        maps=_addition['maps'];derived=_addition['derived']
        changes.update(maps);changes['objdiff.json']=derived['objdiff'];changes.update(derived['targets'])
        after_context.update({p:digest(b) for p,b in maps.items()});after_context['objdiff.json']=digest(derived['objdiff'])
    changes.update(include_depfiles)
    frozen=dict(after_context)
    for row in includes:
        if set(row['after']['headers_sha256'])&set(file_rows):raise ValueError('Included canonical headers must remain unchanged')
        frozen.update(row['after']['headers_sha256'])
    if adding:frozen.update(contracts['original_inputs_sha256'])
    for refs in ref_audit.values():frozen.update(refs)
    targets={}
    for unit in config['units']:
        if unit['name'] in manifest['units']:
            target,_=object_paths(root,unit);relative=target.relative_to(root).as_posix()
            targets[relative]=digest(target.read_bytes());frozen[relative]=targets[relative]
    if adding:
        for relative,content in derived['targets'].items():targets[relative]=digest(content);frozen[relative]=digest(content)
    for source in selected:
        if source not in changes:changes[source]=snapshots[source]
    for relative in frozen:
        if relative not in changes:changes[relative]=safe_path(root,relative).read_bytes()
    modes={}
    for relative in changes:
        path=safe_path(root,relative)
        if path.exists():modes[relative]=stat.S_IMODE(path.stat().st_mode)
        elif adding and relative in _addition['sources']:modes[relative]=stat.S_IMODE(safe_path(worker,relative).stat().st_mode)
        elif adding and relative in derived['target_modes']:modes[relative]=derived['target_modes'][relative]
        else:raise ValueError('Unexpected absent captured contract input')
    mutable=set(file_rows)|set(include_depfiles)
    if adding:mutable|=_addition['sources']|set(maps)|{'objdiff.json'}|{p for p in derived['targets'] if read(root,p) is None}
    audit=dict(source_hashes={s:digest(b) for s,b in snapshots.items()},owner_context_sha256={},map_modes={},owner_context_modes={},
               contract=True,adding=adding,includes=includes,immutable_paths=set(changes)-mutable,preimages_sha256={p:digest(read(root,p)) for p in changes},install_paths=list(file_rows)+(sorted(_addition['sources']) if adding else []),context_sha256=contracts['context_sha256'],after_context_sha256=after_context,references=ref_audit,before_references=before_reference_audit,original_targets_sha256=targets,
               frozen_sha256=frozen,modes=modes,review_bytes=review,evidence=evidence,
               report_units={u['name']:u for u in report['units'] if u['name'] in manifest['units']})
    if adding:
        audit.update(dsd_sha256=contracts['dsd_sha256'],original_inputs_sha256=contracts['original_inputs_sha256'])
        audit['map_modes']={p:modes[p] for p in maps}
    return plan,snapshots,[],maps,changes,audit


def verify(root,audit):
    if context_hashes(root)!=audit.get('after_context_sha256',audit['context_sha256']):raise ValueError('Contract policy/tool context changed')
    if audit.get('adding'):
        from integration_source_additions import DSD,original_input_hashes
        if digest(DSD.read_bytes())!=audit['dsd_sha256'] or original_input_hashes(root)!=audit['original_inputs_sha256']:raise ValueError('Contract original tool/module input changed')
    if audit.get('includes'):
        from integration_contract_includes import verify as verify_includes
        verify_includes(root,audit['includes'],'after')
    for name,expected in audit['references'].items():
        if references(root,name)!=expected:raise ValueError('Contract reference census changed')
    for relative,expected in audit['frozen_sha256'].items():
        if digest(safe_path(root,relative).read_bytes())!=expected:raise ValueError('Contract frozen context/target changed: '+relative)
    for relative,mode in audit['modes'].items():
        if stat.S_IMODE(safe_path(root,relative).stat().st_mode)!=mode:raise ValueError('Contract file mode changed: '+relative)


def check_report(root,audit):
    report=json.loads((root/'build/usa/report.json').read_text());units={u['name']:u for u in report['units']}
    for name,before in audit['report_units'].items():
        if units.get(name)!=before:raise ValueError('Contract original function/section inventory or report metadata changed: '+name)


def verify_preimages(root,audit,journal):
    verify_baseline(root,baseline(audit))
    for row in journal['entries']:
        relative=row['path']
        if row['generated']:continue
        expected=audit['preimages_sha256'].get(relative)
        if expected!=row['before_sha256'] or digest(read(root,relative))!=expected:
            raise ValueError('Contract preimage changed before installation: '+relative)


def verify_baseline(root,baseline):
    if baseline.get('include_dependencies'):
        from integration_contract_includes import verify as verify_includes
        verify_includes(root,baseline['include_dependencies'],'before')
    if 'dsd_sha256' in baseline:
        from integration_source_additions import DSD,original_input_hashes
        if digest(DSD.read_bytes())!=baseline['dsd_sha256'] or original_input_hashes(root)!=baseline['original_inputs_sha256']:raise ValueError('Contract restored original tool/module inputs differ')
    if context_hashes(root)!=baseline['context_sha256']:raise ValueError('Contract restored policy/tool context differs')
    for name,expected in baseline['references'].items():
        if references(root,name)!=expected:raise ValueError('Contract restored reference census differs')


def baseline(audit):
    result=dict(context_sha256=audit['context_sha256'],references=audit['before_references'])
    if audit.get('includes'):result['include_dependencies']=audit['includes']
    if audit.get('adding'):result.update(dsd_sha256=audit['dsd_sha256'],original_inputs_sha256=audit['original_inputs_sha256'])
    return result
