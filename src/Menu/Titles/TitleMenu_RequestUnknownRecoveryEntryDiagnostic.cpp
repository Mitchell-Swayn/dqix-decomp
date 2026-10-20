#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DD04; symbol: func_ov004_0216dd04; size: 0x18.
extern "C" int TitleMenu_RequestUnknownRecoveryEntryDiagnostic(State *self) {
    Menu_QueueScriptEntry(self, 0x191);
    return 0;
}
