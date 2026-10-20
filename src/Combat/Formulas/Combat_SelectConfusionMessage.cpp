#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasConfusion(void*);
extern "C" int Combat_SelectMessageForPartyOrMonster(int,int,int);
// Original: arm9/ov024 @ 0x021E9320; symbol: SelectCombatantFlagMessage; size: 0x7c.
// Selects a party-indexed message halfword from descriptor flag 20 and operation mode.
extern "C" int Combat_SelectConfusionMessage(char* self,int index,int mode) {
 void* object=_Z16GetCombatantByIDii(*(int*)(self+16),index);
 if(!object)return 0;
 int flag=CombatEffect_TargetHasConfusion(object);
 if(mode){if(flag)return Combat_SelectMessageForPartyOrMonster(index,131,132);return Combat_SelectMessageForPartyOrMonster(index,129,130);}
 if(flag)return 133;
 return Combat_SelectMessageForPartyOrMonster(index,621,27);
}
