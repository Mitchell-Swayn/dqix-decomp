#include <globaldefs.h>
ARM
// Original: arm9/ov001:02161374; For each integer parameter, replaces the low 27 bits of the resource-selected packed word at +0xf8 while preserving its high five bits.
#pragma optimization_level 4
extern "C" void *GameResources_GetInstance();
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *);

extern "C" int GameState_ReplacePackedResourceLow27BitsFromParameters(IntegerParameterView *parameters, int count) {
    unsigned char *base = (unsigned char *)GameResources_GetInstance() + 0x3000;
    unsigned int *packed = (unsigned int *)(*(unsigned char **)(base + 0x734) + 0xf8);
    for (int i = 0; i < count; ++i) {
        int value = Script_ReadParameterAsInteger(parameters);
        unsigned int old = *packed;
        parameters = (IntegerParameterView *)((unsigned char *)parameters + 8);
        unsigned int merged = (unsigned int)value | ((unsigned int)((int)(old << 5)) >> 5);
        merged = (old & 0xf8000000) | (merged & ~0xf8000000);
        *packed = merged;
    }
    return 1;
}
