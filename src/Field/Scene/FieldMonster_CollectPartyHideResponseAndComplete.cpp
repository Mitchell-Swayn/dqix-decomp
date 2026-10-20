#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* GameResources_GetInstance();extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(unsigned*);extern "C" unsigned char* GameState_FindFlag20ObjectByKey(void*,int);extern "C" void FieldMonster_RecordPartyHideResponse(unsigned char*,unsigned,int);extern "C" int UpdateFourSlotFlagsAndTestAllSet(unsigned char*);extern "C" bool FieldMonster_TestAllPartyHideResponsesAccepted(unsigned char*);extern "C" void FieldNetwork_QueueSlotFlagUpdate(unsigned short,int);extern "C" void FieldMonster_HideByRecordIdentifier(void*,int);extern "C" void FieldMonster_ClearPartyHideResponses(unsigned char*);
// Original: arm9/ov017 @ 0x02192654; symbol: ApplySlotFlagsAndCompleteFourSlotUpdate; size: 0xac.
extern "C" void FieldMonster_CollectPartyHideResponseAndComplete(unsigned bit,int key,int paired){
void* resources=GameResources_GetInstance();void* state=_ZN9GameState11GetInstanceEv();if(Network_IsParentOrOffline(Network_GetConnectionManager())){unsigned char* object=GameState_FindFlag20ObjectByKey(state,key);if(!object)return;FieldMonster_RecordPartyHideResponse(object,bit,paired);if(!UpdateFourSlotFlagsAndTestAllSet(object))return;if(FieldMonster_TestAllPartyHideResponsesAccepted(object)){FieldNetwork_QueueSlotFlagUpdate((unsigned short)key,1);FieldMonster_HideByRecordIdentifier(resources,key);}FieldMonster_ClearPartyHideResponses(object);}else FieldNetwork_QueueSlotFlagUpdate((unsigned short)key,paired);
}
