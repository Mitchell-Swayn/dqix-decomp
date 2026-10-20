#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char Bgm_GetVolumeSetting(int object);
extern "C" unsigned char SoundSfx_GetVolumeSetting(int object);
// Original: arm9/ov002 @ 0x0215B234; symbol: func_ov002_0215b234; size: 0x34.
extern "C" void PartyMenu_ReadSoundVolumeOptions(unsigned char *object) {
    *(unsigned char *)(object + 0x1C2C) = Bgm_GetVolumeSetting((int)Main_UnknownRoleZeroInitializedStorage_Variant2);
    *(unsigned char *)(object + 0x1C2D) = SoundSfx_GetVolumeSetting((int)Main_UnknownRoleZeroInitializedStorage);
}
