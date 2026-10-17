#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" unsigned short data_0211214c;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x020D18A4; symbol: func_020d18a4; size: 0x2C.
extern "C" ARM void IPC_HandleChannelThirteenCompletion(unsigned a,unsigned b){if((b&63)==1){data_0211214c=1;return;}DisableInterruptsAndHaltForever();}
