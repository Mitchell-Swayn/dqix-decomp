#include <globaldefs.h>

extern "C" int _fflt(int);
extern "C" int _fmul(int, int);
extern "C" int _ffix();

static const int scale_bits = 0x41855604;

// Original: arm9/main @ 0x02070950; symbol: func_02070950; size: 0x5C.
extern "C" void ColorAnimation_StartParameterizedTransition(unsigned char* out, const unsigned int* rgb, int value,
                                int scale, int mode) {
    if (value < 0) {
        return;
    }
    *(int*)(out + 0x10) = value;
    *(unsigned short*)(out + 2) = (unsigned short)(rgb[0] | (rgb[1] << 5) | (rgb[2] << 10));
    int converted = _fflt(scale);
    (void)_fmul(scale_bits, converted);
    *(int*)(out + 8) = _ffix();
    out[4] = mode;
    out[0] = 1;
}
