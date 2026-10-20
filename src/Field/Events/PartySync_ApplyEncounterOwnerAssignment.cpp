#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* PartySync_GetSharedRecordTable();extern "C" bool Network_IsParentOrOffline(unsigned*);extern "C" void ClearIndexedTextRecordStatesAndNotify(void*,int);extern "C" int PartySync_AssignRecordOwnerIfUnassigned(unsigned,unsigned,unsigned);extern "C" char* FieldBattle_GetEncounterRequest(void*);extern "C" char* FieldBattle_GetScene(void*);extern "C" void GameState_UpdateStoredProtagonistIndex(char*,unsigned);
// Original: arm9/ov017 @ 0x021C9BC8; symbol: UpdateRecordOwnerOrStoredProtagonistIndex; size: 0x9c.
extern "C" void PartySync_ApplyEncounterOwnerAssignment(unsigned owner,char* entry,int unused,char* self,unsigned* connection){
void* global=PartySync_GetSharedRecordTable();unsigned index=*(unsigned short*)(entry+4);unsigned slot=*(unsigned short*)(entry+6);if(Network_IsParentOrOffline(connection)){ClearIndexedTextRecordStatesAndNotify(global,slot&255);PartySync_AssignRecordOwnerIfUnassigned((unsigned)global,(unsigned short)index,owner);return;}if(owner)return;void* holder=P(self,0x3718);char* record=FieldBattle_GetEncounterRequest(holder);char* object=FieldBattle_GetScene(holder);if(!record||!object)return;if(*(unsigned short*)(record+8)!=index)return;GameState_UpdateStoredProtagonistIndex(object,slot);
}
