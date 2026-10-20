#include <globaldefs.h>
ARM
extern "C" void Window_ResetResourceTransfers(void *);
// Original: arm9/ov023 @ 0x021D8C94; symbol: func_ov023_021d8c94; size: 0x20.
extern "C" void PartyGrowthPanel_ResetActiveWindowTransfers(void *object) {
    unsigned char value = *(unsigned char *)((char *)object + 0x11a);
    if (value != 0 && value != 3)
        Window_ResetResourceTransfers((char *)object + 0x20);
}
