#include <globaldefs.h>
// func_020407b4: 0x020407b4–0x020407c4, arm; 16 bytes
// Original: arm9/main @ 0x020407B4; symbol: func_020407b4; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x44) = first;
        *(unsigned int*)(self + 0x48) = second;
        *(unsigned int*)(self + 0x4c) = third;
}
