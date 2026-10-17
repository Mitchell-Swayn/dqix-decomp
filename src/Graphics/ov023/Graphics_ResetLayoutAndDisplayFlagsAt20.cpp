#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(char *p);
// Original: arm9/ov023 @ 0x021F8120; symbol: func_ov023_021f8120; size: 0x10.
extern "C" void Graphics_ResetLayoutAndDisplayFlagsAt20(char *canvas) {
    TextCanvas_ResetLayoutAndDisplayFlags(canvas + 0x20);
}
