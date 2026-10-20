#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
extern "C" void MBi_ClearSendStatus(void);
// Original: arm9/ov027 @ 0x021DADF0; symbol: func_ov027_021dadf0; size: 0x2C.
extern "C" void Network_InitializeSendGameInfoStatus(void) {
    *(unsigned int *)(MBAddGameInfo_UnknownRoleZeroInitializedStorage + 0x18) = 0;
    *(unsigned int *)(MBAddGameInfo_UnknownRoleZeroInitializedStorage + 0x1C) = 0;
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x24] = 1;
    *(unsigned int *)(MBAddGameInfo_UnknownRoleZeroInitializedStorage + 0x14) = 0;
    MBi_ClearSendStatus();
}
