#include <globaldefs.h>
ARM

extern "C" void *ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void *object, const void *source, short value);

// Original: arm9/ov017 @ 0x021C5F00; symbol: func_ov017_021c5f00; size: 0x54.
extern "C" void QueueType3FRecordFromSixByteSource(const unsigned char *source) {
    void *object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0x3f;
    *(unsigned short *)(record + 4) = *(unsigned short *)source;
    *(unsigned short *)(record + 6) = *(unsigned short *)(source + 2);
    record[8] = source[4];
    record[9] = source[5];
    record[0xa] = source[6];
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
