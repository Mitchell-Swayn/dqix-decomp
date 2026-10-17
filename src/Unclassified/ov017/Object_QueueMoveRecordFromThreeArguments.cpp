#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CEDF4; symbol: func_ov017_021cedf4; size: 0x40.
extern "C" void Object_QueueMoveRecordFromThreeArguments(void *source, const void *destination, int value) {
    void *target = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0x13;
    *(void **)(record + 4) = source;
    *(const void **)(record + 8) = destination;
    *(unsigned int *)(record + 0xc) = value;
    MoveQueuedRecordAndApplySourceValue(target, record, 0);
}
