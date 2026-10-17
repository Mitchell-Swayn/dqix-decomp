#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2018; symbol: func_020d2018; size: 0x20.
extern "C" void SubmitOperationCodeTwentyOne(unsigned a,unsigned b) {
    AcquireCommandEntryAndStoreFiveValues(21,a,b,0,0);
}
