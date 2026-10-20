#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage;
extern "C" void SoundSfx_LoadGroupAtCurrentHeapState(void *, unsigned int, unsigned short);
// Original: arm9/ov025 @ 0x021E6320; symbol: func_ov025_021e6320; size: 0x20.
extern "C" int Combat_LoadSfxGroup(void *p) {
    SoundSfx_LoadGroupAtCurrentHeapState(&Main_UnknownRoleZeroInitializedStorage, *(unsigned short *)((char *)p + 8), *(unsigned short *)((char *)p + 0xa));
    return 1;
}
