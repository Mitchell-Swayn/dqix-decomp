#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_021707e8[];
extern "C" unsigned char *func_ov004_0215e47c(void *, int);
// Original: arm9/ov004 @ 0x02163284; symbol: func_ov004_02163284; size: 0x38.
extern "C" int Object_ResetSharedValuesAndSetFlag(void *self) {
    *(unsigned int *)(data_ov004_021707e8 + 0x20) = 0xFFFFFFFF;
    *(unsigned int *)(data_ov004_021707e8 + 0x24) = 0;
    unsigned char *object = func_ov004_0215e47c(self, 9);
    object[0x0C] |= 1;
    return 0;
}
