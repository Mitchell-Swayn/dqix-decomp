#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e598;
// Original: arm9/ov031 @ 0x02211848; symbol: func_ov031_02211848; size: 0x1C.
extern "C" int IsOverlayTaskAvailable(void) {
    return data_ov031_0224e598 != 0;
}
