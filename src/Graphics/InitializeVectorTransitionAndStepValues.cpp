#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" {
// Original: arm9/main @ 0x020A0D6C; symbol: func_020a0d6c; size: 0x4C.
    void InitializeVectorTransitionAndStepValues(unsigned char *p,const Vector3i *a,const Vector3i *b,int c,int d,int e){
        *(Vector3i *)(p+4)=*a;
        *(Vector3i *)(p+16)=*b;
        *(int *)(p+28)=c;
        *(int *)(p+32)=d;
        *(int *)(p+36)=e;
        if(!e)*(int *)(p+36)=d;
        *(int *)p=1;
    }
}
