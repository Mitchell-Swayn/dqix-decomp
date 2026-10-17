#include <globaldefs.h>
ARM
extern "C" int OS_SendMessage(void *, void *, int);
extern "C" unsigned int data_ov031_022918bc;
// Original: arm9/ov031 @ 0x022403F4; symbol: func_ov031_022403f4; size: 0x1C.
extern "C" int func_ov031_022403f4(void) { return OS_SendMessage(&data_ov031_022918bc, 0, 0); }
