#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void ResourceEntry_SetTimedStatusOrRelease(void *,int);
// Original: arm9/main @ 0x020BC018; symbol: func_020bc018; size: 0x10.
    void DispatchValueThroughFirstPointer(void **p,int value){
        ResourceEntry_SetTimedStatusOrRelease(*p,value);
    }
}
