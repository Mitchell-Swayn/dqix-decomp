#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
extern "C" void ClearAndStageSharedGraphicsBuffers(char *);
extern "C" void Memory_InitializeTypeEighteenAllocatorState(void *, unsigned);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);

// Original: arm9/ov003 @ 0x0217E5DC; symbol: func_ov003_0217e5dc; size: 0x54.
extern "C" void GameState_InitializeAndAppendIndexedObject(void *state, unsigned value) {
    _ZN9GameState11GetInstanceEv();
    void *owner = (void *)ReadWordFieldAtOffset1C();
    if (*(unsigned int *)((char *)owner + 0x998) != 0) {
        ResetGlobalOwnerAndEmbeddedSelectionState(owner);
        ClearAndStageSharedGraphicsBuffers((char *)owner);
    }
    Memory_InitializeTypeEighteenAllocatorState(*(void **)((char *)state + 0x3b04), value);
    AppendLinkedNodeAndMarkActive(*(unsigned int **)((char *)state + 0x36fc), *(unsigned int *)((char *)state + 0x3b04));
}
