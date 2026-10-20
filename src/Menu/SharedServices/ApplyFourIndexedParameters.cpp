#include <globaldefs.h>
ARM
extern "C" void GameState_AppendValueAndSetNodeFlags(void *, int, int);
// Original: arm9/ov004 @ 0x02157874; symbol: func_ov004_02157874; size: 0x34.
extern "C" void ApplyFourIndexedParameters(void *self) {
    for (int i = 0; i < 4; ++i)
        GameState_AppendValueAndSetNodeFlags(self, i + 0x29, 8);
}
