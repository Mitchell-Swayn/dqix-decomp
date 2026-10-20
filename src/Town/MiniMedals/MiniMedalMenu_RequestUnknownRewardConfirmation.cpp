#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02168268; symbol: func_ov004_02168268; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownRewardConfirmation(void *self) {
    Menu_QueueScriptEntry(self, 0x97);
    return 0;
}
