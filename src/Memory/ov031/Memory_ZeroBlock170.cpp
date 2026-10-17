#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e3b8[];
extern "C" void VectorizedMemset(void *, int, unsigned int);
// Original: arm9/ov031 @ 0x0220AB78; symbol: func_ov031_0220ab78; size: 0x1C.
extern "C" void Memory_ZeroBlock170(void) {
    VectorizedMemset(data_ov031_0224e3b8, 0, 0x170);
}
