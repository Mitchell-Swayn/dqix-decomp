#include <globaldefs.h>
ARM
struct GameState; struct State;
extern "C" unsigned char* data_ov004_021707d8[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int Object_CompactSelectedSlotGroup(char*,unsigned);
extern "C" void Ov004_InitializeRecordFields(void*);
extern "C" void func_ov011_021848a0(State*,unsigned);
extern "C" void GameState_AppendValueAndSetNodeFlags(State*,int,int);
// Original: arm9/ov004 @ 0x0215B694; symbol: func_ov004_0215b694; size: 0x7C.
extern "C" int GameState_CompactEightSelectedSlotGroups(State* self) {
 char* list=(char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 if(!list) return 0;
 for(int i=0;i<8;i++) Object_CompactSelectedSlotGroup(list+0x1d4,(data_ov004_021707d8[2]+i)[0x7c]);
 Ov004_InitializeRecordFields(data_ov004_021707d8[2]);
 func_ov011_021848a0(self,0x3a0);
 GameState_AppendValueAndSetNodeFlags(self,2,8);
 return 0;
}
