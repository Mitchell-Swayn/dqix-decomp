#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int Selection_GetActiveInputIndex(void *);
// Original: arm9/main @ 0x0205D794; symbol: func_0205d794; size: 0xC.
    int Selection_ReadEnabledIndexFromControl(void *p){
        return Selection_GetActiveInputIndex(p);
    }
}
