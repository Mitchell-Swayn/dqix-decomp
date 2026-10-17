#include <globaldefs.h>
// func_0203a47c: 0x0203a47c–0x0203a48c, arm; 16 bytes
// Original: arm9/main @ 0x0203A47C; symbol: func_0203a47c; size: 0x10.
extern "C" void Object_SetUnsignedIntAtOffset34AndSetUnsignedIntAtOffset38AndSetUnsignedIntAtOffset3C(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x34) = first;
        *(unsigned int*)(self + 0x38) = second;
        *(unsigned int*)(self + 0x3c) = third;
}
