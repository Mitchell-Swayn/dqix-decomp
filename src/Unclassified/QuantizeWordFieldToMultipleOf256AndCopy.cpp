#include <globaldefs.h>

// Original: arm9/main @ 0x0203CDA8; symbol: func_0203cda8; size: 0x28.
extern "C" void QuantizeWordFieldToMultipleOf256AndCopy(unsigned int *object, unsigned int value) {
    volatile unsigned int *field = object;
    unsigned int low = value & 0xff;
    field[0x60 / 4] = value;
    value &= 0xffffff00;
    if (low >= 0xffffff80U) {
        value += 0x100;
    }
    field[0x60 / 4] = value;
    field[0x64 / 4] = field[0x60 / 4];
}
