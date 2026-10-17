#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance();
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned int);
extern "C" void Object_SetUnsignedIntAtOffset4(int, unsigned int);
// Original: arm9/ov001 @ 0x02163128; symbol: func_ov001_02163128; size: 0x3C.
extern "C" int func_ov001_02163128(void *parameter) {
    int resources = (int)GameResources_GetInstance();
    int enabled = ReadScriptParameterAsInteger(parameter);
    if (enabled != 0) ClearWordAtOffset4MaskedBits(resources, 0x800);
    else Object_SetUnsignedIntAtOffset4(resources, 0x800);
    return 1;
}
