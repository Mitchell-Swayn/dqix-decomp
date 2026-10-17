#include <globaldefs.h>
// func_0203d008: 0x0203d008–0x0203d018, arm; 16 bytes
// Original: arm9/main @ 0x0203D008; symbol: func_0203d008; size: 0x10.
extern "C" void SetMaskedFlagsAtOffset98(int self) {
    *(unsigned int*)(self + 0x98) |= 1;
}
