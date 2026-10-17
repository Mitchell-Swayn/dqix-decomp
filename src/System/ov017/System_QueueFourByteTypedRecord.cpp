#include <globaldefs.h>
ARM
struct Object;
struct Payload { unsigned char a, b, c, d; };
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021D3BBC; symbol: func_ov017_021d3bbc; size: 0x4C.
extern "C" void System_QueueFourByteTypedRecord(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    unsigned char record[20];
    Object* object = (Object*)ReadGlobalAt02100044();
    Payload* payload = (Payload*)(record + 4);
    record[0] = 0xb8;
    payload->a = c;
    payload->b = d;
    payload->d = a;
    payload->c = b;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
