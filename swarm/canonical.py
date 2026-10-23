"""Compiler-backed canonical interface preflight. Never edits submitted source.

The process lock protects short snapshots, not compiler work. A second snapshot
binds the result to the accepted tree; submit holds that lock through enqueue.
"""
import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import tempfile


class StateUnavailable(RuntimeError):
    pass


@contextlib.contextmanager
def accepted_read(project):
    directory = project.root / 'build/progress'
    directory.mkdir(parents=True, exist_ok=True)
    with (directory / 'integration-process.lock').open('a') as stream:
        try:
            fcntl.flock(stream, fcntl.LOCK_SH | fcntl.LOCK_NB)
        except BlockingIOError:
            raise StateUnavailable('integration is active; retry after publication') from None
        try:
            if (directory / 'integration.lock').exists():
                raise StateUnavailable('accepted state is unpublished; retry after integration recovery')
            yield
        finally:
            fcntl.flock(stream, fcntl.LOCK_UN)


# Supported free function signatures, including multiline parameters and calling
# convention macros. Bodies and comments are excluded, not interpreted as types.
SIGNATURE = re.compile(r'(?m)(?:^|(?<=[;{}]))[ \t]*((?:(?:extern\s+"C"\s+)?[\w:*&<>]+[ \t\n]+)+(?:[*&]\s*)*([A-Za-z_]\w*)\s*\([^;{}]*?\)\s*)([;{])')


def signatures(text, suffix):
    clean = re.sub(r'/\*.*?\*/|//[^\n]*', lambda m: re.sub(r'[^\n]', ' ', m[0]), text, flags=re.S)
    depth = 0
    c_blocks = []
    cursor = 0
    for match in SIGNATURE.finditer(clean):
        # Track linkage scopes, avoiding function-local declarations/definitions.
        for token in re.finditer(r'extern\s+"C"\s*\{|[{}]', clean[cursor:match.start()]):
            if token[0].endswith('{'):
                depth += 1
                if token[0].startswith('extern'):
                    c_blocks.append(depth)
            else:
                if depth in c_blocks:
                    c_blocks.remove(depth)
                depth -= 1
        cursor = match.start()
        if depth != len(c_blocks):
            continue
        decl = match[1].strip()
        if re.search(r'\b(?:return|if|while|asm|__asm|typedef|static)\b', decl):
            continue
        c_link = suffix == '.c' or bool(c_blocks) or '"C"' in decl
        decl = re.sub(r'^extern\s+"C"\s+', '', decl)
        yield dict(name=match[2], decl=decl + ';', c_link=c_link,
                   definition=match[3] == '{', start=match.start(),
                   line=clean.count('\n', 0, match.start()) + 1)


# A cache is valid only for this parser and the exact stat identities below.
# ctime catches same-size edits even when a caller restores mtime; inode catches
# atomic replacement. No Git revision or global SQLite data_version is trusted.
INDEX_VERSION = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
_MEMORY_INDEX = {}


def _stamp(stat):
    return [stat.st_dev, stat.st_ino, stat.st_mode, stat.st_size,
            stat.st_mtime_ns, stat.st_ctime_ns]


def _manifest(root):
    result = {}
    def walk(directory, prefix):
        with os.scandir(directory) as entries:
            for entry in entries:
                if entry.name == 'AssemblyFallback':
                    continue
                relative = prefix + '/' + entry.name
                if entry.is_dir(follow_symlinks=False):
                    walk(entry.path, relative)
                elif entry.is_file():
                    stamp = _stamp(entry.stat())
                    if entry.is_symlink():
                        stamp += _stamp(entry.stat(follow_symlinks=False))
                    result[relative] = stamp
    for base in ('src', 'include', 'config'):
        directory = root / base
        if directory.exists():
            walk(directory, base)
    return dict(sorted(result.items()))


def _file_record(root, relative, stamp):
    path = root / relative
    data = path.read_bytes()
    current = _stamp(path.stat())
    if path.is_symlink():
        current += _stamp(path.lstat())
    if current != stamp:
        raise StateUnavailable(f'{relative} changed while indexing; retry')
    definitions = []
    declarations = []
    content = data.decode(errors='replace') if path.suffix in ('.c', '.cpp', '.h', '.hpp') else ''
    headers = []
    for header in re.findall(r'^\s*#\s*include\s*[<"]([^>"]+)', content, re.M):
        if (root / 'include' / header).is_file():
            headers.append(header)
    type_names = sorted(set(re.findall(r'\b(?:struct|class|enum)\s+(\w+)', content)))
    for row in signatures(content, path.suffix):
        if not row['definition']:
            declarations.append(dict(name=row['name'], decl=row['decl'],
                                     c_link=row['c_link'], line=row['line']))
    if relative.startswith('src/') and path.suffix in ('.c', '.cpp') and 'RuntimeSupport' not in path.parts:
        content = data.decode(errors='replace')
        for row in signatures(content, path.suffix):
            if row['definition']:
                definitions.append(dict(name=row['name'], decl=row['decl'], c_link=row['c_link'],
                                        path=f'{relative}:{row["line"]}', authority='owning-definition', context_headers=headers,
                                        local_type_names=type_names))
    return dict(stamp=stamp, sha256=hashlib.sha256(data).hexdigest(), definitions=definitions,
                declarations=declarations,
                context_headers=headers, type_names=type_names)


def _accepted_assembly_owners(root, files):
    """Use explicit typed SDK assembly interfaces only from hash-pinned policy.

    Untyped asm entry wrappers remain inventory, not interface evidence. Read
    policy on every snapshot so cached source records cannot outlive approval.
    """
    policy_path = 'config/usa/arm9/runtime_support.json'
    if policy_path not in files:
        return []
    policy_bytes = (root / policy_path).read_bytes()
    if hashlib.sha256(policy_bytes).hexdigest() != files[policy_path]['sha256']:
        raise StateUnavailable('assembly policy changed while indexing; retry')
    policy = json.loads(policy_bytes)
    result = []
    for entry in policy['functions']:
        if (entry.get('classification') != 'runtime_assembly'
                or entry.get('assembly_form') != 'codewarrior_inline'):
            continue
        relative = entry['source']
        if (not relative.startswith('src/RuntimeSupport/')
                or '..' in Path(relative).parts
                or Path(relative).as_posix() != relative):
            raise StateUnavailable('noncanonical accepted assembly source')
        record = files.get(relative)
        if not record or record['sha256'] != entry['source_sha256']:
            raise StateUnavailable('accepted assembly source hash changed: ' + relative)
        path = root / relative
        data = path.read_bytes()
        if path.is_symlink() or hashlib.sha256(data).hexdigest() != record['sha256']:
            raise StateUnavailable('accepted assembly source changed while indexing')
        text = data.decode()
        clean = re.sub(r'/\*.*?\*/|//[^\n]*',
                       lambda m: re.sub(r'[^\n]', ' ', m[0]), text, flags=re.S)
        typed_names = set()
        for match in SIGNATURE.finditer(clean):
            if match[3] != '{' or not re.search(r'\b(?:asm|__asm)\b', match[1]):
                continue
            params = match[1].split('(', 1)[1].rsplit(')', 1)[0].strip()
            if params and params != 'void':
                typed_names.add(match[2])
        if entry['name'] not in typed_names:
            continue
        # Preserve line locations; the ordinary parser still checks linkage and
        # scope. Only the policy-selected explicit assembly definition is used.
        ordinary = re.sub(r'\b(?:asm|__asm)\b', lambda m: ' ' * len(m[0]), clean)
        for row in signatures(ordinary, path.suffix):
            if row['definition'] and row['name'] == entry['name'] and row['c_link']:
                result.append(dict(name=row['name'], decl=row['decl'], c_link=True,
                                   path=f'{relative}:{row["line"]}',
                                   authority='accepted-assembly-definition',
                                   context_headers=record['context_headers'],
                                   local_type_names=record['type_names'],
                                   source_sha256=record['sha256'],
                                   policy_sha256=files[policy_path]['sha256']))
    return result


def _load_index(project):
    path = project.state / 'canonical-index.cache'
    try:
        stamp = _stamp(path.stat())
        memory = _MEMORY_INDEX.get(str(project.root))
        if memory and memory[0] == stamp:
            return memory[1]
        checksum, payload = path.read_bytes().split(b'\n', 1)
        if hashlib.sha256(payload).hexdigest().encode() != checksum:
            return None
        index = json.loads(payload)
        if index['version'] != INDEX_VERSION or index['root'] != str(project.root):
            return None
        # Cache corruption is a miss, never an acceptance shortcut.
        for record in index['files'].values():
            if not isinstance(record['stamp'], list) or len(record['sha256']) != 64 or not isinstance(record['definitions'], list):
                return None
        _MEMORY_INDEX[str(project.root)] = (stamp, index)
        return index
    except (OSError, ValueError, KeyError, TypeError):
        return None


def _publish_index(project, index):
    project.state.mkdir(parents=True, exist_ok=True)
    path = project.state / 'canonical-index.cache'
    descriptor, temporary = tempfile.mkstemp(prefix='canonical-index-', suffix='.tmp', dir=project.state)
    try:
        payload = json.dumps(index, separators=(',', ':')).encode()
        with os.fdopen(descriptor, 'wb') as stream:
            stream.write(hashlib.sha256(payload).hexdigest().encode() + b'\n' + payload)
        os.replace(temporary, path)
        _MEMORY_INDEX[str(project.root)] = (_stamp(path.stat()), index)
    finally:
        Path(temporary).unlink(missing_ok=True)


def _declarations(db):
    # Both queries share a SQLite read snapshot. Queue/event writes do not
    # invalidate the declaration index, but every decl/rename edit is rehashed.
    db.execute('SAVEPOINT canonical_read')
    try:
        cache = [dict(r) for r in db.execute('SELECT name,decl,path FROM decls ORDER BY name')]
        renames = [tuple(r) for r in db.execute('SELECT old,new FROM renames ORDER BY old,new')]
    finally:
        db.execute('RELEASE canonical_read')
    return cache, renames


def snapshot(project, db):
    """Caller holds accepted_read. Reuse hashes/parses only for unchanged files.

    The ignored, atomically published index works across fresh CLI processes.
    Every use still stats the complete input tree and reads declaration tables.
    The returned token includes stat identities, so edit/revert during compiler
    work fails closed too. No main/source lock is held by the compiler.
    """
    try:
        manifest = _manifest(project.root)
        index = _load_index(project)
        previous = index['files'] if index else {}
        if not index or manifest != index.get('manifest'):
            # A separate cache lock prevents a cold-start herd. It never waits
            # while holding the main read lock; another builder means retry.
            project.state.mkdir(parents=True, exist_ok=True)
            with (project.state / 'canonical-index.lock').open('a') as lock:
                try:
                    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
                except BlockingIOError:
                    raise StateUnavailable('canonical index is being refreshed; retry') from None
                # Another process may have published before this lock acquisition.
                latest = _load_index(project)
                if latest:
                    previous = latest['files']
                files = {}
                for relative, stamp in manifest.items():
                    old = previous.get(relative)
                    files[relative] = old if old and old['stamp'] == stamp else _file_record(project.root, relative, stamp)
                if _manifest(project.root) != manifest:
                    raise StateUnavailable('canonical inputs changed while indexing; retry')
                owners = {}
                digest = hashlib.sha256()
                for relative, record in files.items():
                    digest.update(relative.encode() + b'\0' + bytes.fromhex(record['sha256']))
                    for row in record['definitions']:
                        owners.setdefault(row['name'], []).append(row)
                index = dict(version=INDEX_VERSION, root=str(project.root), manifest=manifest,
                             files=files, owners=owners, content_sha256=digest.hexdigest())
                _publish_index(project, index)
        cache, renames = _declarations(db)
        digest = hashlib.sha256(index['content_sha256'].encode())
        digest.update(repr(manifest).encode())
        digest.update(repr((cache, renames)).encode())
        for row in cache:
            record = index['files'].get(row['path'].rsplit(':', 1)[0], {})
            row['context_headers'] = record.get('context_headers', [])
            row['local_type_names'] = record.get('type_names', [])
            # The legacy declaration table loses surrounding extern "C" blocks.
            # Recover linkage only from the exact recorded source declaration;
            # stale prototypes must retain their existing conflict checks.
            normalized = lambda text: re.sub(r'\s+', '', re.sub(r'^extern\s+"C"\s+', '', text))
            matches = [decl for decl in record.get('declarations', [])
                       if decl['name'] == row['name']
                       and str(decl['line']) == row['path'].rsplit(':', 1)[-1]
                       and normalized(decl['decl']) == normalized(row['decl'])]
            if len(matches) == 1:
                row['c_link'] = matches[0]['c_link']
        owners = {name: list(rows) for name, rows in index['owners'].items()}
        for row in _accepted_assembly_owners(project.root, index['files']):
            owners.setdefault(row['name'], []).append(row)
        return digest.hexdigest(), owners, cache, renames
    except (OSError, KeyError, TypeError, ValueError) as error:
        raise StateUnavailable(f'canonical index could not be verified ({error}); retry') from error


def _context_probe(text, suffix, evidence):
    """Capture candidate types BEFORE adding real owning headers at file scope.

    Adding headers before a prototype could reinterpret its macros, or add an
    overload that makes a bad prototype look compatible. Template deduction at
    the original declaration captures its existing type instead. No owner-local
    struct definitions are synthesized or transplanted into the candidate.
    """
    headers = sorted({header for row in evidence for header in row.get('context_headers', [])})
    if suffix != '.cpp' or not headers:
        return None
    declarations, captures, tail = [], [], []
    candidates = {row['start']: row for row in signatures(text, suffix) if not row['definition']}
    for index, row in enumerate(evidence):
        name = row['candidate_name']
        candidate = next((c for c in candidates.values() if c['name'] == name), None)
        if candidate is None:
            return None
        capture, compare = f'__swarm_capture_{index}', f'__swarm_same_{index}'
        alias = f'__swarm_context_{index}'
        declarations.append(f'template<class T> void {capture}(T);')
        end = text.find(';', candidate['start']) + 1
        captures.append((end, '\nextern "C++" { '
                         + f'void __swarm_capture_probe_{index}() {{ {capture}(&{name}); }}' + ' }\n'))
        declaration = re.sub(r'^extern\s+"C"\s+', '', row['decl'])
        declaration = re.sub(r'\b' + re.escape(row['name']) + r'\b', alias, declaration)
        linkage = 'C' if row.get('c_link', '"C"' in row['decl']) else 'C++'
        tail.append(f'extern "{linkage}" {{ {declaration} }}\n'
                    + f'template<class T> void {compare}(T, T);\n'
                    + f'template<class T> void {capture}(T candidate) '
                    + '{ ' + f'{compare}(candidate, &{alias});' + ' }')
    reviewed = text
    for offset, capture in sorted(captures, reverse=True):
        reviewed = reviewed[:offset] + capture + reviewed[offset:]
    prelude = 'extern "C++" {\n' + '\n'.join(declarations) + '\n}\n'
    includes = '\n'.join(f'#include <{header}>' for header in headers)
    return prelude + reviewed + '\nextern "C++" {\n' + includes + '\n' + '\n'.join(tail) + '\n}\n'


def _missing_context(messages):
    return bool(re.search(r"undefined|undeclared|unknown|not a (?:class|type)|type name|identifier.*expected", messages, re.I))


def audit(project, text, suffix, include_dir, profile, state, compile_source):
    _, owners, cache, renames = state
    groups = {}
    for old, new in renames:
        group = groups.get(old, {old}) | groups.get(new, {new})
        for name in group:
            groups[name] = group
    declarations = {r['name']: [dict(r, authority='declaration-cache')] for r in cache}
    declarations.update(owners)
    evidence, inserts = [], []
    linkage_conflicts = []
    for candidate in signatures(text, suffix):
        if candidate['definition']:
            continue
        name = candidate['name']
        aliases = groups.get(name, {name})
        rows = [r for alias in sorted(aliases) for r in owners.get(alias, [])]
        if not rows:
            rows = [r for alias in sorted(aliases) for r in declarations.get(alias, [])]
        prefix = []
        for row in rows:
            declaration = re.sub(r'\b' + re.escape(row['name']) + r'\b', name, row['decl'])
            c_link = row.get('c_link', '"C"' in declaration)
            declaration = re.sub(r'^extern\s+"C"\s+', '', declaration)
            if suffix != '.c' and c_link:
                declaration = 'extern "C" { ' + declaration + ' }'
            if suffix != '.c' and not c_link:
                # Ordinary C++ redeclarations can overload instead of conflict.
                # Compare pointer types by template deduction, without adding a
                # canonical overload that could accidentally satisfy the probe.
                index = len(evidence)
                alias = f'__swarm_canonical_{index}'
                helper = f'__swarm_compare_{index}'
                probe = f'__swarm_probe_{index}'
                alias_decl = re.sub(r'\b' + re.escape(name) + r'\b', alias, declaration)
                prefix.append('extern "C++" { ' + alias_decl + '\n'
                              + f'template<class T> void {helper}(T, T);\n'
                              + f'void {probe}() {{ {helper}(&{name}, &{alias}); }} }}')
                if candidate['c_link']:
                    linkage_conflicts.append(name)
            else:
                prefix.append(declaration)
            evidence.append(dict(row, candidate_name=name, candidate_declaration=candidate['decl']))
        if prefix:
            end = text.find(';', candidate['start']) + 1
            inserts.append((end, '\n' + '\n'.join(prefix) + '\n'))
    reviewed = text
    for offset, prefix in reversed(inserts):
        reviewed = reviewed[:offset] + prefix + reviewed[offset:]
    if not evidence:
        return dict(status='ok', declarations=[])
    obj, messages = compile_source(project, reviewed, suffix, include_dir, profile)
    if obj is not None and not linkage_conflicts:
        return dict(status='ok', declarations=evidence)
    context_attempted = False
    if obj is None and _missing_context(messages):
        contextual = _context_probe(text, suffix, evidence)
        if contextual is not None:
            context_attempted = True
            obj, resolved_messages = compile_source(project, contextual, suffix, include_dir, profile)
            if obj is not None and not linkage_conflicts:
                return dict(status='ok', declarations=evidence, context_resolution='owning-headers-with-captured-candidate-types')
            messages = resolved_messages
    if linkage_conflicts:
        messages += '\nCanonical C++ linkage differs from candidate C linkage: ' + ', '.join(linkage_conflicts)
    # Compiler type identity proves declaration compatibility, not an assertion
    # that every nominal pointer-tag mismatch changes the machine ABI.
    incomplete = _missing_context(messages)
    missing = sorted(set(re.findall(r"(?:undefined|undeclared|unknown) (?:identifier|type(?: name)?) ['\"]([^'\"]+)", messages, re.I)))
    headers = sorted({header for row in evidence for header in row.get('context_headers', [])})
    local = sorted({name for row in evidence for name in row.get('local_type_names', []) if name in missing})
    kinds = []
    if incomplete:
        kinds.append('missing-context')
    if linkage_conflicts or re.search(r'illegal (?:function )?overloading|redeclared|does not match', messages, re.I):
        kinds.append('declaration-disagreement')
    context_hint = (' Owning headers: ' + ', '.join(headers) + '.') if headers else ''
    if local:
        context_hint += ' Owner-local types needing investigation: ' + ', '.join(local) + '.'
    return dict(status='context_required' if incomplete else 'conflict',
                proof='unresolved-type-context' if incomplete else 'compiler-declaration-incompatibility',
                declarations=evidence, messages=messages.splitlines(), missing_identifiers=missing,
                context_attempted=context_attempted, diagnostic_kinds=kinds,
                repair_context=[dict(path=row['path'], headers=row.get('context_headers', []),
                                     owner_local_types=row.get('local_type_names', [])) for row in evidence],
                advice=('Use the listed owning headers or inspect owner-local types at the declaration paths; '
                        'nominal tag disagreement alone does not establish a machine ABI difference. '
                        'Rerun check without casts or constant rewrites.' + context_hint))
