"""Explicit, evidence-bound runtime policy shared by acceptance and C queues."""
import hashlib
import json
from pathlib import Path

POLICY = Path('config/usa/arm9/runtime_support.json')
COMPILER_PHRASE = 'Compiler runtime support:'
SDK_PHRASE = 'SDK support (community reconstruction):'
SDK_CLASS = 'sdk_reconstruction'
HEX40 = set('0123456789abcdef')


def evidence_class(row):
    """Rows predating evidence classes are compiler runtime; the class is never inferred otherwise."""
    return row.get('evidence_class', 'compiler_runtime')


def summarize(rows):
    """Count accepted assembly by evidence class; none of it is C/C++ reconstruction."""
    result = {'assembly_functions': 0, 'assembly_bytes': 0, 'compiler_runtime_functions': 0,
              'compiler_runtime_bytes': 0, 'sdk_reconstruction_functions': 0,
              'sdk_reconstruction_bytes': 0}
    for row in rows:
        if row['classification'] != 'runtime_assembly':
            continue
        prefix = 'sdk_reconstruction' if evidence_class(row) == SDK_CLASS else 'compiler_runtime'
        result['assembly_functions'] += 1
        result['assembly_bytes'] += row['size']
        result[prefix + '_functions'] += 1
        result[prefix + '_bytes'] += row['size']
    return result


def _sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def _inside(worker, relative):
    """Resolve a recorded evidence path; it must stay within the worker and not be a symlink."""
    worker = Path(worker).resolve()
    path = worker / relative
    if (Path(relative).is_absolute() or '..' in Path(relative).parts or path.is_symlink() or
            not path.resolve().is_relative_to(worker) or not path.is_file()):
        raise ValueError('SDK evidence path is not a regular file inside the worker: ' + str(relative))
    return path


def _bound(worker, record, path_key, hash_key):
    if _sha256(_inside(worker, record[path_key])) != record[hash_key]:
        raise ValueError('SDK evidence file differs from its pinned hash: ' + record[path_key])
    return _inside(worker, record[path_key])


def validate_sdk_row(worker, row, function):
    """Bind a community-reconstruction row to pinned sources, instruction identity and a fresh object check.

    No vendor library, object or package field may be asserted: the origin is a reconstruction.
    """
    mode = row.get('mode', 'arm')
    if mode not in ('arm', 'thumb'):
        raise ValueError('Invalid SDK instruction mode')
    if 'mode' in function and function['mode'] != mode:
        raise ValueError('SDK instruction mode differs from source function')
    width = 2 if mode == 'thumb' else 4
    if row['size'] <= 0 or row['size'] % width:
        raise ValueError('SDK function size is not aligned to its instruction mode')
    evidence = row.get('evidence', {})
    if (evidence_class(row) != SDK_CLASS or row['classification'] != 'runtime_assembly' or
            row.get('assembly_form') != 'codewarrior_inline' or row.get('c_reconstruction_eligible') is not False or
            not str(row['source']).startswith('src/RuntimeSupport/') or not str(row['source']).endswith('.cpp')):
        raise ValueError('SDK reconstruction rows must be ineligible inline assembly in src/RuntimeSupport')
    if (evidence.get('origin') != 'community_reconstruction' or evidence.get('vendor_archive_match') is not False or
            evidence.get('library') is not None or evidence.get('object') is not None or
            not evidence.get('symbols') or evidence.get('size') != row['size'] or
            any(key in evidence for key in ('package_url', 'package_sha256', 'vendor_source_files'))):
        raise ValueError('SDK evidence must be an unmatched community reconstruction without vendor fields')
    sources = evidence.get('external_sources')
    if not sources:
        raise ValueError('SDK evidence needs pinned external sources')
    for source in sources:
        commit = str(source.get('commit', ''))
        if (len(commit) != 40 or set(commit) - HEX40 or commit not in source.get('url', '') or
                source.get('path', '') not in source.get('url', '') or not source.get('repository')):
            raise ValueError('SDK external source must pin repository, commit, path and URL')
        _bound(worker, source, 'local_copy', 'sha256')
    identity = evidence.get('instruction_identity', {})
    comparison = json.loads(_bound(worker, identity, 'comparison', 'comparison_sha256').read_text())
    variants = identity.get('variants')
    if (not variants or comparison['original_sha256'] != row['original_sha256'] or
            identity.get('instructions') != row['size'] // width or len(comparison['original_words']) != row['size'] // width):
        raise ValueError('SDK instruction identity does not cover the original function')
    for name in variants:
        variant = comparison['variants'][name]
        if (variant['equals_original'] is not True or variant['assembled_sha256'] != row['original_sha256'] or
                variant['instruction_count'] != row['size'] // width):
            raise ValueError('SDK instruction variant does not equal the original: ' + name)
    fresh = evidence.get('fresh_object_check', {})
    result = json.loads(_bound(worker, fresh, 'result', 'result_sha256').read_text())
    raw = json.loads(_bound(worker, fresh, 'bytes', 'bytes_sha256').read_text())
    candidate = _bound(worker, fresh, 'candidate_source', 'candidate_source_sha256')
    if (result.get('status') != 'compared' or result.get('match') is not True or result.get('raw_match') is not True or
            result.get('object_match') is not True or result.get('mismatches') != 0 or
            result.get('unit') != str(Path(row['source']).with_suffix('')) or
            raw.get('raw_match') is not True or
            [(f['symbol'], f['target_bytes'], f['candidate_bytes'], f['raw_match'], f['relocations_present'])
             for f in raw.get('functions', [])] != [(row['name'], row['size'], row['size'], True, False)] or
            fresh['candidate_source_sha256'] != row['source_sha256'] or _sha256(candidate) != row['source_sha256'] or
            result.get('rom_acceptance') is not False):
        raise ValueError('SDK fresh object check does not bind this source and the original bytes')
    manifest = evidence.get('evidence_manifest')
    if not manifest:
        raise ValueError('SDK evidence needs its hashed evidence manifest')
    _bound(worker, manifest, 'path', 'sha256')
    if function.get('function_id', comparison['function_id']) != comparison['function_id']:
        raise ValueError('SDK instruction identity names a different function')


def load(root):
    path = Path(root) / POLICY
    if not path.exists():
        return []
    document = json.loads(path.read_text())
    if document.get('schema_version') != 1:
        raise ValueError('Unknown runtime support policy schema')
    rows = document['functions']
    keys = [(r['module'], int(r['address'], 0)) for r in rows]
    if len(keys) != len(set(keys)):
        raise ValueError('Duplicate runtime function identity')
    return rows


def excluded(root):
    return {(r['module'], int(r['address'], 0)): r for r in load(root)}


def _source_phrase(row):
    return SDK_PHRASE if evidence_class(row) == SDK_CLASS else COMPILER_PHRASE


def _check_selected(worker, row, function):
    source = Path(worker) / row['source']
    if not source.is_file():
        raise ValueError('Runtime policy source is missing from the worker: ' + row['source'])
    text = source.read_text()
    other = COMPILER_PHRASE if evidence_class(row) == SDK_CLASS else SDK_PHRASE
    if (source.suffix not in ('.s', '.cpp') or row['module'] != 'arm9/main' or
        row['name'] != function['name'] or int(row['address'], 0) != int(function['address'], 16) or
        row['size'] != function['size'] or row['original_sha256'] != function['original_sha256'] or
        hashlib.sha256(source.read_bytes()).hexdigest() != row['source_sha256'] or
        _source_phrase(row) not in text or other in text):
        raise ValueError('Runtime policy identity/source differs from selected evidence')


def _original_bytes_ok(main, row):
    path = Path(main) / 'extract/usa/arm9/arm9.bin'
    start = int(row['address'], 0) - 0x02000000
    if not path.is_file() or start < 0:
        raise ValueError('Original ARM9 bytes are required to bind an appended helper')
    data = path.read_bytes()
    return start + row['size'] <= len(data) and hashlib.sha256(data[start:start + row['size']]).hexdigest() == row['original_sha256']


def _capture_append(main, worker, manifest, prior_bytes):
    """Append only authenticated new assembly rows; every accepted row and top-level key stays byte-identical."""
    if manifest.get('runtime_support') is not None or manifest.get('runtime_replacement'):
        raise ValueError('A runtime append is exclusive of acceptance and replacement')
    if prior_bytes is None:
        raise ValueError('Runtime append requires an accepted prior policy')
    document = manifest['runtime_append']
    prior = json.loads(prior_bytes)
    if document.get('schema_version') != 1 or prior.get('schema_version') != 1 or set(document) - {'schema_version', 'functions'}:
        raise ValueError('Invalid runtime append document')
    rows = document['functions']
    selected = {r['source']: r for r in manifest['functions']}
    if not rows or {r['source'] for r in rows} != set(selected) or len(rows) != len(selected) or manifest.get('data'):
        raise ValueError('Runtime append must cover exactly the selected source units')
    old_identity = {(r['module'], int(r['address'], 0)) for r in prior['functions']}
    old_names = {r['name'] for r in prior['functions']}
    old_sources = {r['source'] for r in prior['functions']}
    for row in rows:
        if ((row['module'], int(row['address'], 0)) in old_identity or row['name'] in old_names or
                row['source'] in old_sources):
            raise ValueError('Runtime append duplicates an accepted helper identity')
        function = selected[row['source']]
        _check_selected(worker, row, function)
        if row.get('retained_fallback_code') is not None:
            from runtime_code_retention import retained_symbols
            retained_symbols(main, row, source_root=worker)
        if evidence_class(row) == SDK_CLASS:
            validate_sdk_row(worker, row, function)
        elif evidence_class(row) == "compiler_runtime":
            from runtime_vendor import validate_compiler_row
            validate_compiler_row(main, worker, row, function)
        else:
            raise ValueError("Unrecognized appended runtime evidence class")
        if not _original_bytes_ok(main, row):
            raise ValueError('Original ARM9 bytes differ from the appended helper hash')
    after = dict(prior, functions=prior['functions'] + rows)
    if prior_bytes != (json.dumps(prior, indent=2) + '\n').encode():
        raise ValueError('Accepted policy is not canonically serialized; refusing to rewrite it')
    return {'mode': 'append', 'before': prior_bytes, 'after': (json.dumps(after, indent=2) + '\n').encode(),
            'appended': [r['name'] for r in rows], 'appended_bytes': sum(r['size'] for r in rows)}


def capture(main, worker, manifest):
    path = Path(main) / POLICY
    before = path.read_bytes() if path.exists() else None
    if manifest.get('runtime_append') is not None:
        return _capture_append(main, worker, manifest, before)
    document = manifest.get('runtime_support')
    if document is None:
        if manifest.get('runtime_replacement'):
            raise ValueError('Runtime replacement requires an evidence-bound policy')
        return None
    if document.get('schema_version') != 1:
        raise ValueError('Invalid runtime acceptance policy')
    selected = {r['source']: r for r in manifest['functions']}
    assembly = [r for r in document['functions'] if r['classification'] == 'runtime_assembly']
    if {r['source'] for r in assembly} != set(selected):
        raise ValueError('Runtime assembly policy must cover exactly the selected source units')
    if any(evidence_class(r) == SDK_CLASS for r in document['functions']):
        raise ValueError('SDK reconstruction rows are accepted only through a runtime append')
    for row in assembly:
        _check_selected(worker, row, selected[row['source']])
    if manifest.get('runtime_replacement'):
        if before is None:
            raise ValueError('Runtime replacement requires an accepted prior policy')
        prior = json.loads(before)
        old_rows = {r['name']: r for r in prior['functions']}
        if len(old_rows) != len(document['functions']) or set(old_rows) != {r['name'] for r in document['functions']}:
            raise ValueError('Runtime replacement changed the accepted helper set')
        for row in document['functions']:
            old = old_rows[row['name']]
            if row['classification'] != 'runtime_assembly':
                if old != row:
                    raise ValueError('Runtime replacement changed existing C helpers')
                continue
            if (row['source'] != str(Path(old['source']).with_suffix('.cpp')) or
                old['source'].endswith('.cpp') or row.get('assembly_form') != 'codewarrior_inline' or
                any(old[k] != row[k] for k in ('module','address','name','size','original_sha256','evidence')) or
                hashlib.sha256((Path(main)/old['source']).read_bytes()).hexdigest() != old['source_sha256'] or
                'extern "C" asm void ' + row['name'] not in (Path(worker)/row['source']).read_text()):
                raise ValueError('Runtime replacement changed its accepted identity or source')
    elif before is not None:
        raise ValueError('Existing runtime policy requires an explicit append transaction')
    return {'before': before, 'after': (json.dumps(document, indent=2) + '\n').encode()}


def install(root, snapshot):
    if snapshot:
        (Path(root) / POLICY).write_bytes(snapshot['after'])


def verify(root, snapshot):
    if snapshot and (Path(root) / POLICY).read_bytes() != snapshot['after']:
        raise ValueError('Runtime policy changed during acceptance')


def restore(root, snapshot):
    if snapshot:
        path = Path(root) / POLICY
        if snapshot['before'] is None:
            path.unlink(missing_ok=True)
        else:
            path.write_bytes(snapshot['before'])


def report_aliases(root, snapshot):
    """Verify objdiff's existing nested runtime labels without claiming extra routines."""
    if not snapshot:
        return []
    appended = snapshot.get('mode') == 'append'
    policy = json.loads(snapshot['after'])
    aliases = policy.get('report_aliases', [])
    extension = '.cpp' if all(r.get('assembly_form') == 'codewarrior_inline' for r in policy['functions'] if r['classification'] == 'runtime_assembly') else '.s'
    expected = {('src/RuntimeSupport/_fdiv' + extension, '.L_0200c274', 256),
                ('src/RuntimeSupport/_ddiv' + extension, '.L_0200d484', 256),
                ('src/RuntimeSupport/_u32_div_f' + extension, '.L_0200d158', 500)}
    if {(r['source'], r['name'], r['size']) for r in aliases} != expected or len(aliases) != 3:
        raise ValueError('Runtime report aliases differ from the reviewed overlapping symbols')
    units = json.loads((Path(root) / 'build/usa/report.json').read_text())['units']
    for row in aliases:
        unit = next(u for u in units if u.get('metadata', {}).get('source_path') == row['source'])
        function = next(f for f in unit['functions'] if f['name'] == row['name'])
        if int(function['size']) != row['size'] or function.get('fuzzy_match_percent') != 100:
            raise ValueError('Runtime report alias no longer matches')
    # Nested labels were counted when the accepted policy was first installed.
    return [] if appended else aliases
