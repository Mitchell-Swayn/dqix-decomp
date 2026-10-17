#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    bool FindGroupAndProcessHeadAfterClearingOutputCount(void *,int,void *);
// Original: arm9/main @ 0x020649F4; symbol: func_020649f4; size: 0x14.
    bool Object_ReadStatusKindThree(void *p,void *out){
        return FindGroupAndProcessHeadAfterClearingOutputCount(p,3,out);
    }
}
