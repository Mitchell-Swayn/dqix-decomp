#include <globaldefs.h>
ARM
extern "C" void Window_ResetResourceTransfers(void *);
// Original: arm9/ov023 @ 0x021E76A8; symbol: func_ov023_021e76a8; size: 0x1C.
extern "C" void Menu_ResetSecondaryPanelResourceTransfers(void *p) {
    if (*(unsigned int *)((unsigned char *)p + 0x5dc))
        Window_ResetResourceTransfers((unsigned char *)p + 0x78);
}
