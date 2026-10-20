#include <globaldefs.h>
ARM
extern "C" int _fflt(int);
extern "C" unsigned _fdiv(unsigned, unsigned);
extern "C" unsigned _ffixu(void);
// Original: arm9/ov023 @ 0x021F8198; symbol: func_ov023_021f8198; size: 0x5C.
extern "C" void Math_ConvertVectorToScaledHalfwordPair(unsigned char* output, const int* input) {
    unsigned quotient = _fdiv((unsigned)_fflt(input[0]), 0x45800000);
    unsigned first = _ffixu();
    *(unsigned short*)(output + 0x100) = (unsigned short)first;
    quotient = _fdiv((unsigned)_fflt(input[1]), 0x45800000);
    unsigned second = _ffixu();
    *(unsigned short*)(output + 0x102) = (unsigned short)second;
    unsigned short a = *(unsigned short*)(output + 0x100);
    unsigned short b = *(unsigned short*)(output + 0x102);
    *(unsigned short*)(output + 0xcc) = a;
    *(unsigned short*)(output + 0xce) = b;
}
