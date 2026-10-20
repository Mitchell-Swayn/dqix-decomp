#include <globaldefs.h>
ARM
extern "C" void *SystemState_GetGlobalFlags(void);
extern "C" void SystemState_ClearFlags(unsigned int *, unsigned int);
// Original: arm9/ov004 @ 0x0216312C; symbol: func_ov004_0216312c; size: 0x18.
extern "C" int StatusMenu_ClearSharedMenuFlag(void) {
    SystemState_ClearFlags((unsigned int *)SystemState_GetGlobalFlags(), 1);
    return 0;
}
