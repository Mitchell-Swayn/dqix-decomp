#include <globaldefs.h>
ARM
extern "C" unsigned Ov031_GetGlobalObjectField40(void);
extern "C" void Overlay_RunOperationAndUpdateState(void);
extern "C" unsigned char data_ov031_02290d20[];
// Original: arm9/ov031 @ 0x0223B010; symbol: func_ov031_0223b010; size: 0x30.
extern "C" int System_ActivateGlobalObjectIfReady(void) {
    if (Ov031_GetGlobalObjectField40() != 1) return 0;
    Overlay_RunOperationAndUpdateState();
    *(unsigned char *)(*(unsigned **)data_ov031_02290d20 + 0x2a4) = 1;
    return 1;
}
