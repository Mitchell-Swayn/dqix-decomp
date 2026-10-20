#include <globaldefs.h>
// func_02011570: 0x02011570–0x02011584, arm; 20 bytes
// Original: arm9/main @ 0x02011570; symbol: func_02011570; size: 0x14.
extern "C" int GameState_GetSaveErrorExitRequestMask(int self) {
    return (*(int*)(self + 0x5ccc) << 31) >> 31;
}
