#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int param_1, unsigned int param_2, unsigned int unused3, unsigned int unused4);
// Original: arm9/ov001 @ 0x0216393C; symbol: func_ov001_0216393c; size: 0x2C.
extern "C" int GameState_DispatchWithScriptValueOrDefault30(IntegerParameterView *parameter, int useParameter) {
    unsigned int value = 0x1e;
    if (useParameter > 0)
        value = Script_ReadParameterAsInteger(parameter);
    ((void (*)(int, unsigned int))Bgm_StopActiveSequenceUnlessBlocked)((int)&Main_UnknownRoleZeroInitializedStorage_Variant2, value);
    return 1;
}
