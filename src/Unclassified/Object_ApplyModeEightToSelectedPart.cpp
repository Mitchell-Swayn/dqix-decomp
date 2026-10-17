#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void SetResolvedEntryByte2ABits(void *,int,unsigned int);
// Original: arm9/main @ 0x0208108C; symbol: func_0208108c; size: 0x14.
    void Object_ApplyModeEightToSelectedPart(unsigned char *p,int id){
        SetResolvedEntryByte2ABits(p+4,id,8);
    }
}
