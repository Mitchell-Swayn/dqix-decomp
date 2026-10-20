#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "GameState/GameState.h"
struct Record;struct A;extern "C" GameObject*Combat_FindIndexedMonsterObject(void*,int);extern "C" int CombatStatus_HasAilmentModeOne(Record*),CombatStatus_HasAilmentModeTwo(A*),CombatEffect_TargetHasDazzle(void*),CombatEffect_TargetHasFizzle(unsigned char*);struct Fields{signed f0:3,f1:3,f2:3,f3:3,f4:3,f5:3,f6:3,f7:3,f8:3,f9:3,rest:2;};
// Original: arm9/ov024 @ 0x021F3564; symbol: func_ov024_021f3564; size: 0x124.
extern "C" ARM int Combat_SelectIndexWhenAnyNegativeStatusOrFlagIsPresent(void**self,int index,int unused,int*count,short*out){GameObject*object=Combat_FindIndexedMonsterObject(*self,index);if(!object)return 0;int total=0;if(CombatStatus_HasAilmentModeOne((Record*)P(object,0x138)))total++;if(CombatStatus_HasAilmentModeTwo((A*)P(object,0x138)))total++;if(CombatEffect_TargetHasDazzle(object))total++;if(CombatEffect_TargetHasFizzle((unsigned char*)object))total++;volatile Fields*flags=(volatile Fields*)(P(object,0x138)+0x58);if(flags->f0<0)total++;if(flags->f1<0)total++;if(flags->f2<0)total++;if(flags->f3<0)total++;if(flags->f4<0)total++;if(flags->f5<0)total++;if(flags->f6<0)total++;if(flags->f7<0)total++;if(flags->f9<0)total++;if(flags->f8<0)total++; if(total<=0)return 0;*count=1;*out=index;return 1;}