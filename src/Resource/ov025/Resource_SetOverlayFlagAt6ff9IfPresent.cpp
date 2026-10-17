#include <globaldefs.h>
ARM
extern "C" void *ReadOverlayControlSecondWord(void);
// Original: arm9/ov025 @ 0x021E88B8; symbol: func_ov025_021e88b8; size: 0x20.
extern "C" int Resource_SetOverlayFlagAt6ff9IfPresent(void) {
    char *control = (char *)ReadOverlayControlSecondWord();
    if (control)
        *(unsigned char *)(control + 0x6ff9) = 1;
    return 1;
}
