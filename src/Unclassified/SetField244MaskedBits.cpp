#include <globaldefs.h>
// func_020a28a0: 0x020a28a0–0x020a28b0, arm; 16 bytes
// Original: arm9/main @ 0x020A28A0; symbol: func_020a28a0; size: 0x10.
extern "C" void SetField244MaskedBits(int self, unsigned char mask) {
    *(unsigned char*)(self + 0x244) |= mask;
}
