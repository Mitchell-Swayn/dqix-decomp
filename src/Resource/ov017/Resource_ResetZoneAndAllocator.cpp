#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void _ZN6Zone3D18ResetZoneResourcesEb(void*, int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Object_SetUnsignedIntAtOffset4(int, unsigned);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x0219BF74; symbol: func_ov017_0219bf74; size: 0x40.
extern "C" void* Resource_ResetZoneAndAllocator(void) {
    char* resources = (char*)GameResources_GetInstance();
    _ZN6Zone3D18ResetZoneResourcesEb(ReadGlobalValueAt020FB3F0(), 1);
    void* allocator = resources + 0x38;
    _ZN13SafeAllocator5ResetEv(allocator);
    Object_SetUnsignedIntAtOffset4((int)resources, 2);
    SetWordMaskBits_Main0203B4A0((unsigned*)resources, 4);
    return allocator;
}
