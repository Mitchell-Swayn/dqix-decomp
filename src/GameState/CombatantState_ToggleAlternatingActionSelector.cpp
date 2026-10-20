#include <globaldefs.h>
#pragma optimization_level 4
struct Flag { unsigned char enabled:1; unsigned char remaining:7; };struct Object {char pad[60];Flag flags;};
// Original: arm9/main @ 0x020891B0; symbol: func_020891b0; size: 0x1C.
extern "C" ARM void CombatantState_ToggleAlternatingActionSelector(Object* p){if(p->flags.enabled) p->flags.enabled=0; else p->flags.enabled=1;}
