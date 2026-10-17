#include <globaldefs.h>
// func_020ce234: 0x020ce234–0x020ce240, arm; 12 bytes
// Original: arm9/main @ 0x020CE234; symbol: func_020ce234; size: 0xC.
extern "C" void WriteOutputWhenNonNull(unsigned int value, unsigned int* output) {
    if (output != 0) {
            *output = value;
        }
}
