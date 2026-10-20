#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void Bgm_SetPlaybackVolumeAndFade(unsigned char *, int, int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov001 @ 0x021636D0; symbol: func_ov001_021636d0; size: 0x54.
extern "C" bool Bgm_ScriptSetPlaybackVolumeWithOptionalFade(void *parameters, int count) {
    int value = Script_ReadParameterAsInteger(parameters);
    if (value < 0) value = 0;
    else if (value > 0x7F) value = 0x7F;
    int duration = 0;
    if (count >= 2) duration = Script_ReadParameterAsInteger((unsigned char *)parameters + 8);
    Bgm_SetPlaybackVolumeAndFade(&Main_UnknownRoleZeroInitializedStorage_Variant2, value, duration);
    return true;
}
