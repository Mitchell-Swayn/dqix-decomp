#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" {
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void *DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02029088; symbol: func_02029088; size: 0x24.
void Graphics_CleanInvalidateCharacterBuffer(){void *p=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;if(p)CleanInvalidateCacheRange(p,0x6000);}
}
