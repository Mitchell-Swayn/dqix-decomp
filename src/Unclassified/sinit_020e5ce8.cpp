#include <globaldefs.h>
extern "C" {
extern unsigned char data_021077dc[];
void ClearWordAndTwoBytesAndReturnPointer(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5CE8; symbol: __sinit_020e5ce8; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e5ce8()
{
    ClearWordAndTwoBytesAndReturnPointer(data_021077dc);
}
