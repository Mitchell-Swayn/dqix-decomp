#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x0209E4A0; symbol: func_0209e4a0; size: 0x1C.
    void *ScriptQueryContext_ClearFilteredRecords(unsigned char *p){
        *(int *)(p+152)=0;
        return memset(p+156,0,1024);
    }
}
