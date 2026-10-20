#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void SoundSfx_LoadGroupAndSaveSecondaryHeapState(State *p, int value, short key);
// Original: arm9/ov001 @ 0x02163970; symbol: func_ov001_02163970; size: 0x24.
extern "C" int Resource_UpdateStateFromScriptParameter(IntegerParameterView *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    ((void (*)(State *, int, int))SoundSfx_LoadGroupAndSaveSecondaryHeapState)((State *)Main_UnknownRoleZeroInitializedStorage, value, value);
    return 1;
}
