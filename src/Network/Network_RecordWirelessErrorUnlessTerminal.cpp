#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct A{char pad[0x10];unsigned int mode;char pad2[0x34];unsigned int value;};extern "C" {extern A NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0202C848; symbol: func_0202c848; size: 0x1C.
void Network_RecordWirelessErrorUnlessTerminal(unsigned int v){if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.mode-9u>1u)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.value=v;} }
