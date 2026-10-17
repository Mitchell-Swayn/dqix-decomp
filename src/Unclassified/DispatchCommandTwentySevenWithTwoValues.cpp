#include <globaldefs.h>
ARM
extern "C" void AcquireCommandEntryAndStoreFiveValues(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1FD0; symbol: func_020d1fd0; size: 0x20.
extern "C" void DispatchCommandTwentySevenWithTwoValues(unsigned a,unsigned b) {
    AcquireCommandEntryAndStoreFiveValues(27,a,b,0,0);
}
