#include <globaldefs.h>
ARM
extern "C" unsigned int GameState_ReadLinkedRecordValueByMode(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02181EF8; symbol: func_ov000_02181ef8; size: 0x1C.
extern "C" unsigned int func_ov000_02181ef8(unsigned int unused, unsigned int second, unsigned int third) {
    return GameState_ReadLinkedRecordValueByMode(0, 7, second, third);
}
