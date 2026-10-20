#include <globaldefs.h>
ARM
extern "C" int OverlayLoader_GetSecondarySelectionOrMinusOne(void);
extern "C" void BattleScene_ResetCommandSelectionAndRestoreFlags(char *state);
// Original: arm9/ov000 @ 0x02163D94; symbol: func_ov000_02163d94; size: 0x20.
extern "C" void CombatScene_ResetPartySelectionIfActive(char *state) {
    if (OverlayLoader_GetSecondarySelectionOrMinusOne() == 3)
        BattleScene_ResetCommandSelectionAndRestoreFlags(state);
}
