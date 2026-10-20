#include <globaldefs.h>
extern "C" {
    void CombatStatus_ClearSpellResistanceStage(void *);
    struct Bits{
        unsigned int pad:18;
        int value:3;
        unsigned int high:11;
    };
// Original: arm9/main @ 0x02087D78; symbol: func_02087d78; size: 0x78.
    int CombatStatus_AdjustSpellResistanceStageAndRefreshDuration(unsigned char *p,int delta){
        Bits *b=(Bits *)(p+88);
        int value=delta+b->value;
        if(value>2)value=2;
        if(value<-2)value=-2;
        if(!value){
            CombatStatus_ClearSpellResistanceStage(p);
            return 0;
        }b->value=value;
        p[116]=5;
        p[151]=0;
        *(int *)(p+20)|=0x10000;
        return b->value;
    }
}
