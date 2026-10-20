#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void _Z31SetMainBrightnessWithDurationMsP13GameResourcesij(GameResources *, int, unsigned int);
// Original: arm9/ov025 @ 0x021E58B4; symbol: func_ov025_021e58b4; size: 0x20.
extern "C" int Graphics_SetMainBrightnessFromFields(void *settings) {
    GameResources *resources = GameResources_GetInstance();
    int brightness = *(signed char *)((char *)settings + 0xa);
    unsigned int duration = *(unsigned short *)((char *)settings + 8);
    _Z31SetMainBrightnessWithDurationMsP13GameResourcesij(resources, brightness, duration);
    return 1;
}
