#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
extern volatile unsigned short data_021117b0[];
// Original: arm9/main @ 0x020CE0FC; symbol: func_020ce0fc; size: 0x18.
void WaitForGlobalMaskBitsToClear(unsigned int mask){do{}while(data_021117b0[0x1d]&mask);}
}
