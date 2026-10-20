#include <globaldefs.h>
ARM
extern "C" void GameState_ClearTenBitFlagWords(void *);
// Original: arm9/ov017 @ 0x021D3EF0; symbol: func_ov017_021d3ef0; size: 0x10.
extern "C" void GameState_ClearTenBitFlagWordsForObject(void *, void *, void *p) {
    GameState_ClearTenBitFlagWords(p);
}
