#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215C948; symbol: func_ov004_0215c948; size: 0x14.
extern "C" int Menu_EnterItemMarketOfferList(State *self) {
    Menu_QueueScriptEntry(self, 0x384);
    return 0;
}
