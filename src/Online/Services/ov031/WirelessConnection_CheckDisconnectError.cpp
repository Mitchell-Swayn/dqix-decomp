#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void WirelessConnection_AdvanceFallback();
extern "C" unsigned System_IsGlobalStateHalfwordFourEqualSix();
extern "C" unsigned System_ReadObjectByte17ForContextByte9Range10To16();
extern "C" unsigned Network_GetWirelessLifecycleState();
extern "C" void OnlineError_SetStatusAndDetail(unsigned,unsigned);
// Original: arm9/ov031 @ 0x022123D4; symbol: WirelessConnection_CheckDisconnectError; size: 0x78.
// Advances optional transfer state and writes a state-dependent pair using progress clamped to 99.
extern "C" bool WirelessConnection_CheckDisconnectError() {
 WirelessConnection_AdvanceFallback();
 if(System_IsGlobalStateHalfwordFourEqualSix()) {
 unsigned progress=System_ReadObjectByte17ForContextByte9Range10To16();
 if(progress==255 || progress>99)progress=99;
 if(Network_GetWirelessLifecycleState()==11)OnlineError_SetStatusAndDetail(9,0xffff298c-progress);
 else OnlineError_SetStatusAndDetail(8,0xffff2d10-progress);
 return true;
 }
 return false;
}
