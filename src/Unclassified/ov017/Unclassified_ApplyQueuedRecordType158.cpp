#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void *object, const void *source, short value);
// Original: arm9/ov017 @ 0x021D23BC; symbol: func_ov017_021d23bc; size: 0x30.
extern "C" void Unclassified_ApplyQueuedRecordType158(short sourceValue) {
    void *object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0x9E;
    *(short *)(record + 4) = sourceValue;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
