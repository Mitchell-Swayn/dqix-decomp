#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x02153C60; symbol: func_ov006_02153c60; size: 0xC.
extern "C" void KrakPot_BindRecipeProgressRecords(char *p, int a, unsigned short b) {
    *(int *)(p + 0x20) = a;
    *(unsigned short *)(p + 0x24) = b;
}
