# Swarm: parallel function-level reconstruction

Swarm splits the unreconstructed ARM9 code into one task per function and gives
workers three fast, stateless tools: context, check and submit. One coordinator
integrates submissions in batches with the project's full ROM acceptance.
Worker instructions are in [WORKER.md](WORKER.md).

## Components

| File | Role |
|---|---|
| `swarm.py` | CLI: `build`, `next`, `context`, `check`, `submit`, `release`, `status`, `integrate` |
| `build.py` | Builds `build/swarm/swarm.db` from the evidence inventory and current delinks |
| `canonical.py` | Compiler-backed canonical declaration preflight and accepted-state snapshots |
| `verify.py` | Compiles one candidate on the host and proves bytes and relocations |
| `integrate.py` | Installs batches, runs configure + `ninja rom check report sha1`, bisects failures |
| `selftest.py` | Re-verifies integrated single-function units and perturbed copies |
| `config.json` | Compiler inputs, flags, profiles, module list, keep symbols, container command |

State lives in `build/swarm/swarm.db` (SQLite, WAL). Workers share it; leases are
taken with `BEGIN IMMEDIATE`, so concurrent `next` calls never hand out the same task.

## Setup and operation

```sh
python3 swarm/swarm.py build                 # about 4 s; --force rebuilds and keeps task progress
python3 swarm/selftest.py --count 500        # verifier agreement with integrated source
python3 swarm/swarm.py autosolve             # submits empty and constant-return functions
python3 swarm/swarm.py status --leases
python3 swarm/swarm.py integrate --limit 50  # coordinator only
```

`build` reads `build/evidence/functions.sqlite` (falling back to
`inventory/functions.sqlite`), every module's `symbols.txt`, `relocs.txt` and
`delinks.txt`, and the cached Ghidra pseudocode. A function is a task when no
delinks unit owns its range and it is not accepted runtime support. Each task
stores its original bytes, a Capstone listing annotated with relocation targets,
callers, callees, known declarations and hints: NitroSDK reference sources from
`config/usa/sdk_function_candidates.json`, and an assembly-likely flag (system
instructions, assembly-only SDK references, `ldm`/`stm` block-transfer leaves).
`next` serves assembly-likely tasks last.

Run `build --force` after changes made outside Swarm (manual integrations,
new evidence). `integrate` keeps the database's symbols, renames and
declarations current on its own.

## Verification by `check`

The compiler (`wibo` + MWCC from the factory inputs) runs directly on the host in
a scratch directory under `build/swarm/tmp/`; no link or container is involved.
Before object comparison, `check` compiles candidate prototypes alongside canonical
prototypes using the selected compiler profile, language and candidate include
directory. Current owning free-function definitions take precedence over the
SQLite declaration cache, including old/raw aliases of established renames.
Compiler evidence determines compatibility; source types and constants are never
rewritten. Canonical failures do not increment object-variant counts or improve
the best match score. JSON includes `canonical.status`, declaration paths,
authority, candidate declarations and compiler diagnostics; human output prints
the same evidence.

`canonical_conflict` blocks an incompatible declaration. `canonical_context_required`
blocks a check needing additional type/header context without asserting a proven
ABI disagreement. `canonical_retry` means integration is active, publication is
unfinished, or inputs changed during compilation. Retry after accepted publication.
Short nonblocking shared locks protect snapshots of source, headers, config and
DB declarations/renames; compilation runs outside the process lock. The ignored
`build/swarm/canonical-index.cache` reuses per-file content hashes and parsed
owning declarations across CLI processes. Every use scans file stat identities
(device, inode, mode, size, nanosecond mtime and ctime) and rereads the declaration
and rename tables. Uncommitted edits, same-size edits with restored mtime, atomic
replacement, additions and deletions invalidate the index; changed files alone
are rehashed/reparsed. A checksum, parser version and atomic replacement protect
the regenerable cache. Concurrent refresh returns a retry instead of waiting
under the main lock. Cold refresh scans twice to reject changes during indexing.
Submit checks
again and binds enqueue to the same snapshot under the shared lock. A rejected
submit preserves stored source, queue status and lease. The integration audit and
full ROM acceptance remain independent requirements.

When a canonical type is missing, preflight can use real headers included by the
owning source. It captures the candidate function-pointer type before those
headers are introduced at file scope, then asks the compiler to compare that
captured type with the canonical type. Later macros and overloads cannot change
the captured candidate type. JSON records `context_resolution` or
`context_attempted`, `proof`, and repair paths/headers/local type names. It never
synthesizes owner-local structs. An unresolved local type remains
`canonical_context_required`; the worker must investigate its owning source.
Even a compiler-confirmed nominal pointer-tag disagreement proves declaration
incompatibility, not necessarily a difference in the machine calling ABI.

A candidate matches when:

- the chosen function has the original size and mode, and all unrelocated bytes
  are equal (an original extent that includes alignment padding is reported as a
  boundary problem, because the build's report counts it as a mismatch);
- each candidate relocation resolves through the symbol tables to the original
  target: calls against `relocs.txt` (or the decoded original branch when
  `relocs.txt` has no entry), literal-pool addresses against the original word;
- every original relocation in the range is produced by the candidate, so constant
  addresses cannot stand in for symbol references;
- the object defines no global data and no second definition of an existing symbol
  (extra C++ destructor variants and unused inline copies are reported as warnings).

On the integrated tree, `selftest.py` agreed with the build on 4,802 of 4,804
complete single-function units (99.96%); 95% of perturbed copies were rejected,
and the accepted ones changed dead code or unused declarations. The two
disagreements are outside Swarm's scope: a unit that defines and calls a second
global function, and a unit referencing linker-defined absolute symbols
(`linker_symbols.json`), which needs the existing partial-link transform.

A single check takes 10–30 ms of compiler time and about 75 ms through the CLI;
16 concurrent workers sustain about 110 checks per second on a 20-thread host.

## Integration

`integrate` takes `build/progress/integration-process.lock` (the project-wide lock
shared with the existing gate) and, for each submitted task:

1. applies recorded renames to the source and re-runs `check`;
2. writes `src/<Subsystem>[/<module>]/<Name>.cpp`, injecting the
   `// Original: module @ address; symbol; size` comment when absent;
3. appends a `complete` `.text` block to the module's `delinks.txt`;
4. renames the symbol in `symbols.txt`, every reference in `src/` and `include/`,
   and records it in `config/usa/function_names.json`;
5. registers non-default compiler profiles in `config/usa/compiler_profiles.json`
   and new functions without an unambiguous reference in `config/usa/keep_symbols.txt`;
   `tools/generate_lcf.py` emits these as an LCF `FORCEACTIVE` block, because MWLD runs
   with `-dead` and its command-line `-force_active` list is limited to 255 characters.

One configure + `ninja rom check report sha1` runs in the `factory-dqix:0.1`
container per batch. Acceptance also requires unchanged denominators, each new
function at 100% in `report.json` and `matched_functions` rising by exactly the
batch size. A failing batch is rolled back; a baseline build first proves the
starting tree is good (otherwise nothing is rejected), then the batch is bisected.
Rejected tasks return to the open pool with the failure in their notes, and
`autosolve` does not resubmit them. An incremental integration build takes about
18 s; each rejected function costs roughly two builds per halving, so batches of
about 50 keep bisection cheap.

Functions named in build-affecting configuration keep their original symbol.
Integration does not commit; review and commit the working tree as usual.

## Limits

- ARM9 modules only; ARM7 has its own source manifest and build path.
- One function per source unit. Data definitions, string pools and multi-function
  units still need the existing tools (`prepare_candidates.py`, the integration gate).
- `check` proves bytes and relocations of the function, not program behavior or
  whole-unit layout; the integrated ROM SHA-1 remains the acceptance criterion.
- Callers/callees come from the evidence inventory snapshot; indirect calls are absent.
- Some splits pass `check` but fail the link: carving certain units out of fallback
  displaces neighbouring fallback code (seen at `arm9/ov000:02161be8` and
  `arm9/ov016:0218b5c0` and `arm9/ov004:02165df4`), which needs the reviewed `retained_fallback_code` mechanism
  in `runtime_support.json`. The pinned objdiff panics generating the report for
  `arm9/main:02000b9c`. The integrator rejects all of these with the error in the
  task notes.

## Pilot results

Codex workers (`gpt-6-luna` and `gpt-6.1-sol`, medium reasoning) took up to six tasks
each with only `WORKER.md` as instructions.

- Round 1 (6 workers, at most 96 bytes): size ordering served almost only 4-byte empty
  stubs. One worker released six, misreading `bx lr` as a shared tail. This led to
  `autosolve`, the empty-function and shared-tail guidance, and a validated `--subsystem`.
- Round 2 (6 workers, 12–160 bytes): every lease was a 12-byte function; nine
  `ldr ip`/`bx ip` tail calls were released as "veneers". The listing then decoded the
  pool word as an instruction; it now shows `.word`, and a tail-call hint names the target.
- Round 3 (20 workers, ten per model, fixed size bands per worker):

  | Band (bytes) | Luna submitted/leased | Sol submitted/leased |
  |---|---|---|
  | 12–48 | 6/6 | 6/6 |
  | 49–120 | 16/21 | 18/18 |
  | 121–300 | 9/19 | 14/18 |
  | 301–800 | 3/20 | 14/18 |

  Luna's 49–120 count includes the worker that used the wrong database. Sol named 51 of its 52 submissions descriptively and kept iterating (up to ten
  checks) before releasing; Luna released most tasks above 120 bytes after 0–2 checks
  and kept address-only names for most. One worker omitted `--project` and worked
  against another checkout's database; the default project is now the checkout that
  contains the working directory.
- Round 4 (20 workers on the main checkout; Luna on 12–120 bytes, Sol on 121–2000):

  | Band (bytes) | Model | Submitted/leased | Descriptive names |
  |---|---|---|---|
  | 12–48 | Luna | 30/34 | 1 |
  | 49–120 | Luna | 47/54 | 36 |
  | 121–300 | Sol | 17/24 | 16 |
  | 301–800 | Sol | 28/40 | 27 |
  | 801–2000 | Sol | 12/16 | 12 |

  134 submissions produced 133 functions (about 23 KB of code) with the batches running
  while workers submitted; most batches needed a single build.
- Integration: rounds 1 and 2 produced 345 of 349 and 26 of 27 functions. Round 3
  produced 82 of 85 (36 builds for the first 83, one for the remaining four): three were the known fallback and
  objdiff limits, and two failed because a source called a function renamed in the
  same batch; renames now apply between members of a batch. A recursive function that
  called itself by its address name failed the same way; a unit's own old name now
  follows the rename. Every accepted state kept the target ROM SHA-1.
