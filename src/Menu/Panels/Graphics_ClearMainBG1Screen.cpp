#include <globaldefs.h>
ARM
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov023 @ 0x021DCD78; symbol: func_ov023_021dcd78; size: 0x18.
extern "C" void Graphics_ClearMainBG1Screen(void) {
    memset((void *)GetMainBG1ScreenBase(), 0, 0x800);
}
