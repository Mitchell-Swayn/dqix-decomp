#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216A7FC; symbol: func_ov004_0216a7fc; size: 0x14.
extern "C" int Menu_RequestSavedSummaryFollowup(void *self) {
    Menu_QueueScriptEntry(self, 0x54);
    return 0;
}
