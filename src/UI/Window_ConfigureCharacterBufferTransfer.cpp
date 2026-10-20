#include <globaldefs.h>
// func_020e1368: 0x020e1368–0x020e1374, arm; 12 bytes
// Original: arm9/main @ 0x020E1368; symbol: func_020e1368; size: 0xC.
extern "C" void Window_ConfigureCharacterBufferTransfer(unsigned int* output, unsigned int first, unsigned int second, unsigned char third) {
    output[0] = first;
        output[1] = second;
        *(unsigned char*)((char*)output + 8) = third;
}
