#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(char *p);
// Original: arm9/ov023 @ 0x021F8120; symbol: func_ov023_021f8120; size: 0x10.
extern "C" void MenuTextCanvas_ResetLayoutAndDisplayFlags(char *canvas) {
    TextCanvas_ResetLayoutAndDisplayFlags(canvas + 0x20);
}
