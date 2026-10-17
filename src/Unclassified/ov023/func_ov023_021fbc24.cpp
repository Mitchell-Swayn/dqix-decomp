#include <globaldefs.h>
ARM
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);
extern "C" unsigned int _ffixu(unsigned int);
// Original: arm9/ov023 @ 0x021FBC24; symbol: func_ov023_021fbc24; size: 0x44.
extern "C" void func_ov023_021fbc24(void *out, const int *values) {
    unsigned int x = _ffixu(_fdiv(_fflt(values[0]), 0x45800000));
    *(unsigned short *)((char *)out + 0x32) = x;
    unsigned int y = _ffixu(_fdiv(_fflt(values[1]), 0x45800000));
    *(unsigned short *)((char *)out + 0x34) = y;
}
