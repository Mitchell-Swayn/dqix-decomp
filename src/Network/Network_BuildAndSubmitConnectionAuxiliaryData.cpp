#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
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
// Original data: arm9/main @ 0x21016e0; symbol: data_021016e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
ARM extern unsigned char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[],NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage[],NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage[]; void Network_HandleConnectionAuxiliaryDataCompletion(); int System_ValidateModeZeroThroughThreeAndDispatchCommandTwenty(void(*)(),int,void*); void Network_RecordWirelessErrorUnlessTerminal(int); struct State { char pad[16]; volatile int value; char gap[28]; int(*callback)(void*,void*); };
// Original: arm9/main @ 0x0202D180; symbol: func_0202d180; size: 0x64.
 int Network_BuildAndSubmitConnectionAuxiliaryData() { ((State*)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage)->value=3; int (*callback)(void*,void*)=((State*)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage)->callback; int result=callback(NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage,NetworkConfigureStateFromMode_UnknownRoleZeroInitializedStorage); result=System_ValidateModeZeroThroughThreeAndDispatchCommandTwenty(Network_HandleConnectionAuxiliaryDataCompletion,result,NetworkHandleInitialCallbackAndErrorState_UnknownRoleZeroInitializedStorage); if(result==2)return 1;Network_RecordWirelessErrorUnlessTerminal(result);((State*)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage)->value=9;return 0; }
}
