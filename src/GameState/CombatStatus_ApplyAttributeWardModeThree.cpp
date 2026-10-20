#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void CombatStatus_SetAttributeWardKindAndRefreshDuration(void *,int);
// Original: arm9/main @ 0x0208876C; symbol: func_0208876c; size: 0x1C.
    void CombatStatus_ApplyAttributeWardModeThree(unsigned char *p){
        *(int *)(p+24)|=128;
        CombatStatus_SetAttributeWardKindAndRefreshDuration(p,3);
    }
}
