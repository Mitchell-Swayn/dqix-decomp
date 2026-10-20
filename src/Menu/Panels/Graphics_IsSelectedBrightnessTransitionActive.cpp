#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_ReadPResources(void *);
extern "C" int _Z32IsMainBrightnessTransitionActiveP13GameResources(void *);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(void *);
// Original: arm9/ov023 @ 0x021DDBF8; symbol: func_ov023_021ddbf8; size: 0x3C.
extern "C" int Graphics_IsSelectedBrightnessTransitionActive(void *obj) {
    void *resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    if (*(signed char *)((char *)obj + 0x77c) == 1) return _Z31IsSubBrightnessTransitionActiveP13GameResources(resources) != 0;
    return _Z32IsMainBrightnessTransitionActiveP13GameResources(resources) != 0;
}
