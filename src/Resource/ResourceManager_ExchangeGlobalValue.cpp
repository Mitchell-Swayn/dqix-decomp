#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BD42C; symbol: func_020bd42c; size: 0x18.
extern "C" unsigned int ResourceManager_ExchangeGlobalValue(unsigned int value) { unsigned int old=*(unsigned int*)NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage; *(unsigned int*)NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage=value; return old; }
