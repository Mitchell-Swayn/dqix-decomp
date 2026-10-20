#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x02159B74; symbol: func_ov004_02159b74; size: 0x18.
extern "C" int Menu_EnterPurchaseQuantityFollowup(State *self) {
    Menu_QueueScriptEntry(self, 0x2368);
    return 0;
}
