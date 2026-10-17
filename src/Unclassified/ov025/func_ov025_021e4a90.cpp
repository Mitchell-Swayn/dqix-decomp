#include <globaldefs.h>
ARM
extern "C" unsigned data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E4A90; symbol: func_ov025_021e4a90; size: 0x1C.
extern "C" unsigned func_ov025_021e4a90(void) {
    data_ov025_021ef988[7] |= 0x100;
    return 1;
}
