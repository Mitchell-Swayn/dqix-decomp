#include <globaldefs.h>
ARM
extern "C" void *BattleScene_GetActiveInstance(void);
// Original: arm9/ov025 @ 0x021E8898; symbol: func_ov025_021e8898; size: 0x20.
extern "C" int Resource_SetOverlayFlagIfPresent(void) {
    char *control = (char *)BattleScene_GetActiveInstance();
    if (control)
        *(unsigned char *)(control + 0x6fd8) = 1;
    return 1;
}
