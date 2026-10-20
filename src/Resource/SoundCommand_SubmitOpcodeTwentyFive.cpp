#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2104; symbol: func_020d2104; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeTwentyFive(unsigned a,unsigned b,unsigned c,unsigned d){SoundCommand_EnqueueOpcodeAndFourArguments(25,a,b,c,d);}
