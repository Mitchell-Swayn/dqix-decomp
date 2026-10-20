#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(int *, unsigned int);
// Original: arm9/ov004 @ 0x02168060; symbol: func_ov004_02168060; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownChoicePhase(int *state) {
    Menu_QueueScriptEntry(state, 0x6e);
    return 0;
}
