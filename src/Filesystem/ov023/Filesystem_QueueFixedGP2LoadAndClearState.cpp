#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern "C" void *ClearMemoryRange16(void *);
extern "C" const char *data_020f2a1c;
extern "C" const char *data_020f2a28;
// Original: arm9/ov023 @ 0x021E0B54; symbol: func_ov023_021e0b54; size: 0x48.
extern "C" int Filesystem_QueueFixedGP2LoadAndClearState(void *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    ClearMemoryRange16((unsigned char *)state + 0x7C);
    int task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, data_020f2a1c, data_020f2a28, 0);
    *(int *)((unsigned char *)state + 0x74C) = task;
    return 0x0E;
}
