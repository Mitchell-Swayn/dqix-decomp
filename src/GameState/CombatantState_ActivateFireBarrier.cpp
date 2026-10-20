#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void CombatantState_ClearIceBarrier(void*);
// Original: arm9/main @ 0x02088C10; symbol: func_02088c10; size: 0x28.
extern "C" void CombatantState_ActivateFireBarrier(unsigned char* p){p[108]=5;p[143]=0;*(unsigned*)(p+24)|=2;CombatantState_ClearIceBarrier(p);}
