#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameResources_GetInstance(void);
extern "C" void *ReadGlobalValueAt020FB3F0(void);
extern "C" void *GameState_GetField3B0ObjectWithFlag4(void *);
extern "C" void Object_SetWordAtOffset23CTo1(void *);
extern "C" int _Z21IsGrottoBossFloorZonei(int);
extern "C" void StoreModeTimestampAndDisableTwoInputOwners(unsigned);
// Original: arm9/ov017 @ 0x021A9FA0; symbol: func_ov017_021a9fa0; size: 0x4C.
extern "C" void func_ov017_021a9fa0(void *obj) {
    void *state = _ZN9GameState11GetInstanceEv();
    GameResources_GetInstance();
    unsigned short *global = (unsigned short *)ReadGlobalValueAt020FB3F0();
    Object_SetWordAtOffset23CTo1(GameState_GetField3B0ObjectWithFlag4(state));
    if (_Z21IsGrottoBossFloorZonei(*global)) StoreModeTimestampAndDisableTwoInputOwners(1000);
    *((unsigned char *)obj + 1) = 1;
}
