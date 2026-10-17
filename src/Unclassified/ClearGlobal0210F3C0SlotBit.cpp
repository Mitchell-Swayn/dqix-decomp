#include <globaldefs.h>
ARM
extern "C" unsigned int data_0210f3c0[];
// Original: arm9/main @ 0x020BBEF8; symbol: func_020bbef8; size: 0x20.
 extern "C" void ClearGlobal0210F3C0SlotBit(unsigned int bit) { data_0210f3c0[1]&=~(1U<<bit); }
