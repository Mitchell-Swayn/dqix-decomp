#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021C9AD4; symbol: func_ov017_021c9ad4; size: 0x30.
extern "C" void ApplyQueuedRecordTag56WithInputHalfword(int value) {
    void *object = ReadGlobalAt02100044();
    unsigned char source[0x14];
    source[0] = 0x56;
    *(short *)(source + 6) = (short)value;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
