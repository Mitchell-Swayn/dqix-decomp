#include <globaldefs.h>
ARM
struct NetworkState{unsigned short first;unsigned short pad[4];unsigned short enabled;unsigned short pad2;unsigned short pending;unsigned mode;unsigned words[7];unsigned field30;unsigned field34;unsigned field38;unsigned field3c;void *callback;unsigned word44;unsigned word48;};
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" NetworkState NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2101614; symbol: data_02101614.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101640; symbol: data_02101640.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21016e0; symbol: data_021016e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101b80; symbol: data_02101b80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2103400; symbol: data_02103400.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3840 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2[],NetworkScanNextAllowedChannel_UnknownRoleZeroInitializedStorage_Variant2[],NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage[],NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage[],NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void Network_HaltOnWirelessFifoError();
extern "C" void Network_HandleModeValidationCompletion();
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(void*,unsigned,void*);
extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned);

// Original: arm9/main @ 0x0202D9E0; symbol: Network_BeginModeValidationRequest; size: 0x100.
extern "C" int Network_BeginModeValidationRequest(){
if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.pending)return 0;
 if(!NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.callback)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.callback=(void*)Network_HaltOnWirelessFifoError;
 NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.words[6]=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.field38=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.words[5]=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.first=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.enabled=1;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.word48=0;*(int*)NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2=0;*(short*)(NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2+4)=0;
 VectorizedMemset(NetworkScanNextAllowedChannel_UnknownRoleZeroInitializedStorage_Variant2,0,0x400);VectorizedMemset(NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage,0,0xc0);VectorizedMemset(NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage,0,24);
 NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.words[4]=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.mode=3;
 int result;if(WirelessCommand_InvokeFourArgumentRequestWithZeroMode(NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant3,(unsigned)Network_HandleModeValidationCompletion,(void*)2)==2)result=1;
 else{((void(*)(void))Network_RecordWirelessErrorUnlessTerminal)();NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.mode=10;result=0;}
 if(!result)return 0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.pending=1;return 1;
}
