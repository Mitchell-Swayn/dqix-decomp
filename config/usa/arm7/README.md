# Cartridge ARM7 reconstruction

The cartridge ARM7 program is a required executable component, distinct from the
console ARM7 BIOS. The independent source build currently reconstructs **five
functions: 208 instruction bytes plus 16 bytes of literal pools**. The other 167,652
bytes remain explicit original-binary fallback. Byte equality does not imply
decompilation completion. `baseline.json` records the original zero-source
starting point; `source_units.json` describes the active source replacements.

| Property | USA value |
| --- | --- |
| CPU | ARM7TDMI |
| ROM payload | `[0x001e2400, 0x0020b3c4)` |
| Loaded payload | `[0x02380000, 0x023a8fc4)` |
| Header entry point | `0x02380000` |
| Payload size | 167,876 bytes |
| Payload SHA-1 | `a662d5c6a78e990244299926cf6862ce910a475d` |
| ARM7 overlay table size | 0 |
| Reconstructed C instructions / compiler literal pools | 208 / 16 bytes |
| Reconstructed standalone data / reviewed assembly | 0 / 0 bytes |
| Binary fallback | 167,652 bytes |
| Total function count / complete code-data partition | Unknown |

These load boundaries describe the contiguous cartridge image. The startup code
copies two parts of that image to different runtime addresses (below).
`arm7_entry` is a local header-derived label, not a recovered original name or a
claim about function size. Other symbols still need analysis.

After the ARM9 build has generated `build/usa/build/rom_config.yaml`, run from the
repository root (Windows matching tools):

```bat
.venv\Scripts\python.exe tools\arm7_build.py --rom-config build/usa/build/rom_config.yaml
dsd.exe rom build --config build/usa/build/rom_config_arm7.yaml --rom build/usa/arm7/dqix_usa.nds
.venv\Scripts\python.exe tools\check_arm7.py --rom build/usa/arm7/dqix_usa.nds
.venv\Scripts\python.exe -m unittest discover -s tools -p test_check_arm7.py
.venv\Scripts\python.exe -m unittest discover -s tools -p test_arm7_build.py
```

The verifier validates the base ROM hash, extraction bytes, rebuilt payload
bytes, addresses, size, and header entry label. Its JSON report goes to
`build/usa/arm7-report.json`. This preservation report deliberately makes no
source-coverage claim. The source build's `build/usa/arm7/report.json` separately
records compiled-source checks, linked symbol checks, source hashes, compiler
hashes, flags, and fallback byte counts. Custom paths are available through
`--help` for isolated clean-build checks. Only declared source-unit symbols are
link-checked; no full original ARM7 symbol map is claimed.
Do not add this module's entire size to a *code* denominator: the internal
code/data split is not yet established. Record it as an unclassified executable
payload alongside the ARM9 report until that split is audited.

## Startup and autoload mapping

Disassembly of the entry routine establishes a call at `0x023800a0` to the copy
loop at `0x02380118`. The loop reads six parameters at `0x02380204`: table start
`0x023a8fac`, table end `0x023a8fc4`, copy source `0x0238021c`, empty startup BSS
range `[0x0238021c, 0x0238021c)`, and zero. Each 12-byte descriptor contains
destination, copy length, and subsequent BSS zero-fill length. Both descriptors
and all source/runtime mappings are validated on every source build.

| Part | Payload offsets | Runtime initialized range | Runtime BSS range |
| --- | --- | --- | --- |
| Startup and parameters | `[0, 0x21c)` | `[0x02380000, 0x0238021c)` | Empty |
| Autoload 0 (`wram`) | `[0x21c, 0x11050)` | `[0x037f8000, 0x03808e34)` | `[0x03808e34, 0x0380cda4)` |
| Autoload 1 (`mainram`) | `[0x11050, 0x28fac)` | `[0x027e0000, 0x027f7f5c)` | `[0x027f7f5c, 0x027f98c4)` |
| Copy descriptors | `[0x28fac, 0x28fc4)` | Read at original load location | None |

Names `wram` and `mainram` are descriptive labels for the destinations, not
recovered linker section names. Initialized ranges contain both code and data.
The first range crosses the WRAM boundary; the addresses above are the literal
copy-loop destinations, without assuming a particular physical memory mapping.

## Source units and pipeline

`src/BootFlags.c` reconstructs runtime range `[0x037f84b8, 0x037f84f0)` from
payload range `[0x6d4, 0x70c)`. It reads byte `0x027ffe1d` and returns `0x40` for
input `0x80`, `0x80` for input `0x40`, and zero otherwise. The call sites at
`0x037f8084` and `0x037f8150` occur in firmware-settings validation. The broader
meaning of that shared boot byte remains uncertain, so the name describes the
observed operation. The conditional 16-bit narrowing in the original code is
reproduced with an unsigned-short accumulator and return type.

`src/BitCount.c` reconstructs runtime range `[0x03803f28, 0x03803f6c)` from
payload range `[0xc144, 0xc188)`: a population count using parallel bit summation.
Its 56 instruction bytes and three 32-bit literal masks match exactly.

`src/ArenaBounds.c` reconstructs runtime range `[0x037fce88, 0x037fceec)` from
payload range `[0x50a4, 0x5108)`: arena initialization and low/high boundary
getters. These three functions access shared boundary arrays at `0x027ffdc4`
and `0x027ffda0`. The two initial-boundary selection functions at `0x037fceec`
and `0x037fcf68` remain explicitly declared, address-linked fallback dependencies.
The 100-byte source unit includes no literal pool or standalone data ownership.

`arm7_build.py` compiles each declared unit with `mwccarm` targeting `arm7tdmi`,
links it at its actual runtime address with `mwldarm`, reads its linked ELF,
checks section size, addresses, symbols and bytes, then places it at its original
payload offset. It rejects overlapping units and invalid autoload mappings. All
other payload bytes are retained explicitly as fallback. The linked replacement
is used in the packaged ROM through a generated sibling ROM configuration.
Declared source functions are forced active when linking, so every function in a
multi-function unit remains present; C++ exception tables are disabled.

This is a source-slice pipeline, not full ARM7 delinking. Add coherent source
units and their verified extents to `source_units.json`. Unit `externals` can
define linker addresses for dependencies; any dependency in unreconstructed
ranges remains fallback. Currently each source unit must emit one `.text` image
(including its compiler literal pools) and no separate data/BSS. Extend the
section model before reconstructing globals; do not discard extra sections or
credit untouched bytes. ARM7 sources live here so the current recursive ARM9
source discovery does not compile them with ARM9 flags.

On non-Windows hosts pass `--runner ./wibo` (or an absolute Wine executable path)
to prefix both matching-tool invocations. The runner path is resolved before the
link step changes directory. The pipeline has been executed on Windows; its
Wine/Wibo invocation path still needs validation on a non-Windows host.

## Pinned dsd limitation

The pinned `dsd v0.10.2` source was inspected at commit
`561be9b11bc6e61127070d3c5e6ac9533ea825d0`:

- [init.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/init.rs)
  initializes ARM9, its autoloads and ARM9 overlays only.
- [rom/config.rs](https://github.com/AetiasHax/ds-decomp/blob/561be9b11bc6e61127070d3c5e6ac9533ea825d0/cli/src/cmd/rom/config.rs)
  builds those ARM9 components and rewrites the original ARM7 binary path to
  remain accessible from the new ROM configuration.

The independent pipeline supplies bounded ARM7 source compilation, linking,
comparison and packaging without pretending the dsd configuration supports ARM7.
Full code/data analysis, dependency recovery and source reconstruction remain.
Keep ARM7 coverage separate from the `objdiff` ARM9 report until full compatible
analysis and denominator tracking exist.
