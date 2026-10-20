#include <globaldefs.h>
ARM
extern "C" int OverlayLoader_GetSecondarySelectionOrMinusOne(void);
extern "C" void BattleScene_RemovePartyMemberAndRepairOwnership(char *, int, int);
// Original: arm9/ov000 @ 0x02163B14; symbol: System_ForwardStateAndIndexWhenStackEntryIsThree; size: 0x2C.
// When the last global stack entry equals 3, forwards state and index to the overlay handler with mode 1.
extern "C" void System_ForwardStateAndIndexWhenStackEntryIsThree(char *state, int index) {
    if (OverlayLoader_GetSecondarySelectionOrMinusOne() == 3)
        BattleScene_RemovePartyMemberAndRepairOwnership(state, index, 1);
}
