#include <globaldefs.h>
ARM
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView* descriptor; };
extern "C" bool GameObject_IsDead(void*);
extern "C" bool CombatStatus_HasSleep(unsigned int*);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" int Combat_HasActionRestriction(LinkedDescriptorView*);
extern "C" int CombatEffect_TargetHasConfusion(unsigned char*);
extern "C" int Combatant_IsExcludedFromActionResolution(void*);
// Original: arm9/ov024 @ 0x021FA76C; symbol: func_ov024_021fa76c; size: 0x80.
extern "C" int CombatStatus_CanReceiveEvaluatedDescriptorEffect(LinkedDescriptorView* p) {
if(GameObject_IsDead(p))return 0;
if(Combatant_IsExcludedFromActionResolution(p))return 0;
if(CombatEffect_TargetHasParalysis(p))return 0;
if(CombatStatus_HasSleep((unsigned*)p->descriptor))return 0;
if(Combat_HasActionRestriction(p))return 0;
return CombatEffect_TargetHasConfusion((unsigned char*)p)==0;
}
