#include <globaldefs.h>
// func_020115c0: 0x020115c0–0x020115d0, arm; 16 bytes
// Original: arm9/main @ 0x020115C0; symbol: func_020115c0; size: 0x10.
extern "C" void GameState_ClearPendingFieldReloadMode(int self) {
    *(unsigned char*)(self + 0x63d6) = 0;
}
