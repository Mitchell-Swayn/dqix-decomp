#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" {
// Original: arm9/main @ 0x020A0DB8; symbol: func_020a0db8; size: 0x34.
    void InitializeTwoVectorInterpolationModeTwo(unsigned char *p,const Vector3i *a,const Vector3i *b,int c){
        *(Vector3i *)(p+4)=*a;
        *(Vector3i *)(p+16)=*b;
        *(int *)(p+36)=c;
        *(int *)p=2;
    }
}
