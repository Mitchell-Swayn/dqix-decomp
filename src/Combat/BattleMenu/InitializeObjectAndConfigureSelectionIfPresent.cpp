#include <globaldefs.h>
ARM
extern "C" void BattleMenu_ResetPartyCommandSelection(void *object, unsigned int mode);
extern "C" void BattleMenu_OpenMemberCommandGrid(void *object, unsigned int mode);
// Original: arm9/ov000 @ 0x02170FD0; symbol: func_ov000_02170fd0; size: 0x2C.
extern "C" void InitializeObjectAndConfigureSelectionIfPresent(void *object, unsigned int mode) {
    BattleMenu_ResetPartyCommandSelection(object, mode);
    if (*(void **)((unsigned char *)object + 0x38))
        BattleMenu_OpenMemberCommandGrid(object, mode);
}
