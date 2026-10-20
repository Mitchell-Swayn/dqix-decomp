#include <globaldefs.h>
ARM
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Filesystem_RemoveStoredTasksAndResetLoadFlags(void *self);
// Original: arm9/ov023 @ 0x021DCD90; symbol: func_ov023_021dcd90; size: 0x64.
extern "C" void Graphics_UpdateMainBackgroundScreens(unsigned char *self, unsigned int enabled) {
    if ((((unsigned int)self[0x79B] << 30) >> 31) != 0 && enabled == 0) {
        memset((void *)GetMainBG1ScreenBase(), 0, 0x800);
        memset((void *)GetMainBG2ScreenBase(), 0, 0x800);
        Filesystem_RemoveStoredTasksAndResetLoadFlags(self);
    }
    self[0x79B] = (unsigned char)((self[0x79B] & ~2u) | ((enabled & 1) << 1));
}
