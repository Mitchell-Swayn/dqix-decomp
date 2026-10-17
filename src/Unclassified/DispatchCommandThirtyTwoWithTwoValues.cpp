#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D20C4; symbol: func_020d20c4; size: 0x20.
extern "C" void DispatchCommandThirtyTwoWithTwoValues(unsigned a,unsigned b) {
    AcquireCommandEntryAndStoreFiveValues(32,a,b,0,0);
}
