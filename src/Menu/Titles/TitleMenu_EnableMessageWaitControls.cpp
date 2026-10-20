#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov004 @ 0x0216E894; symbol: func_ov004_0216e894; size: 0x20.
extern "C" int TitleMenu_EnableMessageWaitControls(void) {
    unsigned char *pointer = (unsigned char *)TextContext_GetSharedInstance();
    pointer += 0x1000;
    *(unsigned char *)(pointer + 0x9CA) = 1;
    *(unsigned char *)(pointer + 0x9AF) = 1;
    return 0;
}
