#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void TouchInput_ResetTrackingState(void *);
// Original: arm9/main @ 0x02012BB0; symbol: func_02012bb0; size: 0xC.
    void TouchInput_ResetTrackingStateWrapper(void *p){
        TouchInput_ResetTrackingState(p);
    }
}
