#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/HMRFAllocator.h>
ARM
#pragma always_inline on
struct AllocatorUnion;struct State {int unknown[12];int count;};
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void AllocatorUnion_LeaveUnchanged(void*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" void ActorPool_Initialize(unsigned char*);
extern "C" void ActorPool_CaptureActorSummaries(char*,short);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" int DisplayContext_ReportRequestComplete();
extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
extern "C" void* Network_GetTaggedAcknowledgementTable();
extern "C" char* Network_FindTaggedAcknowledgement(char*,int,int);
extern "C" void Network_InsertTaggedAcknowledgement(void*,int,int);
extern "C" void Network_RemoveTaggedAcknowledgement(unsigned,unsigned,unsigned);
extern "C" void Network_RequestTaggedAcknowledgement(void*,unsigned,unsigned,int);
extern "C" void GameState_DestroyFieldObjectsAndResetAllocators(unsigned char*);
extern "C" void* __clear(void*,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" char PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEventLv5S[],PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEvsptLv5S[],PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEventS[],PrepareSceneArchiveLoadsAndTaggedRecords_TextGp2[],PrepareSceneArchiveLoadsAndTaggedRecords_FormatSStb[],PrepareSceneArchiveLoadsAndTaggedRecords_FormatSLGBin[],PrepareSceneArchiveLoadsAndTaggedRecords_PathDataAniPenPac[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
static inline SafeAllocator *ResourceAllocator(GameResources *resources,int index) {if(index<0 || index>=17)return 0;return &resources->allocator_array_38[index];}
// Original: arm9/ov001 @ 0x02154F24; symbol: func_ov001_02154f24; size: 0x384.
// Allocates scene loading space, queues paired archive files, and updates tagged scene records.
extern "C" int PrepareSceneArchiveLoadsAndTaggedRecords(char *self) {
 GameState *game=GameState::GetInstance();
 GameResources *resources=GameResources_GetInstance();
 BackgroundLoader *loader=BackgroundLoader::GetInstance();
 void *container=ActorPool_GetGlobalInstance();
 void *zone=Zone3D_GetMainInstance();
 void *connection=Network_GetConnectionManager();
 if(!GameResources_GetMaskedPrimaryFlags(resources,0x1000)) {
  DisplayContext_GetGlobalInstance();
  if(!DisplayContext_ReportRequestComplete())return H(self,10);
 }
 if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return H(self,10);
 AllocatorUnion_LeaveUnchanged(Main_UnknownRoleZeroInitializedStorage_Variant3);
 Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x40400);
 AllocatorUnion_LeaveUnchanged(Main_UnknownRoleZeroInitializedStorage_Variant3);
 if((H(self,0x50)&1) && !GameResources_GetMaskedPrimaryFlags(resources,0x1000)) {
  ((void(*)(char*,unsigned short))ActorPool_CaptureActorSummaries)((char*)container,H(zone,0));
  GameState_DestroyFieldObjectsAndResetAllocators((unsigned char*)resources);
  ActorPool_Initialize((unsigned char*)ActorPool_GetGlobalInstance());
  zone=ResourceAllocator(resources,7);
  W(self,0x90)=((SafeAllocator*)zone)->GetSize();
  void *allocation=((SafeAllocator*)zone)->GetSignedAllocator();
  ((SafeAllocator*)zone)->Destroy();
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
 } else if(H(self,0x50)&4) {
  ((void(*)(char*,unsigned short))ActorPool_CaptureActorSummaries)((char*)container,H(zone,0));
  GameState_DestroyFieldObjectsAndResetAllocators((unsigned char*)resources);
  ActorPool_Initialize((unsigned char*)ActorPool_GetGlobalInstance());
  ((SafeAllocator*)((char*)resources+0xc4))->Reset();
 }
 unsigned allocationSize=0x40400;
 if(H(self,0x50)&8)allocationSize-=0xa000;
 if(H(self,0x50)&1)allocationSize+=W(self,0x90);
 if(!GameResources_GetMaskedPrimaryFlags(resources,0x1000)) {
  void *allocation=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,allocationSize);
  ((SafeAllocator*)(self+0x7c))->CreateTypeA(allocation,allocationSize);
  ((SafeAllocator*)(self+0x7c))->Reset();
 } else (*(HMRFAllocator**)(self+0x7c))->Free(1);
 AllocatorUnion_LeaveUnchanged(Main_UnknownRoleZeroInitializedStorage_Variant3);
 char path[80],baseName[16],firstName[16],secondName[32];
 State state;
 if(B(self,0x9c))sprintf(path,PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEventLv5S,self+0x3e);
 else if(B(self,0x13))sprintf(path,PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEvsptLv5S,self+0x3e);
 else sprintf(path,PrepareSceneArchiveLoadsAndTaggedRecords_PathDataEventS,self+0x3e);
 memcpy(path+(strlen(path)-4),PrepareSceneArchiveLoadsAndTaggedRecords_TextGp2,4);
 __clear(baseName,16);
 memcpy(baseName,self+0x3e,strlen(self+0x3e)-4);
 sprintf(firstName,PrepareSceneArchiveLoadsAndTaggedRecords_FormatSStb,baseName);
 sprintf(secondName,PrepareSceneArchiveLoadsAndTaggedRecords_FormatSLGBin,baseName);
 loader->AddFence();
 W(self,0x74)=loader->QueueLoadFileInGP2(path,firstName,(SafeAllocator*)(self+0x7c));
 W(self,0x78)=loader->QueueLoadFileInGP2(path,secondName,(SafeAllocator*)(self+0x7c));
 if(H(self,0x50)&0x200)W(self,0x110)=loader->QueueLoadFile(PrepareSceneArchiveLoadsAndTaggedRecords_PathDataAniPenPac,(SafeAllocator*)(self+0x7c));
 void *global=GameState_GetSerializedProgressState();
 state.unknown[2]=H(self,8);
 if(Script_ExecuteFirstSatisfiedTriggerGroup(global,10,&state))Script_DispatchResultCommandsToWorld(&state);
 char *records=(char*)Network_GetTaggedAcknowledgementTable();
 char *entry=Network_FindTaggedAcknowledgement(records,1,0x71e8);
 if(Network_IsParentOrOffline((unsigned*)connection) && !entry && !Network_FindTaggedAcknowledgement(records,1,H(self,0x18))) {
  Network_RemoveTaggedAcknowledgement((unsigned)records,1,-1);
  Network_InsertTaggedAcknowledgement(records,1,H(self,0x18));
 }
 Network_RequestTaggedAcknowledgement(records,GameState_ReadProtagonistObjectIndex(game),1,H(self,0x18));
 return 2;
}
