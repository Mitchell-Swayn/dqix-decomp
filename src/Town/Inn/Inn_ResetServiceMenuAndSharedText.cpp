#include <globaldefs.h>
ARM
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
extern "C" void Window_PopCanvasesAndResetSelection(void *, int);
extern "C" void Inn_ReleaseServiceMenuGraphics(void *);
// Original: arm9/ov003 @ 0x0216D818; symbol: func_ov003_0216d818; size: 0x34.
extern "C" void Inn_ResetServiceMenuAndSharedText(void *state) {
    _ZN16BackgroundLoader13AddLockGlobalEv();
    _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    TextWindow_ResetGlyphBuffersAndFrameContexts((void *)TextContext_GetSharedInstance());
    Window_PopCanvasesAndResetSelection(*(void **)((char *)state + 0x12c0), 0);
    Inn_ReleaseServiceMenuGraphics(state);
}
