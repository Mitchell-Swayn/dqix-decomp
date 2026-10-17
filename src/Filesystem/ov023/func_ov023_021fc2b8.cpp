#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" int OV023_ReadWordField04(void*);
extern "C" void OV023_WriteWordField04(void*, unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void* _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" char data_ov023_021ff480;
extern "C" char data_ov023_021ff496;
// Original: arm9/ov023 @ 0x021FC2B8; symbol: func_ov023_021fc2b8; size: 0x54.
extern "C" void* func_ov023_021fc2b8(void* owner, void* state) {
    void* entry = func_ov011_021849c8(state);
    int status = OV023_ReadWordField04(entry);
    if (status >= 0) return *(void**)((char*)owner + 0x1c);
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    void* task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
        loader, &data_ov023_021ff480, &data_ov023_021ff496, 0);
    OV023_WriteWordField04(entry, (unsigned int)task);
    return (void*)1;
}
