#include <globaldefs.h>
// func_020340e4: 0x020340e4–0x020340f4, arm; 16 bytes
// Original: arm9/main @ 0x020340E4; symbol: func_020340e4; size: 0x10.
extern "C" void SetMaskedFlagsAtOffsetC1(int self) {
    *(unsigned char*)(self + 0xc1) |= 4;
}
