"""Resolve a reviewed, hash-pinned objdiff repair without replacing input tools."""
import hashlib
import json
from pathlib import Path


def resolve_objdiff(project, version, configured):
    root = Path(project).resolve()
    policy_path = root / 'config' / version / 'objdiff_tool.json'
    if not policy_path.exists():
        return str(configured)
    policy = json.loads(policy_path.read_text())
    if policy.get('schema_version') != 1:
        raise ValueError('Unsupported objdiff tool policy')
    executable = (root / policy['executable']).resolve()
    patch = (root / policy['patch']).resolve()
    if not executable.is_relative_to(root / 'build') or not patch.is_relative_to(root / 'tools'):
        raise ValueError('Objdiff tool policy paths leave their allowed directories')
    digest = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
    if digest(configured) not in {policy['configured_sha256'], policy['binary_sha256']}:
        raise ValueError('Configured objdiff differs from both reviewed binaries')
    if digest(executable) != policy['binary_sha256']:
        raise ValueError('Repaired objdiff hash mismatch; rebuild the pinned tool')
    if digest(patch) != policy['patch_sha256']:
        raise ValueError('Objdiff upstream patch hash mismatch')
    return str(executable)
