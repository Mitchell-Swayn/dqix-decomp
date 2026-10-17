#include <globaldefs.h>
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" unsigned int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void *, const char *, const char *, void *);
extern "C" void *func_ov011_021849c8(void *);
extern "C" void OV023_WriteWordField04(void *, unsigned int);
extern "C" int OV023_ReadWordField04(void *);
extern "C" char *data_020f2a38;
extern "C" char *data_020f2a30;
// Original: arm9/ov023 @ 0x021FBEF0; symbol: func_ov023_021fbef0; size: 0x5C.
extern "C" void *Ov023_QueueAssetWhenHandleInvalid(char *object, void *state) {
    void *entry = func_ov011_021849c8(state);
    if (OV023_ReadWordField04(entry) >= 0) return *(void **)(object + 0x1c);
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    unsigned int handle = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, data_020f2a38, data_020f2a30, 0);
    OV023_WriteWordField04(entry, handle);
    return (void *)1;
}
