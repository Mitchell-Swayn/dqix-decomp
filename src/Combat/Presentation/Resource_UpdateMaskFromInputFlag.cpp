#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void GameResources_SetSecondaryFlags(int self, unsigned int mask);
extern "C" void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
// Original: arm9/ov025 @ 0x021E8314; symbol: func_ov025_021e8314; size: 0x30.
extern "C" int Resource_UpdateMaskFromInputFlag(unsigned char *input) {
    void *resources = GameResources_GetInstance();
    if (input[8]) GameResources_ClearSecondaryFlags((int)resources, 0x400);
    else GameResources_SetSecondaryFlags((int)resources, 0x400);
    return 1;
}
