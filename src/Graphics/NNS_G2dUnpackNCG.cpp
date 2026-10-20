#include <globaldefs.h>
// func_020b01e0: 0x020b01e0–0x020b01f0, arm; 16 bytes
// Original: arm9/main @ 0x020B01E0; symbol: func_020b01e0; size: 0x10.
extern "C" void NNS_G2dUnpackNCG(int self) {
    *(int*)(self + 0x14) += self;
}
