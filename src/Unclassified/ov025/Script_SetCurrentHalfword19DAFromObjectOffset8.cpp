#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov025 @ 0x021E8550; symbol: func_ov025_021e8550; size: 0x1C.
extern "C" int Script_SetCurrentHalfword19DAFromObjectOffset8(void *a0) {
    short value = *(signed short *)((char *)a0 + 8);
    *(unsigned short *)(ReadWordFieldAtOffset1C() + 0x19da) = value;
    return 1;
}
