#include <globaldefs.h>
// func_0206ee60: 0x0206ee60–0x0206ee70, arm; 16 bytes
// Original: arm9/main @ 0x0206EE60; symbol: func_0206ee60; size: 0x10.
extern "C" void ClearOutputWordAndByte(unsigned int* output) {
    output[0] = 0;
        *(unsigned char*)((char*)output + 4) = 0;
}
