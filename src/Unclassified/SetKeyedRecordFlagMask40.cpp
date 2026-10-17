#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void SetResolvedEntryByte2ABits(void *,int,unsigned int);
// Original: arm9/main @ 0x020805F4; symbol: func_020805f4; size: 0x14.
    void SetKeyedRecordFlagMask40(unsigned char *p,int id){
        SetResolvedEntryByte2ABits(p+4,id,64);
    }
}
