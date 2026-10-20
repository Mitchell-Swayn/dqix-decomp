#!/usr/bin/env python3
"""Account for every ARM7 payload/BSS byte without guessing mixed-unit positions."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path

from arm7_build import validate_layout
from arm7_inventory_ranges import validate_inventory
from check_arm7 import read_arm7, sha1_file


def partition(lower, upper, claims):
    """Split at every boundary; overlapping claims must agree, unknown fills gaps."""
    if upper <= lower:
        raise ValueError('Empty partition domain')
    cuts = {lower, upper}
    for item in claims:
        start, end = item['start'], item['end']
        if not lower <= start < end <= upper:
            raise ValueError('Claim outside domain')
        cuts.update((start, end))
    cuts = sorted(cuts)
    result = []
    for start, end in zip(cuts, cuts[1:]):
        active = [item for item in claims if item['start'] <= start and end <= item['end']]
        kinds = {item['classification'] for item in active}
        if len(kinds) > 1:
            raise ValueError('Conflicting classification claims')
        result.append({'start': start, 'end': end, 'size': end-start,
                       'classification': next(iter(kinds)) if kinds else 'unknown',
                       'evidence': sorted({item['evidence'] for item in active})})
    if sum(row['size'] for row in result) != upper-lower:
        raise AssertionError('Partition accounting failed')
    return result


def build(payload, baseline, config, inventory, additional_claims=()):
    if len(payload) != baseline['size'] or hashlib.sha1(payload).hexdigest() != baseline['payload_sha1']:
        raise ValueError('Original payload mismatch')
    validate_layout(payload, baseline, config)
    validate_inventory(inventory, baseline, config)
    claims = []
    for scope in inventory['scopes']:
        for row in scope['ranges']:
            start = int(row['payload_offset'],16)
            claims.append({'start':start,'end':start+int(row['size'],16),
                           'classification':row['classification'],
                           'evidence':'inventory:' + scope['name'] + ': ' + row['evidence']})
    table = config['autoload_table_offset']
    claims.append({'start':table,'end':len(payload),'classification':'initialized_data',
                   'evidence':'Original startup copy descriptor table; validated exact words'})
    constraints = []
    entries = []
    for unit in config['units']:
        size = unit['size']; start = unit['payload_offset']
        classes = {'instruction':unit['code_bytes'], 'literal_pool':unit['literal_pool_bytes'],
                   'initialized_data':unit.get('data_bytes',0),
                   'assembly_instruction':unit.get('reviewed_assembly_bytes',0)}
        if size:
            homogeneous = [key for key,value in classes.items() if value == size]
            if homogeneous:
                # These are source-manifest facts, not independently recovered function extents.
                kind = 'instruction' if homogeneous[0] == 'assembly_instruction' else homogeneous[0]
                claims.append({'start':start,'end':start+size,'classification':kind,
                               'evidence':'homogeneous-source-unit:' + unit['name']})
            else:
                constraints.append({'unit':unit['name'],'start':start,'end':start+size,
                                    'aggregate_classes':classes,
                                    'positions':'unknown; aggregate counts are not interval boundaries'})
        if not unit.get('data_bytes',0):
            for name,address in unit['symbols'].items():
                entries.append({'name':name,'runtime_address':address,
                                'payload_offset':start + (address & ~1)-unit['runtime_address'],
                                'mode':'thumb' if address&1 else 'arm',
                                'evidence':'source_units.symbols:' + unit['name'],
                                'extent':'not inferred from next symbol'})
    claims.extend(additional_claims)
    rows = partition(0,len(payload),claims)
    modules = [{'name':'startup','payload_offset':0,'runtime_address':baseline['load_address'],
                'size':config['startup_size']},*config['autoloads'],
               {'name':'copy_descriptors','payload_offset':table,
                'runtime_address':baseline['load_address']+table,'size':len(payload)-table}]
    # Split at mapping boundaries even when no classification boundary exists there.
    mapped = []
    for module in modules:
        low=module['payload_offset'];high=low+module['size']
        for row in rows:
            start=max(low,row['start']);end=min(high,row['end'])
            if start<end:
                mapped.append({**row,'start':start,'end':end,'size':end-start,'module':module['name'],
                               'runtime_start':module['runtime_address']+start-low,
                               'runtime_end':module['runtime_address']+end-low,
                               'original_sha256':hashlib.sha256(payload[start:end]).hexdigest()})
    if sum(row['size'] for row in mapped)!=len(payload):raise AssertionError('Mapping accounting failed')
    bss=[]
    for module in config['autoloads']:
        lower=module['runtime_address']+module['size'];upper=lower+module['bss_size']
        owned=[]
        for unit in config['units']:
            if unit['autoload']==module['name'] and 'bss' in unit:
                data=unit['bss'];owned.append({'start':data['runtime_address'],
                    'end':data['runtime_address']+data['size'],'classification':'bss',
                    'evidence':'source-unit-bss:' + unit['name']})
        for row in partition(lower,upper,owned):
            bss.append({**row,'module':module['name'],'classification':'bss',
                        'source_definition':'defined' if row['evidence'] else 'unknown',
                        'storage':'zero-filled by original copy loop; no ROM payload offset'})
    counts=Counter()
    for row in mapped:counts[row['classification']]+=row['size']
    # Aggregate constraints can bound the denominator without pretending to locate bytes.
    constrained_unknown = Counter()
    for constraint in constraints:
        known = Counter()
        for row in mapped:
            length = max(0, min(row['end'], constraint['end']) - max(row['start'], constraint['start']))
            if length:
                known[row['classification']] += length
        remaining = {}
        for kind, total in constraint['aggregate_classes'].items():
            if kind == 'assembly_instruction':
                continue  # Mixed reviewed assembly units are rejected by validate_layout.
            remaining[kind] = total - known[kind]
            if remaining[kind] < 0:
                raise ValueError('Independent range contradicts mixed-unit aggregate: ' + constraint['unit'])
        if sum(remaining.values()) != known['unknown']:
            raise ValueError('Mixed-unit aggregate constraint does not account for residual bytes')
        constraint['remaining_unknown_composition'] = remaining
        constrained_unknown.update(remaining)
    unconstrained_unknown = counts['unknown'] - sum(constrained_unknown.values())
    if unconstrained_unknown < 0:
        raise ValueError('Mixed-unit constraints overlap')
    minimum_code = counts['instruction'] + constrained_unknown['instruction']
    known_entries={(row['runtime_address']&~1,row['mode']) for row in entries}
    return {'schema_version':1,'source_coverage_credit':0,'payload_size':len(payload),
            'payload_sha1':hashlib.sha1(payload).hexdigest(), 'payload_totals':dict(sorted(counts.items())),
            'payload_intervals':mapped,'mixed_unit_constraints':constraints,'source_entry_seeds':entries,
            'instruction_byte_bounds':{'minimum':minimum_code,'maximum':minimum_code+unconstrained_unknown,
                                       'unconstrained_unknown_bytes':unconstrained_unknown,
                                       'status':'bounds only; never use as a fixed source-coverage denominator'},
            'distinct_source_entry_seeds':len(known_entries),'function_denominator':None,
            'function_denominator_status':'unknown: uncovered payload, mixed-unit positions and indirect-call targets remain unresolved',
            'bss_size':sum(row['size'] for row in bss),'bss_intervals':bss,
            'bss_source_defined':sum(row['size'] for row in bss if row['source_definition']=='defined'),
            'limitations':['Homogeneous source-unit classifications are manifest facts, not new independent disassembly proofs.',
                           'Mixed code/literal totals constrain composition but do not locate bytes; unknown intervals retain these constraints.',
                           'Entry seeds are not a total-function denominator; shared entries, thunks, callbacks and unknown residual code need review.',
                           'BSS is runtime storage, accounted independently and never appended to stored payload/code denominators.']}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project',type=Path,required=True)
    parser.add_argument('--original',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--boundary-proposal',type=Path)
    args=parser.parse_args();paths={key:args.project/'config/usa/arm7'/name for key,name in
        [('baseline','baseline.json'),('config','source_units.json'),('inventory','inventory_ranges.json')]}
    frozen={key:path.read_bytes() for key,path in paths.items()}
    inputs={key:json.loads(content) for key,content in frozen.items()}
    header,payload=read_arm7(args.original)
    baseline=inputs['baseline']
    if sha1_file(args.original)!=baseline['source_rom_sha1']:raise ValueError('Original ROM SHA1 mismatch')
    for key in ('rom_offset','entry_address','load_address','size','overlay_table_size','payload_sha1'):
        if header[key]!=baseline[key]:raise ValueError('Original header mismatch: '+key)
    additions=[]; boundary_records=[]
    if args.boundary_proposal:
        from arm7_boundary_evidence import verify_proposal
        proposal_bytes=args.boundary_proposal.read_bytes()
        additions,boundary_records=verify_proposal(json.loads(proposal_bytes),payload,baseline,inputs['config'])
    result=build(payload,**inputs,additional_claims=additions)
    result['additional_boundary_records']=boundary_records
    if args.boundary_proposal:
        result['boundary_proposal_sha256']=hashlib.sha256(proposal_bytes).hexdigest()
        result['boundary_proposal_document']=json.loads(proposal_bytes)
    result['input_sha256']={key:hashlib.sha256(content).hexdigest() for key,content in frozen.items()}
    result['input_documents']=inputs
    result['original_rom_sha1']=baseline['source_rom_sha1']
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({key:result[key] for key in ('payload_size','payload_totals','bss_size','bss_source_defined','function_denominator')},indent=2))


if __name__=='__main__':main()
