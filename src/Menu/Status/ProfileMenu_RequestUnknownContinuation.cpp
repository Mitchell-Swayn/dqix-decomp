#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(int *, unsigned int);
// Original: arm9/ov004 @ 0x0216A5FC; symbol: func_ov004_0216a5fc; size: 0x14.
extern "C" int ProfileMenu_RequestUnknownContinuation(int *state) {
    Menu_QueueScriptEntry(state, 0x52);
    return 0;
}
