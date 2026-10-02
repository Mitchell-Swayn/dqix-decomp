# ov016 worker batch: decoder arena cache

Batch `fleet_ov016_20261002t1547`, based on
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No earlier ov016 source units,
attempt ledger entries, or local worker notes were present. Work stayed in this
worktree; no shared headers, queue changes, other modules, or shared tooling edits.

## Accepted source and accounting

- `DecoderTableCache.cpp`: eight functions in `[0x0218fc78,0x0218fea0)`.
  552 text bytes comprise 504 ARM instruction bytes and 48 literal-pool bytes.
  Includes the two arena-size queries, two arena assignments, and four lazy
  copy/fallback accessors, reconstructed together rather than synthetic wrappers.
- Cache BSS: `[0x0219d1c0,0x0219d1e4)`, 36 bytes. Pointer/remaining-size fields
  are established by all observed module accesses. Offset `0x1c` remains unknown.
  The final 28 bytes through `0x0219d200` remain anonymous original fallback;
  they are not claimed as source-owned BSS or folded into the struct.
- `DecoderClampTables.cpp`: `[0x0219ca60,0x0219cee0)`, 1,152 initialized
  read-only bytes, as complete unsigned-byte arrays of sizes `0x180` and `0x300`.
  Their observed values implement saturating identity and divide-by-eight maps
  with lower/upper tails. Their precise roles inside the decoder remain inferred.
- Report delta: +8 matched functions, +552 matched code bytes, +1,188 matched
  data bytes (1,152 rodata + 36 BSS). Instruction/literal/data/BSS accounting above
  separates the report's combined counters. No initialized `.data` or assembly
  source gain. ARM9 totals remain 14,790 functions / 2,959,478 code bytes /
  1,602,476 data bytes; ARM7 unchanged.

## Evidence and dependencies

Original disassembly was generated with `dsd dis` into ignored
`build/factory/ov016_original/`. Callers `0218c04c` and `0218d2f4` obtain arena
3/4 bounds and clamp capacities to `0x659c`/`0x2580` before assigning the caches.
`0218e800` checks MODSN2/MODSN3 file magic, retrieves the four cached resources,
and saves them in its decoder state. `0218f16c` retrieves the clamping table again.
The main-module dependency `func_020ca4b4` is an observed aligned word-copy
routine taking source, destination, and byte count; it remains external source
work and was not modified.

The executable decoder image `[0x02195f78,0x0219c514)` (26,012 bytes) and table
`[0x02193e78,0x02195f78)` (8,448 bytes) remain explicitly sized original fallback
dependencies. The image visibly contains ARM instructions, branches and data;
it is not reconstructed by declaring a byte array, and receives no new source
credit. Additional decoder code at `func_ov016_0219c514_unk`, currently mapped
inside `.rodata`, needs a future instruction/literal/data inventory. Existing
coverage denominators were preserved, not presented as a complete native-code
inventory. ov016 and the decoder are not complete.

## Variants and verification

- Cache v1: 9/9 symbols exact on first compiled comparison.
- Cache v2: const interfaces for reconstructed clamp tables and size assertion;
  9/9 symbols exact. Two variants per function, zero nonmatching compiled variants.
- Tables v1: 2/2 symbols exact on first compiled comparison.
- One preflight attempt could not compare because delink rejected an inferred
  64-byte BSS symbol overlapping the 36-byte source range. Explicit cache size
  fixed this. An initially added padding label then failed full symbol checking;
  removing that unnecessary label preserves the original anonymous trailing BSS.
  Neither issue is counted as a compiler variant or a matching success.
- `tools/match_unit.py --worker fleet_ov016 --hypothesis ...` archived candidates
  and comparisons under `build/matching/`; three successful comparisons total.
  `factory_diff.py` final diagnosis has no mismatches. `factory_evidence.py`
  accepted cache/table packages are under `build/factory/ov016_*_evidence_accepted.json`.
- `ninja -j2 rom check report sha1` passed after the map correction. Log:
  `build/factory/ov016_acceptance_padding.log`. All ARM9 modules and symbols,
  ARM7 checks, and ROM acceptance passed. Input and generated ROM SHA-1:
  `c7c3014c237900c8281289b8bc76a781969b6278`. No gameplay tests were run.
- `git diff --check` passed. No new pipeline tests were needed for this source-only
  reconstruction. All reconfigures explicitly selected this worktree's compiler.

Elapsed wall time and verified coverage snapshots are recorded by
`tools/work_batch.py` under `build/workflow/fleet_ov016_20261002t1547/`.
Token usage was not measured. Continue with decoder image inventory or table
consumers; no ten-variant cap was reached or reset.

## Continuation: NitroVM-backed decoder stream

Batch `fleet_ov016_20261003t_continuation`, based on
`1df10e9585c91c988d80e8be7ae9762e11b4cb5e`. The existing worktree was clean;
the prior attempt ledger contained only the cache/table experiments above.
No queue ownership conflicted with this unowned ov016 family. No shared headers,
other modules, original comparison inputs, or shared tooling were changed.

- `DecoderFileStream.cpp`: seven functions in `[0x0218f508,0x0218f6b8)`;
  432 ARM instruction bytes, no literals or alignment credit. The functions
  attach an already-open file, seek, read synchronously, issue sector-aligned
  asynchronous reads, await completion, dispatch completion virtually, and
  implement the observed empty virtual destructor.
- Complete method table `[0x0219d0a0,0x0219d0c0)`: 32 initialized `.data`
  bytes (seven function pointers and the final zero word). No rodata/BSS gain.
  The actual 0x14-byte stream object is represented by a typed method pointer,
  length, logical position, `NitroVM*`, and a byte pending-read flag. Existing
  `Filesystem/FileAccessor.h` supplies the shared NitroVM layout and APIs.
- Report delta: +7 functions, +432 code bytes, +32 data bytes. ARM9 denominators
  remain 14,790 functions / 2,959,478 code bytes / 1,602,476 data bytes; ARM7
  coverage is unchanged. No necessary assembly was added.

Original evidence is in `build/factory/ov016_original/ov016_4.s`. The factory
constructs a 0x14-byte object at `0218e558` and attaches a NitroVM through
`0218f508`; the method table identifies all slots. Decoder initialization at
`0218e800` invokes synchronous read and seek through those slots. The stream's
length/position derive from NitroVM offsets 0x24/0x28/0x2c, matching the existing
shared type. An asynchronous read starts at the preceding 512-byte boundary,
rounds the requested span up to full sectors, returns the leading-byte count,
and advances the logical position by the requested count. A subsequent sync read
awaits completion and restores that logical position before reading. The byte
flag is tested for equality with 1, preserving the original control flow.

Four compiled variants were archived with `match_unit.py --worker fleet_ov016`:

1. Direct CBool early return: six functions and the table exact; sync read 75%.
2. Native bool return for sync read: same 75% result.
3. Single-error switch: sync read 89.66%, with an extra branch.
4. Original direct early return plus local `optimize_for_size off`: all seven
   functions and the table exact. Other methods keep the default optimization.

The sole failing function `0218f58c` used three unproductive variants; the other
six functions/table matched all four. No ten-variant cap was reached or reset.
A final comparison after layout assertions and the `complete` annotation also
matched 8/8 symbols; it is verification of v4, not a fifth compiler hypothesis.
The size pragma is necessary to preserve the conditional early epilogue instead
of predicating the whole cursor update; it introduces no volatile field or
behavioral change. Final `factory_diff.py` diagnosis reports zero mismatches.

`factory_evidence.py` packages and candidate/difference logs remain under ignored
`build/factory/ov016_stream_*` and `build/matching/`. Full
`ninja -j2 rom check report sha1` passed (exit 0), including all ARM9 modules,
symbols, ARM7 preservation and target ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The independent original input's
SHA-1 was also rechecked. Acceptance log:
`build/factory/ov016_stream_acceptance.log`. `git diff --check` passed.
No gameplay tests were run, and no pipeline change required additional tests.

Elapsed time and post-commit coverage snapshots are recorded by `work_batch.py`
under `build/workflow/fleet_ov016_20261003t_continuation/`. Tokens are unmeasured.
The existing deleting destructor `0218e62c`, allocation/free callbacks,
factory/base table, decoder consumers and executable-image/table dependencies
remain original fallback. The table's final zero word is preserved without a
claim about its semantic role. Earlier deferred decoder inventory remains
required; this batch does not claim ov016 completion or integration.
