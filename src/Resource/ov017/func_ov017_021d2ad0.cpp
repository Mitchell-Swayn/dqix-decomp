#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D2AD0; symbol: func_ov017_021d2ad0; size: 0x54.
extern "C" void func_ov017_021d2ad0(unsigned char a, unsigned int b, unsigned int c, unsigned int d, unsigned char e) {
    void *object = ReadGlobalAt02100044();
    unsigned char source[0x14];
    unsigned char *fields = source + 4;
    source[0] = 0x23;
    fields[0] = a;
    *(unsigned int *)(fields + 4) = b;
    *(unsigned int *)(fields + 8) = c;
    *(unsigned int *)(fields + 0xc) = d;
    fields[1] = e;
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
