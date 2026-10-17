#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02155A04; symbol: func_ov000_02155a04; size: 0x4C.
extern "C" float Object_GetHalfwordRatioAt138(unsigned char *object) {
    unsigned char *record = *(unsigned char **)(object + 0x138);
    unsigned short numerator = *(unsigned short *)record;
    if ((float)numerator == 0.0f) {
        return 0.0f;
    }
    return (float)numerator / (float)*(unsigned short *)(record + 4);
}
