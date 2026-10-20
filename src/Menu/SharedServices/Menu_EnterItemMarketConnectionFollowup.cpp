#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);

// Original: arm9/ov004 @ 0x0215CC40; symbol: func_ov004_0215cc40; size: 0x18.
extern "C" int Menu_EnterItemMarketConnectionFollowup(void *self) {
    Menu_QueueScriptEntry(self, 0x3b1);
    return 0;
}
