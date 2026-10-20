#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f226c; symbol: data_020f226c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111220; symbol: data_02111220.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short GXInit_UnknownRoleInitializedBytes;extern "C" unsigned short GXInit_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020C3898; symbol: func_020c3898; size: 0x3C.
extern "C" void Graphics_SaveDisplayModeAndClearDisplayModeBits() { volatile unsigned int* reg=(volatile unsigned int*)0x04000000;unsigned int old=*reg;GXInit_UnknownRoleInitializedBytes=0;GXInit_UnknownRoleZeroInitializedStorage=(old&0x30000)>>16;*reg=old&~0x30000; }
