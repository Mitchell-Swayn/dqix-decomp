#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d0c; symbol: data_ov031_02290d0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage;
extern "C" void Wireless_NotifyUnregisteredMatchingIdentifier(void*);
extern "C" void Wireless_RecordUsbAccessPointScanResults(void*);
extern "C" int CheckCurrentContextStatus();
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/ov031 @ 0x022376FC; symbol: HandleSuccessfulContextEvent; size: 0x90.
// Handles successful event26 subtype4/5 and updates pending-state byte for event2.
extern "C" void Wireless_HandleUsbAccessPointScanEvent(unsigned short* event){
 if(event[1])return;
 unsigned char* state=WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage;
 if(state[0x1b94]){if(event[0]==2)state[0x1b94]=2;return;}
 if(event[0]!=0x26)return;
 switch(event[4]){case 5:{if(state[0x1b96])Wireless_NotifyUnregisteredMatchingIdentifier(event);else Wireless_RecordUsbAccessPointScanResults(event);CheckCurrentContextStatus();break;}
 case 4:CheckCurrentContextStatus();break;
 default:DisableInterruptsAndHaltForever();break;}
}
