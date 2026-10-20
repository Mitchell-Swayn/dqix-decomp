#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(void*);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" void PartyStatus_SetMappedMemberAnimationFlags(char*,int,unsigned char,int);
extern "C" void PartyStatus_FinishMappedMemberAnimation(unsigned char*,int);
extern "C" void FieldBattle_CancelPendingParticipation(void*,int,int,int);
extern "C" int Network_IsParentOrOffline(void*);
extern "C" void* PartySync_GetSharedRecordTable();
extern "C" void PartySync_ResetEntryByKey(void*,unsigned short);
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" int _ZNK8Object3D10GetField06Ev(void*);
extern "C" void FieldMonster_HideTrackedZoneGroupAndBroadcast(void*,int);
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void*,int,int);
extern "C" void Field_RebuildMemberFollowChain(void*,int,int,int,int);
extern "C" void ClearMatchingHalfwordEntry(void*,unsigned short);
// Original data: arm9/ov017 @ 0x021D6D18; symbol: data_ov017_021d6d18.
// Four initialized words of 0xffffffff seed the temporary member-index list.
extern "C" const int FieldApplyMemberEncounterExit_UnknownRoleInitializedBytes[4];
#pragma force_active on
// Original: arm9/ov017 @ 0x021C8C44; symbol: func_ov017_021c8c44; size: 0x22C.
// Stops the exiting member's mapped animations, cancels participation, reconciles the matching tracked monster group, and rebuilds party follow state.
extern "C" void Field_ApplyMemberEncounterExit(int sender,char* packet,void* game,char* resources,void* connection) {
 int selected;
 unsigned char restoreFlag=*(unsigned char*)(packet+10);
 int key=*(unsigned short*)(packet+8);
 int restore=restoreFlag!=0;
 int groupKey=*(int*)(packet+4);
 void* globalGame=_ZN9GameState11GetInstanceEv();
 char* status=*(char**)(GameResources_GetInstance()+0x36d0);
 for(int i=0;i<4;i++) {
 selected=0;
 if(i==sender)selected=1;
 else {
 void* object=GameState_FindIndexedObjectWithFlag1000(globalGame,i);
 if(object && GameObject_GetAssociatedPartyMemberIndex(object)==sender)selected=1;
 }
 if(selected) {
 PartyStatus_SetMappedMemberAnimationFlags(status,0,1,i);
 PartyStatus_FinishMappedMemberAnimation((unsigned char*)status,i);
 }
 }
 FieldBattle_CancelPendingParticipation(*(void**)(resources+0x3718),key,1,restore);
 if(Network_IsParentOrOffline(connection)) {
 PartySync_ResetEntryByKey(PartySync_GetSharedRecordTable(),(unsigned short)key);
 if(groupKey!=-1) {
 struct MemberIndices {int values[4];};
 MemberIndices matches=*(const MemberIndices*)FieldApplyMemberEncounterExit_UnknownRoleInitializedBytes;
 int count=0;
 for(int i=0;i<4;i++) {
 char* object=_ZN9GameState21GetPartyMemberByIndexEi(game,i);
 if(object && (groupKey==_ZNK8Object3D10GetField06Ev(object) || groupKey==*(int*)(object+0x15c)))matches.values[count++]=i;
 }
 if(count==1 && matches.values[0]!=0)FieldMonster_HideTrackedZoneGroupAndBroadcast(resources,groupKey);
 }
 }
 for(int i=0;i<4;i++) {
 char* object=GameState_GetObjectWithFlag100(game,i);
 if(!object)continue;
 if(sender==*(short*)(object+4))Object_SetHalfword1B2WhenMemberListedOrForced(object,0,1);
 else if(*(unsigned short*)object&0x1000) {
 char* leader=GameState_GetObjectWithFlag100(game,0);
 if(leader)Object_SetHalfword1B2WhenMemberListedOrForced(object,*(unsigned short*)(leader+0x1b2),1);
 }
 }
 Field_RebuildMemberFollowChain(resources,sender,1,1,1);
 ClearMatchingHalfwordEntry(resources,(unsigned short)key);
}
