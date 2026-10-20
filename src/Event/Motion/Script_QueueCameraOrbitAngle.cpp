#include <globaldefs.h>
ARM
extern "C" unsigned int Script_ReadParameterAsFloat(void*);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(void);
extern "C" void CutsceneCamera_QueueOrbitAngle(void*, int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventGetObjectSession_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0215D560; symbol: func_ov001_0215d560; size: 0x38.
extern "C" int Script_QueueCameraOrbitAngle(void* parameter) {
    unsigned int value = _fmul(0x45800000, Script_ReadParameterAsFloat(parameter));
    int integer = _ffix();
    void* object = *(void**)((char*)&EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24);
    CutsceneCamera_QueueOrbitAngle(object, integer);
    return 1;
}
