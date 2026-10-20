#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171B3C; symbol: func_ov000_02171b3c; size: 0x2C.
extern "C" void GameState_ClearSixteenWordsAndByte86(void *object) {
    for (int i = 0; i < 16; ++i)
        *(int *)((char *)object + 0x3f0 + i * 4) = 0;
    *(unsigned char *)((char *)object + 0x86) = 0;
}
