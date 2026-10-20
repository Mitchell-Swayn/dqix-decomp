#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1EBC; symbol: func_020d1ebc; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeNine(unsigned a,unsigned b,unsigned c){SoundCommand_EnqueueOpcodeAndFourArguments(9,a,b,c,0);}
