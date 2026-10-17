#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void InvokeHandleStateWhenPresent(void *,void *);
// Original: arm9/main @ 0x0205EBEC; symbol: func_0205ebec; size: 0x10.
    void DispatchStoredResourceHandleAtOffsetC0(unsigned char *p){
        InvokeHandleStateWhenPresent(p,*(void **)(p+192));
    }
}
