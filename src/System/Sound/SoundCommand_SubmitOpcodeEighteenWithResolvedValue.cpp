#include <globaldefs.h>
ARM
extern "C" unsigned WriteIndexedPairAndIncrementSerial(unsigned,unsigned,unsigned); extern "C" void AcquireCommandEntryAndStoreFiveValues(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1F70; symbol: func_020d1f70; size: 0x40.
 extern "C" void SoundCommand_SubmitOpcodeEighteenWithResolvedValue(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){unsigned v=WriteIndexedPairAndIncrementSerial(a,d,e);AcquireCommandEntryAndStoreFiveValues(18,a,b,c,v);}
