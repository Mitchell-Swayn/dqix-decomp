#include <globaldefs.h>
ARM
extern "C" unsigned char data_02109bf4;
extern "C" void ResourceHandle_UpdateModeSelectedSecondaryHandle(char *);
extern "C" void UpdateByteLevelTransitionAndThreeChannels(unsigned char *, unsigned char, int);
// Original: arm9/ov001 @ 0x021636A8; symbol: func_ov001_021636a8; size: 0x28.
extern "C" int Resource_UpdateModeSelectedSecondaryHandleAndTransition(void) {
    ResourceHandle_UpdateModeSelectedSecondaryHandle((char *)&data_02109bf4);
    UpdateByteLevelTransitionAndThreeChannels((unsigned char *)&data_02109bf4, 0x7f, 0);
    return 1;
}
