#include <globaldefs.h>
ARM
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(void *, int);
extern "C" void Graphics_DestroyAllocationsAndSetDisplayControl(void *);
// Original: arm9/ov003 @ 0x0216D818; symbol: func_ov003_0216d818; size: 0x34.
extern "C" void ResetOverlayGraphicsAndGlobalLoaderState(void *state) {
    _ZN16BackgroundLoader13AddLockGlobalEv();
    _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    ResetGlobalOwnerAndEmbeddedSelectionState((void *)ReadWordFieldAtOffset1C());
    Object_ResetSelectionAndApplyConfiguredMode(*(void **)((char *)state + 0x12c0), 0);
    Graphics_DestroyAllocationsAndSetDisplayControl(state);
}
