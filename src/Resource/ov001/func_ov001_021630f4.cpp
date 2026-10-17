#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" int ReadScriptParameterAsInteger(void *parameter);
// Original: arm9/ov001 @ 0x021630F4; symbol: func_ov001_021630f4; size: 0x34.
extern "C" int func_ov001_021630f4(void *parameter) {
    void *resources = GameResources_GetInstance();
    unsigned int *field = *(unsigned int **)((char *)resources + 0x3734);
    int enabled = ReadScriptParameterAsInteger(parameter) != 0;
    *((unsigned char *)field + 0xfe) = (unsigned char)enabled;
    return 1;
}
