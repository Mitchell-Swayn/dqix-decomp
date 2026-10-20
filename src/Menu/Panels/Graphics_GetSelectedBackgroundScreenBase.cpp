#include <globaldefs.h>
ARM
extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);
// Original: arm9/ov023 @ 0x021DB2B8; symbol: func_ov023_021db2b8; size: 0x2C.
extern "C" unsigned int Graphics_GetSelectedBackgroundScreenBase(int mode, int layer) {
    if (mode == 1)
        return GetSubBG0ScreenBase();
    if (layer)
        return GetMainBG1ScreenBase();
    return GetMainBG2ScreenBase();
}
