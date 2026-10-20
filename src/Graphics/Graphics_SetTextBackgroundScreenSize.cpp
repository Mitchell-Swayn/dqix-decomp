#include <globaldefs.h>
// func_0204b11c: 0x0204b11c–0x0204b12c, arm; 16 bytes
// Original: arm9/main @ 0x0204B11C; symbol: func_0204b11c; size: 0x10.
extern "C" void Graphics_SetTextBackgroundScreenSize(int self, unsigned int value) {
    *(unsigned int*)(self + 0x18) = value;
        *(unsigned char*)(self + 0x1f) = 0;
}
