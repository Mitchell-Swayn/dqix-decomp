#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2105254; symbol: data_02105254.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char GraphicsGetGlobalBackgroundState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0203B628; symbol: func_0203b628; size: 0xC.
void *Graphics_GetGlobalBackgroundState(){return GraphicsGetGlobalBackgroundState_UnknownRoleZeroInitializedStorage;}
}
