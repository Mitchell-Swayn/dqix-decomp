#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance(void*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void GameResources_SetSecondaryFlags(int, unsigned);
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned);
// Original: arm9/ov001 @ 0x0215F1B0; symbol: func_ov001_0215f1b0; size: 0x4C.
extern "C" int Script_SetOrClearResourceMask(IntegerParameterView *parameter) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *resources = GameResources_GetInstance(game);
    int mask = Script_ReadParameterAsInteger(parameter);
    int enabled = Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    if (enabled) GameResources_SetSecondaryFlags((int)resources, (unsigned)mask);
    else GameResources_ClearSecondaryFlags((int)resources, (unsigned)mask);
    return 1;
}
