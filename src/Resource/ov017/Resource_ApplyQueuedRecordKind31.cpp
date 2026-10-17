#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D257C; symbol: func_ov017_021d257c; size: 0x3C.
extern "C" void Resource_ApplyQueuedRecordKind31(unsigned char kind, unsigned value) {
    unsigned char record[0x14];
    void* object = ReadGlobalAt02100044();
    record[0] = 0x1f;
    unsigned char* payload = record + 4;
    *payload = kind;
    *(unsigned*)(payload + 4) = value;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
