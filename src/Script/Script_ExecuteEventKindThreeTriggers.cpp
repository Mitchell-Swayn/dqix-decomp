#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    bool Script_ExecuteFirstSatisfiedTriggerGroup(void *,int,void *);
// Original: arm9/main @ 0x020649F4; symbol: func_020649f4; size: 0x14.
    bool Script_ExecuteEventKindThreeTriggers(void *p,void *out){
        return Script_ExecuteFirstSatisfiedTriggerGroup(p,3,out);
    }
}
