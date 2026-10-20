#include <globaldefs.h>
// func_0203db34: 0x0203db34–0x0203db44, arm; 16 bytes
// Original: arm9/main @ 0x0203DB34; symbol: func_0203db34; size: 0x10.
extern "C" void Object3D_SetRotationComponents(int self, unsigned int first, unsigned int second, unsigned int third) {
    *(unsigned int*)(self + 0x50) = first;
        *(unsigned int*)(self + 0x54) = second;
        *(unsigned int*)(self + 0x58) = third;
}
