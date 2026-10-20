"""Zero-credit return-declaration corrections bound to owning definitions.

This intentionally supports only scalar return types on existing external
declarations. Function bodies, parameters, identities and ownership cannot change.
"""
import hashlib
import os
import re
import stat

from integration_sources import canonical_source


def digest(content):
    return hashlib.sha256(content).hexdigest()


def normalized_type(value):
    return 'unsigned int' if value.strip() == 'unsigned' else value.strip()


def prototype(text):
    match=re.fullmatch(r'(?:extern\s+"C"\s+)?(unsigned char|unsigned int|unsigned|int|signed char|short|unsigned short)\s+([A-Za-z_]\w*)\s*(\([^;{}]*\))\s*;',text.strip())
    if not match:raise ValueError('Refinement must select a scalar external declaration')
    return normalized_type(match[1]),match[2],match[3]


def capture_refinements(main, worker, manifest):
    entries=manifest.get('source_refinements',[])
    if not entries:return None
    if manifest.get('data') or any(manifest.get(k) for k in ('dependencies','runtime_support','runtime_append','runtime_replacement','function_renames')):
        raise ValueError('Declaration refinement cannot transfer other policy or ownership')
    selected={row['source'] for row in manifest['functions']}
    if {row['source'] for row in entries}!=selected or len(entries)!=len(selected):
        raise ValueError('Refinements must cover each selected existing source once')
    result={'sources':{},'owners':{}}
    for entry in entries:
        relative=entry['source'];target=canonical_source(main,relative)
        before=target.read_bytes();after=canonical_source(worker,relative).read_bytes()
        if digest(before)!=entry['before_sha256'] or digest(after)!=entry['after_sha256']:
            raise ValueError('Refinement source hash mismatch')
        expected=before.decode()
        if not entry.get('changes'):raise ValueError('Empty declaration refinement')
        for change in entry['changes']:
            old,new=change['before'],change['after']
            old_type,name,parameters=prototype(old);new_type,new_name,new_parameters=prototype(new)
            if name!=new_name or parameters!=new_parameters or old_type==new_type:
                raise ValueError('Refinement changes parameters/identity or is unchanged')
            owner=change['canonical_source']
            if owner in selected or 'AssemblyFallback' in owner or 'RuntimeSupport' in owner:
                raise ValueError('Canonical owner must be independent C/C++ source')
            content=canonical_source(main,owner).read_bytes()
            if digest(content)!=change['canonical_source_sha256']:
                raise ValueError('Canonical owner hash mismatch')
            matches=re.findall(r'(?m)^extern\s+"C"\s+(unsigned char|unsigned int|unsigned|int|signed char|short|unsigned short)\s+'+re.escape(name)+r'\s*\([^;{}]*\)\s*\{',content.decode())
            if len(matches)!=1 or normalized_type(matches[0])!=new_type:
                raise ValueError('Refinement disagrees with owning definition')
            # Prototypes must be stand-alone declarations, including inside an
            # extern-C block; never replace body expressions or quoted text.
            occurrences=list(re.finditer(r'(?m)(?<![\w"\'])'+re.escape(old),expected))
            if len(occurrences)!=1 or '{' in expected[expected.rfind('\n',0,occurrences[0].start())+1:occurrences[0].start()]:
                raise ValueError('Refinement needs one unambiguous declaration')
            expected=expected[:occurrences[0].start()]+new+expected[occurrences[0].end():]
            result['owners'][owner]=content
        if after.decode()!=expected or after==before:
            raise ValueError('Refinement changes more than explicit return declarations')
        metadata=target.stat()
        result['sources'][relative]=dict(before=before,after=after,mode=stat.S_IMODE(metadata.st_mode),atime_ns=metadata.st_atime_ns,mtime_ns=metadata.st_mtime_ns)
    return result


def install_refinement(root, relative, snapshot):
    path=canonical_source(root,relative)
    if path.read_bytes()!=snapshot['before']:raise ValueError('Refinement source changed after capture')
    path.write_bytes(snapshot['after'])


def verify_refinements(root, snapshot):
    if snapshot is None:return
    for relative,row in snapshot['sources'].items():
        if canonical_source(root,relative).read_bytes()!=row['after']:raise ValueError('Installed refinement changed')
    for relative,content in snapshot['owners'].items():
        if canonical_source(root,relative).read_bytes()!=content:raise ValueError('Canonical owning source changed')


def restore_refinements(root, snapshot):
    if snapshot is None:return
    for relative,row in snapshot['sources'].items():
        path=canonical_source(root,relative);path.write_bytes(row['before']);path.chmod(row['mode'])
        # A restored caller must be newer than the rejected compiled object.
