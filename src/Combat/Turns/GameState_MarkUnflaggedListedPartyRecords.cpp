#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" char* BattleMenu_FindPartyCommandRecord(void*,int);
extern "C" int BattleMenu_HasCommandBlockingStatus(char*);
// Original: arm9/ov000 @ 0x021756B8; symbol: func_ov000_021756b8; size: 0x9C.
extern "C" void GameState_MarkUnflaggedListedPartyRecords(void* self) {
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 unsigned char* list=(unsigned char*)GameState_GetIndexList(state);
 unsigned char count=list[0xf7c];
 for(unsigned char i=0;i<count;i++) {
  int index=*(signed char*)(list+0xf78+i);
  Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi(state,index);
  if(member && (signed char)*(int*)(GameObject_GetLinkedIndexedState(member)+0x94c)!=5) {
   char* record=BattleMenu_FindPartyCommandRecord(self,index);
   if(record && !BattleMenu_HasCommandBlockingStatus(record)) (record+*(signed char*)(record+0x18))[0x10]=13;
  }
 }
}
