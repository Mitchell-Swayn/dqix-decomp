# VRAM mapping state

`System/VRAMMappingState.h` preserves the two existing layouts consumed by
`LoadToVRAM.cpp`. Their definitions now have explicit source ownership:

| Record | USA range | Storage |
| --- | --- | --- |
| `ExtPaletteMappingData` | `0x02111240..0x0211125c` | 28 bytes BSS |
| `TextureMappingData` | `0x0211125c..0x0211127c` | 32 bytes BSS |

The palette record holds released VRAM bank masks, mapped addresses and the
main-BG palette offset. The texture record holds image/palette/clear-texture
bank masks and addresses, including a second image block and the first block's
size. Separate source units preserve their original order. Compile-time size
checks protect both layouts; the original field offsets and JP aliases remain.

Both BSS objects compare at 100%. Moving the declarations into the shared header
leaves the compiled `LoadToVRAM` instruction bytes and relocation entries
unchanged. Full USA ROM/module/symbol/SHA-1 checks pass. The report's 60-byte
matched-data gain is entirely BSS, with no initialized-data or code gain.

## Deferred scanline allocation

The ITCM staging copy-budget consumer uses the first two halfwords at
`0x020ee694`: 212 for main-engine regions and 262 for sub-engine regions. Earlier
source comments reversed these values; the comments are now corrected.

A four-byte source-table trial first failed delink because the inferred symbol
extends to `0x020ee6b0`. Giving the known prefix its exact four-byte symbol size
allowed delink, but the linker discarded the remaining 24 unreferenced bytes:
`data_020ee6b0` moved to `0x020ee698`, and module/symbol checks failed. Both source
and mapping changes were reverted. The full allocation remains required work;
its unknown tail was not represented as padding or assigned invented semantics.
Verbose trial logs stay under ignored `build/sol61-scanline-*-trial.log`.
