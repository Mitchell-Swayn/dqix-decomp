#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02157CC4; symbol: func_ov000_02157cc4; size: 0x18.
extern "C" int GameState_IsFlagBit23Set(int a0) {
    return (*(int *)(*(int *)(a0 + 0x138) + 0x14) & 0x800000) != 0;
}
