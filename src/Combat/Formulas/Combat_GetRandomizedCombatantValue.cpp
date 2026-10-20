#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
int _Z13NextRandomMaxP6Randomi(void*,int);
float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
}
// Original: arm9/ov024 @ 0x021D9654; symbol: func_ov024_021d9654; size: 0x7C.
extern "C" int Combat_GetRandomizedCombatantValue(void** owner,int index,int a,int b,int c,int fallback) {
 char* combatant=(char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!combatant) return fallback;
 void* random=*owner;
 if(_Z13NextRandomMaxP6Randomi(random,2)>0) return 0;
 unsigned value=*(unsigned short*)(*(char**)(combatant+0x134)+0x34);
 float factor=_Z22NextRandomFloatBetweenP6Randomff(random,0.95f,1.05f);
 return (int)((float)value*factor);
}
