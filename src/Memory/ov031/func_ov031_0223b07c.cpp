#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" unsigned int data_ov031_02290d20;
// Original: arm9/ov031 @ 0x0223B07C; symbol: func_ov031_0223b07c; size: 0x44.
extern "C" void func_ov031_0223b07c(void) {
    VectorizedMemset(*(char**)&data_ov031_02290d20 + 0x100, 0, 0x100);
    VectorizedMemset(*(char**)&data_ov031_02290d20, 0, 0x100);
    *(char**)(*(char**)&data_ov031_02290d20 + 0xab0) = *(char**)&data_ov031_02290d20;
}
