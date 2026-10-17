#include <globaldefs.h>
// func_0208aa18: 0x0208aa18–0x0208aa28, arm; 16 bytes
// Original: arm9/main @ 0x0208AA18; symbol: func_0208aa18; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x0c) = first;
        *(unsigned int*)(self + 0x10) = second;
        *(unsigned int*)(self + 0x14) = third;
}
