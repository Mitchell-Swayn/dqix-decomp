#!/usr/bin/env python3
"""Explain observed objdiff JSON mismatches using conservative ARM heuristics."""
import argparse
from collections import Counter
import json
from pathlib import Path
import re
import sys

NOTICE = "Heuristic mismatch categories only; no semantic proof or ROM acceptance claim."
CATEGORIES = ("stack", "register", "control-flow", "immediate", "relocation", "unknown")
REGISTER = re.compile(r"\b(?:r(?:1[0-5]|[0-9])|sp|lr|pc|ip|fp)\b", re.I)
IMMEDIATE = re.compile(r"#\s*-?(?:0x[0-9a-f]+|\d+)", re.I)
BRANCH = re.compile(r"^(?:b(?:l|lx|x)?(?:eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?|cbz|cbnz)$", re.I)


def _code(row):
    return row.get("instruction", {}) if isinstance(row, dict) else {}


def _features(code):
    text = code.get("formatted", "")
    mnemonic = code.get("mnemonic", text.split()[0] if text.split() else "").lower()
    registers = REGISTER.findall(text.lower())
    return text, mnemonic, registers, IMMEDIATE.findall(text.lower())


def categorize(left, right=None):
    """Classify one changed aligned row; evidence describes only observable features."""
    a, b = _code(left), _code(right)
    at, am, ar, ai = _features(a)
    bt, bm, br, bi = _features(b)
    reasons = {}
    paired = bool(a) and bool(b)
    stack = lambda m, r: "sp" in r or "r13" in r or m in ("push", "pop")
    if stack(am, ar) or stack(bm, br):
        reasons["stack"] = "changed row touches SP or a push/pop instruction"
    if paired and ar != br:
        reasons["register"] = f"register operands differ: {ar!r} versus {br!r}"
    if BRANCH.fullmatch(am) or BRANCH.fullmatch(bm) or "branch_dest" in a or "branch_dest" in b:
        reasons["control-flow"] = "changed row contains a branch/call or branch destination"
    if paired and ai != bi and (ai or bi):
        reasons["immediate"] = f"formatted immediate operands differ: {ai!r} versus {bi!r}"
    if ("relocation" in a or "relocation" in b) and (
            not paired or a.get("relocation") != b.get("relocation")):
        reasons["relocation"] = "relocation target/type/addend differs or the corresponding instruction is absent"
    if not paired and ar and not reasons:
        reasons["unknown"] = "instruction has no aligned counterpart; register allocation cannot be compared"
    if not reasons:
        reasons["unknown"] = "changed row has no supported distinguishing operand pattern"
    return [{"category": key, "reason": reasons[key]} for key in CATEGORIES if key in reasons]


def classify(document):
    if not isinstance(document, dict):
        raise ValueError("objdiff result must be an object")
    for side in ("left", "right"):
        if not isinstance(document.get(side), dict) or not isinstance(document[side].get("sections"), list):
            raise ValueError(f"objdiff result missing {side}.sections")
    rows, counts = [], Counter()
    for side, other in (("left", "right"), ("right", "left")):
        for section in document[side]["sections"]:
            for symbol in section.get("symbols", []):
                info = symbol.get("symbol", {})
                if not isinstance(info.get("name"), str):
                    raise ValueError("objdiff symbol missing name")
                if int(info.get("flags", 0)) & 2 or (side == "right" and "target" in symbol):
                    continue
                if not int(info.get("size", 0)) and "match_percent" not in symbol:
                    continue
                percent = symbol.get("match_percent", 0)
                if isinstance(percent, bool) or not isinstance(percent, (int, float)) or not 0 <= percent <= 100:
                    raise ValueError("invalid symbol match_percent")
                counterpart = None
                if "target" in symbol:
                    target = symbol["target"]
                    try:
                        si, yi = int(target.get("section_index", 0)), int(target.get("symbol_index", 0))
                        if si < 0 or yi < 0:
                            raise IndexError
                        counterpart = document[other]["sections"][si]["symbols"][yi]
                    except (IndexError, KeyError, TypeError, AttributeError):
                        raise ValueError("invalid objdiff symbol target index") from None
                instructions = symbol.get("instructions", [])
                opposing = counterpart.get("instructions", []) if counterpart else []
                evidence = []
                for index, instruction in enumerate(instructions):
                    kind = instruction.get("diff_kind", "DIFF_NONE")
                    if kind in ("DIFF_NONE", 0):
                        continue
                    aligned = opposing[index] if index < len(opposing) else None
                    labels = categorize(instruction, aligned)
                    code, other_code = _code(instruction), _code(aligned)
                    evidence.append({"instruction_index": index, "address": code.get("address", "0"),
                                     "diff_kind": kind, "instruction": code.get("formatted"),
                                     "counterpart": other_code.get("formatted"),
                                     "relocation": code.get("relocation"),
                                     "counterpart_relocation": other_code.get("relocation"),
                                     "categories": labels})
                if percent == 100 and counterpart is not None and not evidence:
                    continue
                if not evidence:
                    evidence.append({"categories": [{"category": "unknown", "reason":
                        "symbol is unpaired or below 100%; no changed instruction rows available (may include data/layout)"}]})
                categories = [key for key in CATEGORIES if any(
                    label["category"] == key for entry in evidence for label in entry["categories"])]
                counts.update(categories)
                rows.append({"side": "target" if side == "left" else "candidate", "section": section.get("name"),
                             "symbol": info["name"], "match_percent": percent,
                             "paired": counterpart is not None, "categories": categories, "evidence": evidence})
    return {"schema_version": 1, "notice": NOTICE, "mismatched_symbols": len(rows),
            "category_counts": {key: counts[key] for key in CATEGORIES}, "symbols": rows}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="objdiff --format json output")
    parser.add_argument("--output", type=Path)
    args = parser.parse_args(argv)
    try:
        result = classify(json.loads(args.input.read_text(encoding="utf-8")))
        text = json.dumps(result, indent=2) + "\n"
        if args.output:
            if args.input.resolve() == args.output.resolve() or (args.output.exists() and args.input.samefile(args.output)):
                raise ValueError("output must not overwrite input")
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(text, encoding="utf-8")
        else:
            print(text, end="")
        return 0
    except (OSError, ValueError, TypeError, AttributeError) as error:
        print(f"objdiff_diagnosis: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
