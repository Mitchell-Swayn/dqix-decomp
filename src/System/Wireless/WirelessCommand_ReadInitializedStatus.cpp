#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D41E8; symbol: func_020d41e8; size: 0x1C.
int WirelessCommand_ReadInitializedStatus(){if(WMiCheckIdle_UnknownRoleZeroInitializedStorage[0]!=0)return 0;else return 3;}
}
