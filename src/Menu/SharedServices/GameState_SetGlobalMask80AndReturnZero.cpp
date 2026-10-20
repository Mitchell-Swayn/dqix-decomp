#include <globaldefs.h>
ARM
extern "C" void *SystemState_GetGlobalFlags(void);
extern "C" void SystemState_SetFlags(unsigned int *word, unsigned int mask);
// Original: arm9/ov004 @ 0x0216E3FC; symbol: func_ov004_0216e3fc; size: 0x18.
extern "C" int GameState_SetGlobalMask80AndReturnZero(void) {
    SystemState_SetFlags((unsigned int *)SystemState_GetGlobalFlags(), 0x80);
    return 0;
}
