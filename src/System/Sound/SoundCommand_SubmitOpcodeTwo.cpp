#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1E08; symbol: func_020d1e08; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeTwo(unsigned a,unsigned b,unsigned c,unsigned d){SoundCommand_EnqueueOpcodeAndFourArguments(2,a,b,c,d);}
