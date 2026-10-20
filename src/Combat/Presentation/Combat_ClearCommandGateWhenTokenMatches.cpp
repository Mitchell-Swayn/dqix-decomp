#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned short Combat_GetCommandBlockToken(void*);
extern "C" void Combat_SetCommandBlockToken(void*, unsigned short);
// Original: arm9/ov025 @ 0x021E3C3C; symbol: func_ov025_021e3c3c; size: 0x3C.
extern "C" int Combat_ClearCommandGateWhenTokenMatches(void* self) {
    if (*(unsigned short*)((char*)self + 8) == Combat_GetCommandBlockToken(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc))) {
        Combat_SetCommandBlockToken(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc), 0);
    }
    return 1;
}
