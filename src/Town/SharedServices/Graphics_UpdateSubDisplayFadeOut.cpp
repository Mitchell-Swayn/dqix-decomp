#include <globaldefs.h>
ARM
struct GameState; struct GameResources; struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" bool _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
extern "C" void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
extern "C" void Graphics_ApplySubBackgroundControlRegisters(Object*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void ComputeGrottoAndContextDependentStateFlags(int mode);
// Original: arm9/ov003 @ 0x0215445C; symbol: func_ov003_0215445c; size: 0x90.
extern "C" void Graphics_UpdateSubDisplayFadeOut(unsigned char *self) {
    GameResources *resources = GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
    if (!self[0x58]) { self[0x5a] = 3; return; }
    if (self[0x5b] == 0) {
        _Z16SetSubBrightnessP13GameResourcesii(resources, -16, 1);
        self[0x5b]++;
    } else if (self[0x5b] == 1) {
        if (_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)) return;
        Graphics_ApplySubBackgroundControlRegisters((Object*)(self + 0x38));
        SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(), 1);
        ComputeGrottoAndContextDependentStateFlags(0);
        self[0x5a] = 3;
        self[0x5b] = 0;
    }
}
