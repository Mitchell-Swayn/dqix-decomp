#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov001 @ 0x021608E8; symbol: func_ov001_021608e8; size: 0x1C.
extern "C" int Script_SetWordField99CFromParameter(IntegerParameterView *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    *(int *)(ReadWordFieldAtOffset1C() + 0x99c) = value;
    return 1;
}
