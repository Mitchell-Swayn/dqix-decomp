#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
// Original: arm9/ov017 @ 0x021920DC; symbol: func_ov017_021920dc; size: 0xC0.
extern "C" int GameState_TestGroupedMemberLinkedOrCombatantFlag(void* unused,int value) {
void* state=_ZN9GameState11GetInstanceEv();
int result=0;
int index=-1;
int direct=value>=0 && value<=3;
if(direct)index=value;
else if(value>=19 && value<=103)index=(value-19)/12;
if(index>=0){
void* object=GameState_GetObjectWithFlag100(state,index);
if(object){unsigned char* linked=GameObject_GetLinkedIndexedState(object);unsigned char* combatant=_ZN9GameState19GetCombatantByIndexEi(state,index);
if((linked && linked[0x56c]) || (combatant && (*(unsigned int*)(*(unsigned char**)(combatant+0x138)+0x14)&0x8000000)))result=1;
}
}
return result;
}
