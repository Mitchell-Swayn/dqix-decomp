#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void GameResources_SetPrimaryFlags(unsigned int *, unsigned int);
extern "C" void GameResources_ClearPrimaryFlags(unsigned int *, unsigned int);
// Original: arm9/ov001 @ 0x021632A8; symbol: func_ov001_021632a8; size: 0x3C.
extern "C" bool Resource_SetScriptControlledFlag(void *parameter) {
    void *resources = GameResources_GetInstance();
    int enabled = Script_ReadParameterAsInteger(parameter);
    if (enabled) GameResources_SetPrimaryFlags((unsigned int *)resources, 0x4000);
    else GameResources_ClearPrimaryFlags((unsigned int *)resources, 0x4000);
    return true;
}
