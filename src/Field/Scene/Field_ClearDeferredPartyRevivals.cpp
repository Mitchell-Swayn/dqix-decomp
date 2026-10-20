#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02191B70; symbol: func_ov017_02191b70; size: 0x30.
extern "C" void Field_ClearDeferredPartyRevivals(void *base) {
    unsigned char *record = (unsigned char *)base + 0x449c;
    for (int i = 0; i < 4; i++) {
        record[0] = 0;
        *(unsigned short *)(record + 2) = 0;
        record += 4;
    }
}
