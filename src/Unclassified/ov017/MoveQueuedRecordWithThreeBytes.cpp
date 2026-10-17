#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D27A0; symbol: func_ov017_021d27a0; size: 0x44.
extern "C" void MoveQueuedRecordWithThreeBytes(unsigned char a, unsigned char b, unsigned char c) {
    void *object = ReadGlobalAt02100044();
    unsigned char source[0x14];
    source[0] = 0x22;
    unsigned char *payload = source + 4;
    payload[0] = a;
    payload[1] = b;
    payload[2] = c;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
