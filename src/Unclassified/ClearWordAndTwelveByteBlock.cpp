#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020972B0; symbol: func_020972b0; size: 0x18.
    void *ClearWordAndTwelveByteBlock(unsigned char *p){
        *(int *)p=0;
        return memset(p+4,0,12);
    }
}
