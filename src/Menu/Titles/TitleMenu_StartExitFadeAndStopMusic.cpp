#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameResources_GetInstance();
extern "C" int _s32_div_f(int, int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void *, int, int);
extern "C" unsigned GameState_ReadByteAtOffset4(void *);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int, unsigned);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov004 @ 0x0216DA58; symbol: func_ov004_0216da58; size: 0x78.
extern "C" int TitleMenu_StartExitFadeAndStopMusic(void) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *resources = GameResources_GetInstance();
    int value = _s32_div_f(1000, 34);
    if (GameState_ReadByteAtOffset4(game) == 8)
        _Z13SetBrightnessP13GameResourcesii(resources, 16, value);
    else
        _Z13SetBrightnessP13GameResourcesii(resources, -16, value);
    if (GameState_ReadByteAtOffset4(game) != 2)
        Bgm_StopActiveSequenceUnlessBlocked((int)Main_UnknownRoleZeroInitializedStorage_Variant2, 16);
    return 0;
}
