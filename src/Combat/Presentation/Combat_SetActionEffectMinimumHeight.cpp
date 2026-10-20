#include <globaldefs.h>
ARM
extern "C" void Combat_SetMinimumEffectHeight(void*, short);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E6F20; symbol: Resource_ApplyInputHalfwordAtGlobalOffset22C; size: 0x24.
// Passes the signed halfword at input offset 8 to func_ov025_021ed110 using the global object at data_ov025_021ef988+0x0c, then returns one. Caller listing gives the target parameter as unsigned short; signed short declaration is needed to reproduce its ldrsh.
extern "C" int Combat_SetActionEffectMinimumHeight(short* p) { Combat_SetMinimumEffectHeight((char*)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x22c, p[4]); return 1; }
