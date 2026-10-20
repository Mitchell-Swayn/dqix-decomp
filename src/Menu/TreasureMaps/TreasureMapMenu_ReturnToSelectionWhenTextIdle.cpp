#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);

// Original: arm9/ov004 @ 0x021652BC; symbol: func_ov004_021652bc; size: 0x2C.
extern "C" int TreasureMapMenu_ReturnToSelectionWhenTextIdle(void *state) {
    unsigned char *global = (unsigned char *)TextContext_GetSharedInstance();
    if (*(unsigned int *)(global + 0x998) == 0)
        Menu_QueueScriptEntry(state, 0x65);
    return 0;
}
