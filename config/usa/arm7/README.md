# Cartridge ARM7 baseline

The cartridge ARM7 program is a required executable component, distinct from the
console ARM7 BIOS. Its current source coverage is **zero**. The original binary
is preserved through extraction and ROM packaging; byte equality is a baseline
check, not decompilation completion.

| Property | USA value |
| --- | --- |
| CPU | ARM7TDMI |
| ROM payload | `[0x001e2400, 0x0020b3c4)` |
| Loaded payload | `[0x02380000, 0x023a8fc4)` |
| Header entry point | `0x02380000` |
| Payload size | 167,876 bytes |
| Payload SHA-1 | `a662d5c6a78e990244299926cf6862ce910a475d` |
| ARM7 overlay table size | 0 |
| Reconstructed C/C++, data, reviewed assembly | 0 bytes each |
| Binary fallback | 167,876 bytes |
| Function count; code/data partition; BSS layout | Unknown |

These load boundaries describe the contiguous cartridge image. They do not
establish runtime relocation destinations or internal code/data boundaries.
`arm7_entry` is a local header-derived label, not a recovered original name or a
claim about function size. Other symbols still need analysis.

After a USA build, run from the repository root:

```bat
.venv\Scripts\python.exe tools\check_arm7.py
.venv\Scripts\python.exe -m unittest discover -s tools -p test_check_arm7.py
```

The verifier validates the base ROM hash, extraction bytes, rebuilt payload
bytes, addresses, size, and header entry label. Its JSON report goes to
`build/usa/arm7-report.json`. Custom paths are available through `--help` for
isolated clean-build checks. A real ARM7 linker symbol check is not available.
Do not add this module's entire size to a *code* denominator: the internal
code/data split is not yet established. Record it as an unclassified executable
payload alongside the ARM9 report until that split is audited.

## Tool limitation and next work

The pinned `dsd v0.10.2` source was inspected at commit
`561be9b11bc6e61127070d3c5e6ac9533ea825d0`:

- [init.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/init.rs)
  initializes ARM9, its autoloads and ARM9 overlays only.
- [rom/config.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/rom/config.rs)
  builds those ARM9 components and rewrites the original ARM7 binary path to
  remain accessible from the new ROM configuration.

Therefore creating an ARM7-looking dsd configuration would not establish ARM7
build support. Future work needs ARM7-aware analysis, delinking, source compiler
settings, linker configuration, symbol and module comparison, and packaging of
the linked ARM7 output. Record function extents and code/data ranges from actual
analysis before replacing fallback bytes. Keep this manifest and report separate
from `objdiff` ARM9 coverage until those capabilities exist.
