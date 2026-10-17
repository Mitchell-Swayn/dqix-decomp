#include <globaldefs.h>
// func_0206ee70: 0x0206ee70–0x0206ee80, arm; 16 bytes
// Original: arm9/main @ 0x0206EE70; symbol: func_0206ee70; size: 0x10.
extern "C" void ClearOutputWordAndByte_Main0206EE70(unsigned int* output) {
    output[0] = 0;
        *(unsigned char*)((char*)output + 4) = 0;
}
