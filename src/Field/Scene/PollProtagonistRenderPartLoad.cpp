#include <globaldefs.h>
ARM

#include <Resource/GameResources.h>
struct GameState;struct AllocatorUnion;struct SafeAllocator;
struct Object {unsigned words[28];};
extern "C" GameResources* GameResources_GetInstance();
extern "C" int Ov017_TestNestedWordEqualsTwo(const unsigned char*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Zone3D_GetMainInstance();
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(void*);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void*);
extern "C" void TextureVRAM_CloneSavedAllocationBounds(const Object*,Object*);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void ZoneRenderPart_LoadSerializedDataWithAllocator(void*,const void*,int,SafeAllocator*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(char*);
static inline char *ResourceStateBlock(GameResources *r) {return r->unknown_2cc;}
// Original: arm9/ov017 @ 0x021B5DC4; symbol: func_ov017_021b5dc4; size: 0x13C.
// Polls background load, initializes protagonist render part under saved VRAM state.
extern "C" int PollProtagonistRenderPartLoad(unsigned char *p) {
 if(p[0x54]) {if(!Ov017_TestNestedWordEqualsTwo((unsigned char*)GameResources_GetInstance()))return 3;}
 else {void *loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x28))){
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,*(int*)(p+0x28))==2){
 void *file;unsigned size; Object saved;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x28),&file,&size);
 void *allocation=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,0x100);
 if(size && allocation){
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x40,allocation,0x100);
 GameState *game=(GameState*)_ZN9GameState11GetInstanceEv();unsigned char *global=(unsigned char*)Zone3D_GetMainInstance();
 *(void**)(p+0x20)=global+0x600+0x88*GameState_ReadProtagonistObjectIndex(game);
 _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(*(void**)(p+0x20));
 _ZN23ZoneContainerRenderPart5ResetEv(*(void**)(p+0x20));
 TextureVRAM_CloneSavedAllocationBounds((Object*)(ResourceStateBlock(GameResources_GetInstance())+0x230),&saved);
 Graphics_RestoreTextureImageAndPaletteVRAMState(&saved);
 ZoneRenderPart_LoadSerializedDataWithAllocator(*(void**)(p+0x20),file,size,(SafeAllocator*)(p+0x40));
 Object_InvokeSaveTextureImageVRAMState((char*)&saved);
 }}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x28));*(int*)(p+0x28)=-1;
 }}
 return *(int*)(p+0x28)<0?4:3;
}
