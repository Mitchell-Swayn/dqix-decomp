#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
struct GameResourcesSlot { unsigned int unknown_0; GameResources* instance; };
struct Mode { unsigned char value:4; unsigned char other:4; };
struct Object;
extern "C" {
ARM GameResources* GameResources_GetInstance();
void* FieldBattle_GetEncounterRequest(void*);
unsigned FieldBattle_GetScene(void*);
bool GameState_TestProtagonistIndexMatchesStoredByte(signed char*);

ARM char* BattleMenu_FindPartyCommandRecord(char*,int);
int BattleMenu_HasCommandBlockingStatus(char*);
void Network_QueueBattleContextControlByte(unsigned char);
// Original data: arm9/ov000 @ 0x02183444; symbol: data_ov000_02183444.
// BattleMenu_CommitMatchingPartyVocationActions indexes this table by vocation kind and compares the action ID with each selected party command. The observed span contains 13 nonzero IDs and a trailing zero; the trailing zero may be padding.
// Values (uint16_t[]): {505, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 527, 516, 0}; trailing zero may be padding.
extern unsigned short BattleMenu_VocationActionIds[];
}
// Original: arm9/ov000 @ 0x021759F4; symbol: func_ov000_021759f4; size: 0x160.
// Copies four qualifying party records and applies a queued update unless all four are restricted classes.
extern "C" int BattleMenu_CommitMatchingPartyVocationActions(char* self) {
 char* owner=*(char**)((char*)GameResources_GetInstance()+0x3718);
 signed char* embedded=(signed char*)FieldBattle_GetEncounterRequest(owner);
 if(*(unsigned short*)(self+0x1d72)&0x200)return 0;
 if(*(unsigned short*)(self+0x1d72)&0x400)return 0;
 if(embedded && !GameState_TestProtagonistIndexMatchesStoredByte(embedded)) {
 unsigned linked=FieldBattle_GetScene(owner);if(linked)return *(unsigned char*)((char*)linked+0xeb4);
 }
 GameState* game=GameState::GetInstance();
 unsigned char restricted=0,matched=0;
 for(int i=0;i<4;i++) {
 char* record=BattleMenu_FindPartyCommandRecord(self,i);if(!record)break;
 if(BattleMenu_HasCommandBlockingStatus(record) || *(signed char*)(record+0x10+*(signed char*)(record+0x18))!=100 || *(signed char*)(record+0x1c)!=5)break;
 GameObject* object=game->GetPartyMemberByIndex(i);if(!object)break;
 int kind=*(int*)(*(char**)((char*)object+0x150)+0x950);
 int mapped=BattleMenu_VocationActionIds[kind];
 short key=*(short*)(record+0x26);
 if(mapped!=key)break;
 ((short*)self)[i]=key;(self+i)[8]=*(signed char*)(record+0x1d);(self+i)[0xc]=*(signed char*)(record+0x2e);
 if(*(int*)(self+0x20)>=0 && (kind==6 || kind==11))++restricted;
 ++matched;
 }
 if(matched==4 && restricted!=4) {Network_QueueBattleContextControlByte(1);return 1;}
 return 0;
}
