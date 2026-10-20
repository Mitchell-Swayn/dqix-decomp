#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov004 @ 0x02165BB8; symbol: func_ov004_02165bb8; size: 0x18.
extern "C" int GrottoMenu_EnableUnknownTextControl(void) { *(unsigned int*)((char*)TextContext_GetSharedInstance() + 0x2c8) = 1; return 0; }
