#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetAndApplyGlobalConfiguration(unsigned int);
extern "C" void BattleMenu_ResetMemberCommandState(char *);
// Original: arm9/ov000 @ 0x02170054; symbol: func_ov000_02170054; size: 0x24.
// Applies the graphics reset to embedded configurations at 0x50 and 0x68, then resets the record at offset 8.
extern "C" void BattleMenu_ReleaseMemberTextAndResetCommand(void *p) {
    Graphics_ResetAndApplyGlobalConfiguration((unsigned int)p + 0x50);
    Graphics_ResetAndApplyGlobalConfiguration((unsigned int)p + 0x68);
    BattleMenu_ResetMemberCommandState((char *)p + 8);
}
