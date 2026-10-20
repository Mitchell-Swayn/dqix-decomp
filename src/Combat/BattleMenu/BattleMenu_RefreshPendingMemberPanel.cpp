#include <globaldefs.h>
ARM
extern "C" void BattleMenu_RefreshExistingPanel(void*, void*, int, unsigned, void*, int);
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov000 @ 0x2183ff0; symbol: data_ov000_02183ff0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[];
// Original: arm9/ov000 @ 0x02170078; symbol: Object_DispatchAndClearPendingActionState; size: 0x64.
// For nonnegative state byte self +0x43D, dispatches through the shared data pointers when the object slot is present, then stores -1; negative state returns without rewriting it. Exact instruction match.
extern "C" void BattleMenu_RefreshPendingMemberPanel(void* self) {
    signed char state = *(signed char*)((char*)self + 0x43D);
    if (state >= 0) {
        if (BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2] != 0)
            BattleMenu_RefreshExistingPanel((void*)BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2], self, state, BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0], (void*)BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1], 1);
        *(signed char*)((char*)self + 0x43D) = -1;
    }
}
