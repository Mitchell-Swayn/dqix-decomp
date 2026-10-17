#include <globaldefs.h>
ARM

extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *object, const void *source, short value);

// Original: arm9/ov017 @ 0x021CF4B0; symbol: func_ov017_021cf4b0; size: 0x38.
extern "C" void Unclassified_QueueRecordWithByteArguments(unsigned char first, unsigned char second) {
    unsigned char record[0x14];
    void *object = ReadGlobalAt02100044();
    record[0] = 0x39;
    record[4] = first;
    record[5] = second;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
