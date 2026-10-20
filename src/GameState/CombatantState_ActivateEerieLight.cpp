#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void CombatantState_ClearHolyImpregnable(void*);
// Original: arm9/main @ 0x02088D24; symbol: func_02088d24; size: 0x28.
extern "C" void CombatantState_ActivateEerieLight(unsigned char* p){p[123]=5;p[158]=0;*(unsigned*)(p+24)|=16;CombatantState_ClearHolyImpregnable(p);}
