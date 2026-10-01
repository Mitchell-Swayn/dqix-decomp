# Assets, archives and script baseline

Reproduce this audit from the repository root after `ninja rom`:

```bat
.venv\Scripts\python.exe tools\audit_assets.py
.venv\Scripts\python.exe -m unittest discover -s tools -p test_audit_assets.py
```

The default inputs are `extract/baserom_dqix_usa.nds` and `dqix_usa.nds`.
Use `--original`, `--rebuilt` and `--output` to override them. The generated
`build/usa/assets-audit.json` contains only paths, hashes, sizes, format signatures
and structural metadata. No payloads are extracted or committed by this tool.
Malformed NitroFS structures or any changed/missing/added file fail the command.
Unparsed NARC containers are recorded as errors, not silently classified as assets.

## Preservation evidence

The supplied USA ROM SHA-1 is `c7c3014c237900c8281289b8bc76a781969b6278`.
The audited rebuilt ROM SHA-1 is `c86d3ee5c7434e9be811ed512f1ef0549acaedc7`.
Despite the differing whole-ROM hashes, **all 7,481 FNT-named NitroFS files,
totalling 253,967,681 bytes, are identical by path and complete payload bytes**.
Each receives a SHA-256 in the report. This checks assets independently of ROM
layout, padding, executable matching and secure-area handling; it does not replace
final ROM SHA-1 acceptance.

The build's `dsd rom extract` rule preserves content under `extract/usa/files`,
with file ordering and alignment in extracted metadata. `dsd rom build` repackages
that extracted content using its generated ROM config. Content does not need to
be rewritten as C++ to be preserved exactly. The auditor reads the actual FNT/FAT
in both cartridges rather than assuming unchanged extraction implies preservation.
Files without FNT paths, including overlay payloads, are outside this audit;
see the separate executable inventory for overlays and processor binaries.

## Archive inventory

There are 4,129 top-level files with NARC magic and 4,181 NARC containers including
nested containers: 40 at nesting depth one and 12 at depth two. Recursive parsing
produced 32,160 records including the outer files, with zero NARC parsing errors.
The parser follows the BTAF allocation table, BTNF names and GMIF payload block,
recording names where supplied and stable numeric member IDs otherwise. It validates
container and member boundaries; nested content remains inside the report only.

Extensions alone do not establish formats. Examples from this cartridge:

| Outer file category | Count | Observed handling |
| --- | ---: | --- |
| `.chr` | 2,683 | Classified by actual magic; often NARC |
| `.gp2` | 1,671 | `GPC2` is common; opaque to this tool |
| `.spr` | 1,300 | Opaque unless recognized by actual NARC magic |
| `.ambl` / `.amdj` | 681 / 669 | Classified by actual magic; archive members inventoried when NARC |
| `.pac` | 126 | Three are NARC; other 123 remain opaque |
| `.mse` | 12 | All NARC, including `.bmed` script members |
| `.nsarc` | 7 | Classified by NARC magic |

The three NARC `.pac` files are `data/event_lv5/inevent.pac`,
`data/scenario/flditem.pac`, and `data/tmap/param.pac`. Other PAC files often start
with filename-like bytes, but this is not sufficient to assert their layout.
Compression, GPC2, opaque PAC and other proprietary formats are not decoded here.
The nested archive inventory also includes `.svn` metadata present in cartridge
archives; these are retained and must not be mistaken for newly authored files.

## Script format and known native users

[Script.h](../include/Resource/Script.h) and
[Script.cpp](../src/Resource/Script.cpp) reconstruct a native interpreter whose
opcode table is supplied by each caller. Its 16-byte file header holds instruction
count, data-section offset, data length, and a fourth word tentatively named
`maybeNumStrings`. Each instruction begins with a 16-bit opcode and an 8-bit
argument count. Packed two-bit argument types follow, then padding to a four-byte
boundary and four-byte argument values. Types handled by source are string offset,
integer, and float. String offsets refer to the data section; negative offsets have
special handling. The fourth header word's precise meaning remains uncertain.

The audit checks this structural shape without executing scripts or claiming that
all matching bytes belong to this interpreter. It allows zero or `0xff` padding
between instruction stream and data section, as found in `.bmed` files. It finds
3,511 candidates: 2,530 `.bcfg`, 613 `.bin`, 315 `.bact`, 41 `.svn-base` members,
and 12 `.bmed`. Structural resemblance is not semantic script coverage; formats
with similar headers can be false positives, and unsupported structures can be
missed. Opcode histograms and header fields are included per candidate.

Source-backed interpreter relationships include:

- [BCFG.cpp](../src/Resource/BCFG.cpp) installs `bcfgScriptOpcodes` and executes
  `Script` to populate animation records and related configuration. Its callbacks
  include opcodes `0x64` through `0x71`, with gaps. [Object3D.cpp](../src/World/Object3D.cpp)
  finds `.bcfg` members in character archives and calls `BCFG::LoadFromScript`.
- [AtmosphericEffect.cpp](../src/Graphics/AtmosphericEffect.cpp) loads
  `data/map/%s.mse` as a NARC archive, obtains a `.bmed` member, and executes it with
  `effectScriptOpcodes` (`0x64`–`0x6d`). These affect scrolling, scale, alpha and
  related atmospheric settings. `.mse` is the container, not the instruction stream.
- [LootableContainer.cpp](../src/World/LootableContainer.cpp) executes per-zone
  `.bin` members from the treasure archive with container callbacks, and executes
  `randTBox.bin` and `randTTT.bin` with loot-distribution callbacks. These names
  provide stronger evidence than applying a generic `.bin` classification.

The interpreter and its callbacks are native executable code and remain part of
native decompilation coverage. Preserved script payloads are content coverage.
Other interpreters, dispatch tables and formats may exist in undecompiled code;
this document does not assert a complete interpreter census or recover the
original script-authoring language.

## Native-code triage limitations

The audit scans non-NARC payloads and parsed members for ELF, PE and two Mach-O
header signatures. Eleven payloads contain twelve loose `PE\0\0` matches; none
contains the scanned ELF/Mach-O signatures. A structural follow-up checks for a
DOS `MZ` header whose `e_lfanew` points to each PE signature, including embedded
images. If found, it checks the COFF machine and section count, PE32/PE32+ optional
header, `SizeOfHeaders`, section table and section payload bounds. It does not
emulate an executable loader or infer code semantics from the machine value.

**All twelve matches were rejected as PE image signatures:** none has an associated
DOS header pointing to it. These are false positives for the loose PE signature
scan, not evidence that the entire containing file lacks executable code. The
individual offsets (decimal, relative to each decoded payload) are reproducible:

| Payload path | Signature offsets |
| --- | --- |
| `data/bin/charaview4.bin` | 58112 |
| `data/effect/ev144100000.chr::ev144100000.nsbca` | 8 |
| `data/map/B02M28.ambl::B02M28T1.nsbtx` | 14664 |
| `data/map/B06M04.ambl::B06M04T1.nsbtx` | 3889 |
| `data/map/B06M08.ambl::B06M08T1.nsbtx` | 6664 |
| `data/map/D07M02.amdj::D07M0200.nsbmd` | 1, 14 |
| `data/map/D12M03.ambl::D12M03T1.nsbtx` | 6973 |
| `data/map/D17M03.ambl::D17M03T1.nsbtx` | 1358 |
| `data/map/E01M11.ambl::E01M11T1.nsbtx` | 24438 |
| `data/map/S07M01.amdj::S07M0100.nsbmd` | 1344 |
| `data/pack_lv5/enemy.gp2` | 3008552 |

ARM/Thumb code can have no magic whatsoever, and compressed or opaque archive
members are not exposed by this scan. Consequently neither negative signature
results nor successful asset preservation prove that all files are non-executable.
Finishing the executable census requires decoding unresolved containers, tracing
loaders/decompressors and investigating potential code-loading or dispatch paths.
