#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020A6180; symbol: func_020a6180; size: 0x14.
    void *Object_Clear512Bytes(void *p){
        return memset(p,0,512);
    }
}
