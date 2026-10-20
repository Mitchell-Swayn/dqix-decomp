#include <globaldefs.h>
ARM
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void Network_ConsumeSharedValueAndDispatch(int, int, int, unsigned int);
extern "C" void StartSharedWirelessTransition(void);
// Original: arm9/ov031 @ 0x0220E1E0; symbol: System_DispatchRecordByType; size: 0x78.
// Dispatches record type 0 to one handler, type 1 to another, and other supported values to the default handler.
extern "C" void Network_HandleEndScanResult(void *record) {
 switch (*(unsigned short *)((char *)record + 2)) {
 case 0:
  Network_SetWirelessStateAndConnectionAlarm(3);
  Network_ConsumeSharedValueAndDispatch(0, 0, 0, 0x783);
  break;
 case 1:
  StartSharedWirelessTransition();
  break;
 case 2:
 case 3:
 case 4:
 default:
  Network_SetWirelessStateAndConnectionAlarm(0xb);
  Network_ConsumeSharedValueAndDispatch(7, 0, 0, 0x793);
  break;
 }
}
