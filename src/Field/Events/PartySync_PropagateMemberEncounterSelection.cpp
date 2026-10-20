#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsParentOrOffline(void*);
extern "C" void PartySync_QueueMemberEncounterSelection(int,unsigned short);
extern "C" void* PartySync_GetSharedRecordTable();
extern "C" char* PartySync_FindEntryByKey(void*,unsigned short);
extern "C" void SetIdRecordMemberStateAndPropagateAliases(void*,unsigned short,int,int,int,int,int);
extern "C" char* GameResources_GetInstance();
extern "C" char* FieldBattle_GetEncounterRequest(void*);
extern "C" void FieldBattle_ApplyMemberParticipation(void*,int,unsigned short);
// Original: arm9/ov017 @ 0x021C5A8C; symbol: PropagatePrimaryMemberStateAndMatchingDisplayId; size: 0xb8.
extern "C" void PartySync_PropagateMemberEncounterSelection(int member,int id) {
 if(!Network_IsParentOrOffline(Network_GetConnectionManager()))return;
 PartySync_QueueMemberEncounterSelection(member,(unsigned short)id);void* state=PartySync_GetSharedRecordTable();char* record=PartySync_FindEntryByKey(state,(unsigned short)id);
 if(record)SetIdRecordMemberStateAndPropagateAliases(state,(unsigned short)id,member,1,*(signed char*)(record+4),*(unsigned short*)(record+2),*(unsigned char*)(record+5));
 void* display=*(void**)(GameResources_GetInstance()+0x3718);int found=*(unsigned short*)(FieldBattle_GetEncounterRequest(display)+8);if(found==id)FieldBattle_ApplyMemberParticipation(display,member,(unsigned short)id);
}
