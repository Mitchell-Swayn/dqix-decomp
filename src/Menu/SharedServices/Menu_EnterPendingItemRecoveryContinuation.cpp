#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0215B7E0; symbol: func_ov004_0215b7e0; size: 0x18.
extern "C" int Menu_EnterPendingItemRecoveryContinuation(void *self) {
    Menu_QueueScriptEntry(self, 0x3a5);
    return 0;
}
