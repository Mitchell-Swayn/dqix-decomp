#include <globaldefs.h>
// func_020b0268: 0x020b0268–0x020b0278, arm; 16 bytes
// Original: arm9/main @ 0x020B0268; symbol: func_020b0268; size: 0x10.
extern "C" void RelocateWordOffsetAtField4AgainstBase(int self) {
    *(int*)(self + 4) += self;
}
