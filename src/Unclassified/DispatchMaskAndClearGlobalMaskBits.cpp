#include <globaldefs.h>
ARM
extern "C" volatile unsigned data_0210f3c0[];extern "C" void DispatchCommandTwentySevenWithTwoValues(unsigned,int);
// Original: arm9/main @ 0x020BBE64; symbol: func_020bbe64; size: 0x30.
extern "C" void DispatchMaskAndClearGlobalMaskBits(unsigned mask){if(!mask)return;DispatchCommandTwentySevenWithTwoValues(mask,0);data_0210f3c0[2]&=~mask;}
