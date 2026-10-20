#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
extern "C" void GameResources_SetSecondaryFlags(int, unsigned int);
// Original: arm9/ov001 @ 0x02163128; symbol: func_ov001_02163128; size: 0x3C.
extern "C" int Resource_SetFlagMask800FromParameter(void *parameter) {
    int resources = (int)GameResources_GetInstance();
    int enabled = Script_ReadParameterAsInteger(parameter);
    if (enabled != 0) GameResources_ClearSecondaryFlags(resources, 0x800);
    else GameResources_SetSecondaryFlags(resources, 0x800);
    return 1;
}
