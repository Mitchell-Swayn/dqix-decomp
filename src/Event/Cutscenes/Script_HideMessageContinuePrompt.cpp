#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x0215E960; symbol: func_ov001_0215e960; size: 0x1C.
extern "C" int Script_HideMessageContinuePrompt(void) { *((unsigned char*)((char*)TextContext_GetSharedInstance() + 0x19ca)) = 0; return 1; }
