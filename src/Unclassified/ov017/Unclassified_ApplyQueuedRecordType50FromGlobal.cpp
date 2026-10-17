#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);

// Original: arm9/ov017 @ 0x021CEA8C; symbol: func_ov017_021cea8c; size: 0x28.
extern "C" void Unclassified_ApplyQueuedRecordType50FromGlobal(void) {
    unsigned char record[0x14];
    void *object = ReadGlobalAt02100044();
    record[0] = 0x32;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
