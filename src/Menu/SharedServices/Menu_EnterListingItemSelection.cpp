#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0215C228; symbol: func_ov004_0215c228; size: 0x14.
extern "C" int Menu_EnterListingItemSelection(void *self) {
    Menu_QueueScriptEntry(self, 0x6a);
    return 0;
}
