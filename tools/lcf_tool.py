"""Resolve the hash-pinned DSD acceleration for LCF generation only."""
import hashlib
import json
from pathlib import Path


def profile(root, config):
    root = Path(root).resolve()
    policy = Path(config).resolve().parent / "lcf_tool.json"
    if not policy.exists():
        return None
    if not policy.is_relative_to(root / "config"):
        raise ValueError("LCF policy leaves project config")
    data = json.loads(policy.read_text())
    if data.get("schema_version") != 1:
        raise ValueError("Unsupported LCF tool policy")
    binary = (root / data["executable"]).resolve()
    patch = (root / data["patch"]).resolve()
    if not binary.is_relative_to(root / "build") or not patch.is_relative_to(root / "tools"):
        raise ValueError("LCF tool paths leave allowed directories")
    return data, binary, patch, policy


def dependencies(root, config):
    selected = profile(root, config)
    return [] if selected is None else [str(p.relative_to(Path(root).resolve())) for p in selected[1:]]


def resolve_lcf_tool(root, config, configured):
    selected = profile(root, config)
    if selected is None:
        return str(Path(configured).resolve())
    data, binary, patch, _ = selected
    digest = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
    if digest(configured) not in {data["configured_sha256"], data["binary_sha256"]}:
        raise ValueError("Configured DSD differs from reviewed binaries")
    if digest(binary) != data["binary_sha256"]:
        raise ValueError("Accelerated DSD binary hash mismatch; rebuild pinned tool")
    if digest(patch) != data["patch_sha256"]:
        raise ValueError("DSD acceleration patch hash mismatch")
    return str(binary)
