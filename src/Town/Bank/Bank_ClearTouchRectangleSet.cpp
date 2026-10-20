#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0216A85C; symbol: ClearRecordFieldsAtOffsets0Through14; size: 0x24.
// Clears the halfword, byte, and four word fields at offsets 0 through 0x14.
extern "C" void Bank_ClearTouchRectangleSet(void *object) {
    *(unsigned short *)object = 0;
    *(unsigned short *)((char *)object + 2) = 0;
    *(unsigned char *)((char *)object + 4) = 0;
    *(unsigned *)((char *)object + 0x14) = 0;
    *(unsigned *)((char *)object + 0x10) = 0;
    *(unsigned *)((char *)object + 0xc) = 0;
    *(unsigned *)((char *)object + 8) = 0;
}
