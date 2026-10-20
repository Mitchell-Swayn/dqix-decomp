#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int CombatantState_IsEligibleForLinkedCombatEffect(); struct Object {char pad[24];unsigned flags;};
// Original: arm9/main @ 0x02088DD8; symbol: func_02088dd8; size: 0x2C.
extern "C" ARM int CombatantState_CanApplyLinkedCombatEffect(Object* p){int available=CombatantState_IsEligibleForLinkedCombatEffect();if(!available)return 0;else return (p->flags&0x1000)?0:1;}
