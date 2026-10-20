#include <globaldefs.h>
ARM

// Original: arm9/ov015 @ 0x02190D08; symbol: func_ov015_02190d08; size: 0x74.
extern "C" int Resource_IsAcceptedObjectType(void *object) {
    int type = *(int *)((char *)object + 0x1A4);
    if (type == 0x11) return 1;
    if (type == 0x14) return 1;
    if (type == 0x17) return 1;
    if (type == 0x18) return 1;
    if (type == 0x19) return 1;
    if (type == 0x1A) return 1;
    if (type == 0x1B) return 1;
    if (type == 0x1C) return 1;
    return type == 0x16;
}
