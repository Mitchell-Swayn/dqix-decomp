#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290d04[];

// Original: arm9/ov031 @ 0x02237388; symbol: func_ov031_02237388; size: 0x2C.
extern "C" int Unclassified_IsGlobalObjectMissingOrByte18Zero(void) {
    unsigned char *object = *(unsigned char **)(data_ov031_02290d04 + 4);
    if (object == 0)
        return 1;
    return object[0x18] == 0;
}
