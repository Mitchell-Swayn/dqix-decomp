#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*, unsigned int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*, int, void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int Main_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021ED014; symbol: func_ov023_021ed014; size: 0x50.
extern "C" int System_DispatchStoredIndexWhenMaskOrStateMatches(void) {
    if (!Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0xf03) && *((unsigned char*)&Main_UnknownRoleZeroInitializedStorage_Variant4 + 0x55) == 0) return 0;
    SoundSfx_StartCurrentSequenceArchiveEntry((char*)&Main_UnknownRoleZeroInitializedStorage, 1, 0);
    return 1;
}
