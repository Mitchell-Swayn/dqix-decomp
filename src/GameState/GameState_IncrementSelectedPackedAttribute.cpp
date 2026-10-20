#include <globaldefs.h>
ARM
struct Packed {unsigned a:10,b:10,c:10,rest:2;};
struct Trio {Packed v[3];};
extern "C" {
int CharacterState_ClampStatIncrease(int,unsigned,unsigned,unsigned);
int GameState_SumEnabledFlags45Through221Lookup(void*);
int GameState_SumPresentAttributesFromFirstSentinelTable(void*);
int GameState_SumEnabledFlags47Through280Lookup(void*);
int GameState_SumEnabledFlags154Through284Lookup(void*);
int GameState_SumPresentAttributesFromSecondSentinelTable(void*);
int GameState_SumEnabledFlags78Through257Lookup(void*);
int GameState_SumEnabledAttributeValuesFromSentinelIds(void*);
int GameState_SumPresentAttributesFromThirdSentinelTable(void*);
int GameState_SumEnabledFlags80Through261Lookup(void*);
}
// Original: arm9/main @ 0x02084A64; symbol: func_02084a64; size: 0x3E8.
extern "C" int GameState_IncrementSelectedPackedAttribute(char* p,int id){
 Trio* selected=(Trio*)(p+0x850)+*(int*)(p+0x950);
 int result=0,error=0;
 switch(id){
case 0x1a5:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledFlags45Through221Lookup(p)+((Packed*)(p+0x91c))[0].a+selected->v[0].a,2,999);
selected->v[0].a+=result;break;
case 0x1a7:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumPresentAttributesFromFirstSentinelTable(p)+((Packed*)(p+0x91c))[0].b+selected->v[0].b,2,999);
selected->v[0].b+=result;break;
case 0x1a8:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledFlags47Through280Lookup(p)+((Packed*)(p+0x91c))[0].c+selected->v[0].c,2,999);
selected->v[0].c+=result;break;
case 0x1a6:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledFlags154Through284Lookup(p)+((Packed*)(p+0x91c))[1].a+selected->v[1].a,2,999);
selected->v[1].a+=result;break;
case 0x1ac:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumPresentAttributesFromSecondSentinelTable(p)+((Packed*)(p+0x91c))[1].b+selected->v[1].b,2,999);
selected->v[1].b+=result;break;
case 0x1aa:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledFlags78Through257Lookup(p)+((Packed*)(p+0x91c))[1].c+selected->v[1].c,2,999);
selected->v[1].c+=result;break;
case 0x1a9:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledAttributeValuesFromSentinelIds(p)+((Packed*)(p+0x91c))[2].a+selected->v[2].a,2,999);
selected->v[2].a+=result;break;
case 0x106:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumPresentAttributesFromThirdSentinelTable(p)+((Packed*)(p+0x91c))[2].b+selected->v[2].b,3,999);
selected->v[2].b+=result;break;
case 0x107:
result=CharacterState_ClampStatIncrease((int)p,GameState_SumEnabledFlags80Through261Lookup(p)+((Packed*)(p+0x91c))[2].c+selected->v[2].c,3,999);
selected->v[2].c+=result;break;
case 0x1ab:result=CharacterState_ClampStatIncrease((int)p,*(unsigned short*)(p+0x564),2,2600);
*(unsigned short*)(p+0x564)+=(unsigned short)result;break;
default:error=1;break;
}
return error?-1:result;
}
