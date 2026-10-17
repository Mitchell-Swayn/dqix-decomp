#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DCE88; symbol: func_ov023_021dce88; size: 0x24.
extern "C" void Ov023_ClearThreeWordsAt784(void *object) {
    for (int i = 0; i < 3; ++i)
        *(unsigned int *)((char *)object + 0x784 + i * 4) = 0;
}
