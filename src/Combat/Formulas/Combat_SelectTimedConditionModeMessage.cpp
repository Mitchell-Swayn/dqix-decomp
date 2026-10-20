#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasDazzle(void*);
// Original: arm9/ov024 @ 0x021E9198; symbol: Combat_SelectRecordCodeForCombatant; size: 0x104.
// Selects a combatant record result from the matching three-bit attribute, with separate alternate and default mappings.
extern "C" int Combat_SelectTimedConditionModeMessage(void* self,int combatantId,int attribute,int alternate){
 void* combatant=_Z16GetCombatantByIDii(*(int*)((char*)self+0x10),combatantId);if(!combatant)return 0;
 if(alternate){if(!CombatEffect_TargetHasDazzle(combatant))goto fail;unsigned selector=((unsigned)*(unsigned short*)(*(char**)((char*)combatant+0x138)+0x22)<<23)>>29;if(attribute!=selector)goto fail;switch(attribute){case 0:goto fail;case 1:return 0x26;case 2:return 0x140;case 3:return 0x126;case 4:return 0x13d;default:goto fail;}}
 if(!CombatEffect_TargetHasDazzle(combatant))goto fail;unsigned selector=((unsigned)*(unsigned short*)(*(char**)((char*)combatant+0x138)+0x22)<<23)>>29;if(attribute!=selector)goto fail;switch(attribute){case 0:goto fail;case 1:return 0x27;case 2:return 0x141;case 3:return 0x137;case 4:return 0x13f;default:goto fail;}
 fail:return 0;
}
