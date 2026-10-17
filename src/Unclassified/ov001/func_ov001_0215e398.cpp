#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordFieldAtOffset1C(void);
extern "C" void ClearAndStageSharedGraphicsBuffers(char *p);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *p);
// Original: arm9/ov001 @ 0x0215E398; symbol: func_ov001_0215e398; size: 0x20.
extern "C" unsigned func_ov001_0215e398(void) {
    unsigned value = ReadWordFieldAtOffset1C();
    ClearAndStageSharedGraphicsBuffers((char *)value);
    ResetGlobalOwnerAndEmbeddedSelectionState((void *)value);
    return 1;
}
