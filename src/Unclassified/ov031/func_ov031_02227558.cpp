#include <globaldefs.h>
ARM
struct Nibble { unsigned value : 4; };
extern "C" unsigned data_ov031_02250c0c[];
// Original: arm9/ov031 @ 0x02227558; symbol: func_ov031_02227558; size: 0x18.
extern "C" unsigned func_ov031_02227558(void) {
    return ((struct Nibble *)&data_ov031_02250c0c[2])->value;
}
