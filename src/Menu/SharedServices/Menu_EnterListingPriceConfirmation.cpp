#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0215C23C; symbol: func_ov004_0215c23c; size: 0x14.
extern "C" int Menu_EnterListingPriceConfirmation(void *self) { Menu_QueueScriptEntry(self, 0x6c); return 0; }
