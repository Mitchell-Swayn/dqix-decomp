#include <globaldefs.h>
ARM
#pragma force_active on
// Keep state snapshots and narrowing operations visible to the original compiler.
#pragma opt_propagation off
#pragma opt_common_subs off
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" char* TextContext_GetSharedInstance();
extern "C" void TextContext_SetMessageWindow(void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" void Network_QueueObjectShortValuesInTwoChunks(int, int);
// Shared overlay address 0x0218B5C0: ov016 no-op / ov017 party-status tracking.
// The original relocation binds the common address through the ov016 symbol.
extern "C" void Movie_NoOpOverlayHook(int, int);
extern "C" void* DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(void*);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Window_ClearResourceBuffers(void*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Selection_ReleaseAttachedDisplayResources(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*, unsigned, unsigned);
extern "C" void GameState_ResetNestedAllocatorState(void*);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void Menu_DestroyQueuedRecordPanelResources(void*);
// Original: arm9/ov002 @ 0x021556FC; symbol: func_ov002_021556fc; size: 0x264.
// Releases controller load tasks, window and display resources, member tracking and eight owned allocators.
extern "C" void PartyMenu_ReleaseControllerResources(char* self)
{
    TextContext_SetMessageWindow(TextContext_GetSharedInstance(), 0);
    char* members = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    for (int i = 0; i < (unsigned char)members[0xf7c]; ++i)
        Network_QueueObjectShortValuesInTwoChunks((unsigned char)(members + i)[0xf78], 0);
    Movie_NoOpOverlayHook(1, -1);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (int i = 0; i < 5; ++i) {
        if (*(int*)(self + i * 4 + 0x1ba4) >= 0) loader->RemoveTask(*(int*)(self + i * 4 + 0x1ba4));
        *(int*)(self + i * 4 + 0x1ba4) = -1;
    }
    if (WORD(0x2458) >= 0) { loader->RemoveTask(WORD(0x2458)); WORD(0x2458) = -1; }
    if (WORD(0x1bc4) >= 0) { loader->RemoveTask(WORD(0x1bc4)); WORD(0x1bc4) = -1; }
    BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());
    volatile unsigned* display = (volatile unsigned*)0x04000000;
    *display = (*display & ~0x1f00u) | 0x100;
    *(volatile unsigned short*)0x04000050 = 0;
    Graphics_ApplyMainBackgroundSnapshotAndClearPending(self + 0x38);
    TextWindow_ResetGlyphBuffersAndFrameContexts(TextContext_GetSharedInstance());
    POINTER(0x1bd0) = 0;
    Window_ClearResourceBuffers(self + 0xec8);
    Graphics_ResetCountedThirtyTwoByteTransfers(self + 0xec8);
    Window_ResetResourceTransfers(self + 0xec8);
    Selection_ReleaseAttachedDisplayResources(self + 0xec8);
    if (POINTER(0x1bd8)) {
        memset(POINTER(0x1bd8), 0, 32);
        _Z25CleanInvalidateCacheRangePKvj(POINTER(0x1bd8), 32);
        LoadToMainBG1CharacterData(POINTER(0x1bd8), 0, 32);
    }
    POINTER(0x1bd8) = 0;
    GameState_ResetNestedAllocatorState(self);
    OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    if (POINTER(0x2468)) Menu_DestroyQueuedRecordPanelResources(POINTER(0x2468));
    WORD(0x1bd4) = 0;
    SafeAllocator* allocators[8] = {
        (SafeAllocator*)(self + 0x810), (SafeAllocator*)(self + 0x828),
        (SafeAllocator*)(self + 0x83c), (SafeAllocator*)(self + 0x850),
        (SafeAllocator*)(self + 0x864), (SafeAllocator*)(self + 0x878),
        (SafeAllocator*)(self + 0x88c), (SafeAllocator*)(self + 0x8a0)
    };
    for (int i = 0; i < 8; ++i) {
        SafeAllocator* allocator = allocators[i];
        if (allocator->GetSignedAllocator()) allocator->Destroy();
    }
}
