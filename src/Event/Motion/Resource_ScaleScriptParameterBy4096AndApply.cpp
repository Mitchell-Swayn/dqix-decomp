#include <globaldefs.h>
ARM
struct FloatParameterView;
extern "C" ARM unsigned int Script_ReadParameterAsFloat(FloatParameterView *parameter);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void CutsceneCamera_QueueOrbitDistance(void *, int);
// Original: arm9/ov001 @ 0x0215D5D0; symbol: func_ov001_0215d5d0; size: 0x38.
extern "C" int Resource_ScaleScriptParameterBy4096AndApply(FloatParameterView *parameter) {
    int scaled = _ffix(_fmul(0x45800000, Script_ReadParameterAsFloat(parameter)));
    void *object = *(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24);
    CutsceneCamera_QueueOrbitDistance(object, scaled);
    return 1;
}
