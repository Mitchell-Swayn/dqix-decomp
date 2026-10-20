#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void *resources);
// Original: arm9/ov025 @ 0x021E58D4; symbol: func_ov025_021e58d4; size: 0x1C.
extern "C" int Resource_IsBrightnessTransitionInactive(void) {
    return !_Z28IsBrightnessTransitionActiveP13GameResources(GameResources_GetInstance());
}
