#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088B84; symbol: func_02088b84; size: 0x1C.
void CombatantState_ClearFocusPocus(char *p){*(unsigned int *)(p+20)&=~0x40000000;p[0x68]=0;p[0x8b]=0;}
}
