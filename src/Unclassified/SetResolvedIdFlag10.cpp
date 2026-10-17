#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void SetResolvedEntryByte2ABits(void *,int,unsigned int);
// Original: arm9/main @ 0x020810A0; symbol: func_020810a0; size: 0x14.
    void SetResolvedIdFlag10(unsigned char *p,int id){
        SetResolvedEntryByte2ABits(p+4,id,16);
    }
}
