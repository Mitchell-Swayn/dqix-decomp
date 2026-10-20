#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[]; extern "C" void Network_BeginDisconnectOperationAndHandleFailure(); extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void(*)()); extern "C" void Network_RecordWirelessErrorUnlessTerminal(int);
// Original: arm9/main @ 0x0202D54C; symbol: func_0202d54c; size: 0x38.
 extern "C" int Network_EndMultiplayerBeforeDisconnect(){ NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3; int r=WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(Network_BeginDisconnectOperationAndHandleFailure); if(r==2)return 1; Network_RecordWirelessErrorUnlessTerminal(r);return 0;}
