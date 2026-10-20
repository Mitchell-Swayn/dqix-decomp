#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
extern "C" int MBi_ReadyBeaconSendStatus();
extern "C" void MBi_InitSendFixedBeacon();
extern "C" void MBi_SendFixedGameInfoBeacon(void*,void*,void*);
extern "C" void MBi_InitSendVolatBeacon();
extern "C" void MBi_SendVolatBeacon(void*,void*,void*);
// Original: arm9/ov027 @ 0x021DAE40; symbol: Network_ProcessBeaconStateUntilPacketReady; size: 0x8c.
// Dispatches beacon state byte 24; initializes volatile send beacon and returns packet through state handlers.
extern "C" void Network_ProcessBeaconStateUntilPacketReady(void* a,void* b,void* c) {
 for(;;)switch(MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x24]) {
 case 0:case 1: if(!MBi_ReadyBeaconSendStatus())return;break;
 case 2:MBi_InitSendFixedBeacon();break;
 case 3:MBi_SendFixedGameInfoBeacon(a,b,c);return;
 case 4:MBi_InitSendVolatBeacon();break;
 case 5:MBi_SendVolatBeacon(a,b,c);return;
 case 6:break;
 }
}
