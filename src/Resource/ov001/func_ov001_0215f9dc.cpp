#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct GameResources;
extern "C" GameResources *GameResources_GetInstance();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void SetHalfwordAtOffset11A(unsigned char *p, unsigned short value);
// Original: arm9/ov001 @ 0x0215F9DC; symbol: func_ov001_0215f9dc; size: 0x34.
extern "C" int func_ov001_0215f9dc(IntegerParameterView *parameter) {
    unsigned char *target = *(unsigned char **)((unsigned char *)GameResources_GetInstance() + 0x3734);
    unsigned short value = (unsigned short)ReadScriptParameterAsInteger(parameter);
    SetHalfwordAtOffset11A(target, value);
    return 1;
}
