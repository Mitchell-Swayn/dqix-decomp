#!/usr/bin/env python3
"""Package local, read-only reconstruction evidence for one exact objdiff unit."""
import argparse
from bisect import bisect_right
from collections import deque
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

from match_unit import within

NOTICE = "Local evidence only; references and mapped callers are observations, not semantic proof or acceptance."
TEXT_LIMIT = 2 * 1024 * 1024
LEDGER_LIMIT = 8 * 1024 * 1024


def digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def file_record(root, value, text=False):
    if not value:
        return {"status": "unavailable", "reason": "path not configured"}
    if not isinstance(value, str):
        raise ValueError("configured file path must be a string")
    path = within(root, root / value)
    record = {"path": path.relative_to(root).as_posix()}
    if not path.is_file():
        return {**record, "status": "unavailable", "reason": "local file missing"}
    record.update(status="available", size=path.stat().st_size, sha256=digest(path))
    if text:
        try:
            with path.open("rb") as stream:
                content = stream.read(TEXT_LIMIT + 1)
            # A cap may fall in a multibyte UTF-8 character; avoid inventing a decode failure.
            if len(content) > TEXT_LIMIT:
                import codecs
                record["text"] = codecs.getincrementaldecoder("utf-8")().decode(content[:TEXT_LIMIT], final=False)
            else:
                record["text"] = content.decode("utf-8")
            record["text_truncated"] = len(content) > TEXT_LIMIT
            if record["text_truncated"]:
                record["text_limit_bytes"] = TEXT_LIMIT
        except UnicodeError:
            record["text_status"] = "unavailable: not UTF-8"
    return record


def read_elf(path):
    """Decode ELF32 LE ARM symbols and REL/RELA records without running external tools."""
    data = path.read_bytes()
    if len(data) < 52 or data[:7] != b"\x7fELF\x01\x01\x01":
        raise ValueError("expected ELF32 little-endian version 1")
    header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
    if header[1:3] != (1, 40):
        raise ValueError("expected relocatable ARM ELF")
    offset, stride, count, names_index = header[6], header[11], header[12], header[13]
    if stride != 40 or not count or offset + count * stride > len(data) or names_index >= count:
        raise ValueError("invalid section header table")
    sections = [struct.unpack_from("<IIIIIIIIII", data, offset + i * stride) for i in range(count)]
    for section in sections:
        if section[1] != 8 and section[4] + section[5] > len(data):
            raise ValueError("section payload outside file")

    def payload(index):
        section = sections[index]
        return data[section[4]:section[4] + section[5]]

    def string(strings, index):
        if index >= len(strings) or b"\0" not in strings[index:]:
            raise ValueError("invalid ELF string offset")
        return strings[index:strings.index(0, index)].decode("utf-8", errors="replace")

    if sections[names_index][1] != 3:
        raise ValueError("section names are not a string table")
    names = [string(payload(names_index), section[0]) for section in sections]
    symbols, tables, relocations = [], {}, []
    for index, section in enumerate(sections):
        if section[1] not in (2, 11):
            continue
        if section[9] != 16 or section[5] % 16 or section[6] >= count or sections[section[6]][1] != 3:
            raise ValueError("invalid symbol table")
        table = []
        for position in range(section[4], section[4] + section[5], 16):
            name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", data, position)
            if count <= shndx < 0xff00:
                raise ValueError("invalid symbol section")
            record = {"name": string(payload(section[6]), name), "value": value, "size": size,
                      "binding": info >> 4, "type": info & 15, "visibility": other,
                      "section_index": shndx, "section": names[shndx] if shndx < count else None,
                      "defined": shndx != 0}
            table.append(record)
        tables[index] = table
        symbols.extend(table)
    for index, section in enumerate(sections):
        if section[1] not in (4, 9):
            continue
        entry_size = 12 if section[1] == 4 else 8
        if section[9] != entry_size or section[5] % entry_size or section[6] not in tables or section[7] >= count:
            raise ValueError("invalid relocation table")
        for position in range(section[4], section[4] + section[5], entry_size):
            location, info = struct.unpack_from("<II", data, position)
            symbol_index = info >> 8
            if symbol_index >= len(tables[section[6]]):
                raise ValueError("invalid relocation symbol index")
            record = {"section": names[section[7]], "offset": location, "type": info & 255,
                      "symbol": tables[section[6]][symbol_index]["name"],
                      "addend": struct.unpack_from("<i", data, position + 8)[0] if entry_size == 12 else None,
                      "addend_status": "explicit" if entry_size == 12 else "implicit; not decoded"}
            relocations.append(record)
    return {"status": "available", "format": "ELF32 little-endian ARM", "symbols": symbols,
            "relocations": relocations, "sections": [{"name": name, "type": s[1], "size": s[5],
                "address": s[3]} for name, s in zip(names, sections)]}


def object_record(root, value):
    record = file_record(root, value)
    if record["status"] != "available":
        record["analysis"] = {"status": "unavailable", "reason": record["reason"]}
    else:
        try:
            record["analysis"] = read_elf(root / record["path"])
        except (OSError, ValueError, struct.error) as error:
            record["analysis"] = {"status": "unavailable", "reason": str(error)}
    return record


def mapped_callers(root, names):
    """Resolve explicit *_call map relocations to defined object names, preserving modules."""
    maps, provenance, diagnostics = {}, [], []
    for path in sorted((root / "config").rglob("symbols.txt")):
        within(root, path)
        if "arm9" not in path.parts or "usa" not in path.parts:
            continue
        module = "main" if path.parent.name == "arm9" else path.parent.name
        symbols = []
        for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            match = re.match(r"(\S+) kind:function\([^)]*size=(0x[\da-fA-F]+|\d+)[^)]*\) addr:(0x[\da-fA-F]+)", line)
            if match:
                name, size, address = match.groups()
                symbols.append({"name": name, "size": int(size, 0), "address": int(address, 16),
                                "line": line_number})
        symbols.sort(key=lambda item: item["address"])
        if module in maps:
            diagnostics.append(f"duplicate map module {module}; caller resolution unavailable for that map")
            continue
        maps[module] = {"path": path.relative_to(root).as_posix(), "symbols": symbols,
                        "starts": [item["address"] for item in symbols]}
        provenance.append(file_record(root, path.relative_to(root).as_posix()))
    targets = {(module, item["address"]): item for module, mapping in maps.items()
               for item in mapping["symbols"] if item["name"] in names}
    callers = []
    for path in sorted((root / "config").rglob("relocs.txt")):
        within(root, path)
        if "arm9" not in path.parts or "usa" not in path.parts:
            continue
        module = "main" if path.parent.name == "arm9" else path.parent.name
        mapping = maps.get(module)
        found = False
        for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            match = re.fullmatch(r"from:(0x[\da-fA-F]+) kind:(\w+_call) to:(0x[\da-fA-F]+) module:(\S+).*", line)
            if not match:
                continue
            source, kind, target, target_module = match.groups()
            address, destination = int(source, 16), int(target, 16)
            target_symbol = targets.get((target_module, destination))
            if target_symbol is None:
                continue
            owner = None
            if mapping:
                index = bisect_right(mapping["starts"], address) - 1
                if index >= 0:
                    candidate = mapping["symbols"][index]
                    if address < candidate["address"] + candidate["size"]:
                        owner = candidate["name"]
            callers.append({"module": module, "caller": owner, "from_address": address,
                            "target_module": target_module, "target_symbol": target_symbol["name"],
                            "to_address": destination, "kind": kind,
                            "path": path.relative_to(root).as_posix(), "line": line_number,
                            "record": line})
            found = True
        if found:
            provenance.append(file_record(root, path.relative_to(root).as_posix()))
    return {"status": "available" if targets else "unavailable",
            "reason": None if targets else "no object-defined function names resolved in local USA ARM9 maps",
            "scope": "explicit call relocations in local USA ARM9 maps; indirect/runtime callers are not determined; same-named symbols in different modules remain separate candidates",
            "records": callers, "provenance": provenance, "diagnostics": diagnostics}


def prior_attempts(root, unit_name):
    path = root / "build/matching/attempts.jsonl"
    if not path.is_file():
        return {"status": "unavailable", "reason": "matching attempt ledger missing", "records": []}
    within(root, path)
    records, diagnostics = deque(maxlen=100), []
    total_matches, total_errors = 0, 0
    size = path.stat().st_size
    with path.open("rb") as stream:
        start = max(0, size - LEDGER_LIMIT)
        stream.seek(start)
        if start:
            stream.readline(LEDGER_LIMIT)
        scanned_from = stream.tell()
        window = stream.read(max(0, size - stream.tell()))
        for line_number, raw in enumerate(window.splitlines(), 1):
            line = raw.decode("utf-8", errors="replace")
            if not line.strip():
                continue
            try:
                record = json.loads(line)
                if not isinstance(record, dict):
                    raise ValueError("attempt record is not an object")
                if record.get("unit") == unit_name:
                    total_matches += 1
                    records.append({"line": line_number if not start else None,
                                    "window_line": line_number, "record": record})
            except ValueError as error:
                total_errors += 1
                if len(diagnostics) < 100:
                    diagnostics.append({"line": line_number if not start else None,
                                        "window_line": line_number, "error": str(error)})
    ledger = file_record(root, path.relative_to(root).as_posix()) if size <= LEDGER_LIMIT else {
        "path": path.relative_to(root).as_posix(), "status": "available", "size": size,
        "sha256": None, "hash_status": "not computed: ledger exceeds bounded read limit"}
    return {"status": "available", "ledger": ledger, "records": list(records),
            "diagnostics": diagnostics, "diagnostic_count": total_errors,
            "diagnostics_truncated": total_errors > len(diagnostics), "scanned_from_byte": scanned_from,
            "truncated": bool(start) or total_matches > len(records),
            "scope": "latest 100 matching records in at most the final 8 MiB of the ledger"}


def source_references(root, terms, limit=500):
    terms = {term for term in terms if term and len(term) >= 3}
    if not terms:
        return {"status": "unavailable", "reason": "no source or defined symbol names available", "records": []}
    expression = re.compile(r"(?<![\w])(?:" + "|".join(re.escape(term) for term in sorted(terms, key=len, reverse=True)) + r")(?![\w])")
    records, diagnostics, examined, read_bytes = [], [], 0, 0
    extensions = {".c", ".cpp", ".cp", ".cxx", ".h", ".hpp", ".hxx", ".md", ".json", ".txt"}
    for folder in ("src", "libs", "include", "docs"):
        for path in sorted((root / folder).rglob("*")):
            if not path.is_file() or path.suffix.lower() not in extensions:
                continue
            within(root, path)
            examined += 1
            try:
                size = path.stat().st_size
                if size > TEXT_LIMIT:
                    diagnostics.append({"path": path.relative_to(root).as_posix(), "error": "skipped: file exceeds 2 MiB scan limit"})
                    continue
                if read_bytes + size > 64 * 1024 * 1024:
                    return {"status": "available", "scope": "text references; not proof of calls", "records": records,
                            "truncated": True, "reason": "64 MiB total scan limit", "files_examined": examined,
                            "diagnostics": diagnostics}
                read_bytes += size
                lines = path.read_text(encoding="utf-8").splitlines()
            except (OSError, UnicodeError) as error:
                diagnostics.append({"path": path.relative_to(root).as_posix(), "error": str(error)})
                continue
            for number, line in enumerate(lines, 1):
                matches = sorted(set(expression.findall(line)))
                if matches:
                    records.append({"path": path.relative_to(root).as_posix(), "line": number,
                                    "text": line, "terms": matches})
                    if len(records) >= limit:
                        return {"status": "available", "scope": "text references; not proof of calls", "records": records,
                                "truncated": True, "limit": limit, "files_examined": examined, "diagnostics": diagnostics}
    return {"status": "available", "scope": "text references; not proof of calls", "records": records,
            "truncated": bool(diagnostics), "files_examined": examined, "diagnostics": diagnostics}


def build_evidence(root, unit_name):
    root = Path(root).resolve()
    config_path = within(root, root / "objdiff.json")
    config = json.loads(config_path.read_text(encoding="utf-8"))
    if not isinstance(config, dict) or not isinstance(config.get("units"), list):
        raise ValueError("objdiff.json must contain a units array")
    units = [unit for unit in config["units"] if isinstance(unit, dict) and unit.get("name") == unit_name]
    if len(units) != 1:
        raise ValueError(f"expected one exact unit named {unit_name!r}; found {len(units)}")
    unit = units[0]
    metadata, scratch = unit.get("metadata", {}), unit.get("scratch", {})
    if not isinstance(metadata, dict) or not isinstance(scratch, dict):
        raise ValueError("unit metadata and scratch must be objects")
    target = object_record(root, unit.get("target_path"))
    candidate = object_record(root, unit.get("base_path"))
    if target.get("path") and candidate.get("path"):
        a, b = root / target["path"], root / candidate["path"]
        if a == b or (a.is_file() and b.is_file() and a.samefile(b)):
            raise ValueError("target and candidate must be independent files")
    source = file_record(root, metadata.get("source_path"), text=True)
    context = file_record(root, scratch.get("ctx_path"), text=True)
    defined = {item["name"] for item in target["analysis"].get("symbols", [])
               if item["name"] and item["defined"] and item["type"] == 2}
    terms = defined | {unit_name}
    if metadata.get("source_path"):
        terms.update((metadata["source_path"], Path(metadata["source_path"]).name))
    return {"schema_version": 1, "created_utc": datetime.now(timezone.utc).isoformat(),
            "root": str(root), "unit": unit_name, "notice": NOTICE,
            "config": file_record(root, "objdiff.json"), "unit_config": unit,
            "source": source, "target": target, "candidate": candidate,
            "compiler": {"status": "available" if scratch else "unavailable",
                         "configured": scratch, "context": context,
                         "scope": "objdiff configuration only; compiler executable identity is not inferred"},
            "callers": mapped_callers(root, defined), "prior_attempts": prior_attempts(root, unit_name),
            "source_references": source_references(root, terms)}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", required=True, type=Path)
    parser.add_argument("--unit", required=True)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args(argv)
    try:
        root = args.root.resolve()
        output = within(root / "build", args.output.resolve())
        # Evidence never overwrites a configured input or an existing file.
        result = build_evidence(root, args.unit)
        output.parent.mkdir(parents=True, exist_ok=True)
        with output.open("x", encoding="utf-8") as stream:
            json.dump(result, stream, indent=2)
            stream.write("\n")
        print(f"Evidence: {output}")
        return 0
    except (OSError, ValueError, TypeError, KeyError, AttributeError) as error:
        print(f"factory_evidence: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
