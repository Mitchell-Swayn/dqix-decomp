#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void* Zone3D_GetMainInstance();
extern "C" void _ZN6Zone3D18ResetZoneResourcesEb(void*, int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void GameResources_SetSecondaryFlags(int, unsigned);
extern "C" void GameResources_SetPrimaryFlags(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x0219BF74; symbol: func_ov017_0219bf74; size: 0x40.
extern "C" void* Resource_ResetZoneAndAllocator(void) {
    char* resources = (char*)GameResources_GetInstance();
    _ZN6Zone3D18ResetZoneResourcesEb(Zone3D_GetMainInstance(), 1);
    void* allocator = resources + 0x38;
    _ZN13SafeAllocator5ResetEv(allocator);
    GameResources_SetSecondaryFlags((int)resources, 2);
    GameResources_SetPrimaryFlags((unsigned*)resources, 4);
    return allocator;
}
