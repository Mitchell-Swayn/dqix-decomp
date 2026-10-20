#include <globaldefs.h>
#pragma optimize_for_size on
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101614; symbol: data_02101614.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21016e0; symbol: data_021016e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[], NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned short NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage[]; extern "C" void Network_HandleClientConnectionEvents(); extern "C" int WirelessCommand_SubmitOpcodeTwelveWithCachedBufferAndPayload(int,unsigned short*,const void*,int,unsigned short);extern "C" void Network_RecordWirelessErrorUnlessTerminal(int);
// Original: arm9/main @ 0x0202D224; symbol: func_0202d224; size: 0x80.
extern "C" ARM int Network_BeginStateThreeOperationUnlessAlreadyActive(){int state=*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16);if(state==4||state==6||*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)==5)return 1;*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=3;int result=WirelessCommand_SubmitOpcodeTwelveWithCachedBufferAndPayload((int)Network_HandleClientConnectionEvents,NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage,NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage,1,(unsigned short)(int)(*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+48)!=0));if(result==2)return 1;Network_RecordWirelessErrorUnlessTerminal(result);return 0;}
