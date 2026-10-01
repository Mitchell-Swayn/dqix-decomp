#!/usr/bin/env python3
"""Build an exact Git revision from fresh extraction and objects, without deleting anything.

Uses only a supplied ROM, optional BIOS, and locally installed build tools. Results
stay in a new build/verification directory; never reuses the main working build.
"""

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import zipfile


ROOT = Path(__file__).resolve().parents[1]
USA_SHA1 = "c7c3014c237900c8281289b8bc76a781969b6278"
BIOS_SHA1 = "24f67bdea115a2c847c8813a262502ee1607b7df"


def digest(path, algorithm="sha256"):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, algorithm).hexdigest()


def tool_files(root):
    suffix = ".exe" if os.name == "nt" else ""
    paths = [root / ("dsd" + suffix), root / ("objdiff-cli" + suffix)]
    paths.extend(sorted((root / "tools/mwccarm/2.0/sp2p2").glob("*")))
    if os.name != "nt":
        paths.append(root / "wibo")
    return [path for path in paths if path.is_file()]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--revision", default="HEAD", help="Committed source revision")
    parser.add_argument("--rom", type=Path, default=ROOT / "extract/baserom_dqix_usa.nds")
    parser.add_argument("--bios", type=Path, default=ROOT / "arm7_bios.bin")
    parser.add_argument("--require-sha1", action="store_true", help="Fail if BIOS or final ROM match is absent")
    parser.add_argument("--tool-lock", type=Path, help="Require exact SHA-256s from a previous manifest's tools field")
    args = parser.parse_args()
    revision = subprocess.check_output(
        ["git", "rev-parse", "--verify", args.revision + "^{commit}"], cwd=ROOT, text=True
    ).strip()
    if digest(args.rom, "sha1") != USA_SHA1:
        parser.error("ROM does not match the USA acceptance input")
    has_bios = args.bios.is_file()
    if has_bios and digest(args.bios, "sha1") != BIOS_SHA1:
        parser.error("ARM7 BIOS does not match ci/baseroms_usa.sha1")
    if args.require_sha1 and not has_bios:
        parser.error("--require-sha1 requires the user-supplied ARM7 BIOS")
    suffix = ".exe" if os.name == "nt" else ""
    ninja = shutil.which("ninja") or str(Path(sys.executable).parent / ("ninja" + suffix))
    required = [ROOT / ("dsd" + suffix), ROOT / ("objdiff-cli" + suffix), Path(ninja)]
    required.extend(ROOT / "tools/mwccarm/2.0/sp2p2" / name for name in ("mwccarm.exe", "mwldarm.exe"))
    for path in required:
        if not path.is_file():
            parser.error(f"Missing local build tool: {path}")
    files = tool_files(ROOT)
    tools = {path.relative_to(ROOT).as_posix(): digest(path) for path in files}
    tools["ninja"] = digest(ninja)
    if args.tool_lock:
        expected = json.loads(args.tool_lock.read_text(encoding="utf-8"))["tools"]
        if tools != expected:
            parser.error("Local tool hashes differ from the supplied tool lock")
    parent = ROOT / "build/verification"
    parent.mkdir(parents=True, exist_ok=True)
    run_dir = Path(tempfile.mkdtemp(prefix=revision[:12] + "-", dir=parent))
    source = run_dir / "source"
    source.mkdir()
    manifest = {
        "schema_version": 1,
        "source_revision": revision,
        "started_utc": datetime.now(timezone.utc).isoformat(),
        "python": sys.version,
        "platform": sys.platform,
        "input_rom_sha1": USA_SHA1,
        "arm7_bios_sha1": BIOS_SHA1 if has_bios else None,
        "tools": tools,
        "commands": [],
        "clean_source_archive": True,
        "fresh_extraction": True,
        "fresh_objects": True,
        "module_and_symbol_checks": "not_run",
        "whole_rom_sha1": "not_run",
        "runtime_tests": "not_run",
    }
    manifest_path = run_dir / "manifest.json"
    print(f"Verification directory: {run_dir}", flush=True)

    def run(command, cwd=source):
        manifest["commands"].append(command)
        with (run_dir / "build.log").open("a", encoding="utf-8") as log:
            log.write("\n$ " + subprocess.list2cmdline(command) + "\n")
            log.flush()
            subprocess.run(command, cwd=cwd, stdout=log, stderr=subprocess.STDOUT, check=True)

    try:
        archive = run_dir / "source.zip"
        run(["git", "archive", "--format=zip", "--output", str(archive), revision], ROOT)
        with zipfile.ZipFile(archive) as zipped:
            for name in zipped.namelist():
                if not (source / name).resolve().is_relative_to(source.resolve()):
                    raise ValueError("Unsafe path in Git archive")
            zipped.extractall(source)
        for path in files:
            target = source / path.relative_to(ROOT)
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(path, target)
        (source / "extract").mkdir(exist_ok=True)
        shutil.copy2(args.rom, source / "extract/baserom_dqix_usa.nds")
        if has_bios:
            shutil.copy2(args.bios, source / "arm7_bios.bin")
        run([sys.executable, "tools/configure.py", "usa"])
        run([ninja, "rom", "check", "report"])
        manifest["module_and_symbol_checks"] = "passed"
        report = source / "build/usa/report.json"
        shutil.copy2(report, run_dir / "report.json")
        manifest["arm9_report_measures"] = json.loads(report.read_text())["measures"]
        arm7_report = source / "build/usa/arm7/report.json"
        if arm7_report.is_file():
            shutil.copy2(arm7_report, run_dir / "arm7-source-report.json")
            arm7 = json.loads(arm7_report.read_text())
            manifest["arm7_source_measures"] = {key: arm7[key] for key in (
                "source_code_bytes", "source_literal_pool_bytes", "source_data_bytes",
                "source_functions", "binary_fallback_bytes", "source_symbol_checks_passed")}
        manifest["built_rom_sha1"] = digest(source / "dqix_usa.nds", "sha1")
        if has_bios:
            run([ninja, "sha1"])
            manifest["whole_rom_sha1"] = "passed"
        else:
            manifest["whole_rom_sha1"] = "blocked_missing_arm7_bios"
        manifest["result"] = "passed" if has_bios else "module_baseline_passed_final_sha1_blocked"
    except Exception as error:
        manifest["result"] = "failed"
        manifest["error"] = str(error)
        raise
    finally:
        manifest["finished_utc"] = datetime.now(timezone.utc).isoformat()
        manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
        print(f"Evidence: {manifest_path}", flush=True)
    print(manifest["result"])


if __name__ == "__main__":
    main()
