"""Derive reviewed new owners and their original targets before any installation.

The existing mixed runner owns the guard, journal, validation and publication.
This module never installs sources, original targets or generated configuration.
"""
import json
from pathlib import Path
import re
import stat
import subprocess
import tempfile

from arm9_module import delinks_path
from function_naming import validate_new_functions
from integrate_batch import parse_delinks, validate_ranges, RANGE
from integration_dependencies import safe_path
from integration_mixed_recovery import digest, read
from integration_sources import capture_sources, canonical_source
from match_unit import object_paths

SCHEMA='arm9-source-contract-add-v1'
DSD=Path('/home/swayn/.local/share/factory-inputs/dqix/dsd')


def original_input_hashes(root):
    """Original extracted module inputs only; never generated build outputs."""
    base=root/'extract/usa'
    paths=[p for p in base.glob('*.yaml') if p.is_file()]
    for directory in ('arm9','arm9_overlays','arm7'):
        paths.extend(p for p in (base/directory).rglob('*') if p.is_file() and p.suffix in ('.yaml','.bin'))
    if not paths or not (base/'config.yaml').is_file():raise ValueError('Missing original module input inventory')
    return {p.relative_to(root).as_posix():digest(safe_path(root,p.relative_to(root).as_posix()).read_bytes()) for p in sorted(paths)}


def derive(root,maps,manifest,config,new_rows):
    """Reproduce baseline, derive exact after config/targets in independent files."""
    pins=manifest['source_contracts']
    if digest(DSD.read_bytes())!=pins['dsd_sha256']:raise ValueError('Pinned DSD executable changed')
    if original_input_hashes(root)!=pins['original_inputs_sha256']:raise ValueError('Original module input hash inventory differs')
    scratches={(u['scratch']['compiler'],u['scratch']['c_flags']) for u in config['units'] if u.get('scratch')}
    if len(scratches)!=1:raise ValueError('Additions require one existing default scratch compiler/flags')
    compiler,flags=next(iter(scratches))
    arguments=[str(DSD),'objdiff','--config-path','config/usa/arm9/config.yaml','--scratch','--compiler',compiler,'--c-flags',flags,'--custom-make',config['custom_make']]
    with tempfile.TemporaryDirectory(prefix='dqix-contract-originals-') as temporary:
        stage=Path(temporary)
        for relative,expected in {**pins['context_sha256'],**pins['original_inputs_sha256']}.items():
            if not relative.startswith(('config/','extract/')):continue
            content=safe_path(root,relative).read_bytes()
            if digest(content)!=expected:raise ValueError('Changed independent derivation input')
            target=stage/relative;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(content)
        subprocess.run(arguments,cwd=stage,check=True,capture_output=True,umask=0o022)
        before=(stage/'objdiff.json').read_bytes()
        if before!=(root/'objdiff.json').read_bytes() or json.loads(before)!=config:
            raise ValueError('Independent DSD does not exactly reproduce accepted objdiff configuration')
        for relative,content in maps.items():(stage/relative).write_bytes(content)
        subprocess.run(arguments,cwd=stage,check=True,capture_output=True,umask=0o022)
        after=(stage/'objdiff.json').read_bytes();expected=json.loads(after)
        old_units={u['name']:u for u in config['units']};new_units={u['name']:u for u in expected['units']}
        if len(new_units)!=len(expected['units']):raise ValueError('Derived duplicate comparison units')
        if {k:v for k,v in expected.items() if k!='units'}!={k:v for k,v in config.items() if k!='units'}:raise ValueError('Derived comparison options changed')
        for name,unit in old_units.items():
            if unit.get('metadata',{}).get('source_path') and new_units.get(name)!=unit:raise ValueError('Derived existing source comparison unit changed')
        names={str(Path(r['source']).with_suffix('')) for r in new_rows}
        if {n for n,u in new_units.items() if u.get('metadata',{}).get('source_path') and n not in old_units}!=names:raise ValueError('Derived unexpected new source comparison units')
        subprocess.run([str(DSD),'delink','--config-path','config/usa/arm9/config.yaml'],cwd=stage,check=True,capture_output=True,umask=0o022)
        targets={};modes={}
        for name in names:
            unit=new_units[name]
            if unit.get('metadata',{}).get('complete') is not True:raise ValueError('Derived new owner is not complete')
            target,_=object_paths(stage,unit);relative=target.relative_to(stage).as_posix()
            targets[relative]=target.read_bytes();modes[relative]=stat.S_IMODE(target.stat().st_mode)
        return dict(objdiff=after,targets=targets,target_modes=modes)


def new_plan(root,worker,manifest):
    """Validate all NEW ownership against current original inventory and maps."""
    from integration_source_contracts import exact_keys,owned_sources
    sources=manifest['new_sources']
    if not isinstance(sources,list) or not 1<=len(sources)<=8 or len(set(sources))!=len(sources):raise ValueError('Select one to eight unique new owner sources')
    rows=[r for r in manifest['functions'] if r['source'] in sources]
    if len(rows)!=len(sources) or {r['source'] for r in rows}!=set(sources):raise ValueError('Each new source must own exactly one selected function')
    config=json.loads((root/'objdiff.json').read_text());report=json.loads((root/'build/usa/report.json').read_text());owners=owned_sources(root)
    snapshots,audit=capture_sources(worker,sources,dict(source_hashes={s:manifest['source_hashes'][s] for s in sources}))
    groups={};names=set();identities=set()
    for row in rows:
        exact_keys(row,('source','module','name','address','size','mode'),'new contract function')
        source=row['source'];path=canonical_source(root,source)
        if source in owners or path.exists() or path.is_symlink() or Path(source).suffix not in ('.c','.cpp') or any(p in ('AssemblyFallback','RuntimeSupport','UnitObjects') for p in Path(source).parts):raise ValueError('Contract owner must be new ordinary source')
        module=row['module'];address=int(row['address'],16);size=row['size']
        if type(size) is not int or size<=0 or not 0<=address<address+size<=2**32:raise ValueError('Invalid new owner extent')
        if row['name'] in names or (module,address) in identities:raise ValueError('Aliased new contract owner identity')
        names.add(row['name']);identities.add((module,address))
        symbol_text=(root/delinks_path(module).with_name('symbols.txt')).read_text()
        matches=re.findall(r'(?m)^'+re.escape(row['name'])+r' kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\) addr:0x([0-9a-fA-F]+)\s*$',symbol_text)
        if len(matches)!=1 or matches[0][0]!=row['mode'] or int(matches[0][1],16)!=size or int(matches[0][2],16)!=address:raise ValueError('New owner mode/size/address differs from original symbol inventory')
        originals=[(u,f) for u in report['units'] for f in u.get('functions',[]) if f['name']==row['name']]
        if len(originals)!=1 or not re.fullmatch(re.escape(module)+r'_\d+',originals[0][0]['name']) or int(originals[0][1]['size'])!=size or originals[0][1].get('fuzzy_match_percent')==100 or originals[0][0].get('metadata',{}).get('complete') is True:raise ValueError('New owner must select one unmatched original fallback function')
        groups.setdefault(module,[]).append(row)
    maps={};parts={}
    for module,selected in groups.items():
        relative=delinks_path(module).as_posix();main=parse_delinks((root/relative).read_text(),allow_empty_sections=module!='main');staged=parse_delinks((worker/relative).read_text(),allow_empty_sections=module!='main')
        part=dict(module=module,functions=selected,source_hashes={r['source']:manifest['source_hashes'][r['source']] for r in selected})
        validate_new_functions(root,worker,part,module)
        for row in selected:
            block=staged.blocks.get(row['source'],'');extents=[RANGE.fullmatch(line) for line in block.splitlines()[1:] if line.strip().startswith('.')]
            if 'complete' not in [line.strip() for line in block.splitlines()[1:]] or len(extents)!=1 or not extents[0]:raise ValueError('New contract owner needs one complete code extent')
            section,start,end=extents[0].groups()
            if section not in ('.text','.init') or int(start,16)!=int(row['address'],16) or int(end,16)!=int(row['address'],16)+row['size']:raise ValueError('New contract owner delink extent differs')
            main.blocks[row['source']]=block
        validate_ranges(main,allow_empty_sections=module!='main')
        maps[relative]=(main.header+'\n\n'+'\n\n'.join(main.blocks.values())+'\n').encode();parts[module]=part
    derived=derive(root,maps,manifest,config,rows)
    for relative,expected in derived['targets'].items():
        current=read(root,relative)
        if current is not None and current!=expected:raise ValueError('Unrecognized stale new original target')
    return dict(rows=rows,sources=set(sources),snapshots=snapshots,maps=maps,parts=parts,derived=derived)


def prepare(root,worker,manifest,review_path):
    from integration_source_contracts import prepare as prepare_contract,exact_keys,context_hashes,review_bytes
    exact_keys(manifest,('schema','preparer','functions','units','source_hashes','source_contracts','new_sources'),'contract addition manifest')
    if manifest['schema']!=SCHEMA:raise ValueError('Wrong contract additions schema')
    exact_keys(manifest['source_contracts'],('files','symbols','evidence','context_sha256','dsd_sha256','original_inputs_sha256'),'contract additions')
    if manifest['source_contracts']['context_sha256']!=context_hashes(root):raise ValueError('Contract policy/tool context hash mismatch')
    review_bytes(review_path,worker,manifest)
    addition=new_plan(root,worker,manifest)
    return prepare_contract(root,worker,manifest,review_path,_addition=addition)
