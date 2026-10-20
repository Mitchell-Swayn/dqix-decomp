#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
int WirelessCommand_ReadInitializedStatus();extern unsigned int *WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D46A8; symbol: func_020d46a8; size: 0x24.
unsigned int WMi_GetStatusAddress(){if(WirelessCommand_ReadInitializedStatus())return 0;return WMiCheckIdle_UnknownRoleZeroInitializedStorage[1][1];}
}
