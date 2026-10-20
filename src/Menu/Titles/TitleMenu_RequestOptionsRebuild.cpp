#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(int *, unsigned int);
// Original: arm9/ov004 @ 0x0216DC60; symbol: func_ov004_0216dc60; size: 0x18.
extern "C" int TitleMenu_RequestOptionsRebuild(int *state) {
    Menu_QueueScriptEntry(state, 0x12d);
    return 0;
}
