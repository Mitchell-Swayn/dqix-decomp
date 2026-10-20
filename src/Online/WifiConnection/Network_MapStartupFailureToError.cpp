#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022143A8; symbol: func_ov031_022143a8; size: 0x44.
extern "C" int Network_MapStartupFailureToError(unsigned int type) {
    switch (type) {
    case 1: return -9;
    case 0: return -10;
    case 2: return -8;
    case 3: return -7;
    default: return 0;
    }
}
