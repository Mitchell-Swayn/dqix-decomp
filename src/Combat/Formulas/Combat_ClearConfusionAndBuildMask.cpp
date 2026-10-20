#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasConfusion(void*);
extern "C" void CombatStatus_ClearConfusion(void*);
extern "C" void Combat_SetResultMaskFlag(int,void*,int);
// Original: arm9/ov024 @ 0x021E4588; symbol: EnableCombatantDescriptorAndSetMask25; size: 0x7c.
// Enables descriptor byte3b bit0 and returns a two-word mask containing bit25.
extern "C" unsigned long long Combat_ClearConfusionAndBuildMask(char* self,int unused,int id) {
 char* target=_Z16GetCombatantByIDii(*(int*)(self+16),id);if(!target)return 0;
 unsigned long long mask=0;
 if(CombatEffect_TargetHasConfusion(target)){
 CombatStatus_ClearConfusion(*(void**)(target+0x138));
 struct Bits {unsigned char value:1;unsigned char rest:7;};
 ((Bits*)(*(char**)(target+0x138)+0x3b))->value=1;
 Combat_SetResultMaskFlag(*(int*)(self+16),&mask,25);
 }
 return mask;
}
