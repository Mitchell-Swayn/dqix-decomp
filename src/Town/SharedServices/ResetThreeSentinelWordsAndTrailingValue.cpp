#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0216FB6C; symbol: func_ov003_0216fb6c; size: 0x34.
extern "C" void ResetThreeSentinelWordsAndTrailingValue(char* object) {
    for (int index = 0; index < 3; ++index)
        *(int*)(object + index * 4 + 0x1b68) = -1;
    *(int*)(object + 0x1b74) = 0;
}
