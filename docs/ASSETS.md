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
Unparsed NARC/GPC2 containers are recorded as errors, not silently classified as assets.

## Preservation evidence

The supplied USA ROM SHA-1 is `c7c3014c237900c8281289b8bc76a781969b6278`.
The audited rebuilt ROM SHA-1 is also `c7c3014c237900c8281289b8bc76a781969b6278`.
**All 7,481 FNT-named NitroFS files,
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

There are 4,129 top-level files with NARC magic. The expanded audit parses 5,132
NARC containers and 1,671 GPC2 containers, producing 91,638 records including
outer files and 3,325 decoded Nitro LZ member views, with zero parsing errors.
The GPC2 stage alone produced 88,313 records. The initial NARC-only audit
exposed 4,181 containers and 32,160 records; decoding GPC2 exposes further nested
archives and their members without changing the cartridge's top-level file count.
The parser follows the BTAF allocation table, BTNF names and GMIF payload block,
recording names where supplied and stable numeric member IDs otherwise. It validates
container and member boundaries; nested content remains inside the report only.

Extensions alone do not establish formats. Examples from this cartridge:

| Outer file category | Count | Observed handling |
| --- | ---: | --- |
| `.chr` | 2,683 | Classified by actual magic; often NARC |
| `.gp2` | 1,671 | All GPC2 decoded; 53,639 immediate members |
| `.spr` | 1,300 | Opaque unless recognized by actual NARC magic |
| `.ambl` / `.amdj` | 681 / 669 | Classified by actual magic; archive members inventoried when NARC |
| `.pac` | 126 | Three are NARC; other 123 remain opaque |
| `.mse` | 12 | All NARC, including `.bmed` script members |
| `.nsarc` | 7 | Classified by NARC magic |

The three NARC `.pac` files are `data/event_lv5/inevent.pac`,
`data/scenario/flditem.pac`, and `data/tmap/param.pac`. Other PAC files often start
with filename-like bytes, but this is not sufficient to assert their layout.
Opaque PAC and other proprietary formats still require analysis.
The nested archive inventory also includes `.svn` metadata present in cartridge
archives; these are retained and must not be mistaken for newly authored files.

### GPC2 and compression

[gpc.py](../tools/gpc.py) follows the reconstructed GPC loader and native
decompression routines. The 20-byte GPC2 header supplies word-based boundaries,
file count, decoded table sizes and flags. Each 12-byte file-table entry supplies
a CRC, member location/size and filename offset. Tables and members use a
32-bit compression prefix: low three bits select the algorithm; the remaining
29 bits declare output size. Types 0 through 4 are raw, LZ, four-bit Huffman,
eight-bit Huffman and RLE. This prefix differs from ordinary Nitro compression.

The reader validates table/member bounds and declared sizes, limits each decoded
stream to 64 MiB and caps archive recursion. Immediate GPC2 members comprise
42,402 LZ, 7,763 RLE, 2,437 eight-bit Huffman, 392 four-bit Huffman, 32 raw-prefix
and 613 uncompressed members. These counts exclude compressed index/name tables.
All 1,671 containers decode without errors. The decoder additionally passed
84 whole/fragmented-input comparisons against the original ARM9 instructions;
see [native differential validation](GPC_NATIVE_VALIDATION.md) for samples,
reproduction and limits. These are analysis tools, not newly decompiled game code.

### Nitro LZ map members

`Zone3DMapLoading.cpp` routes map archive members through
`FileIO.cpp`'s BIOS-backed LZ77 wrapper. That wrapper reads the output size from
the upper24 bits of a four-byte prefix. For those source-backed paths, the audit
decodes type `0x10` using the same normal LZ token coding as GPC type1.
Recognition requires `data/map/`, an archive member, an observed loader extension
and the correct prefix; a stray `0x10` in unrelated data is not treated as proof
of compression. Other Nitro encodings remain outside this reader.

All 3,325 selected members decode successfully: 755 `.bmdj`, 737 `.nsbtx`,
667 `.bmbl`, 657 `.dat`, 504 `.bats` and five `.bpos`. Decoded views appear as
`::@lz77` children, retaining the original compressed payload's hash and size in
the parent. Their 2,588 new structural script candidates bring the total to
54,421; all decoded types except `.nsbtx` fit the generic Script structure.
This remains structural evidence, especially for `.dat`, whose native consumer
is only partially understood. The GPC native differential test validates shared
normal-LZ token behavior; it does not execute the missing BIOS implementation.

## Script format and known native users

The GPC loader's runtime metadata, revision text and three signature strings
at USA `[0x020f27c0, 0x020f2800)` now have source definitions in
[`GPCData.cpp`](../src/Filesystem/GPCData.cpp). All 64 bytes, including initial
zero fields and padding, match. `GPCStaticData` preserves adjacent storage order;
it does not assert that the original source grouped these declarations. Interior
references use explicit relocation addends. The 108-byte startup routine at
`0x020e6710` is now matched C++ in [GPCStartup.cpp](../src/Filesystem/GPCStartup.cpp),
placed in `.init` with the compiler's named-section declaration. The existing
startup table still provides its invocation. It constructs the revision suffix
and signatures through the original source-owned helper calls.
This program-owned metadata counts as native data, separately from asset content.
The file-access cache's ready flag, 61 CRC values and 61 handle/file-ID pairs
also have explicit zero-initialized definitions in
[`FileCacheData.cpp`](../src/Filesystem/itcm/FileCacheData.cpp), covering ITCM BSS
`[0x01ffd998, 0x01ffdc78)` (736 bytes including alignment). The 61 configured
path strings, compression-prefix sizes, padding, and root path now have readable
definitions in [FileCacheConfiguration.cpp](../src/Filesystem/FileCacheConfiguration.cpp),
matching all 1,084 bytes at `[0x020f2384, 0x020f27c0)`. Its layout carrier preserves
storage order without asserting the original declaration grouping. The configured
path pointer list remains an original-binary dependency.

The file-cache CRC buffer routine and byte update at `[0x01ff85b8, 0x01ff860c)`
are reconstructed in [FileCacheCRC.cpp](../src/Filesystem/itcm/FileCacheCRC.cpp).
They implement reflected CRC-32 with all-one initial state and final complement.
The 1,024-byte lookup table at `[0x020ee278, 0x020ee678)` is independently generated
from polynomial `0xedb88320` by `tools/generate_crc32_table.py`; `--check` verifies
the checked-in source without reading a ROM. Both routines and the table match.
The adjacent string wrapper remains binary fallback: extracting it leaves an
instruction-free `.text` fallback containing pointer tables, on which pinned
objdiff 2.7.1 crashes in ARM mapping-symbol handling. It receives no source credit.

[CachedMemory.cpp](../src/Filesystem/CachedMemory.cpp) reconstructs the zero-fill
and copy wrappers at `[0x020d84f8, 0x020d8550)` (88 bytes). Both perform the memory
operation, clean/invalidate the destination cache range, and return the processed
length. Caller declarations now preserve that return type. Their vectorized
memory-operation dependencies remain original binary code.

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
54,421 candidates. Before decoding Nitro LZ map members, these comprised 51,833:
47,839 `.bin`, 2,728 `.bcfg`, 930 `.bact`, 283 `.bmmp`, 41 `.svn-base` members
and 12 `.bmed`. The further 2,588 decoded candidates are listed above.
The initial NARC-only audit found 3,511.
Structural resemblance is not semantic script coverage; formats
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
- [Zone3DMapLoading.cpp](../src/World/Zone3DMapLoading.cpp) decompresses `.bmbl`
  and `.bpos` members and executes them through `ZoneFeatures::LoadFromScript`.
  The reconstructed dispatch table in [ZoneFeatures.cpp](../src/World/ZoneFeatures.cpp)
  contains 17 callbacks between `0x64` and `0x7e`, with gaps. The same map loader
  routes decompressed `.bats` files to the lighting interpreter.
- [BMDJ.cpp](../src/World/BMDJ.cpp) executes object-map scripts with its own
  opcode table to construct ID/name records and related entries. Its matched
  constant-return handlers are original successful no-ops, not replacement stubs.

The interpreter and its callbacks are native executable code and remain part of
native decompilation coverage. Preserved script payloads are content coverage.
Other interpreters, dispatch tables and formats may exist in undecompiled code;
this document does not assert a complete interpreter census or recover the
original script-authoring language.

## Native-code triage limitations

The audit scans decoded non-container payloads for ELF, PE and two Mach-O
header signatures. Forty-nine payloads contain 55 loose `PE\0\0` matches;
one contains a Mach-O32 signature. A structural follow-up checks for a
DOS `MZ` header whose `e_lfanew` points to each PE signature, including embedded
images. If found, it checks the COFF machine and section count, PE32/PE32+ optional
header, `SizeOfHeaders`, section table and section payload bounds. It does not
emulate an executable loader or infer code semantics from the machine value.

**All 55 matches were rejected as PE image signatures:** none has an associated
DOS header pointing to it. These are false positives for the loose PE signature
scan, not evidence that the entire containing file lacks executable code. The
individual offsets are recorded in the generated audit. The table below preserves
the sixteen signatures exposed before the additional Nitro LZ decoding
(decimal offsets relative to each decoded payload):

| Payload path | Signature offsets |
| --- | --- |
| `data/ani/oq2.gp2::oq2_en.pac` | 5162 |
| `data/ani/oqmsg.gp2::oqmsg_fr.pac` | 8022 |
| `data/ani/oqmsg.gp2::oqmsg_de.pac` | 5938 |
| `data/bin/charaview4.bin` | 58112 |
| `data/effect/ev144100000.chr::ev144100000.nsbca` | 8 |
| `data/event/ev13320.gp2::ev13320.stb` | 16388 |
| `data/map/B02M28.ambl::B02M28T1.nsbtx` | 14664 |
| `data/map/B06M04.ambl::B06M04T1.nsbtx` | 3889 |
| `data/map/B06M08.ambl::B06M08T1.nsbtx` | 6664 |
| `data/map/D07M02.amdj::D07M0200.nsbmd` | 1, 14 |
| `data/map/D12M03.ambl::D12M03T1.nsbtx` | 6973 |
| `data/map/D17M03.ambl::D17M03T1.nsbtx` | 1358 |
| `data/map/E01M11.ambl::E01M11T1.nsbtx` | 24438 |
| `data/map/S07M01.amdj::S07M0100.nsbmd` | 1344 |
| `data/pack_lv5/minimap.gp2::M09M0001.obg` | 18906 |

The Mach-O32 signature in `data/pack_lv5/minimapt.gp2::mapt_129.pac` at offset
12813 is rejected because its following architecture/file-type fields are
implausible. The checker validates the header and bounded load-command structure
when those fields are plausible. No scanned ELF or Mach-O64 signatures occurred.
The earlier loose match in the compressed outer `enemy.gp2` stream is no longer
reported as a decoded payload candidate.

ARM/Thumb code can have no magic whatsoever, and unresolved opaque formats
are not fully exposed by this scan. Consequently neither negative signature
results nor successful asset preservation prove that all files are non-executable.
Finishing the executable census requires decoding unresolved containers, tracing
loaders/decompressors and investigating potential code-loading or dispatch paths.
