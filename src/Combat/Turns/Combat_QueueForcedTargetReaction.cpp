#include <globaldefs.h>
ARM
#pragma always_inline on
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Record;struct Owner;struct Lists;struct List;struct Node;struct Source;
extern "C" void Combat_InitializeCommandRecord(unsigned char*);
extern "C" void Combat_InitializeTargetResultRecord(Record*);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_AppendTargetResultToCategoryList(Lists*,Node*,int);
extern "C" void Combat_AppendActorSnapshotToCommand(List*,Node*);
extern "C" void Combat_AppendActionTargetRecord(Owner*,Node*);
extern "C" GameObject* GameState_FindIndexedObjectWithFlag400(GameState*,int);
extern "C" int Combat_HasForcedTarget(void*);
extern "C" bool GameObject_IsDead(void*);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" void CombatantState_ClearLinkedCombatEffect(unsigned char*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" void Combat_IncrementCappedEventCounter(unsigned char*,int);
struct Vitals {short hp,mp;short GetHP(){return hp;}short GetMP(){return mp;}};
struct CommandStorage {unsigned char bytes[40];};
struct ActorStorage {unsigned char bytes[52];};
struct ResultStorage {unsigned char bytes[36];};
// Original: arm9/ov000 @ 0x0215A908; symbol: func_ov000_0215a908; size: 0x280.
// Queues the actor's forced-target reaction while the linked target remains eligible.
extern "C" void Combat_QueueForcedTargetReaction(void* context,int index) {
 unsigned char* self=(unsigned char*)context;
 if(self[0x8e0b]>=20 || self[0x8e0c]>=20 || self[0x8e0d]>=20 || self[0x8e0e]>=20)return;
 unsigned char* commands;
 int offset;
 unsigned char* actor;
 unsigned char* target;
 unsigned char* result;
 unsigned char* object=(unsigned char*)GameState_FindIndexedObjectWithFlag400(GameState::GetInstance(),index);
 if(!object || !Combat_HasForcedTarget(object))return;
 int targetId=*(short*)(*(unsigned char**)(object+0x138)+0x2e);
 GameState* game=GameState::GetInstance();
 GameObject* targetObject=game->GetCombatantByIndex(targetId);
 if(!targetObject || GameObject_IsDead(targetObject) || Combat_IsCombatantExcludedFromSelection((char*)targetObject)) {
  CombatantState_ClearLinkedCombatEffect(*(unsigned char**)(object+0x138));object[0x182]=0;return;
 }
 object[0x181]=1;object[0x182]=0;
 commands=self+0x6060;
 offset=(short)self[0x8e0b]*(short)40;
 Combat_InitializeCommandRecord(commands+offset);
 actor=((ActorStorage*)(self+0x6380))[self[0x8e0c]].bytes;
 memset(actor,0,48);*(short*)(actor+0x1c)=-1;*(unsigned*)(actor+0x30)=0;
 target=((ResultStorage*)(self+0x6790))[self[0x8e0d]].bytes;
 Combat_InitializeTargetResultRecord((Record*)target);
 result=((ResultStorage*)(self+0x6a60))[self[0x8e0e]].bytes;
 memset(result,0,32);*(unsigned*)(result+0x20)=0;
 *(short*)(commands+offset)=0x399;
 *(short*)(actor+0x20)=index;
 *(unsigned short*)(actor+0x22)=**(unsigned short**)(object+0x138);
 *(unsigned short*)(actor+0x24)=*(unsigned short*)(*(unsigned char**)(object+0x138)+2);
 Combat_PopulateResultFromCombatantSnapshot(self,(Record*)result,(Owner*)object,0,(*(Vitals**)(object+0x138))->GetHP(),(*(Vitals**)(object+0x138))->GetMP(),0,0,0);
 Combat_AppendResultMessage(self,result,0x212);
 *(short*)(target+0xe)=index;target[0x17]=1;
 *(short*)(target+0xc)=*(short*)(*(unsigned char**)(object+0x138)+0x2e);
 Combat_AppendTargetResultToCategoryList((Lists*)target,(Node*)result,0);
 Combat_AppendActorSnapshotToCommand((List*)(commands+offset),(Node*)actor);
 Combat_AppendActionTargetRecord((Owner*)(commands+offset),(Node*)target);
 unsigned char* descriptor=*(unsigned char**)(object+0x144);
 if(PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList(GameState::GetInstance()),*(short*)(target+0xc)) && descriptor && *(short*)(descriptor+8)==0x143)Combat_IncrementCappedEventCounter(self,9);
 ++self[0x8e0b];++self[0x8e0c];++self[0x8e0d];++self[0x8e0e];
}
