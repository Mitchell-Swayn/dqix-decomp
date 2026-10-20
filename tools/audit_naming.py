#!/usr/bin/env python3
"""List naming/ownership review work from the current ARM9 report; never rename code."""
import argparse
import json
from pathlib import Path
import re
from function_naming import PLACEHOLDER, readable_names


def audit(root):
    report = json.loads((root / 'build/usa/report.json').read_text())
    matched = [(u, f) for u in report['units'] for f in u.get('functions', [])
               if f.get('fuzzy_match_percent') == 100]
    names = readable_names([f['name'] for _, f in matched])
    pending, ownership = [], []
    for (unit, function), readable in zip(matched, names):
        source = unit.get('metadata', {}).get('source_path')
        item = dict(symbol=function['name'], readable_name=readable,
                    size=int(function['size']), source=source)
        reasons = []
        if PLACEHOLDER.search(readable):
            reasons.append('address-only-name')
        elif re.search(r'(?:_|Main|Ov\d{3}_?)[0-9a-fA-F]{8}(?:\(|$)', readable) and not readable.startswith('__sinit_'):
            reasons.append('temporary-address-disambiguation-review')
        if 'Unknown' in readable:
            reasons.append('recorded-uncertainty-review')
        if reasons:
            pending.append(dict(item, reasons=reasons))
        if source and '/Unclassified/' in source:
            ownership.append(item)
    return dict(scope='Matched ARM9 report functions; not a claim of semantic completeness',
                matched_functions=len(matched), naming_review_functions=len(pending),
                address_only_functions=sum('address-only-name' in x['reasons'] for x in pending),
                unclassified_functions=len(ownership), naming_review=pending,
                subsystem_ownership_review=ownership,
                caveat='Review lists are not automatic violations. ABI/runtime names and documented uncertainty need human evidence review; no inferred names or source changes.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = audit(args.project.resolve())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: v for k, v in result.items() if not isinstance(v, list)}))


if __name__ == '__main__':
    main()
