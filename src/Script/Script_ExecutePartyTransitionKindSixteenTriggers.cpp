#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    bool Script_ExecuteFirstSatisfiedTriggerGroup(void *,int,void *);
// Original: arm9/main @ 0x02064A24; symbol: func_02064a24; size: 0x1C.
    bool Script_ExecutePartyTransitionKindSixteenTriggers(unsigned char *p,void *out){
        *(int *)(p+1176)=0;
        return Script_ExecuteFirstSatisfiedTriggerGroup(p,16,out);
    }
}
