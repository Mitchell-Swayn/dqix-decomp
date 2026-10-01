#!/usr/bin/env python3
"""Compare ARM9 coverage with the archived baseline without hiding regressions.

ARM7 is deliberately separate: its total instruction/function denominator is
still unknown, and initialized payload size is not a valid code denominator.
"""

import argparse
import gzip
import json
from pathlib import Path
import sys


COUNTERS = ("total_code", "total_data", "total_functions", "matched_code", "matched_data", "matched_functions")


def compare(baseline, current):
    before = {key: int(baseline["measures"].get(key, 0)) for key in COUNTERS}
    after = {key: int(current["measures"].get(key, 0)) for key in COUNTERS}
    errors = []
    for key in COUNTERS:
        if after[key] < before[key]:
            errors.append(f"{key} decreased from {before[key]} to {after[key]}")
    for key in ("code", "data", "functions"):
        if after["matched_" + key] > after["total_" + key]:
            errors.append(f"Matched {key} exceeds its total")
    return {"before": before, "after": after,
            "delta": {key: after[key] - before[key] for key in COUNTERS},
            "regressions": errors,
            "scope": "ARM9 only; matched bytes include existing assembly and literal pools"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", type=Path, default=Path("docs/inventory-usa-report.json.gz"))
    parser.add_argument("--report", type=Path, default=Path("build/usa/report.json"))
    parser.add_argument("--output", type=Path, default=Path("build/usa/progress-delta.json"))
    args = parser.parse_args()
    with gzip.open(args.baseline, "rt") as stream:
        baseline = json.load(stream)
    result = compare(baseline, json.loads(args.report.read_text()))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result["delta"], indent=2))
    if result["regressions"]:
        print("Coverage regression: " + "; ".join(result["regressions"]), file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
