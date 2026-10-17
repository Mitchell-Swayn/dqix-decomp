#include <globaldefs.h>
ARM
extern "C" int func_ov031_02209b58(void *object);
// Original: arm9/ov031 @ 0x0220A444; symbol: func_ov031_0220a444; size: 0x30.
extern "C" int IsObjectResultSevenThenSix(void *object) {
    if (func_ov031_02209b58(object) != 7)
        return 1;
    return func_ov031_02209b58(object) != 6;
}
