#!/usr/bin/env python3
"""Conservative source-level assembly audit; not approval of assembly exceptions.

Partitions the existing objdiff report by translation units. A unit is marked
assembly-affected if its source or any locally resolved include contains assembly
syntax. Entire units are counted, not purported exact assembly instruction bytes.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re


TOKEN = re.compile(r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'')
ASM = re.compile(r"\b(?:__asm__|__asm|asm)\b|\b(?:DECLARE_ASM_NOP|ASM_GOTO|ASM_LABEL)\s*\(")
INCLUDE = re.compile(r'^\s*#\s*include\s*[<"]([^>"\n]+)[>"]', re.M)
COUNTERS = ("total_code", "matched_code", "total_data", "matched_data", "total_functions", "matched_functions")


def without_comments(text):
    def replace(match):
        token = match.group()
        if token.startswith(("//", "/*")):
            return "".join("\n" if c == "\n" else " " for c in token)
        return token
    return TOKEN.sub(replace, text)


def inspect(path, root, cache):
    if path in cache:
        return cache[path]
    raw = path.read_text(encoding="utf-8")
    text = without_comments(raw)
    # Cache before following includes so mutually including headers terminate.
    entry = {"source": path.relative_to(root).as_posix(), "sites": [], "includes": []}
    cache[path] = entry
    for match in ASM.finditer(text):
        line = text.count("\n", 0, match.start()) + 1
        entry["sites"].append({"line": line, "text": raw.splitlines()[line - 1].strip(),
                               "review_status": "unreviewed"})
    for name in INCLUDE.findall(text):
        candidates = [path.parent / name, root / "include" / name]
        include = next((p.resolve() for p in candidates if p.is_file()), None)
        if include is not None and include.is_relative_to(root):
            entry["includes"].append(include)
            inspect(include, root, cache)
    return entry


def affected_files(path, cache, seen=None):
    if seen is None:
        seen = set()
    if path in seen:
        return set()
    seen.add(path)
    entry = cache[path]
    result = {entry["source"]} if entry["sites"] else set()
    for include in entry["includes"]:
        result.update(affected_files(include, cache, seen))
    return result


def audit(root, report_path):
    root = root.resolve()
    report = json.loads(report_path.read_text())
    cache = {}
    groups = {name: {key: 0 for key in COUNTERS} for name in
              ("original_binary_units", "source_units_with_assembly_syntax", "source_units_without_detected_assembly")}
    units = []
    for unit in report["units"]:
        source = next((root / (unit["name"] + extension) for extension in (".cpp", ".c")
                       if (root / (unit["name"] + extension)).is_file()), None)
        affected = set()
        if source is None:
            category = "original_binary_units"
        else:
            inspect(source.resolve(), root, cache)
            affected = affected_files(source.resolve(), cache)
            category = "source_units_with_assembly_syntax" if affected else "source_units_without_detected_assembly"
        for key in COUNTERS:
            groups[category][key] += int(unit["measures"].get(key, 0))
        units.append({"name": unit["name"], "category": category,
                      "assembly_sources": sorted(affected)})
    for key in COUNTERS:
        if sum(group[key] for group in groups.values()) != int(report["measures"].get(key, 0)):
            raise ValueError(f"Counter partition mismatch: {key}")
    return {"schema_version": 1, "report_sha256": hashlib.sha256(report_path.read_bytes()).hexdigest(),
            "scope": "ARM9 report translation units; conservative lexical scan including local headers",
            "limitations": ["No preprocessor evaluation; inactive branches and unused header macros may flag a unit",
                            "Counts are whole-unit measures, not exact assembly byte coverage",
                            "Absence of detected syntax is not proof of full C++ reconstruction",
                            "No assembly exceptions have been approved by this scan"],
            "groups": groups, "units": units,
            "sites": [dict(source=e["source"], sites=e["sites"]) for _, e in sorted(cache.items()) if e["sites"]]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--report", type=Path, default=Path("build/usa/report.json"))
    parser.add_argument("--output", type=Path, default=Path("build/usa/assembly-audit.json"))
    args = parser.parse_args()
    result = audit(args.root, args.report)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result["groups"], indent=2))


if __name__ == "__main__":
    main()
