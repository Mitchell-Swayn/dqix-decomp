#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02087704; symbol: func_02087704; size: 0x68.
    void CombatStatus_DecrementTensionStage(unsigned char *p){
        p[36]--;
        if(p[36]==3){
            *(int *)(p+20)&=~0x1000000;
            p[36]=0;
            *(int *)(p+20)|=0x800000;
            p[36]=3;
        }if(!p[36]){
            p[36]=0;
            *(int *)(p+20)&=~0x800000;
            p[36]=0;
        }
    }
}
