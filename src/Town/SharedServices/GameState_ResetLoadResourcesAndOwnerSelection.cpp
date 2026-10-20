#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(const void *);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
extern "C" void Window_PopCanvasesAndResetSelection(void *, int);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
extern "C" void Graphics_FinalizeDisplayStateAndRestoreControls(void *);
// Original: arm9/ov003 @ 0x0217DC40; symbol: GameState_ResetLoadResourcesAndOwnerSelection; size: 0x54.
// Locks and frees BackgroundLoader allocations, removes the saved task unless it is -1, resets the object at +0x90, clears owner selection state, and runs the owner reset helper.
extern "C" void GameState_ResetLoadResourcesAndOwnerSelection(unsigned char *state) {
    unsigned owner = TextContext_GetSharedInstance(state);
    _ZN16BackgroundLoader13AddLockGlobalEv();
    _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    int task = *(int *)(state + 0xc);
    if (task != -1)
        _ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(), task);
    Window_PopCanvasesAndResetSelection(*(void **)(state + 0x90), 0);
    TextWindow_ResetGlyphBuffersAndFrameContexts((void *)owner);
    Graphics_FinalizeDisplayStateAndRestoreControls(state);
}
