#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E812C; symbol: func_ov025_021e812c; size: 0x1C.
extern "C" unsigned int Combat_SetPresentationOptionAt228(unsigned char* p) { *(unsigned int*)((char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x228) = p[8]; return 1; }
