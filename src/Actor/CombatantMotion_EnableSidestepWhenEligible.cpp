#include <globaldefs.h>
extern "C" {
    bool GameObject_HasBattleMotionExclusionFlag80(void *);
    bool GameObject_IsBattleIdleMotionSuppressed(void *);
    bool GameObject_IsDead(void *);
    bool CombatantMotion_GetActiveStatus(void *);
// Original: arm9/main @ 0x02049A74; symbol: func_02049a74; size: 0x70.
    void CombatantMotion_EnableSidestepWhenEligible(unsigned char *p){
        if(!*(unsigned char **)(p+0x13c))return;
        if(GameObject_HasBattleMotionExclusionFlag80(p))return;
        if(GameObject_IsBattleIdleMotionSuppressed(p))return;
        if(!(*(unsigned char **)(p+0x13c))[86])return;
        if(GameObject_IsDead(p))return;
        if(CombatantMotion_GetActiveStatus(p)){
            unsigned char *q=*(unsigned char **)(p+0x13c);
            *(int *)(q+32)|=4;
        }
    }
}
