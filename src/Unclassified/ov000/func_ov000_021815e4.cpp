#include <globaldefs.h>
ARM
extern "C" int FindSerializedPrimaryRecordByKey(void *, int);
// Original: arm9/ov000 @ 0x021815E4; symbol: func_ov000_021815e4; size: 0x24.
extern "C" int func_ov000_021815e4(unsigned char *p) {
    int index = *(signed char *)(p + 0x1d6f);
    int key = *(signed short *)(p + index * 2 + 0x26);
    return FindSerializedPrimaryRecordByKey(p + 0x100, key);
}
