# Reviewed source contracts

The existing integration wrapper accepts reviewed corrections to C interfaces
through `--source-contract-only --contract-review /absolute/review.json`. This
mode uses the mixed transaction's project-wide guard, preimage journal, full
validation, recovery, bookkeeping and publication. It earns zero reconstructed
functions, code bytes and data bytes. The scalar caller-return
`source_refinements` mode keeps its existing schema and restrictions.

## Scope

A contract package corrects parameters, return types, declarations, shared types
or explicit caller dataflow across existing complete, exact, code-only ARM9
source units. Changed files are existing ordinary `.c`/`.cpp` sources and
`.h`/`.hpp` headers under `src/` or `include/`. All ordinary source references
must be compared, including unchanged conforming callers. Each compared unit
lists every original function with its module, name, address and size. Aliases,
overloads, new source files, new functions, program-data ownership and assembly
or runtime support edits are outside this mode. Canonical owners have one
explicit `extern "C"` definition for the selected symbol.

By default the package cannot change preprocessor directives or original identity
comments. The explicit existing-header insertion protocol below permits only
its declared include lines. Delink ranges, symbol maps, compiler profiles,
retention and relocation policy retain their existing restrictions.
All configuration files, `objdiff.json` and Python tools are hash-pinned with
exact file membership. Unknown manifest keys are refused even when empty.

The reference census scans every nonbinary file under `src/`, `include/` and
`libs/`, including comments, member/namespace references and assembly fallback.
Every reference file needs before/after hashes and a reviewed conformance row.
Fallback references remain original assembly; their records explain the original
module-qualified caller dataflow and earn no source credit. Unsupported source
extensions are refused when they reference a selected symbol.

Changed headers and symbol-bearing reference headers require current compiler
`.d` files for every configured source unit. The gate combines those dependencies with conservative transitive literal
include discovery. Missing or stale dependency files, an omitted dependent unit,
or a dependent unit outside the supported scope refuse the package. Include
and preprocessor changes are outside this mode. The dependency census does not
replace independent review of macros, aliases or C/C++ type semantics.

## Manifest and review

The top-level schema is exactly:

```json
{
  "schema": "arm9-source-contract-v1",
  "preparer": "migration-worker",
  "functions": [
    {"module": "ov023", "source": "src/Menu/Example.cpp",
     "name": "Example", "address": "0x02100000", "size": 4}
  ],
  "units": ["src/Menu/Example"],
  "source_hashes": {"src/Menu/Example.cpp": "AFTER_SHA256"},
  "source_contracts": {
    "files": [],
    "symbols": [],
    "evidence": [],
    "context_sha256": {}
  }
}
```

`files` contains each changed file once with `path`, `before_sha256`,
`after_sha256` and `edits`. Each edit has `kind` (`declaration`, `definition`,
`dataflow` or `type`), a selected `symbol`, and exact `before`/`after` text.
Every preimage text occurs exactly once; sequential replacements must produce
the entire declared afterimage. The gate transfers those frozen bytes only.

`symbols` contains `name`, canonical `owner` source and `references`. Each
reference has `path`, `before_sha256`, `after_sha256`, `conformance` and `evidence`
paths. Conformance is `owner` for the owner, `repaired` for another changed file,
or `unchanged`. `evidence` at the contract level contains `path`/`sha256` rows
for worker-local original instruction, declaration, object and semantic evidence.
Every conformance row names at least one of those records.

Generate `context_sha256` using `integration_source_contracts.context_hashes`
from the accepted project while holding `integration_guard`. The
`proposal_sha256` helper hashes canonical JSON with sorted keys, compact
separators and ASCII escapes. Source and evidence hashes use SHA-256 of exact
file bytes. Freeze the package after the current integration tools are installed.
Any context, proposal or evidence change requires another matching review.

The integrator supplies a separate canonical, nonsymlink review path outside
the worker. Its exact schema is:

```json
{
  "schema": "arm9-source-contract-review-v1",
  "decision": "approve",
  "reviewer": "independent-reviewer",
  "proposal_sha256": "CANONICAL_MANIFEST_SHA256",
  "evidence_sha256": {"evidence/contracts.md": "EVIDENCE_SHA256"}
}
```

The reviewer differs from the preparer and independently inspects the source
contracts, all declarations/callers and original module-qualified dataflow.
The integrator obtains the review from that reviewer. JSON identity fields are
process evidence, not cryptographic authentication or a C++ type checker.
Exact object or ROM matching alone does not establish source semantics.

## Validation and recovery

The shared runner compares every selected object against unchanged original
targets, audits every selected function's linked address and extent, and runs
`ninja rom check report sha1`. It requires unchanged global and per-module
coverage counters and denominators, identical selected report-unit function,
section and metadata inventories, and byte-identical ARM7 reports. Frozen
configuration, tools, reference census, file modes and original target hashes
are checked before publication. Receipts record zero instruction credit,
refined-function counts, proposal/review hashes and original target hashes.

The journal binds exact source/header preimages and modes, evidence, review,
frozen context and publication outputs. Unchanged inputs and original targets
are immutable entries: rollback authenticates them and never rewrites them.
Changed source/header restoration uses fresh timestamps to rebuild dependents.
Rollback runs the complete ROM gate and checks restored content, modes, reference
census and baseline reports before releasing publication ownership. Unexpected
edits or failed restoration/build verification retain the publication lock.

Interrupted restoration uses the same wrapper flags plus `--restore-interrupted`
(or `--recover-failed`) and `--preimage-tree` pointing to independent retained
preimages. Keep the identical manifest, worker afterimages, evidence and external
review available. Recovery re-derives the complete proposal and immutable path
classes against those preimages, authenticates saved journal/review/evidence,
then restores and verifies the accepted baseline. It never accepts an interrupted
candidate or earns coverage.

## New owners with existing caller repairs

`--source-contract-additions --contract-review /absolute/review.json` installs
new source owners and their necessary existing caller corrections atomically.
It uses the same transaction and independent review. The zero-credit mode above
retains its original schema and scope.

The additions schema is `arm9-source-contract-add-v1`. It has the same top-level
fields plus `new_sources`, a list of one to eight new owner source paths. The
`functions`, `units` and `source_hashes` fields cover the complete union of new
owners and existing caller TUs. Each new-source function row additionally has
`mode` (`arm` or `thumb`). Existing function rows keep their previous schema.

Each new source owns exactly one complete `.text` or `.init` extent, selects an
unmatched original fallback function, and preserves its current symbol name,
mode, size and address. New names, naming dependencies, compiler profiles and
other policy changes are outside this mode. Every new source is a canonical
owner in `source_contracts.symbols`; unrelated new functions are refused.
`source_contracts.files` lists only existing source/header corrections, using
the same explicit edits and preimage checks. New owner bytes are pinned by the
union `source_hashes` map.

The reference census includes new source files. A new owner's own reference row
has `before_sha256: null` and conformance `owner`; a reference from another new
source uses `introduced`. Existing references retain `repaired` or `unchanged`.
All ordinary callers, including already conforming callers, are compared. Only
the new owner rows earn function/code coverage; every existing report unit stays
identical and existing caller corrections earn no additional coverage.

`source_contracts` additionally requires `dsd_sha256` and
`original_inputs_sha256`. The former pins the existing input executable at
`integration_source_additions.DSD`. Generate the latter with
`integration_source_additions.original_input_hashes`: it covers the complete
original module YAML/binary inventory used by independent derivation. Capture
those pins with the current context under `integration_guard`. The independent
review approves the entire additions manifest and its evidence.

Before installation, the gate copies verified configuration and original module
inputs into independent temporary files. The pinned DSD invocation must first
reproduce the accepted `objdiff.json` bytes exactly. Applying only the derived
new delink blocks then produces the exact expected configuration, including
fallback unit splits/labels, and the expected original objects for the new
owners. Existing source comparison units and global comparison options stay
identical. The real configure/delink output must match these independently
derived bytes and target hashes. No preflight object is installed into the
project or used as a candidate implementation.

The journal records `objdiff.json` and newly minted original targets as ordinary
known-before/known-after entries. Unexpected contents fail restoration and keep
the publication gate; they are not accepted as arbitrary generated files.
Existing comparison targets and original module inputs remain immutable.
Recovery repeats independent derivation against retained preimages and verifies
all postimages before restoration. The full gate requires the exact global and
per-module function/code gain from new owners only, unchanged denominators,
unchanged data coverage and ARM7, exact whole-object and linked-layout checks,
and the target ROM SHA-1 before publication.


## Inserting an existing canonical header

An existing `.c`/`.cpp` file row can opt into `include_additions` to use an
existing unchanged canonical header. Rows without that field retain the original
directive-preservation rule. No new header, header edit or data ownership is
introduced by this protocol. The opt-in has exactly these fields:

```json
"include_additions": {
  "directives": [
    {"after": "#include <globaldefs.h>",
     "directive": "#include <System/Matrix.h>",
     "header": "include/System/Matrix.h"}
  ],
  "headers_sha256": {
    "include/globaldefs.h": "BASELINE_HEADER_SHA256",
    "include/System/Matrix.h": "CANONICAL_HEADER_SHA256",
    "include/std_library_functions.h": "TRANSITIVE_HEADER_SHA256"
  },
  "before_depfile_sha256": "ACCEPTED_CANONICAL_DEPFILE_SHA256",
  "after_depfile_sha256": "WORKER_CANONICAL_DEPFILE_SHA256"
}
```

The gate inserts each complete directive immediately after one unique
pre-existing literal include line. Anchors are outside conditionals and macro
continuations. Duplicate anchors, repeated or already included canonical headers,
traversal and symlinks are refused. Angle and quoted operands resolve uniquely
from the including directory, `include/` and each `libs/**/include` directory.
These roots mirror the pinned `tools/configure.py` include list and `-gccinc`
behavior; the gate does not support arbitrary compiler search roots. The
complete literal transitive graph must resolve to existing project headers;
macro includes, `include_next` and unresolved or ambiguous dependencies fail
closed. Conditional dependency over-approximations must also appear in the
actual compiler dependency file; unsupported conditional graphs are refused.

`headers_sha256` covers every existing compiler header dependency of the TU plus
the entire added header closure, with exact membership and bytes. Header modes
are captured and remain unchanged. The source `edits` field describes body/type
changes after the declared insertion; it must not repeat the include insertion
or edit preprocessor directives. Removing only the inserted lines must restore
the original complete directive sequence, including multiline macros, pragmas,
original identity comments and ARM/THUMB selectors.

Generate the block with `integration_contract_includes.metadata(root, worker,
source, directives)` while holding `integration_guard` for the accepted project.
Both the accepted and worker dependency files must be fresh and use the canonical
selected unit's `build/usa/src/... .d` path and object target. Compile the proposal
with the configured Ninja workflow and standard project mount so its dependency
paths match the acceptance build. The actual dependency set must equal baseline
dependencies plus the declared header closure, without omitted or extra files.
Existing unrelated consumers of an unchanged header do not require selection
merely because another TU adds that header. The usual function-reference and
changed-header dependency rules still apply.

The worker `.d` is expected compiler evidence and is never installed into the
project. The real build must produce its exact pinned bytes after source
installation, with fresh timestamps, correct membership, source/header hashes
and modes. The journal authenticates exact before/after `.d` bytes as ordinary
transaction entries. Rollback restores source and dependency preimages, rebuilds
the baseline and checks the exact original `.d` hash, membership, mode and
freshness before releasing publication. Keep independent original `.d` files and
the pinned worker afterimages for interrupted recovery. Unknown dependency or
header edits and failed baseline verification retain the publication lock.

Header hashes do not prove C++ interface semantics. Independent review still
checks canonical type identity, layout, by-value ABI, constructors, methods and
ODR compatibility alongside the original instructions and all callers.
