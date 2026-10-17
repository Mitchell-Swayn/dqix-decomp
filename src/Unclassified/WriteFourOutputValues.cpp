#include <globaldefs.h>
// func_02042c54: 0x02042c54–0x02042c68, arm; 20 bytes
// Original: arm9/main @ 0x02042C54; symbol: func_02042c54; size: 0x14.
extern "C" void WriteFourOutputValues(unsigned int* output, unsigned int first, unsigned int second, unsigned int third, unsigned int fourth) {
    output[0] = first;
        output[1] = second;
        output[2] = third;
        output[3] = fourth;
}
