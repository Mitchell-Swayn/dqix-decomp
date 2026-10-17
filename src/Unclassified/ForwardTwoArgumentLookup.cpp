#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void *Util_FindSixteenByteRecordByHalfwordKey(void *,int);
// Original: arm9/main @ 0x020E5294; symbol: func_020e5294; size: 0xC.
    void *ForwardTwoArgumentLookup(void *p,int id){
        return Util_FindSixteenByteRecordByHalfwordKey(p,id);
    }
}
