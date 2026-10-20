#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void CombatantState_ClearFireBarrier(void *);
// Original: arm9/main @ 0x02088C74; symbol: func_02088c74; size: 0x28.
    void CombatantState_ActivateIceBarrier(unsigned char *p){
        p[109]=5;
        p[144]=0;
        *(int *)(p+24)|=4;
        CombatantState_ClearFireBarrier(p);
    }
}
