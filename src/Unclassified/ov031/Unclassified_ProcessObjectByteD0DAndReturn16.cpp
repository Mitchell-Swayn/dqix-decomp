#include <globaldefs.h>
ARM
extern "C" void func_ov031_02213504(unsigned int);
// Original: arm9/ov031 @ 0x022154E4; symbol: func_ov031_022154e4; size: 0x14.
extern "C" unsigned int Unclassified_ProcessObjectByteD0DAndReturn16(void *object) {
    func_ov031_02213504(*(unsigned char *)((unsigned char *)object + 0xD0D));
    return 0x10;
}
