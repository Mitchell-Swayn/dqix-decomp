#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Zone3D.h>
#include <World/Object3D.h>
ARM
#pragma always_inline on
struct Obj;struct State;struct Record;
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void WorldMap_SetFadeInBlocked(char*,int);
extern "C" void* Network_GetConnectionManager();
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" void* ActorPool_GetSpriteResourceDirectory(void*);
extern "C" void Resource_InitializeNamedGraphicCache(Obj*,unsigned,SafeAllocator*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" void Graphics_InitializeSpriteTransformDefaults(State*);
extern "C" void SpriteAnimation_ResetTrackList(unsigned*);
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
extern "C" int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);
extern "C" void Object_AllocateFiveSafeAllocatorsAndThreeEntries(State*,SafeAllocator*);
extern "C" void QuestMessagePanel_Initialize(unsigned char*,unsigned char);
extern "C" void Bgm_SetPlaybackVolumeAndFade(unsigned char*,unsigned char,int);
extern "C" void Camera_DisableTargetFollowing(void*);
extern "C" void Camera_DisableOrbitInput(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void Memory_InitializeContextBuffersWhenEnabled(int,int,void*);
extern "C" int Event_SelectScriptEntryAndRefreshSessions(void*);
extern "C" void Resource_AllocateOverlayScriptObjectBuffers(unsigned);
extern "C" void Graphics_InitializeAndCopyDisplayRecords();
extern "C" void Memory_ResetAllocatorCache(void*);
extern "C" void Event_SetAllocatorSlot(unsigned,unsigned);
extern "C" void Script_InvokeGlobalCommandAndClearStatus(unsigned,unsigned);
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void*);
extern "C" void* GameResources_GetAlternateLeaderModel(void*);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[],Main_UnknownRoleZeroInitializedStorage_Variant2[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct SceneParameters {unsigned words[26];};
static inline void ApplyLoadedSceneFeatureOverrides(SceneParameters parameters,bool alternate) {
 GameState *game=GameState::GetInstance();
 GameResources *resources=GameResources_GetInstance();
 Zone3D *zone=(Zone3D*)Zone3D_GetMainInstance();
 Network_GetConnectionManager();
 GameState_GetIndexList(game);
 SystemState_GetGlobalFlags();
 if(!(H(&parameters,0x44)&0x400))zone->ApplyBMDJFlag4Overrides(alternate);
 void *global=GameState_GetSerializedProgressState();
 *(signed char*)((char*)global+0x490)=-1;
 if(B(&parameters,7)) {
  Object3D *object=(Object3D*)GameResources_GetAlternateLeaderModel(resources);
  if(object)object->MakeHidden();
 }
}
// Original: arm9/ov001 @ 0x021552A8; symbol: func_ov001_021552a8; size: 0x538.
// Completes queued scene archives, initializes optional graphics resources, and applies feature overrides.
extern "C" int CompleteSceneArchiveLoadsAndInitializeResources(char *self) {
 char *display;GameState *game;GameResources *resources;BackgroundLoader *loader;int featureIndex;int count;Zone3D_BMDJStruct *group;void *global;
 game=GameState::GetInstance();
 resources=GameResources_GetInstance();
 loader=BackgroundLoader::GetInstance();
 void *fieldObject=GameState_GetFieldOrbitCamera(game);
 void *unknown=game->GetUnknownGameObject();
 display=(char*)resources+0x2cc;
 if(!loader->GetTaskStatus(W(self,0x74)))return H(self,10);
 if(!loader->GetTaskStatus(W(self,0x78)))return H(self,10);
 if((H(self,0x50)&0x200) && !loader->GetTaskStatus(W(self,0x110)))return H(self,10);
 if(loader->GetDetailedTaskStatus(W(self,0x74))!=2 || loader->GetDetailedTaskStatus(W(self,0x78))!=2) {
  void *allocation=((SafeAllocator*)(self+0x7c))->GetSignedAllocator();
  ((SafeAllocator*)(self+0x7c))->Destroy();
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
  loader->RemoveTask(W(self,0x74));loader->RemoveTask(W(self,0x78));loader->RemoveTask(W(self,0x110));
  ((void(*)(unsigned char*,unsigned,int))Bgm_SetPlaybackVolumeAndFade)(Main_UnknownRoleZeroInitializedStorage_Variant2,W(self,0x94),0);
  FieldEvent_ReleaseResourcesAndResumeFieldControl(self);B(self,1)=1;return H(self,10);
 }
 void *firstFile,*secondFile;unsigned firstSize,secondSize;
 loader->GetLoadedFileByID(W(self,0x74),&firstFile,&firstSize);
 loader->GetLoadedFileByID(W(self,0x78),&secondFile,&secondSize);
 if(H(self,0x50)&2) {
  P(self,0x120)=(char*)((SafeAllocator*)(self+0x7c))->Allocate(0xe4);
  QuestMessagePanel_Initialize((unsigned char*)P(self,0x120),0);
  void *graphics=(void*)TextContext_GetSharedInstance();
  void *allocation=((SafeAllocator*)(self+0x7c))->Allocate(0xa000);
  ((SafeAllocator*)(self+0x124))->CreateTypeA(allocation,0xa000);
  ((SafeAllocator*)(self+0x124))->Reset();
  Object_AllocateFiveSafeAllocatorsAndThreeEntries((State*)P(self,0x120),(SafeAllocator*)(self+0x124));
  P(graphics,0x8c)=P(self,0x120);
 }
 if((H(self,0x50)&1)||(H(self,0x50)&4))
  Resource_InitializeNamedGraphicCache((Obj*)ActorPool_GetSpriteResourceDirectory(ActorPool_GetGlobalInstance()),12,(SafeAllocator*)(self+0x7c));
 if(H(self,0x50)&0x200) {
  ((SafeAllocator*)(self+0x7c))->GetMaxPossibleAllocation();
  P(self,0x170)=(char*)((SafeAllocator*)(self+0x7c))->Allocate(0x230);
  P(self,0x168)=(char*)((SafeAllocator*)(self+0x7c))->Allocate(0x54);
  P(self,0x16c)=(char*)((SafeAllocator*)(self+0x7c))->Allocate(8);
  for(int i=0;i<14;++i)Graphics_InitializeSpriteTransformDefaults((State*)(P(self,0x170)+i*40));
  SpriteAnimation_ResetTrackList((unsigned*)P(self,0x16c));
  Graphics_InitializeSpriteResourceBuffers((unsigned char*)P(self,0x168));
  B(P(self,0x168),0x50)=0;
  char *record=P(self,0x168);
  P(record,0x40)=P(self,0x170);H(record,0x4c)=14;
  P(P(self,0x168),0x3c)=P(self,0x16c);
  char *out;void *file;unsigned size;
  loader->GetLoadedFileByID(W(self,0x110),&file,&size);
  int count=ResourceFile_CountActiveStrideRecords((Record*)file);
  for(int i=0;i<count;++i) {
   unsigned blockSize;
   void *block=ResourceFile_GetPayloadByIndex((char*)file,i,&out,&blockSize);
   Graphics_DispatchDataByResourceMagic((int)P(self,0x168),block,blockSize,(int)(self+0x7c));
  }
  loader->RemoveTask(W(self,0x110));W(self,0x110)=-1;
 }
 Resource_AllocateOverlayScriptObjectBuffers((unsigned)(self+0x7c));
 Graphics_InitializeAndCopyDisplayRecords();
 Memory_InitializeContextBuffersWhenEnabled((int)firstFile,0,self+0x7c);
 Memory_ResetAllocatorCache(self+0x7c);
 if(H(self,0x50)&4)Event_SetAllocatorSlot(1,(unsigned)((char*)resources+0xc4));
 Script_InvokeGlobalCommandAndClearStatus((unsigned)secondFile,secondSize);
 Object3D *member=(Object3D*)game->GetPartyMemberByIndex(0);
 if(member && (W(P(member,0x130),0)&1))B(self,0x107)=1;
 loader->RemoveTask(W(self,0x74));loader->RemoveTask(W(self,0x78));
 TextureVRAM_SnapshotAllocationBounds(display+0xbd0);
 if(!Event_SelectScriptEntryAndRefreshSessions((void*)H(self,0x4c))) {
  void *allocation=((SafeAllocator*)(self+0x124))->GetSignedAllocator();
  if(allocation) {((SafeAllocator*)(self+0x124))->Destroy();((SafeAllocator*)(self+0x7c))->Free(allocation);}
  allocation=((SafeAllocator*)(self+0x7c))->GetSignedAllocator();
  ((SafeAllocator*)(self+0x7c))->Destroy();Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
  FieldEvent_ReleaseResourcesAndResumeFieldControl(self);B(self,1)=1;return H(self,10);
 }
 global=GameState_GetSerializedProgressState();
 group=((Zone3D*)Zone3D_GetMainInstance())->GetBMDJGroupAtIndex(0);
 count=W(group,0x14);
 if(group) {
  memset((char*)global+0x45b,0,32);
  for(featureIndex=0;featureIndex<count;++featureIndex) {
   char *entry=P(group,0x44)+featureIndex*0x70;
   if(entry && !(H(entry,2)&4))BitArray_SetIndexedBoolean(global,(unsigned char*)global+0x45b,(unsigned char)featureIndex,1);
  }
 }
 ApplyLoadedSceneFeatureOverrides(*(SceneParameters*)(self+12),*(bool*)(self+0x9c));
 Camera_DisableTargetFollowing(fieldObject);Camera_DisableOrbitInput(fieldObject);
 H(unknown,0xb2)=0;
 WorldMap_SetFadeInBlocked(P(resources,0x36d0),0);
 return 3;
}
