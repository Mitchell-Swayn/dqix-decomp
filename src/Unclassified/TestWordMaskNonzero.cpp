#include <globaldefs.h>
// func_02046708: 0x02046708–0x0204671c, arm; 20 bytes
// Original: arm9/main @ 0x02046708; symbol: func_02046708; size: 0x14.
extern "C" bool TestWordMaskNonzero(const unsigned int* word, unsigned int mask) {
    return (*word & mask) != 0;
}
