#include <globaldefs.h>

#include "System/Graphics.h"

extern "C" ARM void func_ov023_021ec454(unsigned int screenSize, unsigned int paletteMode,
                                         unsigned int screenBase, unsigned int characterBase)
{
    BG2CNT = (BG2CNT & 0x43) | (screenSize << 14) | (paletteMode << 7) |
             (screenBase << 8) | (characterBase << 2);
}
