#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CF594; symbol: func_ov017_021cf594; size: 0x40.
extern "C" void MoveQueuedRecordWithShortAndBytePair(unsigned short value, unsigned char first, unsigned char second) {
    void *object = ReadGlobalAt02100044();
    unsigned char source[0x14];
    source[0] = 0x3A;
    *(unsigned short *)(source + 4) = value;
    source[6] = first;
    source[7] = second;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
