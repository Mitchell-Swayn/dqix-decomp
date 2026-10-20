"""Validate declarative retention of exact source-owned initialized data extents.

This supplies linker roots only. It adds no bytes and grants no source credit.
"""
import hashlib
import json
from pathlib import Path
import re


def retained_data_symbols(root, version):
    root = Path(root).resolve()
    config = root / 'config' / version / 'arm9'
    names = []
    for manifest in sorted(config.rglob('retained_data.json')):
        module = manifest.parent.name
        if module not in ('arm9', 'itcm', 'dtcm') and not re.fullmatch(r'ov\d{3}', module):
            raise ValueError('Unknown retained-data module')
        document = json.loads(manifest.read_text())
        if set(document) != {'schema_version', 'symbols'} or document['schema_version'] != 1:
            raise ValueError('Unknown retained-data schema')
        symbols = {}
        for line in (manifest.parent / 'symbols.txt').read_text().splitlines():
            match = re.fullmatch(r'(\w+)\s+kind:data\([^)]*\)\s+addr:0x([0-9a-fA-F]+)', line.strip())
            if match:
                symbols[match[1]] = int(match[2], 16)
        text = (manifest.parent / 'delinks.txt').read_text()
        for row in document['symbols']:
            required = {'name','address','size','section','source','source_sha256','original_sha256','reason'}
            if set(row) != required or not re.fullmatch(r'[A-Za-z_]\w*', row['name']):
                raise ValueError('Invalid retained-data entry')
            if row['name'] in names or row['name'] not in symbols:
                raise ValueError('Unknown or duplicate retained-data symbol')
            address = int(row['address'], 16)
            size = row['size']
            if symbols[row['name']] != address or not isinstance(size,int) or isinstance(size,bool) or size <= 0:
                raise ValueError('Retained-data address/size mismatch')
            if row['section'] not in ('.data','.rodata','.ctor') or not row['reason']:
                raise ValueError('Retained-data must be justified initialized data')
            source = Path(row['source'])
            if source.is_absolute() or '..' in source.parts or source.suffix not in ('.c','.cpp'):
                raise ValueError('Invalid retained-data source path')
            path = root / source
            if not path.resolve().is_relative_to(root) or hashlib.sha256(path.read_bytes()).hexdigest() != row['source_sha256']:
                raise ValueError('Retained-data source hash mismatch')
            if not re.fullmatch(r'[0-9a-f]{64}',row['original_sha256']):
                raise ValueError('Missing original retained-data provenance')
            owners = list(re.finditer(r'(?m)^([^\s]+\.(?:c|cpp)):\s*$',text))
            owned = False
            for index, owner in enumerate(owners):
                if owner[1] != row['source']:
                    continue
                block = text[owner.end():owners[index+1].start() if index+1<len(owners) else len(text)]
                ranges = re.findall(r'(?m)^\s+'+re.escape(row['section'])+r'\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)',block)
                owned = len(ranges)==1 and tuple(int(x,16) for x in ranges[0]) == (address,address+size)
            if not owned:
                raise ValueError('Retained-data source does not own exact initialized extent')
            payload = root / 'extract' / version / ('arm9_overlays/'+module+'.bin' if module.startswith('ov') else 'arm9/'+('arm9' if module=='arm9' else module)+'.bin')
            if payload.exists():
                section = re.search(r'^\s*\.text\s+start:0x([0-9a-fA-F]+)',text,re.M)
                if section:
                    base = int(section[1],16)
                elif module.startswith('ov'):
                    # Some protected overlays classify their executable payload
                    # as rodata. Use the original overlay's load address, never
                    # a selected source range, as provenance origin.
                    metadata = (payload.parent / 'overlays.yaml').read_text()
                    blocks = re.split(r'^- id:\s*', metadata, flags=re.M)[1:]
                    selected = [block for block in blocks if int(block.splitlines()[0]) == int(module[2:])]
                    if len(selected) != 1:
                        raise ValueError('Cannot derive unique original overlay base')
                    bases = re.findall(r'^  base_address:\s*([0-9]+)\s*$', selected[0], re.M)
                    if len(bases) != 1:
                        raise ValueError('Cannot derive original overlay base')
                    base = int(bases[0])
                else:
                    raise ValueError('Cannot derive original module base')
                start = address-base
                blob = payload.read_bytes()
                if start < 0 or start+size>len(blob) or hashlib.sha256(blob[start:start+size]).hexdigest()!=row['original_sha256']:
                    raise ValueError('Original retained-data byte hash mismatch')
            names.append(row['name'])
    return names


if __name__ == '__main__':
    import argparse
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,required=True)
    parser.add_argument('--version',required=True)
    parser.add_argument('--expected',default='')
    args=parser.parse_args()
    try:
        actual=retained_data_symbols(args.root,args.version)
        expected=args.expected.split(',') if args.expected else []
        if actual != expected:
            raise ValueError('Retained-data policy changed: rerun configure')
    except (OSError,ValueError,KeyError,TypeError) as error:
        parser.exit(2,'Retention validation failed: '+str(error)+'\n')
