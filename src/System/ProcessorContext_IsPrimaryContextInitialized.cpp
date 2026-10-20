#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21112ec; symbol: data_021112ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ProcessorContextIsPrimaryContextInitialized_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020C75A4; symbol: func_020c75a4; size: 0x10.
extern "C" unsigned int ProcessorContext_IsPrimaryContextInitialized() { return *(unsigned int*)(ProcessorContextIsPrimaryContextInitialized_UnknownRoleZeroInitializedStorage+0); }
