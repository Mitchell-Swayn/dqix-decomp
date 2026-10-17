#include <globaldefs.h>
extern "C" {
extern unsigned char data_0210783c[];
void SafeAllocator_ResetAndReturnPointer(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5D84; symbol: __sinit_020e5d84; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e5d84()
{
    SafeAllocator_ResetAndReturnPointer(data_0210783c);
}
