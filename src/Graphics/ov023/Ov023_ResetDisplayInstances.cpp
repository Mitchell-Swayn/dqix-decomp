#include <globaldefs.h>
extern "C" void func_ov023_021e4f18(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetField3B0ObjectWithFlag4(void*);
extern "C" void SetField238Enabled(void*);
extern "C" void SetAngleAndCacheTrig(void*, unsigned);
// Original: arm9/ov023 @ 0x021FC6CC; symbol: func_ov023_021fc6cc; size: 0x50.
extern "C" ARM void Ov023_ResetDisplayInstances(void* object) {
    for (int i = 0; i < 2; ++i)
        func_ov023_021e4f18((char*)object + 0x20 + i * 0xc20);
    void* target = GameState_GetField3B0ObjectWithFlag4(_ZN9GameState11GetInstanceEv());
    SetField238Enabled(target);
    unsigned angle = *(unsigned*)((char*)object + 0x1860);
    SetAngleAndCacheTrig(target, angle);
}
