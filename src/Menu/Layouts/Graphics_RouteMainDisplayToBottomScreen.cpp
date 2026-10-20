#include <globaldefs.h>
extern "C" void Graphics_SetMainDisplayTopScreenRouting(unsigned);
// Original: arm9/ov011 @ 0x02187F68; symbol: func_ov011_02187f68; size: 0x14.
extern "C" unsigned Graphics_RouteMainDisplayToBottomScreen() { Graphics_SetMainDisplayTopScreenRouting(0); return 1; }
