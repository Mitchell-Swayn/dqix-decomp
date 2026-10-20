#include <globaldefs.h>
ARM
struct Owner;
extern "C" {
void* SystemState_GetGlobalFlags();
void SystemState_ClearFlags(unsigned*,unsigned);
void CharacterPreview_ResetModelsAndReleaseAllocators(unsigned char*);
unsigned TextContext_GetSharedInstance();
void TextEntry_ResetGlyphCacheAndTextureAllocator(Owner*);
void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
void Graphics_ClearAndStageSharedBuffers(char*);
void Graphics_FinalizeSpriteResourceBuffers(void*);
unsigned Graphics_GetBackgroundResourceOwner();
void TextCache_ResetBeforeStorageRelease(void*);
void Graphics_ClearScreenBuffer(unsigned char*,void*);
void Graphics_CleanConfiguredDestinationCache(void*,int);
void Graphics_TransferScreenBuffer(void*,int);
void Graphics_ResetLoadedLayerResources(unsigned char*);
void Selection_ReleaseAttachedDisplayResources(unsigned char*);
void _ZN13SafeAllocator7DestroyEv(void*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
}
// Original: arm9/ov009 @ 0x02184848; symbol: func_ov009_02184848; size: 0x1D0.
// Releases paired object resources, six buffer records and nested allocators in reverse order.
extern "C" void ReleaseNestedAllocatorStorage(unsigned char* p) {
 if(p[0xd95]==1)SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),15);
 CharacterPreview_ResetModelsAndReleaseAllocators(*(unsigned char**)(p+0x7f0));
 CharacterPreview_ResetModelsAndReleaseAllocators(*(unsigned char**)(p+0x7f4));
 unsigned owner=TextContext_GetSharedInstance();
 TextEntry_ResetGlyphCacheAndTextureAllocator((Owner*)owner);
 TextWindow_ResetGlyphBuffersAndFrameContexts((void*)owner);
 Graphics_ClearAndStageSharedBuffers((char*)owner);
 if(*(void**)(p+0x7d8))Graphics_FinalizeSpriteResourceBuffers(*(void**)(p+0x7d8));
 if(*(void**)(p+0x7e4))Graphics_FinalizeSpriteResourceBuffers(*(void**)(p+0x7e4));
 TextCache_ResetBeforeStorageRelease((void*)Graphics_GetBackgroundResourceOwner());
 unsigned char* records[6]={p+0x138,p+0x158,p+0x178,p+0x198,p+0x1b8,p+0x1d8};
 for(int i=0;i<6;i++) {
  unsigned char* record=records[i];
  Graphics_ClearScreenBuffer(record,0);
  Graphics_CleanConfiguredDestinationCache(record,0);
  Graphics_TransferScreenBuffer(record,0);
  Graphics_ResetLoadedLayerResources(record);
 }
 Selection_ReleaseAttachedDisplayResources(p+0x1f8);
 Selection_ReleaseAttachedDisplayResources(p+0x2b4);
 *(unsigned*)(p+0xf8)=0;
 *(unsigned*)(p+0x7d0)=0;
 *(unsigned*)(p+0x7d4)=0;
 if(*(char**)(p+0xb8)) {
  _ZN13SafeAllocator7DestroyEv(*(char**)(p+0xb8));
  _ZN13SafeAllocator7DestroyEv(*(char**)(p+0xb8)+0x14);
 }
 if(*(void**)(p+0xb4)) _ZN13SafeAllocator7DestroyEv(*(void**)(p+0xb4));
 unsigned char* allocators[10]={0};
 allocators[0]=p+0xa0;allocators[1]=p+0x8c;allocators[2]=p+0x78;allocators[3]=p+0x64;allocators[4]=p+0x50;allocators[5]=p+0x3c;allocators[6]=p+0x28;allocators[7]=p+0x14;allocators[8]=p;
 for(int i=0;allocators[i];i++)if(_ZNK13SafeAllocator18GetSignedAllocatorEv(allocators[i]))_ZN13SafeAllocator7DestroyEv(allocators[i]);
}
