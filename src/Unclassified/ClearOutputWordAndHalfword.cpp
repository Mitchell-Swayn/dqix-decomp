#include <globaldefs.h>
// func_0205a244: 0x0205a244–0x0205a254, arm; 16 bytes
// Original: arm9/main @ 0x0205A244; symbol: func_0205a244; size: 0x10.
extern "C" void ClearOutputWordAndHalfword(unsigned int* output) {
    output[0] = 0;
        *(unsigned short*)((char*)output + 4) = 0;
}
