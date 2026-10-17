#include <globaldefs.h>
ARM
extern "C" unsigned *data_ov031_02290d9c;
extern "C" void func_ov031_0223bf48(void *, unsigned);
// Original: arm9/ov031 @ 0x0223E2C0; symbol: func_ov031_0223e2c0; size: 0x20.
extern "C" void func_ov031_0223e2c0(unsigned index, unsigned other) {
    char *entry = (char *)data_ov031_02290d9c + index * 0x40;
    func_ov031_0223bf48(*(void **)(entry + 4), other);
}
