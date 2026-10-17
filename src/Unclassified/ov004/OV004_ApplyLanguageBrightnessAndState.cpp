#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameResources_GetInstance();
extern "C" int _s32_div_f(int, int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void *, int, int);
extern "C" unsigned GameState_ReadByteAtOffset4(void *);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int, unsigned);
extern "C" unsigned char data_02109bf4[];
// Original: arm9/ov004 @ 0x0216DA58; symbol: func_ov004_0216da58; size: 0x78.
extern "C" int OV004_ApplyLanguageBrightnessAndState(void) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *resources = GameResources_GetInstance();
    int value = _s32_div_f(1000, 34);
    if (GameState_ReadByteAtOffset4(game) == 8)
        _Z13SetBrightnessP13GameResourcesii(resources, 16, value);
    else
        _Z13SetBrightnessP13GameResourcesii(resources, -16, value);
    if (GameState_ReadByteAtOffset4(game) != 2)
        DispatchObjectStateOneOrTwoUnlessFlag4((int)data_02109bf4, 16);
    return 0;
}
