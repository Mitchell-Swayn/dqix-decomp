#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
extern "C" void func_ov017_021c9954(unsigned short, unsigned, unsigned char, int);
// Original: arm9/ov017 @ 0x021C9C64; symbol: func_ov017_021c9c64; size: 0x4C.
extern "C" void Object_QueueTypedRecordAndInitializeState(unsigned short first, unsigned char second) {
    unsigned char record[0x14];
    void* object = ReadGlobalAt02100044();
    record[0] = 0x7c;
    *(unsigned short*)(record + 4) = first;
    record[6] = second;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
    func_ov017_021c9954(first, 1, second, -1);
}
