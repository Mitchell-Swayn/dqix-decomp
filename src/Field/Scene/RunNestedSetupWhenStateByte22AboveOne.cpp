#include <globaldefs.h>
ARM
extern "C" void Menu_DrawPartyPreviewPanel(unsigned int);
// Original: arm9/ov017 @ 0x021A1880; symbol: RunNestedSetupWhenStateByte22AboveOne; size: 0x24.
// When byte +0x22 exceeds one, calls nested setup on the nonzero word at +0x1C.
extern "C" void RunNestedSetupWhenStateByte22AboveOne(void *obj) {
    if (*((unsigned char *)obj + 0x22) > 1) {
        unsigned int value = *(unsigned int *)((char *)obj + 0x1c);
        if (value) Menu_DrawPartyPreviewPanel(value);
    }
}
