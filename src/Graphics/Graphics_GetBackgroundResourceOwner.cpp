#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0203BD14; symbol: func_0203bd14; size: 0x10.
extern "C" unsigned int Graphics_GetBackgroundResourceOwner() { return *(unsigned int*)TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage; }
