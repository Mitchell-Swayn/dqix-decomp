# Reconstruction scripts for agents

These scripts return compact JSON and store verbose evidence under ignored
`build/`. They use the existing Ghidra MCP HTTP backend, Metrowerks compiler,
Wibo, Ninja, and objdiff. They do not install or register additional MCP tools.
Run terminal commands from the intended worktree; `--project` can select another
checkout for selection, preparation, and batch verification.

## Select and inspect

Start from a current coverage report and select functions still owned by binary
fallback. Selection defaults to small functions; adjust bounds for harder work.

```sh
python3 tools/select_candidates.py --module main --limit 100 --max-bytes 24 --output build/functions.json
python3 tools/inspect_functions.py build/functions.json --server http://127.0.0.1:8082 --output build/inspection.json
```

The inspection command fetches pseudocode, assembly, function descriptions, and
up to 200 references per function through the same HTTP server as the Ghidra MCP.
It does not modify Ghidra. Keep the intended program active throughout inspection.
It checks a layout/symbol fingerprint before and after the batch; use
`--expect-fingerprint HASH` to require an earlier identity. The backend exposes no
unique program ID or raw-byte endpoint, so this fingerprint cannot distinguish
two programs with identical layouts/symbols. Original bytes come from delinked
target objects during verification, not from this inspection endpoint.

Review `review_flags`, errors, function boundaries, types and dependencies before
choosing candidates. The shared-epilogue flag is a heuristic, not a definitive
boundary determination. Selection handles one module at a time; `main`, `itcm`,
`dtcm`, and `ov000`–`ov034` are supported. Overlay inspection requires the matching
Ghidra program to be active.

## Search for already-matched instruction patterns

An optional way to investigate a stubborn match is to find another function
with the same distinctive instruction pattern and inspect its recovered source.
This is particularly useful when the operations and control flow match but
register allocation differs, or many source variants produce identical output.

1. Identify a short, distinctive sequence in the original instructions. Include
   apparently redundant conversions, masks, shifts and operand relationships:
   these can expose source types and expression boundaries. For example, a
   nibble update can contain an arithmetic shift by four, a byte mask `0xff`,
   masks `0xf` and `0xc`, and an OR with a four-bit shifted operand.
2. Search original instruction listings across main and overlays, including
   functions already recovered as source. Ghidra instruction searches or a small
   read-only disassembly scan can find candidates. Text searches with `rg` are
   useful when listings are available. Normalize aliases such as `ip`/`r12` and
   immediate formatting; allow consistent register renaming while preserving
   operand relationships, access widths, condition codes and instruction order.
   A short sequence may occur inside a larger function or across basic blocks.
3. Resolve each hit through its module's symbol and delink maps. Keep the module,
   address, ARM/Thumb mode and original function extent attached to the result;
   overlay addresses alone are ambiguous. Use the correct original binary and
   load address, and avoid interpreting data as instructions.
4. Inspect the matched sibling's C/C++ and the surrounding branch. Compare typed
   member access versus pointer arithmetic, named indices, intermediate widths,
   separate compound assignments, and branch-local versus shared stores. Transfer
   only the relevant source idiom, adapting it to the target's independently
   established layout and behavior. Similar instructions do not establish shared
   object types, field meanings or call contracts.
5. Compile the resulting hypothesis against the unchanged original target. Use
   a small number of controlled variations to identify which structural choices
   affect the output. Count distinct emitted patterns as well as candidates so
   repeated compiler output is visible. Save scans, hits and comparisons under
   ignored `build/`. Normal semantic review and object, relocation, layout, module,
   symbol and ROM acceptance checks still apply.

A concrete reference is
[`Script_SetPackedEntryStateAndNotifyPeers`](../src/Script/Script_SetPackedEntryStateAndNotifyPeers.cpp)
(main `0x0206E164`). The `kind == 7` branch of
[`GameState_ApplyEncodedFlagUpdate`](../src/GameState/GameState_ApplyEncodedFlagUpdate.cpp)
(main `0x0206E748`) contains a closely related nibble update. The setter matches
with a typed member byte array, a named `half = index / 2`, and byte locals
followed by separate `&=` and `|=` updates in each branch. A shared result and
single source-level store express the same intended update but change code
allocation. The matched implementation uses the default compiler profile
without extra optimization pragmas or `volatile`.

This example supplies a source-structure hypothesis, not a universal matching
recipe. Tail merging is a plausible explanation for its shared emitted store;
that compiler-internal mechanism is not independently established. Exact output
also does not prove that the recovered text is the original source.

## Check SDK source language when aggregate copies differ

For SDK code that returns structures through inline helpers, include the source
language among the bounded matching hypotheses. Compare the reference source and
both emitted objects when aggregate copies or stack slots differ. Source language
is one possible cause; other SDK routines match as C++.

[TextLayout_RenderAnchoredTextInDirection.c](../src/Graphics/TextLayout_RenderAnchoredTextInDirection.c)
uses native C and emits the matching 292-byte routine with the pinned compiler.
The same-body C++ experiment emits 284 bytes; a C++ wrapper that directly returns
the measurement result emits 264 bytes. A named result in the inner C helper
preserves the aggregate copies and stack arrangement in this case. These sizes
are observations for this routine and toolchain, not a general compiler rule.
Use a `.c` translation unit and the normal build's `-lang=c` selection for this
option. Canonical interfaces, whole-object comparisons, independent relocated-byte
proofs and full ROM validation still apply.

## Prepare candidates

Use an isolated worktree. Preparation validates each name, address and size
against that module's `symbols.txt`, checks original section bounds and assigned
range overlaps, and creates one source file and one legal `.text` entry per
function. It refuses to overwrite source files or an existing output manifest.

```sh
python3 tools/prepare_candidates.py build/inspection.json --source-dir src/Reconstruction/Batch01 --output build/batch.json --write
```

Omit `--write` to preview; choose a different output filename for the subsequent
write. Each scaffold contains an explicit `#error` and commented Ghidra evidence,
so unimplemented functions cannot accidentally pass compilation. Replace the
scaffolds with reviewed C/C++. Ghidra pseudocode is not automatically assumed to
be valid or matching source. To import existing reviewed candidates, supply
`--candidate-dir PATH` containing `NAME.cpp` files instead of creating scaffolds.
For other modules, supply the appropriate `--delinks` path, for example
`config/usa/arm9/overlays/ov017/delinks.txt`.

## Configure and generate original targets

Configure once when source/range assignments change. The added `--objdiff` option
uses an installed tool without generating a download rule. Linux compilation now
invokes dependency processing through the configured Python interpreter.

```sh
python3 tools/configure.py usa --compiler /path/to/mwccarm --dsd /path/to/dsd --objdiff /path/to/objdiff-cli -w /path/to/wibo
ninja objdiff
ninja delink
```

Existing original target objects are
required before the verification command. The batch verifier locates objdiff at
the project-root `objdiff-cli` (or `.exe` on Windows); when using an external tool,
make that project-root entry point to it. Ninja is resolved from the local virtual
environment or PATH; `--ninja PATH` overrides it.

Use repeatable `--keep-symbol NAME` on configure when an original unused function
would otherwise be discarded by the linker. The 100-function test required
`--keep-symbol func_0200bbd8`. Preserving a symbol retains its compiled code; it
does not weaken matching checks or count fallback as reconstructed source.

## Compile and verify in one call

```sh
python3 tools/compile_verify_batch.py --manifest build/batch.json --jobs 2 --compare-jobs 4 --require-raw
```

The command invokes Ninja once for all selected candidate objects, then compares
them in parallel. It does not repeatedly run configure or rebuild the ROM.
Compilation failure stops comparison for the entire batch, preventing stale
objects from producing success. Original target hashes, configuration and
candidate source hashes are checked for changes during the operation.

Exit codes are **0** for all selected units passing, **1** for mismatches, and
**2** for build/comparison errors. Output includes phase timings and a small set
of differences with conservative mismatch categories. Full logs, source snapshots,
objdiff output, raw-byte results and per-unit details remain in the returned
artifact directory. Exact unit names can also be supplied directly instead of a
manifest. `--no-build` compares existing objects and is explicitly not a recompile.

By default, success means an objdiff object match. `--require-raw` additionally
requires every sized function's bytes and size to match. Functions in sections
with code relocations return `raw_match: null`: raw bytes in relocatable objects
do not establish final linked identity. Those candidates need relocation-aware
objdiff comparison and integrated validation. Raw comparisons do not prove
semantic correctness or compare all object data/padding.

## Integrate and diagnose layout

After the candidate batch matches, run the normal project acceptance checks:

```sh
ninja -j 2 rom check report sha1
python3 tools/audit_link_layout.py build/batch.json --elf build/usa/arm9.o --output build/layout-audit.json
```

The layout audit identifies missing functions, changed addresses and changed
symbol sizes in the linked ELF. It supports MWLD's ELF with external module
binaries. Run it after a link even if integrated checks fail, to diagnose dead
stripping or shifts before spending time examining ROM differences. Exit codes
are 0 for unchanged selected layouts, 1 for differences, and 2 for errors.
It is not a replacement for module, symbol, ROM SHA-1, coverage or gameplay checks.

## Measured results

On the i7-12700 Linux host, the tools were exercised against the existing 100
verified small ARM9 functions in a fresh worktree:

- Ghidra inspection of 100 functions: **22.50 seconds**.
- Fresh configuration, complete build and integrated validation: **17.08 seconds**.
- Five forced recompiles of all 100 separate candidate objects plus raw-byte and
  objdiff verification: **1.85 seconds average**, range **1.74–1.97 seconds**.
- Deliberate source mismatch returned 1; compiler error returned 2; restoring the
  source returned 0. All 100 linked addresses/sizes passed the layout audit.

The benchmark reuses already reconstructed source. It measures workflow tools,
not the agent's time to reconstruct another 100 functions. Logs and timing records
are in `build/workflow-tools-test/`; detailed candidates remain in its isolated
worktree. Unit tests cover range conflicts, source preservation, changing Ghidra
identity, stale objects, changed original targets, raw-byte mismatches, relocations,
and missing/shifted linked symbols.

## Indexed evidence and cached Ghidra analysis

`tools/evidence_store.py` reuses `inventory/functions.sqlite` rather than building
another original-function inventory. The existing snapshot contains 15,067
functions across 41 modules, 64,012 relationships, original bytes/disassembly,
dependency layers and historical source evidence. Preparation checks SQLite
integrity and every function's byte length/hash, then makes an independent local
copy under ignored `build/evidence/`. The original inventory is preserved.

```sh
python3 tools/evidence_store.py prepare
python3 tools/evidence_store.py stats
python3 tools/evidence_store.py queue --project build/my-worker/project --limit 100 --output build/queue.json
python3 tools/evidence_store.py fetch build/queue.json --server http://127.0.0.1:8082 --fingerprint EXPECTED_PROGRAM_FINGERPRINT --output build/inspection.json
python3 tools/evidence_store.py get arm9/main:02039750 --fingerprint EXPECTED_PROGRAM_FINGERPRINT --neighbors 10
```

An agent needs one queue call, one cache fetch, then the existing preparation and
compile/verify commands. `get` returns only the requested function and bounded
neighbors. All commands emit JSON; large batch results stay in the output file.
The queue uses the selected worktree's **current report**, never the inventory's
historical completion flags. Original evidence is keyed by module and address,
so overlay addresses do not collide.

Ghidra records have a separate table keyed by function ID, original-byte hash and
program fingerprint. `fetch` checks the active program before/after, calls the
MCP HTTP backend only for misses, and retains complete inspection records.
Previously captured `inspect_functions.py` output can be added with `import`.
Cached Ghidra analysis does not receive matched-source credit. The backend's
fingerprint identifies layout/symbols, not memory contents or analysis revisions;
keep the program fixed and rebuild/import analysis after changing types or bytes.
The current fetch command supports the active ARM9 main/ITCM program only.
Whole-project original evidence is present; whole-project Ghidra pseudocode is
not. Lazy prefetch avoids spending time decompiling functions an agent will not
use. Compiler targets and coverage reports remain worktree-local and mutable;
reuse their normal Ninja caches, rather than sharing generated outputs.

## Call DAG and dependency-ranked batches

`evidence_store.py queue` now ranks all eligible candidates before applying its
limit. It reads the existing inventory's call relationships and recomputes the
condensed DAG and per-function metrics using `tools/dependency_rank.py`. Original
inventory completion flags are never used as current completion evidence.

```sh
python3 tools/evidence_store.py queue --project build/my-worker/project --module main --limit 100 --max-bytes 512 --rank-by context,readiness,unlocks,size,downstream,depth --dag-output build/evidence/call-dag.json --output build/evidence/ranked-batch.json
```

The default policy is lexicographic: `context,readiness,unlocks,size,downstream,depth`.

1. **Context:** reviewed functions with all required context known and direct
   callees available first; then reviewed blocked functions with lower weighted
   context burden; unassessed functions last. Unresolved resources cost twice
   partial resources, multiplied by importance (1–5). Unassessed functions do
   not receive a misleading advantage from undeclared dependencies.
2. **Call readiness:** all known direct callees matched, then matched-callee
   fraction and unresolved/ambiguous or unmatched direct dependencies.
3. **Unlocks:** more currently unfinished functions that depend directly on this
   function or on unresolved shared resources it is recorded as providing.
   Consumers are deduplicated. This estimates useful context impact, not a
   promise that all those functions become ready.
4. **Size:** fewer original bytes first.
5. **Downstream / depth:** larger distinct callee reach, then smaller lineage
   depth and stable module-qualified function ID.

Use `--rank-by readiness,downstream,size,depth` to reproduce the previous policy.

These are ordered priorities, not a weighted score. A later criterion breaks
ties and cannot outweigh an earlier one. Change `--rank-by` to change priorities:

```sh
# Small ready functions first, with downstream reach as a tie breaker:
python3 tools/evidence_store.py queue --project build/my-worker/project --limit 100 --max-bytes 128 --rank-by readiness,size,downstream,depth --output build/evidence/small-ready.json

# Functions with the largest outgoing dependency trees first:
python3 tools/evidence_store.py queue --project build/my-worker/project --limit 100 --max-bytes 512 --rank-by downstream,readiness,size,depth --output build/evidence/dependency-heavy.json

# Frequently depended-on functions first, rather than dependency-heavy callers:
python3 tools/evidence_store.py queue --project build/my-worker/project --limit 100 --max-bytes 512 --rank-by readiness,callers,size,depth --output build/evidence/shared-foundations.json

# Preserve the earlier size/address-oriented selection intent:
python3 tools/evidence_store.py queue --project build/my-worker/project --limit 100 --rank-by size --output build/evidence/small.json
```

The size window is a hard eligibility filter. Its default remains 8–24 bytes;
raise `--max-bytes` to include ordinary callers. `--rank-by size` sorts size then
module-qualified ID; the standalone `select_candidates.py` retains size/address
sorting and performs no dependency ranking.

Edges point **caller → callee**, including static tail transfers. Mutual/self
recursion is collapsed into strongly connected components. Each component is a
DAG node; its members share lineage depth. Leaf groups have depth 1; a caller
group has depth `1 + max(callee-group depths)`. This is longest dependency depth,
not shortest distance to a leaf. Recursive peers are listed as a joint-analysis
group, not assigned a fictitious internal order, and are not marked ready.

`downstream_dependencies` counts unique functions reachable in other groups,
excluding the candidate's recursive peers and itself. Diamond/shared paths do
not double-count functions. `transitive_callers` counts reachable functions in
the reverse direction; it is an impact proxy, not a guarantee that those callers
become ready after one reconstruction.

The export contains all inventoried functions, original call edges, condensed
groups/dependencies, lineage depth, recursive flags, reachability counts, current
callee completion and unresolved/ambiguous flags. Unknown indirect targets are
not invented. Ambiguous possible targets are included conservatively; unresolved
or ambiguous direct calls prevent a function from being labelled ready.

Current ARM9 callee completion requires a 100% matched function in a source unit
of the selected report, with a matching original size, module/range ownership
in that checkout's delink maps and an existing C/C++ source file. Current ARM7
availability uses its separate verified source-build report. These indicate
matched source availability, including approved mixed source/assembly routines,
not proof that types and semantics have been fully understood. A stale report
must be rebuilt before selection; a queue is a fixed snapshot and does not
assume other selected functions will pass later in the batch. The session tool
below refreshes that snapshot after each accepted batch.

Graph/report hashes and inventory creation time are recorded. The stored graph
is an original-inventory snapshot: rebuild the call inventory after changing
original binaries, boundaries or call-analysis assumptions. ARM7 inventory scope
is incomplete, and callbacks/computed targets may be absent. Ranking is advisory;
inspect boundaries, code/data distinctions and compiler feasibility before
preparing source. Exporting/ranking does not reconstruct or verify any function.


### Reviewed context and worker packages

`config/reconstruction-context.json` is a source-controlled context ledger.
Resources have stable IDs, a kind (`signature`, `type`, `layout`, `global`,
`interface`, or `note`), state (`known`, `partial`, `unresolved`), importance,
review notes and workspace-relative evidence paths/lines with SHA256 hashes.
A `known` signature means its calling contract was reviewed, not that its class
layout or semantics are complete. Record those as separate resources.

Every static callee adds an implicit `signature:<module-qualified-function-id>`
requirement. A matching body alone never establishes that signature. Explicit
function requirements describe its additional context dependencies; `provides`
links work to shared context it may recover. Providers earn only an impact
estimate: completing their bodies does not automatically make a resource known.

Record facts after reviewing actual evidence. Commands update the named entry
as a whole; include all retained requirements, providers and evidence references.
Evidence paths may use `:LINE` suffixes. Changed/missing evidence invalidates
known/partial resource credit and invalidates the affected function review.
A reviewed function entry means its required context has been inventoried from
instructions and existing work; it does not mean the function is reconstructed.
Unknown dependencies remain unassessed rather than being invented as known.

```sh
python3 tools/reconstruction_context.py resource layout:Widget --kind layout --state partial --importance 5 --evidence include/Widget.h:12 --note 'Fields at offsets 0x10 and 0x24 established; remaining layout unresolved'
python3 tools/reconstruction_context.py function arm9/main:02000000 --reviewed --requires layout:Widget --evidence docs/Widget-analysis.md:20 --note 'Reviewed required context from instruction stream'
# For a function expected to recover that shared layout:
python3 tools/reconstruction_context.py function arm9/main:02000040 --provides layout:Widget --evidence docs/Widget-analysis.md:35
```

The repository ledger starts with a reviewed allocator signature; other facts
need review. No automated source/header discovery is promoted to `known`.

Generate packages alongside any ranked queue:

```sh
python3 tools/evidence_store.py queue --module main --limit 20 --max-bytes 512 --context-output build/next-context --output build/next-assignment.json
```

Each package includes original inventory assembly, direct callee source paths,
reviewed resource notes/evidence, bounded source/header excerpts, symbol-reference
hints, and original-object relocation targets selected by exact function range
and section. File hashes, context/report identities and package hashes accompany
these inputs. Includes and symbol search are discovery hints, not proof of
recovered types or ownership. Missing original targets/readelf are labelled
unavailable; use the tested configure/delink environment before relying on them.
Read truncated files at the supplied full paths. Queues retain package paths
through evidence fetching. Packages do not replace fingerprint-checked Ghidra
inspection or binary acceptance.

### Resumable small batches

Use `reconstruction_session.py` for new runs that permit dynamic selection.
The default batch size is 20; permitted sizes are 1–20. Sessions currently support
ARM9 main integrated acceptance. They record the initial eligible scope and
requested total, retain one pending assignment until accepted, and rerank the
remaining scope from the current report and context ledger at each `next`.
Only one worker should own a session.

```sh
python3 tools/reconstruction_session.py --session build/my-session next --total 100 --batch-size 20
```

For a fixed collection, supply `--scope build/fixed-assignment.json` on the first
`next`. Its entire collection remains required; reprioritisation changes only
execution order. Without `--scope`, the initial eligible pool is retained and
`--total` determines the number to finish. Session selection parameters are
stored on creation; subsequent `next` calls reuse them. A pending batch is
returned unchanged, never replaced because it is difficult.

Read the emitted assignment/packages, fetch inspection and prepare only that
batch. Reconstruct, compare, integrate, run all mandatory module/symbol/ROM
checks, refresh the report and record recovered context before acceptance.
Use these commands in the configured build environment:

```sh
python3 tools/reconstruction_session.py --session build/my-session accept --manifest build/current-batch.json --comparison build/current-verification.json
python3 tools/reconstruction_session.py --session build/my-session next
python3 tools/reconstruction_session.py --session build/my-session status
```

Acceptance requires the exact pending IDs/boundaries and unit set, successful
object comparison with current candidate snapshots and object hashes, no raw
mismatches or unexplained inconclusive bytes, a refreshed report crediting every
selected function, unchanged denominators, actual linked ARM9 address/size audit,
and the exact USA ROM SHA1. The session tool checks these existing artifacts;
it does not run the full build or replace mandatory project checks. Failed
acceptance preserves the pending batch and gives no completion credit. Work
completed outside the session requires explicit reconciliation rather than
silently counting towards the run. Context gains trigger reranking only after
the pending batch is accepted. Existing fixed timed benchmarks retain their
original assignments and policy.

## Standard integration entry point

Only the coordinator integrates verified uncommitted subsets. Use:

```sh
python3 tools/integrate_verified_subset.py --worker /absolute/worker/project --manifest build/matched.json --receipts /absolute/main/build/run --label batch01 --role worker-b
```

The command acquires `build/progress/integration-process.lock` before reading main
source/maps/reports, then creates the dashboard publication lock before mutation.
It copies only listed new sources and ownership blocks, runs object/layout and full
ROM/module/symbol/SHA1 checks, checks exact coverage deltas and fixed denominators,
then publishes. Rejected additions alone are restored; configuration and generated
objects are rebuilt and the restored report checked before publication unlock.
If rollback verification fails, the publication lock stays in place for recovery.
The command uses the factory Docker toolchain and retains the three established
unused symbols required by the current verified baseline. It does not commit.


### Interior BSS aliases

A `data_alias_dependency` in a single-module manifest carries new interior BSS
labels through the guarded integration transaction. The dependency names that
module's `linker_symbols.json`, pins its before and after SHA256 hashes, and lists
the added alias names. A missing original policy uses a null `before_sha256`.
Every existing policy entry remains unchanged. Existing compiler profiles that
reference the selected policy through `absolute_linker_symbols` retain all their
fields except `policy_sha256`: the transaction derives that pin's replacement
from the authenticated before hash and the append-only policy's after hash.
Mismatched existing pins are rejected. Worker compiler-profile edits are not
imported, and the original profile bytes are recorded and restored on rejection.
Each added entry uses the normal
`base`, `offset`, `object` and `section` linker-alias fields; the section is `.bss`.

The base is a selected source-owned BSS row with a frozen source hash and an exact
positive extent. Its original module symbol address is preserved. Every original
interior BSS label within that extent is declared, and its offset resolves to the
same original address. An alias adds no storage and receives no independent data
or function credit. `symbol_size_dependency` records an exact base-size refinement
when the original symbol map divides one established object at interior labels.

The compiler object reserves the complete typed base object in `SHT_NOBITS`.
`compile_verify_batch.py` checks the original and candidate BSS section and base
object layouts and rejects extra allocated sections or storage. Only original-only
interior labels authenticated by the dependency are deferred from object symbol
comparison. Receipts list `linker_aliases_deferred` and set
`linked_alias_audit_required`; this is not a claim that C defines those labels.
Neither original comparison targets nor candidate ELF metadata is rewritten.

The linker defines the aliases as base-plus-offset expressions.
`audit_bss_layout.py` checks every alias's linked address, module section, global
binding, zero size and `NOTYPE` classification, together with the base reservation,
alignment, original BSS bounds and unchanged initialized module bytes. Acceptance
requires the complete linked alias audit, the normal module/symbol/ROM SHA1 gates
and unchanged coverage denominators. Integration receipts separate BSS bytes from
initialized data and C/C++ code.

The transaction records the policy preimage and restores it on a rejected batch
before rebuilding and checking the prior state. Automated `--restore-interrupted`
excludes data manifests. An interrupted data transaction retains its publication
marker until authenticated manual restoration and all normal validation gates
succeed; the recorded `data-alias-preimage.json` preserves the policy's prior bytes
or its original absence.
