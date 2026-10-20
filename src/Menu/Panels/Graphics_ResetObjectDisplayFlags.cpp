#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021ECBBC; symbol: func_ov023_021ecbbc; size: 0x2C.
extern "C" void Graphics_ResetObjectDisplayFlags(void *object) {
    unsigned short *field = (unsigned short *)((char *)object + 0x438);
    unsigned int flags = *field;
    flags &= ~0x100u;
    *field = (unsigned short)flags;
    *field = (unsigned short)(*field | 0x40);
    *((unsigned char *)object + 0x43c) = 0;
    *((unsigned char *)object + 0x433) = 0;
}
