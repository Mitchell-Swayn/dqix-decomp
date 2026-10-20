#include <globaldefs.h>
ARM
extern "C" int Menu_GetSelectedGridNode(int value, int mode);
// Original: arm9/ov004 @ 0x021571D8; symbol: func_ov004_021571d8; size: 0x1C.
extern "C" int GameState_TestRecordWithMode65(int value) {
    return Menu_GetSelectedGridNode(value, 0x65) != 0;
}
