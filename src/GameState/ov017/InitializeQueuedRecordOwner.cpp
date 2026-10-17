#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021C9B90; symbol: func_ov017_021c9b90; size: 0x38.
extern "C" void InitializeQueuedRecordOwner(short owner, short value) {
    void *object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0x7b;
    *(short *)(record + 4) = owner;
    *(short *)(record + 6) = value;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
