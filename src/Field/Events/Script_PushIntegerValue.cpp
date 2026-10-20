#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4A78; symbol: func_ov017_021d4a78; size: 0x20.
extern "C" void Script_PushIntegerValue(int a0, int a1) {
    *(int *)(*(int *)(a0 + 0x14)) = 0;
    int *pointer = (int *)*(int *)(a0 + 0x14);
    *(int *)(a0 + 0x14) = (int)(pointer + 2);
    pointer[1] = a1;
}
