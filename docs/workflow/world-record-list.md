# World linked-record helpers

Branch `work/luna-world-placement-opcodes`, based on `1267d2c978aeb56d549684215e8b23c0df1f9925`.

Reconstructed the adjacent helpers at `0x0208e000` (36 bytes), `0x0208e024` (72 bytes), and `0x0208e06c` (60 bytes). The first copies a 12-byte linked record: signed halfword key at +0, packed selector halfword at +2, opaque word at +4, and next pointer at +8. The selector lookup compares bits 9?14 of that halfword and returns the requested matching occurrence. The key lookup rejects negative keys, then returns the first node whose signed key matches. The upper selector bit and word at +4 remain unnamed.

Caller evidence comes from `main_78.s`: `func_0208df94` allocates 12-byte records and calls `func_0208e000` to copy the observed key, selector, opaque word, and link. Overlay `ov013_3.s` calls `func_0208e024` with a record-list pointer, selector, and occurrence, and calls `func_0208e06c` with the list pointer and a signed 16-bit key. Both lookup helpers traverse the +8 next pointer. The routines remain global address-named C-linkage functions because callers use those symbols.

A follow-up uses a single `WorldScriptRecordNode` type across all three helpers. Its selector halfword is a union of the raw 16-bit value and the observed 9/6/1 bitfield view; a compile-time typedef check requires the complete node to remain 12 bytes. This preserves the raw copy and the six-bit lookup view without incompatible pointer types. The three candidate objects still match 1/1 symbols at 100%, and the full guarded acceptance suite passed again after this layout change.

All three candidate objects matched 1/1 symbols at 100%. The batch removes 168 bytes of fallback code across three functions, with no literal/data/BSS changes and no denominator change. Each function stayed under the ten-variant cap (e000: 4 candidate builds; e024: 5; e06c: 4).

`ninja rom check report sha1` passed. Module and symbol checks passed; the ARM7 baseline and guarded USA ROM checks passed. The ROM SHA-1 is `c7c3014c237900c8281289b8bc76a781969b6278`, equal to the verified worker input. The input and generated output are separate files. The batch clock began at 2026-10-02 12:21:52.118 UTC; `tools/work_batch.py` measured 243.09 seconds at the first full acceptance pass. Final verification repeated after the opaque word was changed from pointer-typed to integer-typed. Token usage was not measured. Verbose logs remain under ignored `build/workflow/world-record-list/` and `build/matching/`.
