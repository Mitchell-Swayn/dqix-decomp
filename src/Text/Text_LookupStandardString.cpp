#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x2153694; symbol: data_02153694.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TextLookupStandardString_UnknownRoleZeroInitializedStorage[];extern "C" void* ResourceStringTable_GetTextByKey(void*,unsigned);
// Original: arm9/main @ 0x020E51CC; symbol: func_020e51cc; size: 0x18.
extern "C" void* Text_LookupStandardString(unsigned key){return ResourceStringTable_GetTextByKey(TextLookupStandardString_UnknownRoleZeroInitializedStorage,key);}
