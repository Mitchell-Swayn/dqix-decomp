#include <globaldefs.h>
ARM
extern "C" int _fflt(int);
extern "C" unsigned _fdiv(unsigned, unsigned);
extern "C" unsigned _ffixu(unsigned);
// Original: arm9/ov023 @ 0x021FD394; symbol: func_ov023_021fd394; size: 0x44.
extern "C" void Resource_ConvertDimensions(void* output, const int* values) {
    *(unsigned short*)((char*)output + 0x22) = (unsigned short)_ffixu(_fdiv((unsigned)_fflt(values[0]), 0x45800000));
    *(unsigned short*)((char*)output + 0x24) = (unsigned short)_ffixu(_fdiv((unsigned)_fflt(values[1]), 0x45800000));
}
