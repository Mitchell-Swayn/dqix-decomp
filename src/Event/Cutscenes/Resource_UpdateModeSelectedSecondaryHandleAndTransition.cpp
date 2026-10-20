#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" void ResourceHandle_UpdateModeSelectedSecondaryHandle(char *);
extern "C" void Bgm_SetPlaybackVolumeAndFade(unsigned char *, unsigned char, int);
// Original: arm9/ov001 @ 0x021636A8; symbol: func_ov001_021636a8; size: 0x28.
extern "C" int Resource_UpdateModeSelectedSecondaryHandleAndTransition(void) {
    ResourceHandle_UpdateModeSelectedSecondaryHandle((char *)&Main_UnknownRoleZeroInitializedStorage_Variant2);
    Bgm_SetPlaybackVolumeAndFade((unsigned char *)&Main_UnknownRoleZeroInitializedStorage_Variant2, 0x7f, 0);
    return 1;
}
