#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_020fdd44[];
    extern unsigned char data_020fdd38[];
    void* ConstructFourRecordsAndInitializeOwner(void*);
    void* CleanupFourRecordsAndOwner(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5AFC; symbol: __sinit_020e5afc; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5afc()
{
    ConstructFourRecordsAndInitializeOwner(data_020fdd44);
    __register_global_object(data_020fdd44, (void (*)(void*, int))CleanupFourRecordsAndOwner, data_020fdd38);
}
