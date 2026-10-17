#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void func_ov017_0219b624(void*);
// Original: arm9/ov017 @ 0x021B2B68; symbol: func_ov017_021b2b68; size: 0x38.
extern "C" int UpdateLoadStateAfterQueueDrains(int* state) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (_ZN16BackgroundLoader17GetNumQueuedTasksEv(loader) > 0)
        return state[2];
    func_ov017_0219b624(GameResources_GetInstance());
    unsigned* flags = (unsigned*)((char*)state + 0x38);
    *flags &= ~4u;
    return 3;
}
