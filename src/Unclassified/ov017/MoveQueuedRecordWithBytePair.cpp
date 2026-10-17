#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFED0; symbol: func_ov017_021cfed0; size: 0x3C.
extern "C" void MoveQueuedRecordWithBytePair(unsigned char first, unsigned char second) {
    unsigned char source[0x14];
    void *object = ReadGlobalAt02100044();
    source[0] = 0x16;
    unsigned char *payload = source + 4;
    payload[0] = first;
    payload[1] = second;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
