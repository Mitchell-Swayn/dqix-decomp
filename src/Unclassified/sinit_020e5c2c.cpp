#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_02105ab4[];
    extern unsigned char data_02105248[];
    void* Object_ResetEmbeddedRecordsAndReleaseState(void*);
    void* CleanupThirtyTwoFortyByteRecords(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5C2C; symbol: __sinit_020e5c2c; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5c2c()
{
    Object_ResetEmbeddedRecordsAndReleaseState(data_02105ab4);
    __register_global_object(data_02105ab4, (void (*)(void*, int))CleanupThirtyTwoFortyByteRecords, data_02105248);
}
