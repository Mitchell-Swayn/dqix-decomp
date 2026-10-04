"""Track pinned dsd's real ELF outputs using Ninja dynamic dependencies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time


def ninja_path(path):
    return str(path).replace("\\", "/").replace("$", "$$").replace(" ", "$ ").replace(":", "$:")


def depfile_path(path):
    return str(path).replace("\\", "/").replace("$", "$$").replace(" ", "\\ ").replace("#", "\\#").replace(":", "\\:")


def output_paths(project, directory):
    root = Path.cwd().resolve()
    directory = directory.resolve()
    paths = []
    for unit in project["units"]:
        path = Path(unit["target_path"])
        resolved = path.resolve()
        if not resolved.is_relative_to(directory) or resolved.suffix != ".o":
            raise ValueError(f"Invalid delink output: {path}")
        paths.append(resolved.relative_to(root).as_posix())
    if not paths or len(set(paths)) != len(paths):
        raise ValueError("Expected a nonempty unique delink object list")
    return sorted(paths)


def extracted_inputs(root):
    # Pinned dsd's extracted ARM9 layout, including its module metadata and
    # overlay table. Cartridge assets and ARM7 are not delink inputs.
    directories = [root, root / "arm9", root / "arm9_overlays"]
    for directory in directories:
        if not directory.is_dir():
            raise ValueError(f"Missing extracted ARM9 directory: {directory}")
    files = [path for directory in directories for path in directory.iterdir()
             if path.is_file()]
    if not (root / "config.yaml").is_file() or not (root / "arm9/arm9.bin").is_file():
        raise ValueError("Missing extracted ARM9 configuration or program")
    return sorted(files), directories


def atomic_json(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_suffix(path.suffix + ".tmp")
    temp.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    os.replace(temp, path)


def plan(args):
    outputs = output_paths(json.loads(args.objdiff.read_text(encoding="utf-8")), args.directory)
    inputs, directories = extracted_inputs(args.extract)
    atomic_json(args.plan, {"schema_version": 1, "outputs": outputs})
    args.dyndep.write_text("ninja_dyndep_version = 1\n" +
        "build " + ninja_path(args.completion) + " | " + " ".join(map(ninja_path, outputs)) +
        " : dyndep | " + " ".join(map(ninja_path, inputs)) + "\n", encoding="utf-8")
    # Directory mtimes regenerate the inventory if extracted files are added or
    # removed. The dynamic edge itself tracks every inventoried file's contents
    # through Ninja's normal mtime rules.
    args.depfile.write_text(depfile_path(args.dyndep) + ": " +
        " ".join(map(depfile_path, directories)) + "\n", encoding="utf-8")


def run(args):
    planned = json.loads(args.plan.read_text(encoding="utf-8"))["outputs"]
    # Validate again: do not allow a manipulated plan to inventory arbitrary files.
    outputs = output_paths({"units": [{"target_path": p} for p in planned]}, args.directory)
    args.completion.unlink(missing_ok=True)
    before = {p: (Path(p).stat().st_mtime_ns, Path(p).stat().st_size)
              if Path(p).exists() else None for p in outputs}
    started = time.monotonic()
    command = [str(args.dsd.resolve()), "delink", "--config-path", str(args.config)]
    subprocess.run(command, check=True)
    records = []
    for name in outputs:
        path = Path(name)
        content = path.read_bytes()
        stat = path.stat()
        if not content.startswith(b"\x7fELF"):
            raise ValueError(f"Delink did not produce an ELF object: {name}")
        if before[name] == (stat.st_mtime_ns, stat.st_size):
            raise ValueError(f"Delink left an old output untouched: {name}")
        records.append({"path": name, "size": len(content),
                        "sha256": hashlib.sha256(content).hexdigest()})
    atomic_json(args.completion, {"schema_version": 1, "command": command,
        "elapsed_seconds": round(time.monotonic() - started, 6), "outputs": records})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="mode", required=True)
    planning = sub.add_parser("plan")
    planning.add_argument("--objdiff", type=Path, required=True)
    planning.add_argument("--extract", type=Path, required=True)
    planning.add_argument("--dyndep", type=Path, required=True)
    planning.add_argument("--depfile", type=Path, required=True)
    running = sub.add_parser("run")
    running.add_argument("--dsd", type=Path, required=True)
    running.add_argument("--config", type=Path, required=True)
    for child in (planning, running):
        child.add_argument("--directory", type=Path, required=True)
        child.add_argument("--plan", type=Path, required=True)
        child.add_argument("--completion", type=Path, required=True)
    args = parser.parse_args()
    (plan if args.mode == "plan" else run)(args)


if __name__ == "__main__":
    main()
