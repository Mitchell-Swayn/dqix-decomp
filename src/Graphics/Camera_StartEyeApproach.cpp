#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" {
    void InitializeTwoVectorInterpolationModeTwo(unsigned char *,const Vector3i *,const Vector3i *,int);
// Original: arm9/main @ 0x0202EE38; symbol: func_0202ee38; size: 0x20.
    void Camera_StartEyeApproach(unsigned char *p,const Vector3i *v,int value){
        InitializeTwoVectorInterpolationModeTwo(p+364,(const Vector3i *)(p+4),v,value);
    }
}
