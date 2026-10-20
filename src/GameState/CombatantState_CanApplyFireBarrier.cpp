#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088BF0; symbol: func_02088bf0; size: 0x20.
bool CombatantState_CanApplyFireBarrier(unsigned int *p){unsigned int flags=p[5];if(flags&1)return false;return !(flags&0x20000);}
}
