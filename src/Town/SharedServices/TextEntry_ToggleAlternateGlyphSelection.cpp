#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EE68; symbol: func_ov003_0215ee68; size: 0x20.
extern "C" int TextEntry_ToggleAlternateGlyphSelection(unsigned char *object) {
    object[0x1e] = 1;
    object[0x20] = object[0x20] == 0;
    return 5;
}
