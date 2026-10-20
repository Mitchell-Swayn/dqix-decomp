#include <globaldefs.h>
// Original data: arm9/main @ 0x214e4c8; symbol: data_0214e4c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern char DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage[]; void WriteDisplayFlagsAndRefreshProtectedState(void*,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DAF9C; symbol: func_020daf9c; size: 0x38.
 void DisplayOverlay_ConfigureGlobalState(unsigned a,unsigned b,unsigned c,unsigned d) { WriteDisplayFlagsAndRefreshProtectedState(DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage,a,b,c,d); } }
