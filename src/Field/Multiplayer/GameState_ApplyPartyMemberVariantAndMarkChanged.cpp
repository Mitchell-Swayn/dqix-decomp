#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Field_QueuePartyMemberEquipmentRefresh(void*,int,int,int,int);
// Original: arm9/ov017 @ 0x021D0E64; symbol: GameState_ApplyPartyMemberVariantAndMarkChanged; size: 0x94.
// Applies record variant byte to party member and resets negative transition before setting game changed bit.
extern "C" void GameState_ApplyPartyMemberVariantAndMarkChanged(void* unused,unsigned char* record,char* game,void* resources) {
 char* member=_ZN9GameState21GetPartyMemberByIndexEi(game,*(signed char*)(record+4));if(!member)return;
 char* object=GameObject_GetLinkedIndexedState(member);if(!object)return;
 if(*(unsigned char*)(object+0x56a)!=record[5] && *(short*)(object+0x488)<0){*(short*)(member+2)=-1;Field_QueuePartyMemberEquipmentRefresh(resources,*(signed char*)(record+4),0,0,0);}
 object[0x56a]=record[5];*(unsigned*)(game+0x5ccc)|=2;
}
