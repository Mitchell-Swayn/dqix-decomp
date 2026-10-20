"""Regular hash-bound diagnostic copies made before integration rollback."""
import hashlib,json,shutil,time
from pathlib import Path
from integration_bookkeeping import atomic_write,json_bytes
from integration_dependencies import safe_path

def capture(root,folder):
    root,folder=Path(root),Path(folder)
    destination=folder/'failure-evidence';destination.mkdir(exist_ok=False)
    files={};missing=[]
    def copy(relative):
        resolved=(root/relative).resolve()
        if not resolved.is_relative_to(root.resolve()):raise ValueError('Diagnostic path escapes project')
        relative=resolved.relative_to(root.resolve()).as_posix()
        if relative in files:return
        source=safe_path(root,relative)
        if not source.is_file():missing.append(relative);return
        target=destination/'files'/relative;target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copy2(source,target)
        if target.is_symlink() or target.stat().st_nlink!=1:raise ValueError('Diagnostic copy is not independent')
        before=hashlib.sha256(source.read_bytes()).hexdigest();after=hashlib.sha256(target.read_bytes()).hexdigest()
        if before!=after:raise ValueError('Diagnostic source changed during capture')
        files[relative]=dict(sha256=after,size=target.stat().st_size)
    for relative in ('objdiff.json','build.ninja','config/usa/compiler_profiles.json','config/usa/objdiff_tool.json','build/usa/arm9.o','build/usa/report.json','build/usa/arm7/report.json','build/usa/arm9.lcf','build/usa/short_link/report.json'):
        copy(relative)
    for path in (root/'build/usa/build').glob('*.bin'):copy(path.relative_to(root).as_posix())
    for filename in ('delinks.txt','symbols.txt','relocs.txt','retained_data.json'):
        for path in (root/'config/usa/arm9').rglob(filename):copy(path.relative_to(root).as_posix())
    units=[]
    if (root/'objdiff.json').is_file():
        config=json.loads((root/'objdiff.json').read_text())
        for unit in config.get('units',[]):
            paths={key:unit[key] for key in ('target_path','base_path') if unit.get(key)}
            for relative in paths.values():
                if relative not in files and relative not in missing:copy(relative)
            units.append(dict(name=unit['name'],paths=paths,metadata=unit.get('metadata',{})))
    manifest=folder/'manifest.json'
    if manifest.exists():
        for row in json.loads(manifest.read_text()).get('functions',[]):
            if row['source'] not in files:copy(row['source'])
    evidence=dict(time=time.time(),phase='before-supported-rollback',files=files,units=units,missing=missing,
                  regular_independent_copies=True,source_acceptance=False,credit=0)
    atomic_write(destination/'evidence.json',json_bytes(evidence))
    return evidence
