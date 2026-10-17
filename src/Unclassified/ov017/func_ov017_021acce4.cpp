#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" void *GameResources_GetInstance(void);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov017 @ 0x021ACCE4; symbol: func_ov017_021acce4; size: 0x18.
extern "C" unsigned int func_ov017_021acce4(void) {
    _ZN9GameState11GetInstanceEv();
    Object_GetGlobalConnectionState();
    GameResources_GetInstance();
    return ReadWordFieldAtOffset1C();
}
