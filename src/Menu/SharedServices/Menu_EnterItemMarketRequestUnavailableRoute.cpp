#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0215C95C; symbol: func_ov004_0215c95c; size: 0x18.
extern "C" int Menu_EnterItemMarketRequestUnavailableRoute(void *self) { Menu_QueueScriptEntry(self, 0x395); return 0; }
