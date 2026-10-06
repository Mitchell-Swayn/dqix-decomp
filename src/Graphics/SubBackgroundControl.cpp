#include <globaldefs.h>

#include "System/Graphics.h"

extern "C" ARM void func_ov020_0218cd64(unsigned int screenSize, unsigned int paletteMode,
                                         unsigned int screenBase, unsigned int characterBase,
                                         unsigned int colorMode)
{
    BG0CNTSUB = (BG0CNTSUB & 0x43) | (screenSize << 14) | (paletteMode << 7) |
                (screenBase << 8) | (characterBase << 2) | (colorMode << 13);
}
