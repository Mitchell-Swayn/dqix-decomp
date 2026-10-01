# Goal: 100% decompiled Dragon Quest IX USA

## Deliverable

Produce a maintainable, reproducible source reconstruction of the USA release of
**Dragon Quest IX: Sentinels of the Starry Skies** that rebuilds the original game
byte-for-byte. This is a reconstruction of equivalent source, not a claim to have
recovered the developers' original source text or names.

The target ROM SHA-1 is:

`c7c3014c237900c8281289b8bc76a781969b6278`

The deliverable includes all game executable components on the cartridge: ARM9,
its overlays and autoload sections, and the cartridge's ARM7 program and any
additional executable modules identified by an inventory. SDK, runtime, and
middleware code within those components must also be accounted for. The console's
ARM7 BIOS is an external build input, not code this project must decompile.

USA is the acceptance target. Japanese compatibility is useful upstream work but
is not a prerequisite for completing this deliverable. A native PC/ARM port,
remaster, new content, or online-service replacement is outside this goal.

## What counts as complete

- [ ] Every executable module and code range is inventoried, including code
  outside the current ARM9 progress report. No executable ranges are silently
  excluded from the denominator.
- [ ] All originally compiler-generated code is reconstructed as understandable
  C/C++ with appropriate types and interfaces. Every function matches its original
  instructions and its module matches the original bytes.
- [ ] There are no undecompiled binary code slices, generated disassembly
  fallbacks, placeholder functions, or assembly wrappers used to inflate source
  completion. Ghidra pseudocode alone does not count.
- [ ] Necessary assembly is limited to documented, reviewed low-level routines
  that require assembly or are established to have been assembly originally.
  Each exception has its range, reason, source, and verification recorded. Report
  this coverage separately; do not present it as C/C++ decompilation.
- [ ] Program-owned data has source definitions: globals, constants, strings,
  tables, initializers, and relevant layout/alignment. External declarations are
  acceptable between source files; they must not conceal unresolved dependencies
  on original program-binary fragments.
- [ ] Types, class relationships, calling conventions, and module boundaries are
  sufficiently understood and documented for maintenance. Remaining uncertainty
  in names or intent is recorded rather than represented as established fact.
- [ ] Every module, symbol check, and final USA ROM SHA-1 check passes from a clean
  build using the documented inputs and pinned toolchain.
- [ ] Representative gameplay smoke tests pass, and the verification record
  clearly separates build matching from runtime testing.
- [ ] Build instructions, input hashes, tool versions, coverage reports, assembly
  exceptions, and test evidence accompany a fixed final source revision.

A successful ROM rebuild alone is not completion: the existing build already
combines source with original code. Likewise, 100% of the current ARM9 report alone
is insufficient if ARM7 or other executable ranges remain outside that report.
Matching percentages measure binary coverage, not percentage of effort completed.

## Assets and scripts

Graphics, audio, maps, dialogue, and other content may remain extracted assets
from the user's target ROM. They do not need to be rewritten as C/C++. Document
how the build extracts and preserves them and distinguish these assets from
program-owned data and executable code.

Inventory script/bytecode formats and their interpreters. Interpreters are native
code and must be decompiled. Preserve and reproducibly package script payloads;
record their coverage separately from native code. Editable script tooling is
useful, but recovering the original script-authoring language is not required for
this native-code deliverable. Investigate any asset-like file that actually
contains native executable code before classifying it as an asset.

## Verified starting point

Workspace: `C:\Users\swayn\Projects\DQIX-Decomp`

- Upstream: <https://github.com/DQIX/dqix-decomp>
- Starting revision: `94cc9c872266f0a6d15d3fb037fba24b8d3696d6`
- Working branch created during setup: `work/full-decomp`
- Setup verified on 2026-10-02: supplied USA ROM hash, ROM build, ARM9 main,
  ITCM, DTCM, all 35 configured ARM9 overlays, and symbol checks.
- Baseline report: 1,072 / 14,790 matched functions (7.248141%);
  142,700 / 2,959,478 matched code bytes (4.8217964%);
  25,908 / 1,602,476 matched data bytes (1.6167481%).
- These numbers describe the existing report, not verified whole-cartridge
  coverage. Audit its scope before defining final totals.
- Whole-ROM SHA-1 acceptance has not been verified: the ARM7 BIOS was not supplied.

## Milestones

### 1. Establish the full inventory and reproducible baseline

- [ ] Enumerate ARM9, overlays, autoloads, ARM7, and any other executable payloads.
- [ ] Record code/data ranges, processor, module size, source coverage, binary
  fallbacks, and build/verification method for each module.
- [x] Archive the baseline report and record the exact source and tool versions.
- [x] Add ARM7 build, symbol, and coverage tracking where absent; first establish
  a matching baseline, then replace its original code progressively with source.
- [x] Establish final-ROM hash verification. The USA path now preserves verified
  secure-area checksum metadata instead of requiring the missing ARM7 BIOS;
  see the execution record and `docs/REPRODUCIBILITY.md` for the strict guards.
- [x] Confirm a clean build works without stale objects or generated outputs.

### 2. Recover shared interfaces and engine foundations

- [ ] Map core object types, inheritance, globals, flags, and calling conventions.
- [ ] Extend partial filesystem, resource, memory, graphics, and scripting work.
- [ ] Recover interfaces needed by gameplay: input, text/UI, sound, save data,
  timing, and communication. Treat these as inventory categories, not claims
  that each subsystem is completely untouched.
- [ ] Replace unknown dependencies with matched source in coherent increments.

### 3. Complete gameplay and overlays

- [ ] Finish combat, field/world behaviour, grotto generation, menus, inventory,
  progression, quests, and other systems identified by the inventory.
- [ ] Track every overlay individually; mark one complete only after all its
  code and program-owned data are reconstructed and verified.
- [ ] Use focused systems such as alchemy, battle records, or the bestiary as
  manageable entry points when their dependencies are understood.
- [ ] Finish ARM7 and embedded library/runtime coverage alongside ARM9 work.

### 4. Close coverage and source-quality gaps

- [ ] Audit every remaining unmatched range and every source-external dependency.
- [ ] Resolve program data, strings, initializers, padding, and layout issues.
- [ ] Review all assembly exceptions and validate the final coverage denominator.
- [ ] Remove temporary stubs and unexplained binary fallbacks; document unresolved
  semantic naming questions without overstating understanding.

### 5. Validate and deliver

- [ ] Build from a fresh checkout using only the documented external inputs.
- [ ] Verify all modules and symbols, then compare the final ROM SHA-1 to target.
- [ ] Publish separate code, function, data, assembly, and asset/script coverage
  records, with explicit ARM9 and ARM7 breakdowns.
- [ ] Smoke-test boot, new game, field navigation, battles, menus, save/load,
  grotto generation, and representative scripted events.
- [ ] Check multiplayer/communication and late-game paths where practical;
  record the environment and anything not exercised. Do not infer these tests
  passed merely from booting the ROM.
- [ ] Record a final source revision and complete the acceptance checklist above.

## Working method

1. Read `CONTRIBUTING.md` and `Decompiling.md`. Investigate upstream branches and
   open work before duplicating an existing effort.
2. Select a bounded, coherent function group or class. Record its module,
   addresses, dependencies, and expected source/data ownership.
3. Use disassembly, decompiler output, call sites, and runtime observations to
   infer behaviour and types. Treat generated pseudocode as a starting hypothesis.
4. Write readable source and iterate against the original assembly with the
   matching compiler. Preserve behaviour and layout rather than refactoring while
   matching. Document any compiler quirks required for an exact match.
5. Update headers, symbols, and delink ranges. Mark a range `complete` only when
   every function in that range matches; this does not imply its subsystem is done.
6. Run `build-usa.cmd`. Review module/symbol results and the progress delta; ensure
   gains reflect new reconstructed coverage rather than a reduced denominator.
7. Keep changes focused and commit verified milestones. Record remaining unknowns
   and useful reverse-engineering observations with the affected subsystem.

## Build and tool guidance

Run from the workspace in Command Prompt:

```bat
build-usa.cmd
```

The helper activates `.venv`, configures USA, and runs `ninja rom check report`.
The checked-out revision has no `min` target despite the upstream README referring
to one. Use the helper or those explicit targets for the tested workflow.

Progress is in `build\usa\report.json`; object comparison configuration is in
`objdiff.json`. Reconfigure when adding/removing source files or changing maps.

For final whole-ROM verification, run `ninja rom check report sha1`. The current
USA build verifies unchanged secure-area bytes, preserves the supplied original
ROM's secure-area checksum metadata, recomputes its header checksum, and requires
the exact target SHA-1. This removes the USA BIOS blocker without copying code or
weakening the hash requirement. A BIOS can still be supplied; the encrypted-domain
checksum is otherwise preserved, not independently recomputed. Use
`tools/verify_clean_build.py --revision HEAD --require-sha1` for fresh extraction,
fresh objects and archived evidence. See `docs/REPRODUCIBILITY.md`.

GCC 9+ is needed for decomp.me context generation in the default build workflow.
It is not the matching game compiler. Ghidra 11.2.1 with dsd-ghidra 0.5.0 is the
upstream-documented interactive analysis combination. See `START-HERE.txt` and the
upstream README for setup references. A Japanese ROM is optional for this USA goal.

## Final handoff contents

- Source, headers, build scripts, and complete module/symbol/address maps.
- Reproducible input extraction and asset packaging instructions.
- Toolchain versions and external-input checksums.
- Coverage inventory, progress reports, and documented assembly exceptions.
- Clean-build logs, module/symbol results, and final ROM SHA-1 verification.
- Runtime test record and a list of any untested scenarios or semantic unknowns.

Keep ROMs, BIOS dumps, and generated proprietary assets out of source commits.
The source deliverable must clearly state which user-supplied files are needed to
reproduce the final ROM.

## Execution record: 2026-10-02

Work remains in progress. None of the overall completion criteria above has been
waived, and a byte-identical ROM does not imply that its code is fully reconstructed.

- Archived original ARM9 report and 39 known cartridge/module records; per-module
  counts reconcile with the ARM9 total. ARM7 startup, both autoload copies and
  their BSS are now mapped separately without double-counting the parent payload.
- Built the original revision from a clean Git source archive and fresh inputs;
  recorded compiler/tool hashes and complete log in `docs/verification/`.
- Added independent ARM7 C compilation, linking at actual runtime addresses,
  symbol/byte checks and packaging. Source units are explicit; all other bytes
  remain binary fallback. The full ARM7 code/function denominator remains unknown.
- Added an assembly audit distinguishing assembly-affected source units from
  other source and original binary units. Existing matching hacks are unapproved
  exceptions pending individual review; they are not silently credited as C++.
- Verified all 7,481 NitroFS files (253,967,681 bytes) preserved exactly; inventoried
  4,181 NARC containers. Known Script layouts/users are documented in `docs/ASSETS.md`.
  Opaque/compressed content still needs analysis before an exhaustive native-code
  inventory can be claimed.
- Fixed the Ninja dependency race between objdiff and original-object generation.
- Resolved final USA SHA-1 verification through guarded header metadata preservation.
  No BIOS was obtained, and no program bytes are supplied by this finalization step.
- Reconstructed additional ARM9 allocator/arena functions and ARM7 helpers in
  verified commits. Current counters belong in generated reports, not this static
  baseline. Keep denominator changes visible and compare against archived evidence.
- Emulator title menu, character creation, the opening battle/scripted events,
  Observatory movement/menus, and Quick Save followed by a fresh cartridge reload
  were visually observed. Ordinary church saves, grotto generation, multiplayer
  and later gameplay remain untested. See `docs/RUNTIME_TESTS.md`; screenshots
  and generated saves are local evidence under `build/runtime/`.

Remaining work includes most original compiler-generated code, program-owned data,
unresolved interfaces and symbols, exact assembly exceptions, opaque asset audit,
complete ARM7 analysis and representative gameplay tests. Continue coherent source
reconstruction and preserve the explicit fallback counts throughout.
