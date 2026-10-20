#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateMainBackgroundScreens(unsigned char *self, unsigned int enabled);
extern "C" void CancelTwoBackgroundTasksAndResetObject(void *self);
// Original: arm9/ov006 @ 0x02157184; symbol: func_ov006_02157184; size: 0x34.
extern "C" void Graphics_ClearFlagAndRefreshBackgrounds(unsigned char *self) {
    unsigned short *flags = (unsigned short *)(self + 0xAE2);
    unsigned int flagValue = *flags;
    *flags = (unsigned short)(flagValue & ~0x40u);
    Graphics_UpdateMainBackgroundScreens(self + 0xAE4, 0);
    CancelTwoBackgroundTasksAndResetObject(self);
}
