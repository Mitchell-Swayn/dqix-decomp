#include <globaldefs.h>
ARM
extern "C" void *data_ov004_021707c4;
extern "C" void* OV004_FindSixByteRecordByHalfword(void*, int);
// Original: arm9/ov004 @ 0x02155090; symbol: func_ov004_02155090; size: 0x38.
extern "C" int OV004_ReadRecordByteFiveForHalfwordEight(void) {
    short value = 0;
    void *record = OV004_FindSixByteRecordByHalfword(data_ov004_021707c4, 8);
    if (record) value += (unsigned char)((char *)record)[5];
    return value;
}
