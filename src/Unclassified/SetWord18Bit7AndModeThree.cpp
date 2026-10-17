#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void WriteKindAndSetStateFive(void *,int);
// Original: arm9/main @ 0x0208876C; symbol: func_0208876c; size: 0x1C.
    void SetWord18Bit7AndModeThree(unsigned char *p){
        *(int *)(p+24)|=128;
        WriteKindAndSetStateFive(p,3);
    }
}
