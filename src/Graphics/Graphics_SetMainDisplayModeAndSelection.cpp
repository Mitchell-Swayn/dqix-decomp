#include <globaldefs.h>
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
// Original: arm9/main @ 0x020C391C; symbol: func_020c391c; size: 0x68.
extern "C" ARM void Graphics_SetMainDisplayModeAndSelection(unsigned short mode,unsigned flags,int selection){unsigned short enabled=GXInit_UnknownRoleInitializedBytes;unsigned control=*(volatile unsigned*)0x04000000;GXInit_UnknownRoleZeroInitializedStorage=mode;if(!enabled)mode=0;*(volatile unsigned*)0x04000000=((control&0xfff0fff0)|((unsigned)mode<<16))|flags|(selection<<3);if(!GXInit_UnknownRoleZeroInitializedStorage)GXInit_UnknownRoleInitializedBytes=0;}
