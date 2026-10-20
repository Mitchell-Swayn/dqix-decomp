#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02158CAC; symbol: func_ov006_02158cac; size: 0x50.
extern "C" void KrakPot_ResetRecipePagination(unsigned char *object) {
    unsigned char *node = *(unsigned char **)(object + 0x2C);
    unsigned short count = 0;
    while (node != 0) {
        count = (unsigned short)(count + 1);
        node = *(unsigned char **)(node + 0x1C);
    }
    object[0x389] = (unsigned char)((count + 15) / 16);
    if (object[0x389] == 0) {
        object[0x389] = 1;
    }
    object[0x388] = 0;
}
