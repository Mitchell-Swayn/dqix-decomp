#include <globaldefs.h>
extern "C" void VectorizedMemset(void*,int,unsigned int);
// Original: arm9/ov017 @ 0x0219A674; symbol: func_ov017_0219a674; size: 0x44.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM void InitializeTwentyByteRecordDefaults(unsigned char* p)
{
    VectorizedMemset(p,0,20);
    p[0]=15;
    p[1]=18;
    *(unsigned short*)(p+2)=255;
    p[4]=0;
    *(unsigned short*)(p+16)=0x3244;
}
