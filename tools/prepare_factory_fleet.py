"""Prepare independently built overlay worktrees for the explicitly requested fleet."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
SHA1 = 'c7c3014c237900c8281289b8bc76a781969b6278'


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha1').hexdigest()


def prepare(root, module, revision):
    worker = 'fleet_' + module
    tree = root.parent / ('DQIX-Decomp-' + worker.replace('_', '-'))
    logs = root / 'build/factory/provision'
    logs.mkdir(parents=True, exist_ok=True)
    with (logs / (worker + '.log')).open('w', encoding='utf-8') as log:
        def run(argv):
            subprocess.run(argv, cwd=tree if tree.exists() else root, stdout=log, stderr=subprocess.STDOUT, check=True)
        if not tree.exists():
            subprocess.run(['git', 'worktree', 'add', '-b', 'work/' + worker, str(tree), revision], cwd=root,
                           stdout=log, stderr=subprocess.STDOUT, check=True)
        else:
            if not (tree / '.git').is_file():
                raise ValueError('Existing directory is not a worktree: ' + str(tree))
        # Read-only tools may be shared; program input and generated outputs may not.
        for name in ('.venv', 'tools/mwccarm'):
            target, source = tree / name, root / name
            if not target.exists():
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(target), str(source)],
                               stdout=log, stderr=subprocess.STDOUT, check=True)
        for name in ('dsd.exe', 'objdiff-cli.exe'):
            if not (tree / name).exists():
                shutil.copy2(root / name, tree / name)
        rom = tree / 'extract/baserom_dqix_usa.nds'
        if not rom.exists():
            shutil.copy2(root / 'extract/baserom_dqix_usa.nds', rom)
        if digest(rom) != SHA1 or rom.stat().st_nlink != 1:
            raise ValueError('Worker ROM is not independent verified original: ' + str(rom))
        run([str(root / '.venv/Scripts/python.exe'), 'tools/configure.py', 'usa', '--compiler', str(tree / 'tools/mwccarm')])
        run([str(root / '.venv/Scripts/ninja.exe'), '-j', '2', 'rom', 'check', 'report', 'sha1'])
        if digest(tree / 'dqix_usa.nds') != SHA1:
            raise ValueError('Baseline acceptance failed')
    prompt = logs / (worker + '.prompt.txt')
    prompt.write_text(f'''You are an independent Sol6.1 reconstruction worker for Dragon Quest IX USA.
Assigned worktree: {tree}. Exclusive module: {module}.
Work only inside this worktree using absolute edit paths. Root integrator owns main.
Read AGENTS.md, GOALS.md, docs/workflow/README.md, Decompiling.md and relevant code.
Do not spawn any subagents: the supervisor already runs24 independent workers.
Baseline is configured and full ROM/module/symbol/SHA1 checked. .venv and compiler
directories are shared read-only tooling; never modify them or install packages there.
Every reconfigure must pass --compiler "{tree / 'tools/mwccarm'}" to avoid
scheduling compiler downloads against shared tools.
Original ROM is independent verified extract/baserom_dqix_usa.nds. Never hardlink ROMs.

TASK: reconstruct one coherent bounded family of originally compiler-generated
functions in config/usa/arm9/overlays/{module}/. Inspect that module's symbol and
delink maps, original code/callers and existing source. Choose unowned functions
whose types/dependencies you can establish. Favor meaningful connected functions,
not artificial wrappers. No edits in other modules or main queue.json. New source
belongs under src/Factory/{module}/; shared header changes must be justified and
travel in your commit. Original fallback remains for any nonexact function.

Iterate candidate objects with tools/match_unit.py --worker {worker} --hypothesis
and tools/factory_evidence.py. tools/factory_diff.py diagnoses observed differences.
Use original disassembly via dsd help/map/object tools; generated pseudocode is
only a hypothesis. Never patch original comparison inputs, lower denominators,
embed binary code, fake matching, add assembly to bypass C reconstruction, or
hide data dependencies. Actual arrays/subobjects and correct shared types required.
Preserve separate instruction/literal/data/BSS/alignment distinctions. After10
unproductive variants/function, persist evidence and switch dependencies. Prior
batch caps survive; inspect build/factory and docs/workflow notes before retrying.

Use tools/work_batch.py start/finish with unique {worker} timestamp batch names.
Aim for a bounded20-minute batch, not an entire module in one session. Compile
candidates before full builds; use ninja -j2 to share host capacity. Once exact,
run full ninja -j2 rom check report sha1. Commit verified source with Codex git
identity. Do not integrate or merge into main. Leave verbose logs/drafts under
ignored build; add concise evidence doc under docs/workflow/{worker}.md.
At end provide exact commit list, ranges, code/function/data/BSS deltas, tests,
attempt counts, elapsed time, unresolved dependencies. Do not invent tokens or
claim module completion. If no match, preserve candidate and failed hypotheses
and report zero coverage. The next supervised batch can continue this module.
''', encoding='utf-8')
    return dict(id=worker, worktree=str(tree), prompt_file=str(prompt), module=module)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--backend', required=True)
    parser.add_argument('--revision', default='HEAD')
    parser.add_argument('--parallel', type=int, default=3)
    args = parser.parse_args()
    root = args.root.resolve()
    if digest(root / 'extract/baserom_dqix_usa.nds') != SHA1:
        raise ValueError('Main original ROM hash mismatch')
    revision = subprocess.check_output(['git', 'rev-parse', args.revision], cwd=root, text=True).strip()
    modules = [f'ov{i:03}' for i in range(26) if i not in (8, 17)]
    workers = []
    with ThreadPoolExecutor(max_workers=args.parallel) as pool:
        futures = {pool.submit(prepare, root, module, revision): module for module in modules}
        for future in as_completed(futures):
            workers.append(future.result())
            print('Prepared ' + futures[future], flush=True)
    config = dict(backend=str(Path(args.backend).resolve()), model='gpt-6.1-sol',
                  max_concurrent=24, repeat=True, max_unreviewed_batches=2,
                  workers=sorted(workers, key=lambda x: x['id']))
    output = root / 'build/factory/fleet-config.json'
    output.write_text(json.dumps(config, indent=2) + '\n', encoding='utf-8')
    print(output)


if __name__ == '__main__':
    main()
