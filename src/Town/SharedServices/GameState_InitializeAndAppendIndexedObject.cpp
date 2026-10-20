#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
extern "C" void Graphics_ClearAndStageSharedBuffers(char *);
extern "C" void Memory_InitializeTypeEighteenAllocatorState(void *, unsigned);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *p, unsigned int n);

// Original: arm9/ov003 @ 0x0217E5DC; symbol: func_ov003_0217e5dc; size: 0x54.
extern "C" void GameState_InitializeAndAppendIndexedObject(void *state, unsigned value) {
    _ZN9GameState11GetInstanceEv();
    void *owner = (void *)TextContext_GetSharedInstance();
    if (*(unsigned int *)((char *)owner + 0x998) != 0) {
        TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
        Graphics_ClearAndStageSharedBuffers((char *)owner);
    }
    Memory_InitializeTypeEighteenAllocatorState(*(void **)((char *)state + 0x3b04), value);
    LinkedQueue_AppendAndMarkActive(*(unsigned int **)((char *)state + 0x36fc), *(unsigned int *)((char *)state + 0x3b04));
}
