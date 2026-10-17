#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_02104b6c[];
    extern unsigned char data_02104b60[];
    void* ZoneContainer_ConstructTwoArraysOfFiveRenderParts(void*);
    void* ZoneContainer_DestroyTenRenderParts(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5C00; symbol: __sinit_020e5c00; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5c00()
{
    ZoneContainer_ConstructTwoArraysOfFiveRenderParts(data_02104b6c);
    __register_global_object(data_02104b6c, (void (*)(void*, int))ZoneContainer_DestroyTenRenderParts, data_02104b60);
}
