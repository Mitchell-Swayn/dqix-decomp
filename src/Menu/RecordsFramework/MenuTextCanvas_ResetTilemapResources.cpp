#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ResetWithTilemapResource(int);

// Original: arm9/ov023 @ 0x021F8130; symbol: func_ov023_021f8130; size: 0x10.
extern "C" void MenuTextCanvas_ResetTilemapResources(int object) {
    TextCanvas_ResetWithTilemapResource(object + 0x20);
}
