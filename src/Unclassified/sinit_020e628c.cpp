#include <globaldefs.h>
extern "C" {
extern unsigned char data_02108f0c[];
void Object_InitializeFiveStringFieldsAndState(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E628C; symbol: __sinit_020e628c; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e628c()
{
    Object_InitializeFiveStringFieldsAndState(data_02108f0c);
}
