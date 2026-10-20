#include <globaldefs.h>
extern "C" {
    void CombatStatus_ClearEvasionStage(void *);
    struct Bits{
        unsigned int pad:27;
        int value:3;
        unsigned int high:2;
    };
// Original: arm9/main @ 0x02087F78; symbol: func_02087f78; size: 0x78.
    int CombatStatus_AdjustEvasionStageAndRefreshDuration(unsigned char *p,int delta){
        Bits *b=(Bits *)(p+88);
        int value=delta+b->value;
        if(value>2)value=2;
        if(value<-2)value=-2;
        if(!value){
            CombatStatus_ClearEvasionStage(p);
            return 0;
        }b->value=value;
        p[119]=5;
        p[154]=0;
        *(int *)(p+20)|=0x2000000;
        return b->value;
    }
}
