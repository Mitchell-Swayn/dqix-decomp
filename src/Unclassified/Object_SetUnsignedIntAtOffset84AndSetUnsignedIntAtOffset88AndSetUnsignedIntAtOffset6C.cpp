#include <globaldefs.h>
// func_0209fde8: 0x0209fde8–0x0209fdf8, arm; 16 bytes
// Original: arm9/main @ 0x0209FDE8; symbol: func_0209fde8; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffset84AndSetUnsignedIntAtOffset88AndSetUnsignedIntAtOffset6C(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x84) = first;
        *(unsigned int*)(self + 0x88) = third;
        *(unsigned int*)(self + 0x6c) = second;
}
