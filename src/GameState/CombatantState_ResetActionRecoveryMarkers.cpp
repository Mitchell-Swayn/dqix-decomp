#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02089758; symbol: func_02089758; size: 0x24.
void CombatantState_ResetActionRecoveryMarkers(unsigned char *p){p[59]&=~2;p[60]&=~64;p[58]=0;}
}
