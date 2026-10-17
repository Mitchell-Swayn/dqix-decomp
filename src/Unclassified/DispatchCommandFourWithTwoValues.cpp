#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1E50; symbol: func_020d1e50; size: 0x20.
extern "C" void DispatchCommandFourWithTwoValues(unsigned a,unsigned b) {
    AcquireCommandEntryAndStoreFiveValues(4,a,b,0,0);
}
