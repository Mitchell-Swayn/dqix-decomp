#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CBFB8; symbol: func_ov017_021cbfb8; size: 0x3C.
extern "C" void QueueTaggedHalfwordByteRecord(unsigned short value, unsigned char byte) {
    unsigned char record[0x14];
    void* destination = ReadGlobalAt02100044();
    record[0] = 0x81;
    unsigned char* fields = record + 4;
    *(unsigned short*)fields = value;
    fields[2] = byte;
    MoveQueuedRecordAndApplySourceValue(destination, record, 0);
}
