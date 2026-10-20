#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x02033E18; symbol: func_02033e18; size: 0x14.
    void Object_SetHalfwordC6AndVectorC8(unsigned char *p,const Vector3i *v,short value){
        *(short *)(p+198)=value;
        *(Vector3i *)(p+200)=*v;
    }
}
