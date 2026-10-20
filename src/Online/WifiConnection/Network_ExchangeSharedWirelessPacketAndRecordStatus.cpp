#include <globaldefs.h>
ARM
struct Global { void (*log)(unsigned,const char*); unsigned char* object; };
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Global WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
extern "C" char Network_ExchangeSharedWirelessPacketAndRecordStatus_TextDWCiMOVWHStepDataSharingWarningNoChild[];
extern "C" char Network_ExchangeSharedWirelessPacketAndRecordStatus_TextDWCiMOVWHStepDataSharingWarningNoDataSet[];
extern "C" int Network_ExchangeQueuedWirelessPacket(unsigned char*,void*,void*);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
// Original: arm9/ov031 @ 0x0223A2B0; symbol: func_ov031_0223a2b0; size: 0xA8.
extern "C" int Network_ExchangeSharedWirelessPacketAndRecordStatus(void* send) {
 unsigned char* self=WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.object;
 int result=Network_ExchangeQueuedWirelessPacket(self+0x13e0,send,self+0x1c00);
 if(result==7) {
  if(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.log) WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.log(0x8000000,Network_ExchangeSharedWirelessPacketAndRecordStatus_TextDWCiMOVWHStepDataSharingWarningNoChild);
  return 0;
 }
 if(result==5) {
  if(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.log) WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.log(0x8000000,Network_ExchangeSharedWirelessPacketAndRecordStatus_TextDWCiMOVWHStepDataSharingWarningNoDataSet);
  WirelessHost_StoreErrorUnlessTerminal(result);
  return 0;
 }
 if(!result) return 1;
 WirelessHost_StoreErrorUnlessTerminal(result);
 return 0;
}
