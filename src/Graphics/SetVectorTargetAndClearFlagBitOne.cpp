#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" {
    void InitializeTwoVectorInterpolationModeTwo(unsigned char *,const Vector3i *,const Vector3i *,int);
// Original: arm9/main @ 0x0202EE58; symbol: func_0202ee58; size: 0x2C.
    void SetVectorTargetAndClearFlagBitOne(unsigned char *p,const Vector3i *v,int value){
        InitializeTwoVectorInterpolationModeTwo(p+404,(const Vector3i *)(p+16),v,value);
        *(int *)(p+360)&=~2;
    }
}
