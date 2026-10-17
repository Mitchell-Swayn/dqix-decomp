#include <globaldefs.h>
// func_0201155c: 0x0201155c–0x02011570, arm; 20 bytes
// Original: arm9/main @ 0x0201155C; symbol: func_0201155c; size: 0x14.
extern "C" void GameState_ClearFlagBitZeroAtOffset5CCC(int self) {
    *(unsigned int*)(self + 0x5ccc) &= ~1u;
}
