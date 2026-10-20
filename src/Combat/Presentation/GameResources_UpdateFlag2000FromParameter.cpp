#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void GameResources_SetSecondaryFlags(int, unsigned int);
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
// Original: arm9/ov025 @ 0x021E72F4; symbol: func_ov025_021e72f4; size: 0x30.
extern "C" int GameResources_UpdateFlag2000FromParameter(void *parameter) {
    void *resources = GameResources_GetInstance();
    if (*(unsigned char *)((unsigned char *)parameter + 8) != 0)
        GameResources_ClearSecondaryFlags((int)resources, 0x2000);
    else
        GameResources_SetSecondaryFlags((int)resources, 0x2000);
    return 1;
}
