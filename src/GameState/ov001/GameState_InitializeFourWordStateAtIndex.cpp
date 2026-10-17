#include <globaldefs.h>
ARM
extern "C" char data_ov001_02165880[];
extern "C" void InitializeFourWordState(void *state);
// Original: arm9/ov001 @ 0x0215ACD4; symbol: func_ov001_0215acd4; size: 0x24.
extern "C" void GameState_InitializeFourWordStateAtIndex(int index) {
    char *base = *(char **)(data_ov001_02165880 + 4);
    if (base)
        InitializeFourWordState(base + index * 16);
}
