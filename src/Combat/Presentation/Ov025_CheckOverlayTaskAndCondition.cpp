#include <globaldefs.h>
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" int Combat_AreTimedPresentationRecordsIdle(unsigned char*);
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" int TestCombatantState4OrDisplayKey2();
// Original: arm9/ov025 @ 0x021E62C8; symbol: func_ov025_021e62c8; size: 0x3C.
extern "C" ARM int Ov025_CheckOverlayTaskAndCondition() {
    unsigned char* object = *(unsigned char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    if (!Combat_AreTimedPresentationRecordsIdle(object + 0x22c)) return 0;
    BattleScene_GetActiveInstance();
    return !TestCombatantState4OrDisplayKey2();
}
