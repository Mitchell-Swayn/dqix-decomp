#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void InitializeWorldScriptArrayList(void *);
// Original: arm9/main @ 0x0208D854; symbol: func_0208d854; size: 0xC.
    void WorldScriptArrayList_ResetPointersCountsAndSentinel(void *p){
        InitializeWorldScriptArrayList(p);
    }
}
