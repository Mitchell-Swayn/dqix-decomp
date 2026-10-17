#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1DE8; symbol: func_020d1de8; size: 0x20.
extern "C" void DispatchCommandOneWithValue(unsigned a) {
    AcquireCommandEntryAndStoreFiveValues(1,a,0,0,0);
}
