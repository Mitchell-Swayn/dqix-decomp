#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance(void*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void Object_SetUnsignedIntAtOffset4(int, unsigned);
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned);
// Original: arm9/ov001 @ 0x0215F1B0; symbol: func_ov001_0215f1b0; size: 0x4C.
extern "C" int Script_SetOrClearResourceMask(IntegerParameterView *parameter) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *resources = GameResources_GetInstance(game);
    int mask = ReadScriptParameterAsInteger(parameter);
    int enabled = ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    if (enabled) Object_SetUnsignedIntAtOffset4((int)resources, (unsigned)mask);
    else ClearWordAtOffset4MaskedBits((int)resources, (unsigned)mask);
    return 1;
}
