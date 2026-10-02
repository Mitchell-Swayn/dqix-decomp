# Runtime data batch: decimal text and exception callbacks

Based on `6fb131c`. This batch types two small initialized records with direct
reference evidence:

- `data_020ef048` at `0x020ef048` is a 40-byte digit string. The literal pool
  for the existing double-to-decimal routine `func_0200a180` points to it at
  `0x0200a9bc`. The bytes contain 36 ASCII digits followed by four zeros. The
  source keeps the original symbol name and does not assign a more specific
  numeric meaning.
- `data_020ef070` at `0x020ef070` is an 8-byte pair of function pointers. Its
  relocations point to `func_0200efa0` and `func_0200efac`. The existing runtime
  exception handler `func_0200efb8` loads and calls the first slot. The second
  slot is declared as unknown; its use was not established.

Both data units match 100% in objdiff, as does the existing handler after its
declaration was updated to use the typed pair. The symbol extents are explicit
at 40 and 8 bytes. The source preserves the original data section, bytes, and
relocation targets.

Matched initialized data increased by 48 bytes. Code, function counts, and
coverage denominators did not change. Full module and symbol checks, ARM7
baseline verification, ROM build, and exact USA SHA-1 passed:
`c7c3014c237900c8281289b8bc76a781969b6278`. The measured batch window was
96.8 seconds; token usage was not measured. Start and finish snapshots are in
`docs/workflow/evidence/luna-runtime-data-2-start.json` and
`docs/workflow/evidence/luna-runtime-data-2-finish.json`. Detailed logs and
object comparisons are under ignored `build/`.
