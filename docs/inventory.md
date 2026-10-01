# USA executable inventory

Generate metadata after a matching build, from the repository root:

```bat
.venv\Scripts\python.exe tools\inventory.py
.venv\Scripts\python.exe -m unittest discover -s tools -p test_inventory.py
```

The output defaults to `build/usa/inventory.json`. The tool requires the target
USA ROM, dsd extraction, config files, and the existing objdiff report. It verifies
the input ROM SHA-1, parses the actual NDS header, FAT and both overlay tables,
compares ROM and config overlay IDs, checks extracted overlay lengths and ARM7
bytes, validates source ranges against their module sections, assigns every
report unit to a module, and reconciles every integer coverage counter with the
report totals. Malformed or unassigned entries fail the command. It does not run
the build or establish freshness of the existing report: build first.

When `config/usa/arm7/source_units.json` is present, the tool also validates ARM7
autoload parameters/descriptors against the original payload and partitions it
into startup, initialized autoloads and copy-table subcomponents. These are
children of the existing ARM7 module, **not additional payload bytes in the module
total**. Runtime BSS remains separate from initialized bytes.

If `build/usa/arm7/report.json` is present, its independent source measurements
are attached to ARM7 without adding them to the ARM9 objdiff counters. Payload
hash, source hashes, linked-unit hashes, source unit metadata, check flags and
coverage counters must agree with current inputs. Stale ARM7 source reports fail
with a rebuild instruction. A missing report receives no measured source credit.
The complete ARM7 instruction/data/function denominator remains unknown even when
some source units match. This positive source accounting does not estimate a
whole-cartridge percentage.

`inventory-usa-baseline.json` records the initial metadata and module counters.
`inventory-usa-report.json.gz` is the complete initial objdiff JSON, archived with
deterministic gzip metadata; its decompressed SHA-256 is recorded in the inventory.
These files contain metadata and symbol names, not original program bytes.
The source revision identifies the repository HEAD; it is not a claim that the
working tree was clean. Tool versions are configured pins, not a measurement of
installed executable versions. Later reports should be generated into `build/`,
preserving this baseline.

## Findings

The cartridge header declares ARM9 and ARM7 programs, 35 ARM9 overlays, and no
ARM7 overlays. dsd also extracts ARM9 ITCM and DTCM autoloads. These form 39 known
module records. ARM9 is stored compressed (638,196 bytes); its extracted main
image is 994,912 bytes. ITCM is 5,952 initialized bytes and DTCM is 96 bytes.
The cartridge ARM7 range is 167,876 bytes at address `0x02380000`, and the extracted
ARM7 binary matches that range exactly. This ARM7 comparison proves preservation,
not source reconstruction.

The initial objdiff report covers the 38 ARM9 modules only: 142,700 / 2,959,478
matched code bytes, 1,072 / 14,790 matched functions, and 25,908 / 1,602,476 matched
data bytes. The machine-readable inventory breaks these counters down per module,
records all configured code/data/BSS address ranges and source ownership ranges,
and counts generated fallback units. Source ranges marked `complete` remain
configuration claims, separate from measured matches. The build still links
original delinked objects for unreconstructed ranges. A source unit can also have
unmatched bytes; counting generated units alone is not complete fallback coverage.

Initialized module size includes data and padding; overlay BSS is separate. Neither
module sizes nor the data counter (which includes BSS) should be added to the code
denominator. Some overlays have zero reported code but substantial data/BSS; they
remain explicit records. Shared runtime addresses of overlays do not imply their
cartridge payloads are duplicate coverage.

## Open inventory work

The frozen initial baseline predates ARM7 autoload analysis and source tracking.
Current inventories include the subsequently established two autoloads and bounded
source reconstruction through the independent pipeline; see
[the ARM7 notes](../config/usa/arm7/README.md). Startup is 540 bytes, WRAM autoload
69,172 bytes, main-RAM autoload 98,140 bytes, and the copy table 24 bytes, summing
to the parent payload's 167,876 bytes. The complete ARM7 code/data/function
boundaries and objdiff coverage remain unknown. Do not interpret null ARM7 objdiff
coverage as zero total code, or quote the ARM9 percentage as whole-game coverage.

Header enumeration cannot detect native code disguised as assets. Asset archives,
script/bytecode formats, interpreter dispatch and payload ownership still need an
audit. Program data, padding and embedded constants inside code sections require
further analysis. The known-module inventory therefore does not satisfy the final
goal of inventorying every executable range on the cartridge.

Module/symbol comparisons use `ninja check`; objdiff uses `ninja report`.
Final cartridge hash acceptance and gameplay smoke tests are separate checks and
are not performed by this script. Binary passthrough and unresolved inventory
categories remain explicit even when a rebuilt ROM matches.
