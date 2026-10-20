#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* GameResources_GetInstance();extern "C" char* FieldMonster_FindByPersistentRecordIdentifier(void*,int);extern "C" int LinkedList_ContainsNodeByIdentity(void*,void*);extern "C" void FieldBattle_InitializeCommand(void*);extern "C" void Field_InitializeEncounterDescriptor(void*);extern "C" int FieldBattle_ResolveMonsterAndTreasureMapFlags(void*,int);extern "C" void FieldBattle_ConfigureEncounterRequest(void*,void*);extern "C" void LinkedQueue_AppendAndMarkActive(void*,void*);
// Original: arm9/ov017 @ 0x021C5B44; symbol: CreateAndQueueTypeTenMonsterDescriptor; size: 0xb4.
extern "C" void Field_QueueMonsterEncounterDescriptor(unsigned char type,unsigned short identifier,unsigned value,unsigned char mode,unsigned char flag){
_ZN9GameState11GetInstanceEv();char* resources=GameResources_GetInstance();int index=-1;void* queue=P(resources,0x36fc);void* record=P(resources,0x3718);char* monster=FieldMonster_FindByPersistentRecordIdentifier(resources,identifier);if(monster)index=*(short*)(monster+4);if(LinkedList_ContainsNodeByIdentity(queue,record))return;FieldBattle_InitializeCommand(record);char descriptor[24];Field_InitializeEncounterDescriptor(descriptor);B(descriptor,0)=0;B(descriptor,1)=type;H(descriptor,4)=identifier;H(descriptor,2)=index;W(descriptor,8)=value;B(descriptor,15)=mode;FieldBattle_ResolveMonsterAndTreasureMapFlags(descriptor,index);B(descriptor,18)=flag;FieldBattle_ConfigureEncounterRequest(record,descriptor);LinkedQueue_AppendAndMarkActive(queue,record);
}
