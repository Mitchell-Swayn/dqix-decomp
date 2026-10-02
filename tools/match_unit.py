#!/usr/bin/env python3
"""Compare one ARM9 candidate object. Exit 0 means comparison ran, not ROM acceptance."""

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time
import uuid


ROOT = Path(__file__).resolve().parents[1]
NOTICE = "Object comparison only; no ROM acceptance claim."


def select_unit(config, name):
    if not isinstance(config, dict) or not isinstance(config.get("units"), list):
        raise ValueError("objdiff.json must contain a units array")
    matches = [u for u in config["units"] if isinstance(u, dict) and u.get("name") == name]
    if len(matches) != 1:
        raise ValueError(f"expected one exact unit named {name!r}; found {len(matches)}")
    unit = matches[0]
    if not unit.get("base_path") or not unit.get("target_path"):
        raise ValueError("unit needs both base_path and target_path (candidate source may be missing)")
    if unit.get("scratch", {}).get("platform") != "nds_arm9":
        raise ValueError("unit is not marked as an nds_arm9 candidate")
    return unit


def within(root, path):
    root, path = root.resolve(), path.resolve()
    if not path.is_relative_to(root) or path == root:
        raise ValueError(f"path must stay inside {root}: {path}")
    return path


def object_paths(root, unit):
    paths = []
    for field in ("target_path", "base_path"):
        value = unit[field]
        if not isinstance(value, str) or not value:
            raise ValueError(f"invalid {field}")
        path = within(root / "build", root / value)
        if path.suffix != ".o":
            raise ValueError(f"{field} must be an object (.o)")
        paths.append(path)
    target, base = paths
    relative = base.relative_to(root.resolve() / "build")
    if len(relative.parts) < 3 or relative.parts[1] not in ("src", "libs"):
        raise ValueError("candidate must be under build/<version>/src or libs")
    if target == base or (target.exists() and base.exists() and target.samefile(base)):
        raise ValueError("target and candidate must be different files")
    return target, base


def new_attempt(root):
    # No user-controlled unit name enters an output path, including JSONL paths.
    output_root = within(root, root / "build" / "matching")
    output_root.mkdir(parents=True, exist_ok=True)
    attempt = within(output_root, output_root / (
        datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S") + "-" + uuid.uuid4().hex))
    attempt.mkdir()
    return attempt


def sha256(path):
    if not path.is_file():
        return None
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def summarize(document, difference_limit=3):
    """Read objdiff 2.7.x protobuf JSON (left/right.sections[].symbols[])."""
    if not isinstance(document, dict):
        raise ValueError("objdiff result must be an object")
    rows = []
    for side in ("left", "right"):
        obj = document.get(side)
        if not isinstance(obj, dict) or not isinstance(obj.get("sections"), list):
            raise ValueError(f"objdiff result missing {side}.sections")
        for section in obj["sections"]:
            for symbol in section.get("symbols", []):
                info = symbol.get("symbol", {})
                if not isinstance(info.get("name"), str):
                    raise ValueError("objdiff symbol missing name")
                # Section markers have no comparison; right matched symbols repeat left.
                if int(info.get("flags", 0)) & 2 or (side == "right" and "target" in symbol):
                    continue
                if not int(info.get("size", 0)) and "match_percent" not in symbol:
                    continue
                percent = symbol.get("match_percent", 0.0)
                if isinstance(percent, bool) or not isinstance(percent, (float, int)) or not 0 <= percent <= 100:
                    raise ValueError("invalid symbol match_percent")
                differences = []
                for instruction in symbol.get("instructions", []):
                    kind = instruction.get("diff_kind", "DIFF_NONE")
                    if kind not in ("DIFF_NONE", 0):
                        code = instruction.get("instruction", {})
                        differences.append(f"{kind} @0x{int(code.get('address', 0)):x}: "
                                           f"{code.get('formatted', '<gap>')}")
                rows.append({"side": "target" if side == "left" else "base",
                             "section": section.get("name", "?"), "symbol": info["name"],
                             "match_percent": percent, "paired": "target" in symbol,
                             "differences": differences[:difference_limit]})
    if not rows:
        raise ValueError("objdiff result has no sized symbols to compare")
    return rows


def run_logged(command, root, attempt, label):
    with (attempt / f"{label}.stdout.log").open("w", encoding="utf-8") as stdout, \
            (attempt / f"{label}.stderr.log").open("w", encoding="utf-8") as stderr:
        result = subprocess.run(command, cwd=root, stdout=stdout, stderr=stderr, check=False)
    if result.returncode:
        raise ValueError(f"{label} exited {result.returncode}; see {attempt}")


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("unit", help="exact unit name in objdiff.json")
    parser.add_argument("--no-build", action="store_true", help="compare existing objects")
    parser.add_argument("--hypothesis", help="specific source/compiler hypothesis being tested")
    parser.add_argument("--worker", help="factory worker identifier")
    parser.add_argument("--job", help="factory job identifier")
    args = parser.parse_args(argv)
    started = time.monotonic()
    attempt = None
    record = {"unit": args.unit, "no_build": args.no_build,
              "hypothesis": args.hypothesis, "worker": args.worker, "job": args.job,
              "started_utc": datetime.now(timezone.utc).isoformat(), "rom_acceptance": False}
    try:
        config_path = ROOT / "objdiff.json"
        unit = select_unit(json.loads(config_path.read_text(encoding="utf-8")), args.unit)
        target, base = object_paths(ROOT, unit)
        attempt = new_attempt(ROOT)
        record.update(attempt=str(attempt.relative_to(ROOT)), target_path=str(target.relative_to(ROOT)),
                      base_path=str(base.relative_to(ROOT)), config_sha256=sha256(config_path),
                      target_sha256_before=sha256(target), base_sha256_before=sha256(base))
        source = unit.get("metadata", {}).get("source_path")
        if source:
            source_path = within(ROOT, ROOT / source)
            record.update(source_path=source, source_sha256=sha256(source_path))
            if source_path.is_file():
                # Preserve the candidate, not just its hash, for subsequent workers.
                snapshot_path = attempt / ('candidate' + source_path.suffix)
                snapshot_path.write_bytes(source_path.read_bytes())
                record['source_snapshot'] = str(snapshot_path.relative_to(ROOT))
        if not target.is_file():
            raise ValueError(f"target object missing: {target}; configure/extract it first")
        commands = []
        record["commands"] = commands
        if not args.no_build:
            ninja = ROOT / (".venv/Scripts/ninja.exe" if os.name == "nt" else ".venv/bin/ninja")
            if not ninja.is_file():
                raise ValueError(f"local venv Ninja missing: {ninja}")
            command = [str(ninja), str(base.relative_to(ROOT)).replace("\\", "/")]
            commands.append(command)
            run_logged(command, ROOT, attempt, "ninja")
        if not base.is_file():
            raise ValueError(f"candidate object missing: {base}")
        command = [str(ROOT / ("objdiff-cli.exe" if os.name == "nt" else "objdiff-cli")),
                   "diff", "-1", str(target), "-2", str(base), "-o", str(attempt / "diff.json"),
                   "--format", "json"]
        commands.append(command)
        run_logged(command, ROOT, attempt, "objdiff")
        rows = summarize(json.loads((attempt / "diff.json").read_text(encoding="utf-8")))
        mismatches = [r for r in rows if r["match_percent"] < 100 or not r["paired"]]
        record.update(status="compared", symbols=len(rows), mismatches=len(mismatches), summary=rows)
        from factory_diff import classify
        analysis = classify(json.loads((attempt / "diff.json").read_text(encoding="utf-8")))
        (attempt / 'diagnosis.json').write_text(json.dumps(analysis, indent=2) + '\n', encoding='utf-8')
        record['diagnosis_path'] = str((attempt / 'diagnosis.json').relative_to(ROOT))
        print(f"{args.unit}: {len(rows) - len(mismatches)}/{len(rows)} symbols at 100%")
        for row in mismatches:
            print(f"  {row['side']} {row['section']} {row['symbol']}: {row['match_percent']:.2f}%"
                  + (" (unpaired)" if not row["paired"] else ""))
            for difference in row["differences"]:
                print(f"    {difference}")
        return 0
    except (OSError, ValueError, TypeError, KeyError, AttributeError) as error:
        record.update(status="error", error=str(error))
        print(f"match_unit: {error}", file=sys.stderr)
        return 2
    finally:
        record["elapsed_seconds"] = round(time.monotonic() - started, 6)
        if attempt is not None:
            record.update(target_sha256_after=sha256(target), base_sha256_after=sha256(base))
            (attempt / "attempt.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
            ledger = within(attempt.parent, attempt.parent / "attempts.jsonl")
            with ledger.open("a", encoding="utf-8") as stream:
                stream.write(json.dumps(record) + "\n")
            print(f"Artifacts: {attempt}")
        print(NOTICE)


if __name__ == "__main__":
    sys.exit(main())
