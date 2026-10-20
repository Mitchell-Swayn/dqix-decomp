#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov017 @ 0x021972CC; symbol: func_ov017_021972cc; size: 0x2C.
extern "C" void ClearEmbeddedFieldsAtOffsets45B8And44C0(void *object) {
    memset((char *)object + 0xb8 + 0x4400, 0, 8);
    *((unsigned char *)object + 0x4000 + 0x4c0) = 0;
}
