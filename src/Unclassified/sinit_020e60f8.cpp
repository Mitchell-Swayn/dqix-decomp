#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_02108e10[];
    extern unsigned char data_02108e04[];
    void* Object_ClearFourTwelveByteRecordsAndReturnSelf(void*);
    void* ClearFourTwelveByteBlocksAndReturnPointer(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E60F8; symbol: __sinit_020e60f8; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e60f8()
{
    Object_ClearFourTwelveByteRecordsAndReturnSelf(data_02108e10);
    __register_global_object(data_02108e10, (void (*)(void*, int))ClearFourTwelveByteBlocksAndReturnPointer, data_02108e04);
}
