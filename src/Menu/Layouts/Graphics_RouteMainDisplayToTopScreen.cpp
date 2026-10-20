#include <globaldefs.h>
extern "C" void Graphics_SetMainDisplayTopScreenRouting(unsigned);
// Original: arm9/ov011 @ 0x02187F38; symbol: func_ov011_02187f38; size: 0x14.
extern "C" unsigned Graphics_RouteMainDisplayToTopScreen() { Graphics_SetMainDisplayTopScreenRouting(1); return 1; }
