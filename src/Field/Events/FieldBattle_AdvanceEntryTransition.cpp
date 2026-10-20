#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(void*);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* Zone3D_GetMainInstance();
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* ColorAnimation_GetGlobalInstance();
extern "C" unsigned ColorAnimation_GetProgress(void*);
// Original soft-float runtime ABI: the float bit pattern is supplied in r0.
extern "C" int _ffix(unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(void*,unsigned);
extern "C" void _ZN6Zone3D20RecordBMDJFlag4StateEv(void*);
extern "C" int PollAndConsumeBackgroundResourceTask(void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" int LinkedList_ContainsTag(void*,int);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
extern "C" int Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(void*,int,const void*,unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void Bgm_EnterSecondaryPlayback(void*,int);
extern "C" void Bgm_SetPlaybackVolumeAndFade(void*,unsigned char,int);
extern "C" void SoundSfx_SetScaledPlayerVolumes(void*,int);
extern "C" void GameResources_SetSecondaryFlags(void*,unsigned);
extern "C" void TextContext_GetSharedInstance();
extern "C" void Graphics_ClearAndStageSharedBuffers();
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" void ActorPool_SetSpriteVisibility(void*,int);
extern "C" int GameResources_GetSelectedScreenBrightness(void*,int);
extern "C" int abs(int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" int Graphics_UpdateTimedAngleAndBrightness(void*);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void GameResources_SetPrimaryFlags(void*,unsigned);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(void*,unsigned);
extern "C" void ModelObject_NoOpCleanup(void*);
extern "C" void ModelObject_ReleaseOwnedArenaAndResetCamera(void*);
extern "C" void Graphics_InitializeTextureVRAMForGameState(void*);
extern "C" void GameState_ApplyReadyActionsToFourObjects(void*);
extern "C" void Graphics_StageObjectTexturesSevenToEighteen(void*);
// Original data: arm9/ov017 @ 0x021D7C10; symbol: data_ov017_021d7c10.
// Initialized event/eventbattle.bin path; full bytes: docs/data-symbols/ov017.md.
extern "C" const char FieldBattle_AdvanceEntryTransition_PathDataEventEventbattleBin[];
// Original data: arm9/main @ 0x02109BF4; symbol: data_02109bf4.
// Mutable zero-initialized BGM controller storage; docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x02108760; symbol: data_02108760.
// Mutable zero-initialized sound state storage; docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
#pragma force_active on
// Original: arm9/ov017 @ 0x021B6290; symbol: func_ov017_021b6290; size: 0x32C.
// Advances battle entry through script loading, brightness transitions, shared graphics setup, and field-control suspension.
extern "C" void FieldBattle_AdvanceEntryTransition(char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 Zone3D_GetMainInstance();
 char* leader=_ZN9GameState20GetUnknownGameObjectEv(game);
 void* color=ColorAnimation_GetGlobalInstance();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 void* battle=*(void**)(resources+0x3718);
 if((unsigned char)self[0xfc]==0) {
 GameObject_DisableMovementInput(leader,1);
 *(unsigned short*)(leader+0xb2)=0;
 if(*(short*)(self+0xfe)>=0) {
 *(short*)(self+0x100)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,FieldBattle_AdvanceEntryTransition_PathDataEventEventbattleBin,0);
 Bgm_StopActiveSequenceUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2,10);
 }
 if(*(short*)(self+0xfe)<=0)self[0xfd]=0;
 if(*(unsigned char*)(self+8))_ZN6Zone3D20RecordBMDJFlag4StateEv(Zone3D_GetMainInstance());
 self[0xfc]=1;
 }
 if(*(unsigned char*)(self+0xfd))--*(unsigned char*)(self+0xfd);
 unsigned stage=(unsigned char)self[0xfc];
 if(stage==1) {
 if(PollAndConsumeBackgroundResourceTask(self+12))self[0xfc]=2;
 } else if(stage==2) {
 if(*(unsigned char*)(self+0xfd))return;
 int sequence=23;
 if(*(short*)(self+0x100)>-1) {
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(short*)(self+0x100)))return;
 void* code;unsigned size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(short*)(self+0x100),&code,&size);
 unsigned char temporary[20];
 unsigned char* descriptor=temporary;
 if(LinkedList_ContainsTag(*(void**)(resources+0x36fc),10)) {
 char* request=FieldBattle_GetEncounterRequest(battle);
 if(request)descriptor=(unsigned char*)request+16;
 }
 if(Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(descriptor,*(short*)(self+0xfe),code,size))sequence=*(unsigned short*)(descriptor+14);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(short*)(self+0x100));
 *(short*)(self+0x100)=-1;
 }
 Bgm_EnterSecondaryPlayback(Main_UnknownRoleZeroInitializedStorage_Variant2,sequence);
 Bgm_SetPlaybackVolumeAndFade(Main_UnknownRoleZeroInitializedStorage_Variant2,127,0);
 SoundSfx_SetScaledPlayerVolumes(Main_UnknownRoleZeroInitializedStorage,127);
 GameResources_SetSecondaryFlags(resources,0x40);
 TextContext_GetSharedInstance();
 Graphics_ClearAndStageSharedBuffers();
 ActorPool_SetSpriteVisibility(ActorPool_GetGlobalInstance(),0);
 int progress=_ffix(ColorAnimation_GetProgress(color));
 if(progress>30 || abs(GameResources_GetSelectedScreenBrightness(resources,0))==16) {
 _Z17SetMainBrightnessP13GameResourcesii(resources,-16,0);
 if(GameResources_GetSelectedScreenBrightness(resources,1)==0)_Z16SetSubBrightnessP13GameResourcesii(resources,-16,15);
 self[0xfc]=4;
 } else self[0xfc]=3;
 } else if(stage==3) {
 if(Graphics_UpdateTimedAngleAndBrightness(self+12))self[0xfc]=4;
 } else if(stage==4) {
 if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;
 GameResources_SetSecondaryFlags(resources,4);
 GameResources_SetSecondaryFlags(resources,0x10);
 GameResources_SetSecondaryFlags(resources,2);
 GameResources_SetPrimaryFlags(resources,4);
 SystemState_SetFlags(SystemState_GetGlobalFlags(),1);
 ModelObject_NoOpCleanup(self+12);
 ModelObject_ReleaseOwnedArenaAndResetCamera(self+12);
 Graphics_InitializeTextureVRAMForGameState(resources);
 GameState_ApplyReadyActionsToFourObjects(resources);
 Graphics_StageObjectTexturesSevenToEighteen(resources);
 ActorPool_SetSpriteVisibility(ActorPool_GetGlobalInstance(),1);
 self[1]=1;
 }
}
