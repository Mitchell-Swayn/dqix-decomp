#include <globaldefs.h>
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int OV023_ReadWordField04(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" void OV023_WriteWordField04(void*, unsigned);
extern "C" char data_ov023_021fe4e0[];
// Original: arm9/ov023 @ 0x021F7010; symbol: func_ov023_021f7010; size: 0x6C.
extern "C" ARM void* Ov023_LoadAssetForNegativeField(void* object, void* context) {
    void* record = func_ov011_021849c8(context);
    if (OV023_ReadWordField04(record) >= 0)
        return *(void**)((char*)object + 0x1c);
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    char path[0x50];
    sprintf(path, data_ov023_021fe4e0, *(char**)((char*)object + 0x10));
    unsigned handle = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
    OV023_WriteWordField04(record, handle);
    return (void*)1;
}
