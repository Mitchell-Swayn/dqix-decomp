#include <globaldefs.h>
ARM
class GameState {public:static GameState* GetInstance();void* GetPartyMemberByIndex(int);};
extern "C" {bool BattleMenu_HasCommandBlockingStatus(void*);unsigned char* GameObject_GetLinkedIndexedState(void*);}
// Original: arm9/ov000 @ 0x0217F6BC; symbol: func_ov000_0217f6bc; size: 0xd0.
// Finds the first eligible party panel lacking a completed command.
extern "C" int BattleMenu_FindNextPartyNeedingCommand(unsigned char* menu) {
 unsigned char* panels=menu; signed char* order; GameState* state; unsigned char* panel;
 state=GameState::GetInstance();
 order=(signed char*)panels+0x6c;
 panels+=0x958;
 for(int i=0;i<4;i++) {
  panel=panels+order[i]*0x448;
  if(*(int*)(panel+0x4c)<0)continue;
  if(!panel[0x87])continue;
  if(panel[0x24]&4)continue;
  if((((signed char*)panel)+((signed char*)panel)[0x18])[0x10]==0x64)continue;
  if(BattleMenu_HasCommandBlockingStatus(panel))continue;
  if(!panel[0x445])continue;
  void* member=state->GetPartyMemberByIndex(order[i]);
  if(!member || (signed char)*(int*)(GameObject_GetLinkedIndexedState(member)+0x94c)==5)return *(int*)(panel+0x4c);
 }
 return -1;
}
