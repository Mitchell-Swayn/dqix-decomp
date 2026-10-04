"""Read MWCC's actual include graph and emit portable Ninja dependencies."""

import hashlib
import os
from pathlib import Path, PurePosixPath
import platform
import re


def parse_depfile(text):
    """Parse one MWCC make rule, retaining Windows separators/drive letters."""
    text = re.sub(r"\\\r?\n", " ", text)
    separator = re.search(r":(?=\s|$)", text)
    if not separator or not text[:separator.start()].strip():
        raise ValueError("Invalid compiler dependency rule")
    body = text[separator.end():]
    tokens, token = [], []
    index = 0
    while index < len(body):
        char = body[index]
        if char == "\\" and index + 1 < len(body) and body[index + 1] in " \t#$":
            index += 1
            token.append(body[index])
        elif char == "$" and body[index:index + 2] == "$$":
            token.append("$")
            index += 1
        elif char.isspace():
            if token:
                tokens.append("".join(token))
                token = []
        else:
            token.append(char)
        index += 1
    if token:
        tokens.append("".join(token))
    if not tokens or any(re.search(r":$", item) for item in tokens):
        raise ValueError("Empty or multiple compiler dependency rules")
    return tokens


def has_assembly(text):
    # Ignore comments and strings, but inspect macro bodies as well as functions.
    clean = re.sub(r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                   " ", text)
    return bool(re.search(r"\b(?:asm|__asm|__asm__)\b", clean))


def native_dependency_name(name, host=None, wineprefix=None, wsl=None):
    """Use the same Wine drive mapping as transform_dep, after make unescaping."""
    name = name.replace("\\", "/")
    if (host or os.name) == "nt" or not re.match(r"^[A-Za-z]:/", name):
        return name
    drive, tail = name[0].lower(), name[3:]
    if drive == "z":
        return "/" + tail
    if wsl is None:
        wsl = "microsoft-standard" in platform.uname().release.lower()
    if wsl:
        return f"/mnt/{drive}/{tail}"
    prefix = wineprefix or os.environ.get("WINEPREFIX") or str(Path.home() / ".wine")
    return str(PurePosixPath(prefix) / "dosdevices" / (drive + ":") / tail)


def dependency_records(depfile, cwd, root, source, assembly_exception=False):
    """Resolve every emitted include, reject missing/outside inputs and header asm."""
    root, source = root.resolve(), source.resolve()
    paths = set()
    for name in parse_depfile(depfile.read_text(encoding="utf-8-sig")):
        path = Path(native_dependency_name(name))
        if not path.is_absolute():
            path = cwd / path
        path = path.resolve()
        if not path.is_relative_to(root) or not path.is_file():
            raise ValueError(f"Compiler dependency is missing or outside repository: {name}")
        paths.add(path)
    if source not in paths:
        raise ValueError("Compiler dependencies omit the unit source")
    records = []
    for path in sorted(paths):
        data = path.read_bytes()
        if has_assembly(data.decode("utf-8-sig")) and (path != source or not assembly_exception):
            raise ValueError(f"{path.relative_to(root)}: inline assembly requires a reviewed source exception; header assembly is not covered")
        records.append({"path": path.relative_to(root).as_posix(),
                        "sha1": hashlib.sha1(data).hexdigest()})
    return records


def write_depfile(path, target, dependencies):
    def escape(value):
        value = str(value).replace("\\", "/")
        if "\n" in value or "\r" in value:
            raise ValueError("Newlines are unsupported in dependency paths")
        return value.replace("$", "$$").replace(" ", "\\ ").replace("#", "\\#").replace(":", "\\:")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(escape(target) + ": " + " ".join(escape(p) for p in sorted(set(dependencies))) + "\n",
                    encoding="utf-8")
