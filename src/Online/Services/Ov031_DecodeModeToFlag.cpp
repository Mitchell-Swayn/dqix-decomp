#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022140CC; symbol: func_ov031_022140cc; size: 0x1C.
extern "C" unsigned int Ov031_DecodeModeToFlag(void *object) {
    unsigned int mode = ((unsigned int)*(unsigned char *)((char *)object + 0xd0b) << 28) >> 30;
    return mode == 1 ? 0xc0000 : 0x80000;
}
