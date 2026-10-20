#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021FB478; symbol: func_ov024_021fb478; size: 0x18.
extern "C" int GameState_IsFlagBit17Set(int a0) {
    return (*(int *)(*(int *)(a0 + 0x138) + 0x14) & 0x20000) != 0;
}
