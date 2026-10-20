#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02180B3C; symbol: func_ov000_02180b3c; size: 0x14.
extern "C" void BattleMenu_ResetHeaderSlideAnimation(int a0) {
    *(int *)(a0 + 0x934) = 0;
    *(int *)(a0 + 0x930) = 0x180;
}
