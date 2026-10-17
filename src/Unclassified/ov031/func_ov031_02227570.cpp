#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02250c0c[];
// Original: arm9/ov031 @ 0x02227570; symbol: func_ov031_02227570; size: 0x1C.
extern "C" unsigned func_ov031_02227570(unsigned mask) {
    return (mask & (data_ov031_02250c0c[2] >> 4)) != 0;
}
