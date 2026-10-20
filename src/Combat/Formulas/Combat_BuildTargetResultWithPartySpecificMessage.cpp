#include <globaldefs.h>
ARM
struct PartySelectionA{unsigned a:20;unsigned party:10;unsigned rest:2;};
struct PartySelectionB{unsigned party:10;unsigned rest:22;};
struct Flags{unsigned char low:7;unsigned char active:1;};
extern "C" void* _Z16GetCombatantByIDii(int,int);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(int);
extern "C" void Combat_AppendResultMessage(int,void*,int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(int,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021E1328; symbol: Combat_CreateIndexedRecordFromPackedPartySelection; size: 0xb8.
extern "C" void* Combat_BuildTargetResultWithPartySpecificMessage(char* self,int unused,int id,char* descriptor) {
 void* combatant=_Z16GetCombatantByIDii(*(int*)(self+16),id);if(!combatant)return 0;
 int selected=Combat_SelectMessageForPartyOrMonster(id,((PartySelectionA*)(descriptor+32))->party,((PartySelectionB*)(descriptor+36))->party);void* record=Combat_ClearCurrentResultNodeSlot(*(int*)(self+16));if(!record)return 0;
 Combat_AppendResultMessage(*(int*)(self+16),record,selected);bool active=((Flags*)(*(char**)(self+12)+28))->active!=0;Combat_PopulateResultWithCurrentHealthAndMagic(*(int*)(self+16),record,combatant,0,0,0,active);return record;
}
