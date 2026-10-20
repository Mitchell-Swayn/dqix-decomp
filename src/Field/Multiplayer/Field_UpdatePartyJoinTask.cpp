#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" char* Zone3D_GetMainInstance();
extern "C" int GameResources_GetSelectedScreenBrightness(void*,int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void GameResources_SetSecondaryFlags(void*,unsigned);
extern "C" void GameResources_ClearSecondaryFlags(void*,unsigned);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Mutable zero-initialized allocator-union storage; full record: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void G3X_SetClearColor(unsigned short,int,int,int,int);
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void* NavigationMessage_GetGlobalInstance();
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void UpdateEmbeddedDisplayContextWhenEnabled(void*,unsigned);
extern "C" int Network_IsMemberConnected(void*,int);
extern "C" void Field_EndMultiplayerSessionAndRestoreLocalParty();
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z22UnlockAndSetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void InitializeTypeFourStateAndBuffers(void*,int);
extern "C" void FieldEvent_InitializeLuidaScriptRequest(void*,unsigned,int);
extern "C" int GameState_ReadFirstObjectIndex(void*);
extern "C" void LinkedQueue_AppendAndMarkActive(void*,void*);
extern "C" void GameResources_ClearPrimaryFlags(void*,unsigned);
extern "C" void Field_QueueSessionTransitionTask(int,int,int);
extern "C" void NavigationMessage_ClearActiveQueue(void*);
extern "C" int Field_RemoveNextDisconnectedOrSupersededMember(void*);
extern "C" void System_ForwardStateAndIndexWhenStackEntryIsThree(void*,int);
extern "C" void TextPanel_InitializeFormattedName(void*,void*);
extern "C" void System_CallStateFunctionWhenLastStackEntryIsThree(void*);
extern "C" void LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void GameObject_CommitMovementInputEnable(void*);
extern "C" void TextLayout_HidePanelImmediately(void*);
extern "C" void SystemState_ClearFlags(void*,unsigned);
extern "C" void GameResources_SetPartyStatusSnapshotTracking(int,int);
extern "C" void DisplayOverlay_ConfigureGlobalState(int,int,int,int);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" char* TextContext_GetSharedInstance();
struct PartyJoinCallbacks { int (*handlers[13])(unsigned char*); };
// Original data: arm9/ov017 @ 0x021D6AEC; symbol: data_ov017_021d6aec.
// Thirteen original procedure references indexed by join task stage; docs/data-symbols/ov017.md.
extern "C" const PartyJoinCallbacks FieldUpdatePartyJoinTask_UnknownRoleProcedureReferenceRecords;
struct LowBit {unsigned char value:1,other:7;};
#pragma force_active on
// Original: arm9/ov017 @ 0x021AF66C; symbol: func_ov017_021af66c; size: 0x404.
// Dispatches join-task stages, reconciles disconnected members and battle state, and restores field display/control resources when the task finishes.
extern "C" void Field_UpdatePartyJoinTask(unsigned char* self,void* queue) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 char* connection=(char*)Network_GetConnectionManager();
 char* leader=_ZN9GameState20GetUnknownGameObjectEv(game);
 void* system=SystemState_GetGlobalFlags();
 void* messages=NavigationMessage_GetGlobalInstance();
 unsigned char* battle=*(unsigned char**)(resources+0x3718);
 GameObject_DisableMovementInput(leader,0);
 *(unsigned short*)(leader+0xb2)=0;
 PartyJoinCallbacks callbacks=FieldUpdatePartyJoinTask_UnknownRoleProcedureReferenceRecords;
 if(callbacks.handlers[self[10]]) {
 unsigned tick=_ZNK9GameState12GetTickCountEv(game);
 if(!tick)tick=1;
 UpdateEmbeddedDisplayContextWhenEnabled(self+0x48,tick);
 self[10]=callbacks.handlers[self[10]](self);
 }
 if(self[8])self[1]=1;
 if(self[9]!=2 && *(unsigned*)(connection+0xfc0)==0 && !Network_IsMemberConnected(connection,self[12]))self[1]=1;
 if(*(unsigned char*)(resources+0x42e2)) {
 if(self[9]==2) {
 Field_EndMultiplayerSessionAndRestoreLocalParty();
 *(unsigned char*)(resources+0x42e3)=1;
 char* zone=Zone3D_GetMainInstance();
 if(*(unsigned short*)zone==1) {
 _Z13SetBrightnessP13GameResourcesii(resources,0,30);
 _Z22UnlockAndSetBrightnessP13GameResourcesii(resources,0,30);
 }
 unsigned char* event=*(unsigned char**)(resources+0x3734);
 if(!event[2]) {
 InitializeTypeFourStateAndBuffers(event,1);
 FieldEvent_InitializeLuidaScriptRequest(event,*(unsigned*)(zone+8),2);
 event[0xcd]=GameState_ReadFirstObjectIndex(game);
 event[0xce]=((LowBit*)(*(char**)(leader+0x150)+0x49c))->value;
 event[0xcc]=1;event[0xcf]=3;
 LinkedQueue_AppendAndMarkActive(queue,event);
 }
 GameResources_ClearPrimaryFlags(resources,0x40);
 } else {
 Field_QueueSessionTransitionTask(0,0,0);
 unsigned char* event=*(unsigned char**)(resources+0x3734);
 if(event[2] && event[0xcf]==2) {
 NavigationMessage_ClearActiveQueue(messages);
 ComputeGrottoAndContextDependentStateFlags(0);
 }
 }
 self[1]=1;
 }
 int removed=Field_RemoveNextDisconnectedOrSupersededMember(resources);
 if(removed>0) {
 (self+removed)[0x1b]=0;
 if(battle[2]) {
 void* scene=FieldBattle_GetScene(battle);
 if(scene) {
 System_ForwardStateAndIndexWhenStackEntryIsThree(scene,removed);
 TextPanel_InitializeFormattedName(self,self+14);
 }
 }
 }
 if(battle[2]) {
 void* scene=FieldBattle_GetScene(battle);
 if(scene)System_CallStateFunctionWhenLastStackEntryIsThree(scene);
 }
 if(self[1]) {
 if(self[0x42]) {
 _Z17SetMainBrightnessP13GameResourcesii(resources,*(int*)(self+0x3c),0);
 G3X_SetClearColor(*(unsigned short*)(self+0x40),0,0x7fff,0,0);
 GameResources_ClearSecondaryFlags(resources,~0U);
 GameResources_SetSecondaryFlags(resources,*(unsigned*)(self+0x38));
 }
 self[11]=0;
 LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(queue);
 unsigned char* event=*(unsigned char**)(resources+0x3734);
 bool resume=true;
 if(event[2] && event[0xcf]==2)resume=false;
 if(resume) {
 char* object=_ZN9GameState20GetUnknownGameObjectEv(game);
 if(object) {
 GameObject_RequestMovementInputEnable(object);
 GameObject_CommitMovementInputEnable(object);
 }
 }
 TextLayout_HidePanelImmediately(self+0x48);
 SystemState_ClearFlags(SystemState_GetGlobalFlags(),0x800000);
 GameResources_SetPartyStatusSnapshotTracking(1,-1);
 DisplayOverlay_ConfigureGlobalState(0,1,0,1);
 volatile unsigned* display=(volatile unsigned*)0x04000000;
 *display=(*display&~0x1f00)|(*(unsigned*)(self+0x280)<<8);
 GameResources_ClearSecondaryFlags(resources,0x40);
 void* snapshot=*(void**)(self+0x288);
 if(snapshot) {
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,snapshot);
 *(void**)(self+0x288)=0;
 }
 *(unsigned char*)(TextContext_GetSharedInstance()+0x19d0)=0;
 if(!(*(unsigned char**)(resources+0x3718))[2])SystemState_ClearFlags(system,0x40000);
 }
}
