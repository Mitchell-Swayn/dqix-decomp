#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void CutsceneCamera_QueuePairedPathDuration(void *object, int value);
// Original: arm9/ov001 @ 0x0215D784; symbol: func_ov001_0215d784; size: 0x24.
extern "C" int GameState_DispatchScriptIntegerToGlobalObject(IntegerParameterView *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    void *object = *(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24);
    CutsceneCamera_QueuePairedPathDuration(object, value);
    return 1;
}
