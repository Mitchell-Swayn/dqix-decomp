#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(unsigned int, unsigned int, void *, void *);
// Original: arm9/ov000 @ 0x02181DF8; symbol: func_ov000_02181df8; size: 0x1C.
extern "C" void Combat_ReadLinkedRecordModeOneIndexSix(void *unused, void *first, void *second) { GameState_ReadLinkedRecordValueByMode(1, 6, first, second); }
