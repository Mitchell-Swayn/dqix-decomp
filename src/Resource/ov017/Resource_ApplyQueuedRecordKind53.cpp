#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021C8C04; symbol: func_ov017_021c8c04; size: 0x40.
extern "C" void Resource_ApplyQueuedRecordKind53(unsigned short halfword, unsigned char byte, unsigned value) {
    unsigned char record[0x14];
    void* object = ReadGlobalAt02100044();
    record[0] = 0x53;
    *(unsigned short*)(record + 8) = halfword;
    record[0xa] = byte;
    *(unsigned*)(record + 4) = value;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
