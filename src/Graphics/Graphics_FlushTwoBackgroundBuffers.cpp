#include <globaldefs.h>
#include <System/Cache.h>
extern "C" {
// Original data: arm9/main @ 0x21052b4; symbol: data_021052b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21056b4; symbol: data_021056b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant5[];extern char GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0203BD88; symbol: func_0203bd88; size: 0x28.
void Graphics_FlushTwoBackgroundBuffers(){CleanInvalidateCacheRange(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant5,0x400);CleanInvalidateCacheRange(GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage,0x400);}
}
