#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void CombatStatus_SetAttributeWardKindAndRefreshDuration(void*,unsigned);
// Original: arm9/main @ 0x020887FC; symbol: func_020887fc; size: 0x1C.
extern "C" void CombatStatus_ApplyAttributeWardModeFive(unsigned char* p){*(unsigned*)(p+24)|=128;CombatStatus_SetAttributeWardKindAndRefreshDuration(p,5);}
