#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" char* ActionData_GetGlobalTables();
extern "C" char* ActionData_FindDefinitionInPrimaryOrSecondaryTable(void*,int);
extern "C" char* Combat_GetIndexedActionTarget(void*,int);
extern "C" int Combat_GetLatestTargetFromHistory(void*);
extern "C" int Combat_ClassifySpecialEncounterSpecies(void*);
extern "C" void Combat_QueueTimedPresentationForActionParticipants(void*,void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov025 @ 0x021E2F54; symbol: Combat_ApplyDescriptorRecordAndSetClassifiedFlag; size: 0xF4.
extern "C" void Combat_QueueActionResultEffectDescriptors(char* self,char* first,char* second){
 char* control=P(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage,12);char* transformed=ActionData_FindDefinitionInPrimaryOrSecondaryTable(ActionData_GetGlobalTables(),S(first,0));char* linked=Combat_GetIndexedActionTarget(first,0);
 if(transformed&&linked){unsigned char valid=Combat_GetLatestTargetFromHistory(linked)>=192&&Combat_GetLatestTargetFromHistory(linked)<=199;
 if(valid&&(unsigned)W(transformed,20)>>28==4){H(self,38)|=8;Combat_QueueTimedPresentationForActionParticipants(control+0x22c,self);H(self,38)=7;Combat_QueueTimedPresentationForActionParticipants(control+0x22c,self);}else Combat_QueueTimedPresentationForActionParticipants(control+0x22c,self);
 }else Combat_QueueTimedPresentationForActionParticipants(control+0x22c,self);
 if(Combat_ClassifySpecialEncounterSpecies(second)){char* owner=P(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage,12);W(owner,0x1c4)|=16;}
}