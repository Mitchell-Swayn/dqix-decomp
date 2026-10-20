#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int Selection_GetActiveInputIndex(void *);
// Original: arm9/main @ 0x0205CB64; symbol: func_0205cb64; size: 0x10.
    int Selection_ReadEnabledIndexFromEmbeddedControl(unsigned char *p){
        return Selection_GetActiveInputIndex(p+28);
    }
}
