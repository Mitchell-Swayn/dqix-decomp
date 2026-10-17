#include <globaldefs.h>
ARM
extern "C" void *ReadOverlayControlSecondWord(void);
extern "C" void func_ov000_02163710(void *, int);
extern "C" void func_ov000_021636ac(void *, int);
// Original: arm9/ov025 @ 0x021E82E4; symbol: func_ov025_021e82e4; size: 0x30.
extern "C" int UpdateOverlayControlFromByte(void *parameter) {
    void *control = ReadOverlayControlSecondWord();
    int enabled = *((unsigned char *)parameter + 8);
    if (enabled != 0)
        func_ov000_02163710(control, 1);
    else
        func_ov000_021636ac(control, enabled);
    return 1;
}
