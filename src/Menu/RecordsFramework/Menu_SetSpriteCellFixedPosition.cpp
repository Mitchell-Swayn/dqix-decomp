#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB1C8; symbol: func_ov023_021fb1c8; size: 0x14.
extern "C" void Menu_SetSpriteCellFixedPosition(void *destination, void *source) {
    *(unsigned int *)((unsigned char *)destination + 0x28) = *(unsigned int *)source;
    *(unsigned int *)((unsigned char *)destination + 0x2c) = *(unsigned int *)((unsigned char *)source + 4);
}
