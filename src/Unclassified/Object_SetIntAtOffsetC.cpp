#include <globaldefs.h>
// func_020b0278: 0x020b0278–0x020b0288, arm; 16 bytes
// Original: arm9/main @ 0x020B0278; symbol: func_020b0278; size: 0x10.
extern "C" void Object_SetIntAtOffsetC(int self) {
    *(int*)(self + 0x0c) += self;
}
