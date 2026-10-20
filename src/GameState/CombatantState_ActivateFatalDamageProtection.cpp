#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088B14; symbol: func_02088b14; size: 0x20.
void CombatantState_ActivateFatalDamageProtection(char *p){p[0x67]=6;p[0x8a]=0;*(unsigned int *)(p+20)|=0x400000;}
}
