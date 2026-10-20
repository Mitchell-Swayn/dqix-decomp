#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov025 @ 0x021E85E8; symbol: func_ov025_021e85e8; size: 0x34.
extern "C" int SetResourceFlagFromStateByte(void* state) {
    unsigned char* resources = (unsigned char*)GameResources_GetInstance();
    unsigned char enabled = 1;
    resources[0x4488] = enabled;
    if (*(unsigned char*)((char*)state + 8) == 0) enabled = 0;
    resources[0x4488] = enabled;
    return 1;
}
