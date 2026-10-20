#include <globaldefs.h>
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Graphics_CancelTasksFreeArenaAndClearTwoBackgrounds(void*);
extern "C" bool Sound_HasTypeOneJobForOwnerId(void*);
extern "C" void ResourceHandle_UpdateModeSelectedSecondaryHandle(char*);
extern "C" void Bgm_SetPlaybackVolumeAndFade(unsigned char*, unsigned char, int);
// Original: arm9/ov017 @ 0x021AB010; symbol: func_ov017_021ab010; size: 0x50.
extern "C" ARM void Ov017_SetOwnerActiveAndUpdateSound(bool* owner, int updateSound) {
    Graphics_CancelTasksFreeArenaAndClearTwoBackgrounds(owner);
    if (updateSound && !Sound_HasTypeOneJobForOwnerId((void*)Main_UnknownRoleZeroInitializedStorage_Variant2)) {
        ResourceHandle_UpdateModeSelectedSecondaryHandle((char*)Main_UnknownRoleZeroInitializedStorage_Variant2);
        Bgm_SetPlaybackVolumeAndFade(Main_UnknownRoleZeroInitializedStorage_Variant2, 0x7f, 0);
    }
    *((unsigned char*)owner + 1) = 1;
}
