#include <globaldefs.h>
ARM
extern "C" int System_ClearSharedPointerWhenWord2260IsOne();
extern "C" void Network_RequestWirelessPowerOff();
extern "C" int Network_RequestSharedStateSeven();
extern "C" void Network_RequestDcfDisconnect();
extern "C" int Network_DispatchSharedWirelessStateOperation();
extern "C" void GameState_SetSelectedStateWordFields(unsigned);
// Original: arm9/ov031 @ 0x0221425C; symbol: Network_DispatchSharedStateAndReportCompletion; size: 0x90.
extern "C" unsigned Network_GetWirelessLifecycleState();
extern "C" int Network_ProcessWirelessShutdown() {
 switch(Network_GetWirelessLifecycleState()) {
 case 0:return 1;case 1:System_ClearSharedPointerWhenWord2260IsOne();break;case 3:Network_RequestWirelessPowerOff();break;case 6:Network_RequestSharedStateSeven();break;case 9:Network_RequestDcfDisconnect();break;case 12:Network_DispatchSharedWirelessStateOperation();break;case 11:GameState_SetSelectedStateWordFields(0);return -1;
 }return 0;
}
