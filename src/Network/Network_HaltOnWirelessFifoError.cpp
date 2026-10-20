#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Input {unsigned short a,mode;};struct State {char pad[16];unsigned state;};extern "C" State NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x0202DAE0; symbol: func_0202dae0; size: 0x28.
extern "C" void Network_HaltOnWirelessFifoError(Input* input) {if(input->mode!=8)return;NetworkGetAssociationId_UnknownRoleZeroInitializedStorage.state=9;DisableInterruptsAndHaltForever();}
