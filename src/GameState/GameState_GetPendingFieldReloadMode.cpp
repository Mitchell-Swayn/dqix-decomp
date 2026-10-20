#include <globaldefs.h>
// func_020115a8: 0x020115a8–0x020115b4, arm; 12 bytes
// Original: arm9/main @ 0x020115A8; symbol: func_020115a8; size: 0xC.
extern "C" unsigned char GameState_GetPendingFieldReloadMode(int self) {
    return *(unsigned char*)(self + 0x63d6);
}
