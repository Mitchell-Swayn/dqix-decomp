#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02028D58; symbol: func_02028d58; size: 0x10.
void DebugText_SetPaletteIndex(unsigned int v){DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage[1]=v;}
}
