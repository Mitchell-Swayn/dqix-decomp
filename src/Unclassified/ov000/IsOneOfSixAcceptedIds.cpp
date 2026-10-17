#include <globaldefs.h>
ARM

// Original: arm9/ov000 @ 0x02159C58; symbol: func_ov000_02159c58; size: 0x5C.
extern "C" int IsOneOfSixAcceptedIds(void *unused, unsigned value) {
    switch (value) {
    case 0x205:
    case 0x20a:
    case 0x20b:
    case 0x20c:
    case 0x20d:
    case 0x212:
        return 1;
    default:
        return 0;
    }
}
