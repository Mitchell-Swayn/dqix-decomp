#include <globaldefs.h>
ARM
// Original data: arm9/ov024 @ 0x2200154; symbol: data_ov024_02200154.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAIPrepareTurnActionEvaluation_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov024 @ 0x021F67F8; symbol: Unclassified_ClearFourSharedStateBytes; size: 0x28.
// Clears the four bytes starting at data_ov024_02200154; caller is combat turn processing.
extern "C" void BattleAI_ResetPartyActionAvailabilityCache(void) {
    for (int i = 0; i < 4; ++i) BattleAIPrepareTurnActionEvaluation_UnknownRoleZeroInitializedStorage[i] = 0;
}
