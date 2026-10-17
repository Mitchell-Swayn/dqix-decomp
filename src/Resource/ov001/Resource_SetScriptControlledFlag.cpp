#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned int *, unsigned int);
extern "C" void Flags_ClearWordMask(unsigned int *, unsigned int);
// Original: arm9/ov001 @ 0x021632A8; symbol: func_ov001_021632a8; size: 0x3C.
extern "C" bool Resource_SetScriptControlledFlag(void *parameter) {
    void *resources = GameResources_GetInstance();
    int enabled = ReadScriptParameterAsInteger(parameter);
    if (enabled) SetWordMaskBits_Main0203B4A0((unsigned int *)resources, 0x4000);
    else Flags_ClearWordMask((unsigned int *)resources, 0x4000);
    return true;
}
