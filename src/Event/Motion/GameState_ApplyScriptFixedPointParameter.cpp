#include <globaldefs.h>
ARM
struct FloatParameterView;
extern "C" float Script_ReadParameterAsFloat(FloatParameterView *parameter);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void *EventGetObjectSession_UnknownRoleZeroInitializedStorage;
extern "C" void CutsceneCamera_QueueOrbitHeight(void *, int);
// Original: arm9/ov001 @ 0x0215D598; symbol: func_ov001_0215d598; size: 0x38.
extern "C" int GameState_ApplyScriptFixedPointParameter(FloatParameterView *parameter) {
    int value = (int)(4096.0f * Script_ReadParameterAsFloat(parameter));
    CutsceneCamera_QueueOrbitHeight(*(void **)((unsigned char *)&EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24), value);
    return 1;
}
