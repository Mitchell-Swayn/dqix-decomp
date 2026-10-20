#include <globaldefs.h>
// func_0203d018: 0x0203d018–0x0203d028, arm; 16 bytes
// Original: arm9/main @ 0x0203D018; symbol: func_0203d018; size: 0x10.
extern "C" void ActorPool_DisableMarkedDrawFilter(int self) {
    *(unsigned int*)(self + 0x98) &= ~1u;
}
