#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
extern "C" void GameResources_SetSecondaryFlags(int self, unsigned int value);
// Original: arm9/ov025 @ 0x021E7FDC; symbol: func_ov025_021e7fdc; size: 0x2C.
extern "C" int Resource_UpdateFlagFromObjectByte8(void *object) {
    unsigned char enabled = *((unsigned char *)object + 8);
    int resources = (int)GameResources_GetInstance();
    if (enabled)
        GameResources_ClearSecondaryFlags(resources, 0x100000);
    else
        GameResources_SetSecondaryFlags(resources, 0x100000);
    return 1;
}
