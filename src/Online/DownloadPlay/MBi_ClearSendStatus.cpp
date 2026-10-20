#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DAE1C; symbol: func_ov027_021dae1c; size: 0x24.
extern "C" void MBi_ClearSendStatus(void) {
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x25] = 0;
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x26] = 0;
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x27] = 0;
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x28] = 0;
    MBAddGameInfo_UnknownRoleZeroInitializedStorage[0x29] = 0;
}
