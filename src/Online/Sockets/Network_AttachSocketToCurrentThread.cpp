#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02203164; symbol: func_ov031_02203164; size: 0x14.
extern "C" void Network_AttachSocketToCurrentThread(unsigned int value) { *(unsigned int*)((char*)OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1] + 0xa4) = value; }
