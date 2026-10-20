#include <globaldefs.h>
ARM
extern "C" int Field_RebuildDisplayedAndProtagonistRosters(...);
extern "C" int GameState_GetObjectWithFlag100(...);
extern "C" int GameState_ReadPResources(...);
extern "C" int GameObject_ResolveLinkedStatsOrNull(...);
extern "C" int InitializeCharacterStateArraysAndDefaults(...);
extern "C" int InitializeKind63StateAndThirteenAttributeRecords(...);
extern "C" int Network_IsSessionActive(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int Ov017_QueueSourceForIndex(...);
extern "C" int GameObject_GetLinkedIndexedState(...);
extern "C" int Network_IsParentOrOffline(...);
extern "C" int CharacterResourceContext_InvalidateOwnerIndex(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int CharacterState_Serialize(...);
extern "C" int Field_RemovePartyMemberAndEquipment(...);
extern "C" int Field_RebuildActiveRosterAndCameraTarget(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021B6D60; symbol: ApplyCharacterRecordAndRebuildActivePartyLists.
extern "C" int Field_StoreMemberAndRemoveFromActiveParty(int index,char*record){
InitializeKind63StateAndThirteenAttributeRecords(record);int state=_ZN9GameState11GetInstanceEv();char*object=C(GameState_GetObjectWithFlag100(state,index));if(!object)return 0;char*character=C(GameObject_GetLinkedIndexedState(object));int indirect=GameObject_ResolveLinkedStatsOrNull(object);if(!character)return 0;if(!indirect)return 0;CharacterState_Serialize(character,record);char*resources=C(GameState_ReadPResources(state));InitializeCharacterStateArraysAndDefaults(character);if(P(object,340))CharacterResourceContext_InvalidateOwnerIndex(P(object,340));Field_RemovePartyMemberAndEquipment(resources,index);Field_RebuildActiveRosterAndCameraTarget(resources,1,1,1,1);Field_RebuildDisplayedAndProtagonistRosters(resources);struct View{inline int Base(){return (int)this+0x435c;}};int base=((View*)resources)->Base();*(unsigned char*)(base+index*48)=0;int connection=Network_GetConnectionManager();if(Network_IsSessionActive(connection)&&Network_IsParentOrOffline(connection))Ov017_QueueSourceForIndex(index);return record!=0;
}
