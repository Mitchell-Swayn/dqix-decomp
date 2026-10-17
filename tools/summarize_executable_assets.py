#!/usr/bin/env python3
"""Separate source-associated script structure from opaque native-code questions."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re


def summarize(audit, bcfg_source):
    if audit.get('nitrofs_equal') is not True:
        raise ValueError('Asset byte preservation not verified')
    opcodes = {int(value,16) for value in re.findall(r'\{\s*(0x[0-9a-fA-F]+),\s*&BCFGScript_',bcfg_source)}
    if not opcodes:
        raise ValueError('No BCFG opcode lookup evidence')
    associated=[];unknown=[];native=[];counts=Counter()
    for row in audit['records']:
        shape=row.get('script_structure_candidate')
        if shape:
            suffix=Path(row['path'].removesuffix('::@lz77')).suffix
            counts[suffix]+=1
            if suffix=='.bcfg':
                values={int(value) for value in shape['opcodes']}
                associated.append({'path':row['path'],'size':row['size'],'sha256':row['sha256'],
                    'instructions':shape['instructions'],'unsupported_lookup_opcodes':sorted(values-opcodes),
                    'association':'Object3D .bcfg selection -> BCFG::LoadFromScript -> Script::Execute',
                    'status':'source-associated interpreted configuration; no semantic execution proof'})
        for candidate in row.get('native_header_candidates',[]):
            native.append({'path':row['path'],'sha256':row['sha256'],**candidate})
        if 'container_error' in row or 'compression_error' in row:
            unknown.append({'path':row['path'],'reason':'container/decompression error'})
        elif row['path']=='dwc/utility.bin' or Path(row['path']).suffix=='.pac':
            unknown.append({'path':row['path'],'size':row['size'],'sha256':row['sha256'],
                            'reason':'opaque format; neither raw native-code nor script content ruled out'})
    statuses=Counter(item.get('structure',{}).get('status','signature-only') for item in native)
    return {'schema_version':1,'source_coverage_credit':0,'nitrofs_equal':True,
            'top_level_files':audit['top_level_files'],'records_including_members':len(audit['records']),
            'named_file_size_sum':sum(row['size'] for row in audit['records'] if '::' not in row['path']),
            'native_code_absence_verified':False,
            'decoded_member_size_accounting':'separate decoded domains; never added to stored file or executable denominators',
            'all_records_native_content_status':'unknown beyond validated structural header triage; raw ARM/Thumb absence unproved',
            'script_candidate_extensions':dict(sorted(counts.items())),
            'bcfg_lookup_opcodes':sorted(opcodes),'source_associated_bcfg':associated,
            'native_signature_findings':native,'native_signature_statuses':dict(statuses),
            'unresolved_payloads':unknown,
            'limitations':['Weak executable signatures cannot detect or exclude raw ARM/Thumb code.',
                           'Structural script matches alone do not establish interpreter association.',
                           'Source-associated BCFG opcode tables do not prove runtime behavior or complete script semantics.',
                           'Opaque files and decoded members remain native/script-content unknown; no executable absence claim.']}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--audit',type=Path,required=True);parser.add_argument('--project',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    paths=[args.project/name for name in ['src/Resource/BCFG.cpp','src/Resource/Script.cpp','include/Resource/Script.h','src/World/Object3D.cpp']]
    frozen={str(path.relative_to(args.project)):path.read_bytes() for path in paths}
    audit=args.audit.read_bytes();result=summarize(json.loads(audit),frozen['src/Resource/BCFG.cpp'].decode())
    result['audit_sha256']=hashlib.sha256(audit).hexdigest()
    result['source_evidence_sha256']={name:hashlib.sha256(content).hexdigest() for name,content in frozen.items()}
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'source_associated_bcfg':len(result['source_associated_bcfg']),
                      'native_signature_statuses':result['native_signature_statuses'],
                      'opaque_payloads':len(result['unresolved_payloads'])},indent=2))


if __name__=='__main__':main()
