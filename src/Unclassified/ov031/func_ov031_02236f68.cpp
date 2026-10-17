#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02290d04;
// Original: arm9/ov031 @ 0x02236F68; symbol: func_ov031_02236f68; size: 0x20.
extern "C" unsigned func_ov031_02236f68(void) {
    char *object = *(char **)((char *)&data_ov031_02290d04 + 4);
    return *(unsigned *)(object + 0x14) != 0;
}
