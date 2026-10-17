#include <globaldefs.h>
extern "C" void AcquireCommandEntryAndStoreFiveValues(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D20E4; symbol: func_020d20e4; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeTwentyThree(unsigned value) {AcquireCommandEntryAndStoreFiveValues(0x17,value,0,0,0);}
