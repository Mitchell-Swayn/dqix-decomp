#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void CopyPackedCharacterDescriptor(unsigned char*, const unsigned char*);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D2CC0; symbol: func_ov017_021d2cc0; size: 0x40.
extern "C" void func_ov017_021d2cc0(const unsigned char* source) {
    void* object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0x25;
    CopyPackedCharacterDescriptor(record + 4, source);
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
