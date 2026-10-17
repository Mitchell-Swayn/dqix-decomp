#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
// Original: arm9/ov001 @ 0x0215E4B4; symbol: func_ov001_0215e4b4; size: 0x3C.
extern "C" int Script_SetGlobalIntegerAndFlag(IntegerParameterView *parameter) {
    unsigned char *state = (unsigned char *)ReadWordFieldAtOffset1C();
    if (!state) return 0;
    int value = ReadScriptParameterAsInteger(parameter);
    state[0x195b] |= 4;
    *(int *)(state + 0x9a8) = value;
    return 1;
}
