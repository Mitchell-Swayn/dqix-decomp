#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2102be0; symbol: data_02102be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2080 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[]; extern unsigned char NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" int WM_EndDataSharing(void*); extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned); extern "C" void Network_HandleShutdownCompletion(unsigned short*); extern "C" int WirelessCommand_SubmitOpcodeOne(void (*)(unsigned short*));
#pragma always_inline on
static inline bool start() { int status=WirelessCommand_SubmitOpcodeOne(Network_HandleShutdownCompletion); if(status==2)return true; Network_RecordWirelessErrorUnlessTerminal(status); return false; }
// Original: arm9/main @ 0x0202DD28; symbol: func_0202dd28; size: 0x70.
extern "C" void Network_RestartOperationAndTrackFailure() { if(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]==5){int status=WM_EndDataSharing(NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2); if(status)Network_RecordWirelessErrorUnlessTerminal(status);} NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3; if(!start())NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=10; }
