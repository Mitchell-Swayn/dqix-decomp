"""Evidence-based naming checks for newly accepted functions."""
import json
from pathlib import Path
import re
import subprocess

POLICY = Path('config/usa/function_naming.json')
PLACEHOLDER = re.compile(r'(?:^|::)(?:func|Func|FUN|sub)_?[0-9a-fA-F]{8}(?:\(|$)')


def readable_names(names):
    if not names:
        return []
    result = subprocess.run(['c++filt'], input='\n'.join(names)+'\n',
                            capture_output=True, text=True, check=True)
    return result.stdout.splitlines()


def validate_new_functions(main, worker, manifest, module='main'):
    policy = Path(main) / POLICY
    if not policy.exists() or not json.loads(policy.read_text()).get('enforce_new_functions'):
        return
    rows = manifest.get('functions', [])
    names = readable_names([row['name'] for row in rows])
    runtime = manifest.get('runtime_append') or manifest.get('runtime_support')
    runtime_names = {row['name'] for row in runtime.get('functions', [])} if runtime else set()
    for row, name in zip(rows, names):
        text = (Path(worker) / row['source']).read_text()
        if PLACEHOLDER.search(name) or re.search(r'\bUnknownOperation\b', name):
            raise ValueError('Function requires an evidence-based descriptive name: '+row['name'])
        if row['name'] in runtime_names:
            # Runtime identities and dedicated source provenance are checked by runtime_support.
            continue
        address = int(row['address'], 16)
        location = re.compile(r'//\s*Original:\s*arm9/'+re.escape(module)+
                              r'\s*@\s*0x'+format(address, '08x')+r'\b[^\n]*\bsymbol:\s*\S+', re.I)
        if not location.search(text):
            raise ValueError('Function requires its original module/address/symbol comment: '+row['name'])
