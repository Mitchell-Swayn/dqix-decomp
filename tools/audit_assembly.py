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


def reviewed_exceptions(root, report):
    """Validate explicitly reviewed units; this function never grants approval."""
    path = root / 'config/usa/arm9/assembly_exceptions.json'
    if not path.exists():
        return []
    manifest = json.loads(path.read_text())
    if manifest.get('schema_version') != 1:
        raise ValueError('Unknown assembly exception manifest schema')
    units = {unit['name']: unit for unit in report['units']}
    result, seen = [], set()
    for entry in manifest['exceptions']:
        name = entry['unit']
        if name in seen:
            raise ValueError('Duplicate assembly exception unit')
        seen.add(name)
        unit = units[name]
        source = (root / entry['source']).resolve()
        module = (root / entry['module_path']).resolve()
        if not source.is_relative_to(root) or not module.is_relative_to(root):
            raise ValueError('Assembly review paths must stay in the repository')
        source_hash = hashlib.sha256(source.read_text(encoding='utf-8').encode('utf-8')).hexdigest()
        if source_hash != entry['source_sha256']:
            raise ValueError(f'Assembly source changed since review: {name}')
        start, end = int(entry['start'], 0), int(entry['end'], 0)
        base = int(entry['module_base'], 0)
        data = module.read_bytes()
        if not 0 <= start - base < end - base <= len(data):
            raise ValueError('Assembly review range outside module')
        if hashlib.sha256(data[start-base:end-base]).hexdigest() != entry['original_bytes_sha256']:
            raise ValueError(f'Reviewed assembly bytes differ: {name}')
        measures = unit['measures']
        size = end - start
        if (int(measures.get('total_code', 0)) != size or
            int(measures.get('matched_code', 0)) != size or
            entry['reviewed_assembly_routine_bytes'] != size or
            not 0 < entry['inline_assembly_instruction_bytes'] <= size or
            entry['c_instruction_credit'] != 0):
            raise ValueError('Assembly review counter mismatch')
        functions = {function['name']: function for function in unit['functions']}
        cursor = start
        for routine in entry['routines']:
            function = functions.pop(routine['symbol'])
            routine_start, routine_end = int(routine['start'], 0), int(routine['end'], 0)
            if (routine_start != cursor or routine_end <= routine_start or
                int(function['size']) != routine_end - routine_start or
                function.get('fuzzy_match_percent') != 100):
                raise ValueError('Assembly exception routine mismatch')
            cursor = routine_end
        if cursor != end or functions:
            raise ValueError('Assembly exception must cover its exact unit')
        result.append(entry)
    return result


def audit(root, report_path):
    root = root.resolve()
    report = json.loads(report_path.read_text())
    reviewed = reviewed_exceptions(root, report)
    reviewed_sources = {entry['source'] for entry in reviewed}
    cache = {}
    groups = {name: {key: 0 for key in COUNTERS} for name in
              ("original_binary_units", "source_units_with_assembly_syntax", "source_units_without_detected_assembly")}
    units = []
    for unit in report["units"]:
        source = next((root / (unit["name"] + extension) for extension in (".cpp", ".c")
                       if (root / (unit["name"] + extension)).is_file()), None)
        if not unit.get('metadata', {}).get('auto_generated', True) and unit.get('metadata', {}).get('source_path'):
            source = root / unit['metadata']['source_path']
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
    for entry in cache.values():
        if entry['source'] in reviewed_sources:
            for site in entry['sites']:
                site['review_status'] = 'explicitly reviewed; source and module hashes verified'
    return {"schema_version": 1, "report_sha256": hashlib.sha256(report_path.read_bytes()).hexdigest(),
            "scope": "ARM9 report translation units; conservative lexical scan including local headers",
            "limitations": ["No preprocessor evaluation; inactive branches and unused header macros may flag a unit",
                            "Counts are whole-unit measures, not exact assembly byte coverage",
                            "Absence of detected syntax is not proof of full C++ reconstruction",
                            "This scan grants no approval; separately recorded reviews are validated against source/module hashes and report matches"],
            "groups": groups, "units": units,
            "reviewed_exceptions": reviewed,
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
