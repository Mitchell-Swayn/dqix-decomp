#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void CutsceneCamera_QueueShakeDelay(void *, int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215D8D0; symbol: func_ov001_0215d8d0; size: 0x24.
extern "C" int Script_QueueCameraShakeDelay(void *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    CutsceneCamera_QueueShakeDelay((void *)EventGetObjectSession_UnknownRoleZeroInitializedStorage[9], value);
    return 1;
}
