#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
extern "C" const char* data_020f2a1c;
extern "C" const char* data_020f2a20;
// Original: arm9/ov023 @ 0x021E0C38; symbol: func_ov023_021e0c38; size: 0x48.
extern "C" int Filesystem_QueueBackgroundPair(void* self) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    CancelOwnerTaskAndResetEmbeddedState((char*)self + 0xA4);
    *(unsigned*)((char*)self + 0x750) = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, data_020f2a1c, data_020f2a20, 0);
    return 3;
}
