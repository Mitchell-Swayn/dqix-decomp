#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{short first;short unused[4];short ready;unsigned pad;unsigned phase;};extern "C" State NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;extern "C" void Network_HandlePeerJoinLeaveAndStartEvents();extern "C" int DispatchRequestWithModeOne(void(*)());extern "C" void Network_RecordWirelessErrorUnlessTerminal();
// Original: arm9/main @ 0x0202C958; symbol: func_0202c958; size: 0x54.
extern "C" ARM int Network_StartParentConnection(){if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.phase-4<=2)return 1;if(DispatchRequestWithModeOne(Network_HandlePeerJoinLeaveAndStartEvents)!=2){Network_RecordWirelessErrorUnlessTerminal();return 0;}NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.first=0;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.ready=1;return 1;}
