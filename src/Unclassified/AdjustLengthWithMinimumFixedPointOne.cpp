#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void RescaleField74ForNewField78Value(void *,int);
// Original: arm9/main @ 0x0202E858; symbol: func_0202e858; size: 0x1C.
    void AdjustLengthWithMinimumFixedPointOne(unsigned char *p,int delta){
        int value=delta+*(int *)(p+120);
        if(value<4096)value=4096;
        RescaleField74ForNewField78Value(p,value);
    }
}
