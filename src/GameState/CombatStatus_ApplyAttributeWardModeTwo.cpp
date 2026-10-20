#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void CombatStatus_SetAttributeWardKindAndRefreshDuration(void*,unsigned);
// Original: arm9/main @ 0x02088724; symbol: func_02088724; size: 0x1C.
extern "C" void CombatStatus_ApplyAttributeWardModeTwo(unsigned char* p){*(unsigned*)(p+24)|=128;CombatStatus_SetAttributeWardKindAndRefreshDuration(p,2);}
