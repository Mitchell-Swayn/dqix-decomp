#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2738; symbol: func_ov017_021d2738; size: 0x3C.
extern "C" void QueueTaggedBytePair(unsigned char first, unsigned char second) {
    unsigned char record[0x14];
    void* destination = ReadGlobalAt02100044();
    record[0] = 0x21;
    unsigned char* fields = record + 4;
    fields[0] = first;
    fields[1] = second;
    MoveQueuedRecordAndApplySourceValue(destination, record, 0);
}
