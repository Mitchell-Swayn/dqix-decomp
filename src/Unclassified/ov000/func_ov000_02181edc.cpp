#include <globaldefs.h>
ARM
extern "C" int GameState_ReadLinkedRecordValueByMode(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x02181EDC; symbol: func_ov000_02181edc; size: 0x1C.
extern "C" int func_ov000_02181edc(unsigned int a, unsigned int b, unsigned int c) { (void)a; return GameState_ReadLinkedRecordValueByMode(0, 6, b, c); }
