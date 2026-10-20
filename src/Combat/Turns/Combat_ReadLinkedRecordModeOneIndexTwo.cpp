#include <globaldefs.h>
ARM
extern "C" int GameState_ReadLinkedRecordValueByMode(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02181D88; symbol: func_ov000_02181d88; size: 0x1C.
extern "C" int Combat_ReadLinkedRecordModeOneIndexTwo(unsigned int a, unsigned int b, unsigned int c) { (void)a; return GameState_ReadLinkedRecordValueByMode(1, 2, b, c); }
