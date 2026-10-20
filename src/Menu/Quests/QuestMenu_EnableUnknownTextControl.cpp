#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov004 @ 0x0216768C; symbol: func_ov004_0216768c; size: 0x18.
extern "C" int QuestMenu_EnableUnknownTextControl(void) {
    unsigned int object = TextContext_GetSharedInstance();
    *(unsigned int *)(object + 0x2c8) = 1;
    return 0;
}
