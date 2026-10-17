#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void InitializeThirtyTwoRecordsAndOwnerCounters(void *);
// Original: arm9/main @ 0x0203C4C4; symbol: func_0203c4c4; size: 0xC.
    void Object_InitializeEmbeddedContainerWrapper(void *p){
        InitializeThirtyTwoRecordsAndOwnerCounters(p);
    }
}
