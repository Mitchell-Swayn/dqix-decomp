#include <globaldefs.h>
#include <System/DMA.h>
extern "C" int DrainPendingCommandsResetDMAAndHalt();
extern "C" void OS_SpinWait(unsigned);
extern "C" void IPC_SendChannelFourteenCommandUntilAccepted(unsigned,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x020D11A8; symbol: func_020d11a8; size: 0x8C.
extern "C" void ResetDMAAndProcessSharedHardwareStatus() {bool active=true;ResetDMAChannel(0);ResetDMAChannel(1);ResetDMAChannel(2);ResetDMAChannel(3);if((int)(*(volatile unsigned short*)0x027fffa8&0x8000)>>15){int state=DrainPendingCommandsResetDMAAndHalt();if(state==4)do{OS_SpinWait(0xa3a47);state=DrainPendingCommandsResetDMAAndHalt();}while(state==4);if(state==0)active=false;}if(active)IPC_SendChannelFourteenCommandUntilAccepted(1,1);DisableInterruptsAndHaltForever();}
