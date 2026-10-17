#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D20A4; symbol: func_020d20a4; size: 0x20.
extern "C" void SubmitOperationCodeThirtyOne(unsigned a,unsigned b) {
    AcquireCommandEntryAndStoreFiveValues(31,a,b,0,0);
}
