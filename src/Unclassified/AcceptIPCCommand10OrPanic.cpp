#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" unsigned short data_02111668;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x020C9890; symbol: func_020c9890; size: 0x34.
extern "C" ARM void AcceptIPCCommand10OrPanic(int ignored,unsigned message){unsigned short command=(message&0x7f00)>>8;if(command==0x10){data_02111668=1;return;}DisableInterruptsAndHaltForever();}
