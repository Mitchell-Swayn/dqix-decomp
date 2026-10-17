"""Use short, disposable object paths for MWLD's expensive path comparisons.

Objects are byte-identical workspace-local copies. Only LCF object selectors
change; symbols, directives, sections and response order remain unchanged.
"""
from contextlib import contextmanager
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import tempfile
import time


def short_name(index):
    alphabet = 'abcdefghijklmnopqrstuvwxyz0123456789'
    result = ''
    while True:
        result += alphabet[index % len(alphabet)]
        index //= len(alphabet)
        if not index:
            return result + '.o'


@contextmanager
def short_alias(directory, temporary=None):
    """Atomically claim a name; never reuse or delete another invocation's alias."""
    temporary = Path(temporary if temporary is not None else tempfile.gettempdir())
    directory = Path(directory).resolve()
    for index in range(4096):
        alias = temporary / short_name(index)[:-2]
        try:
            alias.symlink_to(directory, target_is_directory=True)
        except FileExistsError:
            continue
        identity = alias.lstat()
        break
    else:
        raise RuntimeError('No temporary short linker path available')
    try:
        yield alias
    finally:
        try:
            current = alias.lstat()
        except FileNotFoundError:
            current = None
        if current is not None and (current.st_dev, current.st_ino) == (identity.st_dev, identity.st_ino):
            alias.unlink()


def rewrite_lcf(text, names):
    pattern = re.compile(r'(?m)^([ \t]*)(\S+\.o)(\(\.[A-Za-z0-9_]+\)[ \t]*)$')
    def replace(match):
        if match[2] not in names:
            raise ValueError('LCF object missing from response file: ' + match[2])
        return match[1] + names[match[2]] + match[3]
    return pattern.sub(replace, text)


def run(objects_file, lcf_file, workspace, command):
    objects_file, lcf_file, workspace = map(Path, (objects_file, lcf_file, workspace))
    # The optimization targets Wibo on POSIX. Keep native Windows invocation.
    if os.name != 'posix':
        return subprocess.run(command, check=True)
    started = time.perf_counter()
    paths = [Path(line.strip().strip('"')) for line in objects_file.read_text().splitlines() if line.strip()]
    if not paths or len({p.name.casefold() for p in paths}) != len(paths):
        raise ValueError('Expected nonempty, unique object basenames for short linking')
    workspace = workspace.resolve()
    if workspace == lcf_file.resolve().parent or any(p.resolve().is_relative_to(workspace) for p in paths):
        raise ValueError('Short linker workspace overlaps input objects or LCF directory')
    names = {p.name: short_name(index) for index, p in enumerate(paths)}
    script = rewrite_lcf(lcf_file.read_text(), names)
    response_indices = [i for i, arg in enumerate(command)
                        if arg.startswith('@') and Path(arg[1:]).resolve() == objects_file.resolve()]
    lcf_indices = [i for i, arg in enumerate(command) if arg == str(lcf_file)]
    if len(response_indices) != 1 or len(lcf_indices) != 1:
        raise ValueError('Expected one response file and one LCF in linker command')
    workspace.mkdir(parents=True, exist_ok=True)
    records = []
    for path in paths:
        target = workspace / names[path.name]
        if target.is_symlink() or (target.exists() and target.stat().st_nlink != 1):
            raise ValueError('Short linker copy must be an independent file')
        content = path.read_bytes()
        target.write_bytes(content)
        records.append(dict(original=str(path), copy=str(target),
                            sha256=hashlib.sha256(content).hexdigest()))
    script_file = workspace / 'script.lcf'
    response_file = workspace / 'objects.txt'
    for output in (script_file, response_file, workspace / 'report.json'):
        if output.is_symlink() or (output.exists() and output.stat().st_nlink != 1):
            raise ValueError('Short linker metadata must be an independent file')
    script_file.write_text(script)
    updated = list(command)
    updated[response_indices[0]] = '@' + str(response_file)
    updated[lcf_indices[0]] = str(script_file)
    report = dict(schema_version=1, purpose='byte-identical short-path link copies; no source coverage',
                  objects=records)
    try:
        with short_alias(workspace) as alias:
            response_file.write_text(''.join('"' + str(alias / names[p.name]) + '"\n' for p in paths))
            report['prepare_seconds'] = time.perf_counter() - started
            linked = time.perf_counter()
            try:
                subprocess.run(updated, check=True)
            finally:
                report['link_seconds'] = time.perf_counter() - linked
    finally:
        # Leave a usable stable response file after removing the temporary alias.
        response_file.write_text(''.join('"' + str(workspace / names[p.name]) + '"\n' for p in paths))
        (workspace / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    return report
