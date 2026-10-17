#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" int OV023_ReadWordField04(void *);
extern "C" void OV023_WriteWordField04(void *, unsigned int);
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void *, const char *, void *);
extern "C" char data_ov023_021ff7b4[];
// Original: arm9/ov023 @ 0x021FCEB8; symbol: func_ov023_021fceb8; size: 0x6C.
extern "C" int OV023_QueueBackgroundLoadIfUnloaded(void *owner, void *asset) {
    void *loaderState = func_ov011_021849c8(asset);
    int status = OV023_ReadWordField04(loaderState);
    if (status >= 0) return *(int *)((char *)owner + 0x1c);
    char path[0x50];
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    sprintf(path, data_ov023_021ff7b4, *(unsigned int *)((char *)owner + 0x10));
    unsigned int queued = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
    OV023_WriteWordField04(loaderState, queued);
    return 1;
}
