#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
extern "C" void* _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" unsigned int data_020f2a1c;
extern "C" unsigned int data_020f2a10;
// Original: arm9/ov023 @ 0x021E0A48; symbol: func_ov023_021e0a48; size: 0x48.
extern "C" int func_ov023_021e0a48(char* owner) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    CancelOwnerTaskAndResetEmbeddedState(owner + 0x8c);
    void* task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
        loader, *(const char**)&data_020f2a1c, *(const char**)&data_020f2a10, 0);
    *(void**)(owner + 0x748) = task;
    return 0xc;
}
