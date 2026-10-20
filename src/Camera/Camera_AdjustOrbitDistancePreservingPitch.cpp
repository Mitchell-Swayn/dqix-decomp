#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Camera_SetOrbitDistancePreservingPitch(void *,int);
// Original: arm9/main @ 0x0202E858; symbol: func_0202e858; size: 0x1C.
    void Camera_AdjustOrbitDistancePreservingPitch(unsigned char *p,int delta){
        int value=delta+*(int *)(p+120);
        if(value<4096)value=4096;
        Camera_SetOrbitDistancePreservingPitch(p,value);
    }
}
