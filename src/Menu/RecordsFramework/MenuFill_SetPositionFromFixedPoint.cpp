#include <globaldefs.h>
ARM

// Original: arm9/ov023 @ 0x021FC470; symbol: func_ov023_021fc470; size: 0x44.
extern "C" void MenuFill_SetPositionFromFixedPoint(unsigned char *record, int *values) {
    *(unsigned short *)(record + 0x26) = (unsigned short)((float)values[0] / 4096.0f);
    *(unsigned short *)(record + 0x28) = (unsigned short)((float)values[1] / 4096.0f);
}
