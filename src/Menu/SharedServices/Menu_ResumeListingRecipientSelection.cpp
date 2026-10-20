#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x0215C250; symbol: func_ov004_0215c250; size: 0x18.
extern "C" unsigned Menu_ResumeListingRecipientSelection(void *self) {
    Menu_QueueScriptEntry(self, 0x396);
    return 0;
}
