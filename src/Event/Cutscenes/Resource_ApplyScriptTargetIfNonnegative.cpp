#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" void ResourceHandle_SwitchTargetUnlessBlocked(void* state, int value);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int object, unsigned value, unsigned unused3, unsigned unused4);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x02163640; symbol: func_ov001_02163640; size: 0x68.
extern "C" int Resource_ApplyScriptTargetIfNonnegative(IntegerParameterView* parameter, int type) {
    int value = -1;
    if (type == 2) {
        Script_ReadParameterAsInteger(parameter);
        value = Script_ReadParameterAsInteger((IntegerParameterView*)((char*)parameter + 8));
    } else if (type == 1) {
        value = Script_ReadParameterAsInteger(parameter);
    }
    if (value < 0)
        return 0;
    ResourceHandle_SwitchTargetUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2, value);
    ((void (*)(int, unsigned))Bgm_StopActiveSequenceUnlessBlocked)((int)Main_UnknownRoleZeroInitializedStorage_Variant2, 0);
    return 1;
}
