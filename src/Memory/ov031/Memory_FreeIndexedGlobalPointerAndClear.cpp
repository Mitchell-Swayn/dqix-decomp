#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d2c[];
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void *);

// Original: arm9/ov031 @ 0x0223BD88; symbol: func_ov031_0223bd88; size: 0x28.
extern "C" void Memory_FreeIndexedGlobalPointerAndClear(unsigned int index) {
    Unclassified_FreeArgumentAndUpdateGlobalOwner((void *)data_ov031_02290d2c[index]);
    data_ov031_02290d2c[index] = 0;
}
