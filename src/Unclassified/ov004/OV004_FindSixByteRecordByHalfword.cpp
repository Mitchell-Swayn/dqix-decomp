#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x021550C8; symbol: func_ov004_021550c8; size: 0x3C.
extern "C" void* OV004_FindSixByteRecordByHalfword(void *records, int key) {
    for (unsigned char i = 0; i < 2; i++) {
        void *record = (char *)records + i * 6;
        if (*(short *)record == key) return record;
    }
    return 0;
}
