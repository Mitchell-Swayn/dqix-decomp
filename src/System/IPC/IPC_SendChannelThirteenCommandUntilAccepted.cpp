#include <globaldefs.h>
#include <System/IPC.h>
extern "C" void WaitByLoop(int);
#pragma optimization_level 4
// Original: arm9/main @ 0x020D1564; symbol: func_020d1564; size: 0x50.
extern "C" ARM void IPC_SendChannelThirteenCommandUntilAccepted(int a){if(SendCommandToArm7(13,a,false)){do{WaitByLoop(1);}while(SendCommandToArm7(13,a,false));}}
