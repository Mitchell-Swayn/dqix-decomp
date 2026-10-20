#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Graphics_ClearAndStageSharedBuffers(void*);
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
extern "C" void* GameState_GetFieldOrbitCamera(void*);
extern "C" void Camera_ClearFollowControlFlags(void*,unsigned char);
// Original: arm9/ov017 @ 0x021AC32C; symbol: Graphics_ResetSharedBuffersAndReleaseStateAllocator; size: 0x84.
// Resets shared graphics and background tasks, releases embedded allocator, and clears object flags.
extern "C" void Graphics_ResetSharedBuffersAndReleaseStateAllocator(char* self) {
 char* owner=TextContext_GetSharedInstance();TextWindow_ResetGlyphBuffersAndFrameContexts(owner);Graphics_ClearAndStageSharedBuffers(owner);
 BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());
 void* game=_ZN9GameState11GetInstanceEv();GameObject_RequestMovementInputEnable(_ZN9GameState20GetUnknownGameObjectEv(game));
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+16);
 if(allocation){_ZN13SafeAllocator7DestroyEv(self+16);Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);FileCache_RestoreRomTablesIfSpaceAvailable();}
 *(int*)(self+12)=0;void* object=GameState_GetFieldOrbitCamera(game);if(object)Camera_ClearFollowControlFlags(object,3);
}
