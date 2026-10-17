#include <globaldefs.h>
#include "System/IPC.h"
extern "C" void WaitByLoop(int);
// Original: arm9/main @ 0x020D1294; symbol: func_020d1294; size: 0x50.
extern "C" ARM void IPC_SendChannelFourteenCommandUntilAccepted(int command,int delay){if(SendCommandToArm7(14,command,false)==0)return;do{WaitByLoop(delay);}while(SendCommandToArm7(14,command,false)!=0);}
