#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171B9C; symbol: func_ov000_02171b9c; size: 0x24.
extern "C" unsigned int GameState_GetIndexedWordIfValid(void *table, int index) {
    if (index < 0 || index >= 0x10)
        return 0;
    return *(unsigned int *)((char *)table + index * 4 + 0x3f0);
}
