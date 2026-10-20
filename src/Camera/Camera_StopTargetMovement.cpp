#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Camera_ResetInterpolationRecord(void *);
// Original: arm9/main @ 0x0202EE94; symbol: func_0202ee94; size: 0x10.
    void Camera_StopTargetMovement(unsigned char *p){
        Camera_ResetInterpolationRecord(p+404);
    }
}
