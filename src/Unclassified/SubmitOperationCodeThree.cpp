#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1E30; symbol: func_020d1e30; size: 0x20.
extern "C" void SubmitOperationCodeThree(unsigned a) {
    AcquireCommandEntryAndStoreFiveValues(3,a,0,0,0);
}
