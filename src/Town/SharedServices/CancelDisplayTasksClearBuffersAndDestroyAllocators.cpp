#include <globaldefs.h>
ARM
struct Object;struct Obj;struct State;
extern "C" {
void* memset(void*,int,unsigned);void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void _ZN13SafeAllocator7DestroyEv(void*);
unsigned TextContext_GetSharedInstance();void Graphics_ClearAndStageSharedBuffers(char*);void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);void Graphics_ApplyMainBackgroundSnapshotAndClearPending(Object*);
void BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks(Obj*);void TextCanvas_ClearDisplayLayerBuffers(unsigned char*);void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(State*);void Graphics_ResetCountedTransferEntriesWithModeZero(State*);
void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);void Menu_DestroyQueuedRecordPanelResources(void*);
}
// Original: arm9/ov003 @ 0x021549A8; symbol: func_ov003_021549a8; size: 0x14C.
// Cancels background tasks and clears display buffers before destroying the eight allocator slots.
extern "C" void CancelDisplayTasksClearBuffersAndDestroyAllocators(char* p) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(int*)(p+0x1d0)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1d0));*(int*)(p+0x1d0)=-1;}
 if(*(int*)(p+0x20c)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x20c));*(int*)(p+0x20c)=-1;}
 if(*(void**)(p+0x204)){Menu_DestroyQueuedRecordPanelResources(*(void**)(p+0x204));*(void**)(p+0x204)=0;}
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x100;*(volatile unsigned short*)0x4000050=0;
 Graphics_ApplyMainBackgroundSnapshotAndClearPending((Object*)(p+0x160));
 State* display=*(State**)(p+0x18);if(display){TextCanvas_ClearDisplayLayerBuffers((unsigned char*)display);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(display);Graphics_ResetCountedTransferEntriesWithModeZero(display);BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks((Obj*)display);}
 if(*(void**)(p+0xc)){memset(*(void**)(p+0xc),0,32);_Z25CleanInvalidateCacheRangePKvj(*(void**)(p+0xc),32);LoadToMainBG1CharacterData(*(void**)(p+0xc),0,32);}*(void**)(p+0xc)=0;
 char* owner=(char*)TextContext_GetSharedInstance();if(*(int*)(owner+0x998)){TextWindow_ResetGlyphBuffersAndFrameContexts(owner);Graphics_ClearAndStageSharedBuffers(owner);}
 *(int*)(owner+0x2d8)=0;owner[0x2e6]=1;
 if(*(char**)p)for(unsigned char i=0;i<8;++i)_ZN13SafeAllocator7DestroyEv(*(char**)p+i*20);
}
