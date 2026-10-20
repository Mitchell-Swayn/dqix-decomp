#include <globaldefs.h>
// func_020115e8: 0x020115e8–0x020115f4, arm; 12 bytes
// Original: arm9/main @ 0x020115E8; symbol: func_020115e8; size: 0xC.
extern "C" unsigned short GameState_GetDeferredTransitionMapId(int self) {
    return *(unsigned short*)(self + 0x63d8);
}
