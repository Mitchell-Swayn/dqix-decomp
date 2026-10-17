#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFDE0; symbol: func_ov017_021cfde0; size: 0x44.
extern "C" void MoveQueuedRecordWithThreeHalfwords(unsigned short a, unsigned short b, unsigned short c) {
    void *object = ReadGlobalAt02100044();
    unsigned char source[0x14];
    unsigned char *payload = source + 4;
    source[0] = 0xA5;
    *(unsigned short *)payload = a;
    *(unsigned short *)(payload + 2) = b;
    *(unsigned short *)(payload + 4) = c;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
