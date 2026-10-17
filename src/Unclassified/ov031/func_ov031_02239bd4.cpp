#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02290d18;
// Original: arm9/ov031 @ 0x02239BD4; symbol: func_ov031_02239bd4; size: 0x14.
extern "C" unsigned func_ov031_02239bd4(void) {
    unsigned *object = *(unsigned **)((char *)&data_ov031_02290d18 + 4);
    return *(unsigned short *)((char *)object + 0x52);
}
