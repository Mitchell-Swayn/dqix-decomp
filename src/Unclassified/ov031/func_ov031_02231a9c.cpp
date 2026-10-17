#include <globaldefs.h>
ARM
extern "C" void System_IncrementMainLoopCallbackCounter(void);
extern "C" void func_ov031_02231aac(void);
// Original: arm9/ov031 @ 0x02231A9C; symbol: func_ov031_02231a9c; size: 0x10.
extern "C" void func_ov031_02231a9c(void) { System_IncrementMainLoopCallbackCounter(); func_ov031_02231aac(); }
