#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020883AC; symbol: func_020883ac; size: 0x20.
bool CombatStatus_CanApplyConfusion(unsigned int *p){unsigned int f=p[5];if(f&1)return false;return !(f&0x1000000);}
}
