#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101600; symbol: data_02101600.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101640; symbol: data_02101640.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{char pad[16];int status;char pad2[40];unsigned(*callback)(void*,void*,State*,int);};extern "C" State NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;extern "C" char NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage[],NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" void Network_RecordWirelessErrorUnlessTerminal();extern "C" int Network_StartParentConnection();extern "C" void Network_HandleParentConfigurationCompletion();extern "C" int System_ValidateModeZeroThroughThreeAndDispatchCommandTwenty(void(*)(),unsigned,void*);
// Original: arm9/main @ 0x0202C864; symbol: func_0202c864; size: 0xB4.
extern "C" ARM void Network_HandleInitialCallbackAndErrorState(unsigned short* p){if(p[1]){Network_RecordWirelessErrorUnlessTerminal();NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status=9;return;}if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.callback){NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status=3;unsigned value=NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.callback(NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage,NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2,&NetworkGetAssociationId_UnknownRoleZeroInitializedStorage,3);int success;if(System_ValidateModeZeroThroughThreeAndDispatchCommandTwenty(Network_HandleParentConfigurationCompletion,value,NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage)==2)success=1;else{Network_RecordWirelessErrorUnlessTerminal();NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status=9;success=0;}if(!success)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status=9;}else if(!Network_StartParentConnection())NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.status=9;}
