#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02088540; symbol: func_02088540; size: 0x20.
bool CombatStatus_CanApplyAilmentModeTwo(unsigned int *p){unsigned int f=p[5];if(f&1)return false;return !(f&0x1000000);}
}
