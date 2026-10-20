#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
struct GameResources;
extern "C" GameResources *GameState_ReadPResources(void *);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(GameResources *, int, int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(GameResources *, int, int);

// Original: arm9/ov023 @ 0x021DDBB8; symbol: func_ov023_021ddbb8; size: 0x40.
extern "C" void Graphics_SetMainOrSubBrightness(void *state, int brightness, int duration) {
    GameResources *resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    if (*((signed char *)state + 0x77c) == 1)
        _Z16SetSubBrightnessP13GameResourcesii(resources, brightness, duration);
    else
        _Z17SetMainBrightnessP13GameResourcesii(resources, brightness, duration);
}
