#include <globaldefs.h>
ARM
struct GameState;struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" char* BattleMenu_FindPartyCommandRecord(void*,int);
// Original: arm9/ov000 @ 0x02175628; symbol: func_ov000_02175628; size: 0x90.
extern "C" void GameState_SetEligiblePartySlotValue100(void* self) {
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
char* list=(char*)GameState_GetIndexList(state);
unsigned char count=*(unsigned char*)(list+0xf7c);
for(unsigned char i=0;i<count;++i) {
int index=*(list+i+0xf78);
Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi(state,index);
if(member && (signed char)*(unsigned*)(GameObject_GetLinkedIndexedState(member)+0x94c)!=5) {
char* rec=BattleMenu_FindPartyCommandRecord(self,index);
if(rec) *(rec+rec[0x18]+0x10)=100;
}
}
}
