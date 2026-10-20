#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void CombatantMotion_ClearSidestepState(void *);
// Original: arm9/main @ 0x02049520; symbol: func_02049520; size: 0x30.
void CombatantMotion_ResetSidestep(char **p){if(!p[79])return;CombatantMotion_ClearSidestepState(p[79]+0x4e);*(int *)(p[79]+32)&=~4;}
}
