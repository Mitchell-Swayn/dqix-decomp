#include <globaldefs.h>
ARM
struct AttributeBits {
    unsigned int low : 10;
    unsigned int bit10 : 1;
    unsigned int bits11to17 : 7;
    unsigned int bits18to24 : 7;
    unsigned int high : 7;
};
// Original: arm9/ov023 @ 0x021ED7E0; symbol: func_ov023_021ed7e0; size: 0x24.
extern "C" void Graphics_KeepAttributeBits25To31(unsigned int *attributes) {
    AttributeBits *bits = (AttributeBits *)attributes;
    bits->low = 0;
    bits->bit10 = 0;
    bits->bits11to17 = 0;
    bits->bits18to24 = 0;
}
