#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
typedef unsigned int undefined4;
extern "C" ARM undefined4 GameObject_GetLinkedIndexedState(int);
extern "C" unsigned char Vocation_GetSkillLineId(unsigned int,unsigned int);
// Original: arm9/ov023 @ 0x021F5228; symbol: func_ov023_021f5228; size: 0x78.
// Tests the five mapped equipment values for a party object and returns whether any is below 100.
extern "C" int SkillAllocation_HasUncappedActiveVocationSkillLine(int index){
char* object;unsigned char* state;unsigned char row;int i;
 object=(char*)GameState_GetObjectWithFlag100(GameState::GetInstance(),index);if(!object)return 0;
 state=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);if(!state)return 0;
 row=*(unsigned*)(*(char**)(object+0x150)+0x950);
 for(i=0;i<5;i++){
 unsigned offset=Vocation_GetSkillLineId(row,(unsigned char)i);
 struct Field {unsigned char pad[0x464];unsigned char value;};
 if(((Field*)(state+offset))->value<100)return 1;
 }
 return 0;
}
