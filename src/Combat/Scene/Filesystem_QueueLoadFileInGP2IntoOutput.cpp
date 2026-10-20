#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void *_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern "C" char Filesystem_QueueLoadFileInGP2IntoOutput_PathDataPrmActmsgGp2[];
extern "C" char Filesystem_QueueLoadFileInGP2IntoOutput_MarkupActmsgLGNat[];

// Original: arm9/ov000 @ 0x0216FD0C; symbol: func_ov000_0216fd0c; size: 0x2C.
extern "C" void Filesystem_QueueLoadFileInGP2IntoOutput(void **result) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    *result = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
        loader, Filesystem_QueueLoadFileInGP2IntoOutput_PathDataPrmActmsgGp2, Filesystem_QueueLoadFileInGP2IntoOutput_MarkupActmsgLGNat, 0);
}
