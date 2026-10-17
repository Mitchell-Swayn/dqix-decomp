#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void *ClearMemoryRange16(void *);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern const char *data_020f2a1c;
extern const char *data_020f2b68;
// Original: arm9/ov023 @ 0x021E07F8; symbol: func_ov023_021e07f8; size: 0x48.
extern "C" int Filesystem_ClearAndQueueInitialGP2(void *self) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    ClearMemoryRange16((char *)self + 0x6C);
    int handle = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, data_020f2a1c, data_020f2b68, 0);
    *(int *)((char *)self + 0x744) = handle;
    return 10;
}
