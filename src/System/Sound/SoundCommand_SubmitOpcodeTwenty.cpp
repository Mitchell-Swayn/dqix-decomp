#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1FF0; symbol: func_020d1ff0; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeTwenty(unsigned a,unsigned b,unsigned c){SoundCommand_EnqueueOpcodeAndFourArguments(20,a,b,c,0);}
