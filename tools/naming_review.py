"""Validate exhaustive, hash-bound naming review coverage without inferring semantics."""
from collections import Counter
from pathlib import PurePosixPath
import re


def validate_proposal_shape(proposal):
    """Reject malformed transport fields; this never approves semantics."""
    if not re.fullmatch(r'[A-Za-z_]\w*', proposal.get('new_symbol', '')):
        raise ValueError('Proposal new_symbol must be a linkage identifier')
    source = PurePosixPath(proposal.get('source', ''))
    destination = PurePosixPath(proposal.get('destination', ''))
    if (destination.is_absolute() or '..' in destination.parts or
            not destination.parts or destination.parts[0] != 'src' or
            destination.suffix != source.suffix):
        raise ValueError('Proposal destination must be a canonical same-language source path')
    evidence = proposal.get('evidence', {})
    if evidence.get('reviewed') is not True or not str(evidence.get('note', '')).strip():
        raise ValueError('Proposal needs reviewed evidence and an actual note')




def validate_review(scope, review):
    units = {u['source']: u for u in scope}
    expected = {f['function_id']: (u, f) for u in scope for f in u['functions']}
    rows = review.get('functions', [])
    counts = Counter(r['function_id'] for r in rows)
    if set(counts) != set(expected) or any(n != 1 for n in counts.values()):
        raise ValueError('Review must cover each scoped function identity exactly once')
    unit_rows = review.get('units', [])
    unit_counts = Counter(r['source'] for r in unit_rows)
    if set(unit_counts) != set(units) or any(n != 1 for n in unit_counts.values()):
        raise ValueError('Review must cover each compilation unit exactly once, including data')
    for row in rows:
        unit, original = expected[row['function_id']]
        for key in ('module', 'address', 'symbol', 'source'):
            if row.get(key) != original[key]:
                raise ValueError('Review identity mismatch: ' + key)
        if row.get('source_sha256') != unit['source_sha256']:
            raise ValueError('Review source hash mismatch')
        if row.get('status') not in ('approved_existing', 'proposed_change', 'unresolved'):
            raise ValueError('Invalid review disposition')
        if not row.get('evidence'):
            raise ValueError('Review needs specific evidence')
        if row['status'] == 'unresolved' and not row.get('next_dependency'):
            raise ValueError('Unresolved review needs a next dependency')
    for row in unit_rows:
        if row.get('source_sha256') != units[row['source']]['source_sha256']:
            raise ValueError('Unit source hash mismatch')
        if not row.get('evidence'):
            raise ValueError('Unit review needs placement evidence')
    proposal_ids = [p['function_id'] for p in review.get('proposals', [])]
    if len(set(proposal_ids)) != len(proposal_ids):
        raise ValueError('Duplicate proposal identity')
    for proposal in review.get('proposals', []):
        validate_proposal_shape(proposal)
        identity = proposal['function_id']
        if identity not in expected:
            raise ValueError('Proposal outside scope')
        unit, original = expected[identity]
        if proposal.get('source') != unit['source'] or proposal.get('module') != original['module'] or proposal.get('address') != original['address'] or proposal.get('old_symbol') != original['symbol']:
            raise ValueError('Proposal identity mismatch')
        if proposal.get('evidence', {}).get('source_sha256') != unit['source_sha256']:
            raise ValueError('Proposal source hash mismatch')
    return dict(functions=len(rows), units=len(unit_rows), dispositions=dict(Counter(r['status'] for r in rows)))


def validate_incremental_review(package, review):
    """Authenticate a ready subset; absent package rows remain pending, never approved."""
    units = {u['source']: u for u in package['units']}
    expected = {f['function_id']: (u, f) for u in package['units'] for f in u['functions']}
    rows = review.get('functions', [])
    seen = set()
    for row in rows:
        identity = row['function_id']
        if identity not in expected or identity in seen:
            raise ValueError('Incremental review has outside or duplicate identity')
        seen.add(identity)
        unit, original = expected[identity]
        for key in ('module', 'address', 'symbol', 'source'):
            if row.get(key) != original[key]:
                raise ValueError('Incremental review identity mismatch: ' + key)
        if row.get('source_sha256') != unit['source_sha256']:
            raise ValueError('Incremental review source hash mismatch')
        if row.get('status') not in ('approved_existing', 'proposed_change', 'unresolved') or not row.get('evidence'):
            raise ValueError('Incremental review lacks disposition/evidence')
        if row['status'] == 'unresolved' and not row.get('next_dependency'):
            raise ValueError('Incremental unresolved item lacks actual dependency')
    proposal_ids = [p['function_id'] for p in review.get('proposals', [])]
    if len(set(proposal_ids)) != len(proposal_ids):
        raise ValueError('Duplicate proposal identity')
    for proposal in review.get('proposals', []):
        validate_proposal_shape(proposal)
        identity = proposal['function_id']
        if identity not in seen:
            raise ValueError('Proposal has no reviewed subset identity')
        unit, original = expected[identity]
        for key, target in (('module','module'),('address','address'),('old_symbol','symbol'),('source','source')):
            if proposal.get(key) != original[target]:
                raise ValueError('Incremental proposal identity mismatch: ' + key)
        if proposal.get('evidence', {}).get('source_sha256') != unit['source_sha256']:
            raise ValueError('Incremental proposal source hash mismatch')
    pending = sorted(set(expected) - seen)
    return dict(reviewed_functions=len(seen), pending_function_ids=pending,
                package_complete=not pending, proposals=len(review.get('proposals', [])))
