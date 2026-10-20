#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int GameState_GetObjectWithFlag100(GameState*,int);extern "C" void* GameObject_GetLinkedIndexedState();extern "C" int CharacterState_GetLearnedSkillMask(void*,unsigned);
struct Object{char pad[4];short id;char pad2[0x12a];unsigned short* info;};
// Original: arm9/main @ 0x02048448; symbol: func_02048448; size: 0x88.
extern "C" ARM bool Object_TestAvailableAmountWithConditionalScaling(Object* p,int value){if(GameState_GetObjectWithFlag100(GameState::GetInstance(),p->id)){void* q=GameObject_GetLinkedIndexedState();if(q && CharacterState_GetLearnedSkillMask(q,0x106)){value=(int)(0.75f+0.75f*value);if(value<=0)value=0;}}return value<=p->info[3];}
