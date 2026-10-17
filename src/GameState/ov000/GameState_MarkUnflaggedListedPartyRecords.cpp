#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" char* FindFourSlotRecordByIndex(void*,int);
extern "C" int TestFourWord28Flags(char*);
// Original: arm9/ov000 @ 0x021756B8; symbol: func_ov000_021756b8; size: 0x9C.
extern "C" void GameState_MarkUnflaggedListedPartyRecords(void* self) {
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 unsigned char* list=(unsigned char*)GameState_GetIndexList(state);
 unsigned char count=list[0xf7c];
 for(unsigned char i=0;i<count;i++) {
  int index=*(signed char*)(list+0xf78+i);
  Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi(state,index);
  if(member && (signed char)*(int*)(ReadWordFieldAtOffset150(member)+0x94c)!=5) {
   char* record=FindFourSlotRecordByIndex(self,index);
   if(record && !TestFourWord28Flags(record)) (record+*(signed char*)(record+0x18))[0x10]=13;
  }
 }
}
