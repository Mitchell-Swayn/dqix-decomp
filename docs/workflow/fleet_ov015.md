# ov015 worker evidence

Batch: `fleet_ov015_20261003_01`. Baseline revision:
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`.

## Scope and layouts

Reconstructed the script-populated registry's ownership and indexed access
family. Source ranges (exclusive ends):

- `0x0218b810–0x0218ba44`: reset, cleanup, allocate records, allocate groups,
  append record, append group (six functions, 564 text bytes).
- `0x0218bae8–0x0218bb3c`: record/group bounds-checked lookup (two functions,
  84 text bytes).

The registry is a real 16-byte subobject at offset `0x3c` in the larger overlay
state, not a flattened word buffer. Its arrays contain 12-byte records and
8-byte groups. Groups own chains of 12-byte nodes, with the next pointer at
offset 8. Each record owns two strings; each group and node owns one string.
The node's byte at offset 7 is compiler padding, not a fabricated field.

Evidence comes from original `dsd dis` output, symbol/delink/relocation maps,
script producers `0218b5c8` and `0218b6e4`, the loader `0218ba44`, setup
`021934f8`, and consumers `02193160`, `02191c70`, and `02192700`.
The byte at record offset 10 is compared by `02193160`. String and selector
names remain provisional. Cleanup reloads array pointers after allocator calls,
preserving the original alias-sensitive behaviour.

Main helpers `02012d88` and `02012da4` respectively round allocation size to four
bytes and call `AllocatorUnion::Allocate`, and forward to `AllocatorUnion::Free`.
The existing shared `Memory/AllocatorUnion.h` is used without modifying it.
The allocator instance `data_02114e20` remains an external main-module dependency.
No registry-owned initialized data or BSS was reconstructed in this batch.

## Variants and object evidence

Five object comparisons: three registry variants and two lookup variants.

1. Typed arrays and ownership cleanup: five of six registry functions exact;
   record assignment emitted an extra out-of-line assignment helper (append
   match 5.56%). Lookup candidates matched 81.82% / 80.00%, with reversed
   compare operands and branch direction.
2. Explicit copies of all five record fields: six of six exact, no helper.
   Count-first bounds comparisons: two of two exact.
3. Replace provisional opaque allocator with established `AllocatorUnion`:
   six of six remain exact.

Per-function candidate counts: three for the first six functions, two for each
lookup. Only append and the two lookups had an unsuccessful variant; none
reached the ten-unproductive-variant cap. All candidate snapshots, object hashes,
diffs, and conservative mismatch diagnoses are in `build/matching/`.
Final factory evidence: `build/factory/ov015_registry_final_evidence.json` and
`build/factory/ov015_lookup_evidence.json`; original disassembly is under
`build/factory/ov015_dis/`. Detailed first-variant diagnosis:
`build/factory/ov015_variant1_diagnosis.json`.

## Coverage and remaining work

Measured report text delta: +648 bytes and +8 functions. Separately, this is
636 ARM instruction bytes plus 12 literal-pool bytes; initialized data, BSS,
alignment and assembly deltas are all zero. No denominator changes.

`tools/work_batch.py` start/finish recorded 445.751471 seconds (7m 25.75s),
five comparisons, +648 matched ARM9 code bytes, +8 matched functions, zero
matched-data delta, and zero ARM7 deltas. Snapshots are under
`build/workflow/fleet_ov015_20261003_01/`. Token usage was not measured.

Final validation: `ninja -j2 rom check report sha1` passed after the shared
allocator type correction; all ARM9 modules and symbols passed, and the ARM7
baseline check passed. Final ROM SHA-1:
`c7c3014c237900c8281289b8bc76a781969b6278`. The original input separately
has this verified hash; original input and generated output each have one link.
Detailed logs: `build/factory/ov015_final_acceptance.log` (final run) and
`build/factory/ov015_acceptance.log` (initial run). Existing ARM7 compiler warnings
are outside this batch and were not modified.

Script producers, script loader, script opcode table, registry global pointer,
the containing overlay state, and the consumers remain original fallback.
Record string meanings and selector semantics need further caller analysis.
No gameplay test was performed and ov015 is not complete. The integrator owns
queue updates and main integration; neither was changed here.

## Continuation: script population and loading

Batch `fleet_ov015_20261003_02`, baseline
`12a4b7067fc0f2b1d737d025ea15f97cd2cac44f`. Existing source, attempt ledger,
and previous evidence were inspected before selecting untouched producers.

New source ranges, with exclusive ends:

- `0x0218b5a0..0x0218b810`: four Script opcode callbacks allocating record/group
  arrays, copying record strings, and appending ordered linked group entries.
- `0x0218ba44..0x0218bae8`: registry cleanup and synchronous script loading,
  initialization, opcode setup, and execution while holding the background
  loader's global lock.
- `.data 0x02193fa0..0x02193fc8`: full five-entry opcode array (100--103 plus
  zero terminator), using the existing `Script::OpcodeLookupEntry` type.
- `.data 0x02193fc8..0x02193fe0`: default `data/bin/charaview4.bin` path.
- `.bss 0x02194560..0x02194564`: callback registry context pointer.

Original disassembly and relocation maps establish the callback signatures and
parameter strides. The loader uses the existing 0x430-byte `Script` object,
not an opaque stack buffer. Its setup caller `021934f8` supplies the registry
subobject at offset 0x3c and a null filename, selecting the default path.
Existing `Script::SetOpcodeLookup` counts entries until opcode zero and sorts
the table. Group nodes contain the same real fields and padding established in
the first batch; no shared headers or unrelated modules changed.

Four object comparisons: three command-unit comparisons and one loader-unit
comparison. First command candidate matched three callbacks; `0218b6e4`
matched 72%, with parameter-pointer and register scheduling differences.
Using postincrement on the original parameter pointer for each conversion
matched all four callbacks in variant two. Variant three added the complete
opcode array and BSS pointer, retaining exact code and matching both objects.
The loader and its path matched on their first comparison. Per-callback counts
are three comparisons, with one unsuccessful variant only for `0218b6e4`;
loader count is one. Prior registry/lookup counts remain three/two respectively.
No function reached its ten-unproductive-variant cap.

Measured delta: +5 functions, +788 text bytes (748 ARM instruction bytes,
40 literals), and +68 report data bytes. Separately, initialized storage is
63 bytes (40 opcode bytes and 23 path bytes), with one trailing alignment byte
and 4 BSS bytes. No assembly or ARM7 gains, and no denominator changes.
`work_batch.py` recorded 271.232534 seconds (4m 31.23s), including full
acceptance; snapshots are under `build/workflow/fleet_ov015_20261003_02/`.
Token usage was not measured.

Validation: exact candidate comparisons and `ninja -j2 rom check report sha1`
passed, including module/symbol checks and ARM7 baseline validation. ROM SHA-1
is `c7c3014c237900c8281289b8bc76a781969b6278`. Original and generated ROMs each
have one independent link. Logs: `build/factory/ov015_02_acceptance.log`.
Final read-only evidence: `build/factory/ov015_commands_final_evidence.json`
and `build/factory/ov015_loader_final_evidence.json`. Failed candidate source,
diff and object hashes remain in `build/matching/20261002T155314-497f56b1c4524000b2823cbfeab0b22d/`;
diagnosis is `build/factory/ov015_commands_v1_diagnosis.json`.

The script asset remains extracted content. Main allocator and file scratch
storage are external dependencies; the containing overlay state, registry
consumers, record string meanings, and selector semantics still require work.
Remaining ov015 functions retain original fallback. Gameplay was not tested;
ov015 is incomplete. No main integration or queue edits were performed.
