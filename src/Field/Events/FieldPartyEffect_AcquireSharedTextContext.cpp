#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *Network_GetConnectionManager(void);
extern "C" void *GameResources_GetInstance(void);
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov017 @ 0x021ACCE4; symbol: func_ov017_021acce4; size: 0x18.
extern "C" unsigned int FieldPartyEffect_AcquireSharedTextContext(void) {
    _ZN9GameState11GetInstanceEv();
    Network_GetConnectionManager();
    GameResources_GetInstance();
    return TextContext_GetSharedInstance();
}
