#include <globaldefs.h>
extern "C" {
extern unsigned char data_02108d5c[];
void Object_InitializeColorAnimationRecord(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E6024; symbol: __sinit_020e6024; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e6024()
{
    Object_InitializeColorAnimationRecord(data_02108d5c);
}
