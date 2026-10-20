#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0215cd80; symbol: func_ov000_0215cd80; size: 0x20.
extern "C" void Combat_ResetActionCalculationScratch(void* object) {
    unsigned char* bytes = (unsigned char*)object;
    bytes[0x8e82] = 0;
    bytes[0x8e83] = 0;
    *(unsigned short*)(bytes + 0x8e52) = 0;
    *(unsigned int*)(bytes + 0x8e58) = 0;
}
