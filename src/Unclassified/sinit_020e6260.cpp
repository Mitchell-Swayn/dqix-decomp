#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_02108ea8[];
    extern unsigned char data_02108e9c[];
    void* ResetFourTwelveByteRecords(void*);
    void* ResetFourTwelveByteEntries(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E6260; symbol: __sinit_020e6260; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e6260()
{
    ResetFourTwelveByteRecords(data_02108ea8);
    __register_global_object(data_02108ea8, (void (*)(void*, int))ResetFourTwelveByteEntries, data_02108e9c);
}
