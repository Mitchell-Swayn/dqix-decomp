#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State { unsigned short a,flag; }; struct Control { char pad[16]; int state; }; extern "C" Control NetworkGetAssociationId_UnknownRoleZeroInitializedStorage; extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned); extern "C" int Network_StartParentConnection(unsigned);
// Original: arm9/main @ 0x0202C918; symbol: func_0202c918; size: 0x40.
extern "C" void Network_HandleParentConfigurationCompletion(State* self) { unsigned flag=self->flag; if(flag) { Network_RecordWirelessErrorUnlessTerminal(flag); NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state=9; } else { if(!Network_StartParentConnection(flag))NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state=9; } }
