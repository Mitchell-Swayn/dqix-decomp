# Timed 100-function worker guide

## Assigned workspace and starting state

Use `/home/swayn/Projects/dqix-factory-v01/build/luna100-reset/project` for every source edit. This independent detached worktree already includes the three previous accepted 100-function batches and reconstruction tools. Do not create another worktree, reapply prior patches, copy generated objects from another worker, or edit the main checkout. Parent preparation and baseline build are outside your measured reconstruction interval; say so in the report.

Read AGENTS.md and this guide first. GOALS.md defines acceptance; docs/RECONSTRUCTION_TOOLS.md explains tool contracts. This task is 100 additional source reconstructions, not 100 cache reads or recompilation of old source.

## Proven execution environment

Run Python evidence/selection tools on the host. Run configure, Ninja, matching, and integrated builds in the existing container. Docker access requires `sudo -n`; ordinary Docker socket permission denial does not imply Docker is unavailable. Do not download Ninja or tools, assemble a host toolchain, or alter the shared inputs.

Use this prefix for all container commands (append the program and arguments):

```sh
sudo -n docker run --rm --user 1000:1000 \
  -v /home/swayn/Projects/dqix-factory-v01/build/luna100-reset:/bench \
  -v /home/swayn/.local/share/factory-inputs/dqix:/inputs:ro \
  -w /bench/project factory-dqix:0.1
```

Compiler root is `/opt/dqix/mwccarm`, NOT its `2.0/sp2p2` subdirectory: configure appends the version itself. Tools are `/inputs/dsd`, `/inputs/wibo`, `/inputs/objdiff-cli`; Ninja and Python are installed in the image. Worker input symlinks to `/inputs/original.nds` and `/inputs/objdiff-cli` intentionally resolve only inside the container. Do not repair them into host paths. The original ROM is mounted read-only; all generated outputs belong to this worker.

Reconfigure only after source/range changes:

```sh
python3 tools/configure.py usa --compiler /opt/dqix/mwccarm --dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo --keep-symbol func_0200bbd8
ninja -j 2 objdiff delink
```

Run these through the container prefix, using `bash -c` when both commands are required. Keep the retained symbol flag for all configurations. Parent baseline log is `/home/swayn/Projects/dqix-factory-v01/build/luna100-reset/baseline.log`.

## Start timer, select, and retrieve evidence

Start a monotonic timer immediately on beginning your turn; retain it through all retries. Use tools/work_batch.py start/finish as well for coverage records; consult `--help` for its arguments. Capture before coverage from the existing passing build/usa/report.json and ARM7 report. Never reset the timer after a failure.

The shared prepared SQLite database is `/home/swayn/Projects/dqix-factory-v01/build/evidence/functions.sqlite`. Make an independent copy to this worker's build/evidence/functions.sqlite, using SQLite backup if another process is writing it. No need to rebuild the inventory. Queue must use THIS worker's current coverage report, not historical inventory completion flags.

From worker root on host:

```sh
python3 tools/evidence_store.py queue --project . --limit 100 --output build/luna-queue.json
python3 tools/evidence_store.py fetch build/luna-queue.json --server http://127.0.0.1:8082 --fingerprint 58c481b6aa2da9cc844fbbb7b27c045c33a1abc05bf524f9befd46cdab159ec8 --output build/luna-inspection.json
```

Inspect output/errors and the pseudocode, original assembly, types, relocations and dependencies. Cache retrieval is analysis only. If an unsuitable candidate needs replacement, maintain an explicit final 100-function manifest with unique module-qualified IDs and validate against current fallback ownership. Avoid spending time generating a 1,000-function queue without a concrete need.

## Write source and iterate

```sh
python3 tools/prepare_candidates.py build/luna-inspection.json --source-dir src/Luna100 --output build/luna-batch.json --write
```

Preparation creates source scaffolds with intentional #error and updates delink ranges. Replace each with reviewed readable C/C++; never compile Ghidra comments as if they are verified source. Use assembly to infer parameter widths, signedness, offsets and return conventions. Existing source provides conventions and examples, not permission to count it again.

Reconfigure through container once source/range assignments exist, then use this container command:

```sh
python3 tools/compile_verify_batch.py --manifest build/luna-batch.json --require-raw --jobs 2 --compare-jobs 4
```

This builds all selected candidate objects once, compares objdiff and original function bytes, and emits compact JSON with artifact paths and timings. Exit 0 means all selected objects pass; 1 means mismatch; 2 means build/comparison error. Read only the failing per-function artifacts, correct types/code, and rerun; unchanged objects use Ninja's local cache. After ten unproductive variants on one function record evidence and switch dependencies. No binary substitutes, assembly wrappers, stale-object success, or denominator reductions.

## Final acceptance and report

After all 100 exact object matches, run through container:

```sh
ninja -j 2 rom check report sha1
python3 tools/audit_link_layout.py build/luna-batch.json --elf build/usa/arm9.o --output build/luna-layout.json
```

Require full module/symbol/ARM7 checks, selected linked addresses and sizes, unchanged coverage denominators, exactly 100 additional matched functions, and final ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. If baseline or integrated checks fail, report the specific failure promptly; do not invent a new build environment. An object match alone is not acceptance.

Finish coverage/timing records and write a concise report under docs/verification/luna-100-functions.md in the worker. Include model/reasoning, start/end and total monotonic elapsed time, retrieval and compile/comparison timings when measured, matched functions/bytes, function size distribution, coverage delta and validation. Distinguish parent setup from your timed work and cached analysis from source reconstruction. No fabricated token/cost figures or gameplay claims. Keep logs in build/. Leave source uncommitted for review.
