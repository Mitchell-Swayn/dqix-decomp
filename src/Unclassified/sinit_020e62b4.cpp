#include <globaldefs.h>
extern "C"
{
    extern unsigned char data_02109020[];
    extern unsigned char data_02109014[];
    void* _ZN23WorldObjectInstanceListC1Ev(void*);
    void* _ZN23WorldObjectInstanceListD1Ev(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E62B4; symbol: __sinit_020e62b4; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e62b4()
{
    _ZN23WorldObjectInstanceListC1Ev(data_02109020);
    __register_global_object(data_02109020, (void (*)(void*, int))_ZN23WorldObjectInstanceListD1Ev, data_02109014);
}
