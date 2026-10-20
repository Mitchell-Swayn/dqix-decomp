#include <globaldefs.h>
// func_0203cea4: 0x0203cea4–0x0203ceb4, arm; 16 bytes
// Original: arm9/main @ 0x0203CEA4; symbol: func_0203cea4; size: 0x10.
extern "C" void ActorSprite_StopTargetMovement(int self) {
    *(unsigned int*)(self + 0x5c) &= ~1u;
}
