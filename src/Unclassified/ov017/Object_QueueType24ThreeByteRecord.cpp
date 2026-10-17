#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2C34; symbol: func_ov017_021d2c34; size: 0x44.
extern "C" void Object_QueueType24ThreeByteRecord(unsigned char a, unsigned char b, unsigned char c) {
    unsigned char record[0x14];
    void* owner = ReadGlobalAt02100044();
    unsigned char* payload = record + 4;
    record[0] = 0x24;
    payload[0] = a;
    payload[1] = b;
    payload[2] = c;
    MoveQueuedRecordAndApplySourceValue(owner, record, 0);
}
