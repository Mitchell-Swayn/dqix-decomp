#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x21023c0; symbol: data_021023c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2080 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2102be0; symbol: data_02102be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2080 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NetworkHandleClientMultiplayerCallback_UnknownRoleZeroInitializedStorage[],NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned);
extern "C" int Network_EndMultiplayerBeforeParentShutdown();
extern "C" int Network_RequestPeerDiscoveryStop();
extern "C" int Network_EndMultiplayerBeforeDisconnect();
extern "C" void Network_RestartOperationAndTrackFailure();
extern "C" int WM_EndDataSharing(int);
extern "C" int WM_EndKeySharing(void*);
// Original: arm9/main @ 0x0202DD98; symbol: func_0202dd98; size: 0x178.
extern "C" void Network_RestartCallbackForCurrentOperation() {
 int state=NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4];
 if(state==1)return;
 if(state==2) {
  if(!Network_RequestPeerDiscoveryStop())Network_RestartOperationAndTrackFailure();
  return;
 }
 if(state!=6 && state!=5 && state!=4) {
  NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3;
  Network_RestartOperationAndTrackFailure();return;
 }
 NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3;
 switch(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[13]) {
 case 3: {
  int result;
  if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]!=6)result=0;
  else {
   NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3;
   if((result=WM_EndKeySharing(NetworkHandleClientMultiplayerCallback_UnknownRoleZeroInitializedStorage))!=0) { Network_RecordWirelessErrorUnlessTerminal(result);result=0; }
   else { if(!Network_EndMultiplayerBeforeDisconnect())result=0;else result=1; }
  }
  if(!result)Network_RestartOperationAndTrackFailure();
  break;
 }
 case 5:
  if(WM_EndDataSharing((int)NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2)){Network_RestartOperationAndTrackFailure();break;}
 case 1:
  if(!Network_EndMultiplayerBeforeDisconnect())Network_RestartOperationAndTrackFailure();
  break;
 case 2: {
  int result;
  if((result=WM_EndKeySharing(NetworkHandleClientMultiplayerCallback_UnknownRoleZeroInitializedStorage))!=0) {Network_RecordWirelessErrorUnlessTerminal(result);result=0;}
  else if(Network_EndMultiplayerBeforeParentShutdown())result=1;
  else {Network_RestartOperationAndTrackFailure();result=0;}
  if(!result)Network_RestartOperationAndTrackFailure();
  break;
 }
 case 4:
  if(WM_EndDataSharing((int)NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2)){Network_RestartOperationAndTrackFailure();break;}
 case 0:
  if(!Network_EndMultiplayerBeforeParentShutdown())Network_RestartOperationAndTrackFailure();
  break;
 }
}
