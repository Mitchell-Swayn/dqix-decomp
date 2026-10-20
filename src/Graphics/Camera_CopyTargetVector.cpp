#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x0202E938; symbol: func_0202e938; size: 0x10.
    void Camera_CopyTargetVector(unsigned char *p,const Vector3i *v){
        *(Vector3i *)(p+16)=*v;
    }
}
