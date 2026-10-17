#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_021079ec[];
    extern unsigned char data_021079e0[];
    void* Object_InitializeSixteenDisplayEntriesAndContainer(void*);
    void* GameState_ResetSixteenObjectSlots208Through223AndReturnPointer(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5EB4; symbol: __sinit_020e5eb4; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5eb4()
{
    Object_InitializeSixteenDisplayEntriesAndContainer(data_021079ec);
    __register_global_object(data_021079ec, (void (*)(void*, int))GameState_ResetSixteenObjectSlots208Through223AndReturnPointer, data_021079e0);
}
