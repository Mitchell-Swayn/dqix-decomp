#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D212C; symbol: func_020d212c; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeSixWithFourArguments(unsigned a,unsigned b,unsigned c,unsigned d){SoundCommand_EnqueueOpcodeAndFourArguments(6,a,b,c,d);}
