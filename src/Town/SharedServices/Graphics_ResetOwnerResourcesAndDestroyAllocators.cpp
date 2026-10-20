#include <globaldefs.h>
ARM
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" unsigned Window_IsVisible(void**);
extern "C" void Window_HideAndResetOptionSelection(void**);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
extern "C" void Window_ClearResourceBuffers(unsigned char*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBG1ScreenData(const void*,unsigned,unsigned);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov003 @ 0x02158D4C; symbol: func_ov003_02158d4c; size: 0x148.
extern "C" void Graphics_ResetOwnerResourcesAndDestroyAllocators(unsigned char* p) {
 BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());
 if(*(void***)(p+0x570) && Window_IsVisible(*(void***)(p+0x570))) Window_HideAndResetOptionSelection(*(void***)(p+0x570));
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x100;
 *(volatile unsigned short*)0x4000050=0;
 Graphics_ApplyMainBackgroundSnapshotAndClearPending(p+0x80);
 Window_ClearResourceBuffers(p+0xf4);
 Graphics_ResetCountedThirtyTwoByteTransfers(p+0xf4);
 Window_ResetResourceTransfers(p+0xf4);
 Selection_ReleaseAttachedDisplayResources(p+0xf4);
 _ZN13SafeAllocator5ResetEv(p+0x28);
 char* buffer=_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x28),0x800);
 memset(buffer,0,0x800);
 _Z25CleanInvalidateCacheRangePKvj(buffer,0x20);
 LoadToMainBG1CharacterData(buffer,0,0x20);
 LoadToMainBG1ScreenData(buffer,0,0x800);
 char* context=(char*)TextContext_GetSharedInstance();
 Graphics_ClearAndStageSharedBuffers(context);
 TextWindow_ResetGlyphBuffersAndFrameContexts(context);
 *(unsigned*)(p+0x7c)=0;
 *(unsigned*)(p+0x57c)=0;
 void* allocators[5]={0};
 allocators[0]=p+0x3c;
 allocators[1]=p+0x28;
 allocators[2]=p+0x14;
 allocators[3]=p;
 for(int i=0;allocators[i];i++) {
  if(_ZNK13SafeAllocator18GetSignedAllocatorEv(allocators[i])) _ZN13SafeAllocator7DestroyEv(allocators[i]);
 }
}
