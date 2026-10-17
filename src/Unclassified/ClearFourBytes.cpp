#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020E5280; symbol: func_020e5280; size: 0x14.
    void *ClearFourBytes(void *p){
        return memset(p,0,4);
    }
}
