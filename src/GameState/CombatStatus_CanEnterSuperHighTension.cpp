#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208810C; symbol: func_0208810c; size: 0x44.
extern "C" bool CombatStatus_CanEnterSuperHighTension(unsigned int* p) { unsigned int flags=p[5];if(flags&1)return false;if(flags&0x1000000)return false;if(flags&16)return false;if(flags&0x80000)return false;return !(flags&8); }
