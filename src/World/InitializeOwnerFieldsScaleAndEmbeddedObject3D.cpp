#include <globaldefs.h>
#pragma optimization_level 4
#include "World/Object3D.h"
// Original: arm9/main @ 0x02058C88; symbol: func_02058c88; size: 0xB8.
extern "C" ARM void InitializeOwnerFieldsScaleAndEmbeddedObject3D(char* p)
{
    *(unsigned*)(p+0x28)=0;
    p[12]=0;
    *(unsigned*)(p+4)=0;
    *(unsigned*)(p+8)=0;
    *(unsigned*)(p+16)=0;
    *(unsigned*)(p+20)=0;
    *(unsigned*)(p+24)=0;
    *(unsigned*)(p+28)=0;
    *(unsigned*)(p+32)=0;
    *(unsigned*)(p+36)=0;
    p[44]=0;
    p[45]=0;
    p[46]=0;
    *(unsigned*)(p+88)=0;
    *(unsigned*)(p+92)=0;
    *(unsigned*)(p+96)=0;
    *(unsigned*)(p+52)=0;
    *(unsigned*)(p+56)=0;
    *(unsigned*)(p+60)=0;
    *(unsigned*)(p+64)=0;
    *(unsigned*)(p+68)=0;
    *(unsigned*)(p+72)=0;
    *(unsigned*)(p+76)=0;
    *(short*)(p+100)=0;
    *(short*)(p+102)=0;
    *(short*)(p+104)=0;
    *(short*)(p+106)=0;
    *(unsigned*)(p+300)=0;
    *(unsigned*)(p+304)=0;
    *(unsigned*)(p+308)=0;
    *(unsigned*)(p+312)=0;
    *(unsigned*)(p+316)=0;
    *(unsigned*)(p+320)=0;
    *(unsigned*)(p+324)=0;
    *(unsigned*)(p+116)=0;
    *(unsigned*)(p+112)=0;
    *(unsigned*)(p+108)=0;
    *(unsigned*)(p+120)=0;
    *(float*)(p+0x30)=1.0f;
    *(unsigned*)(p+0x128)=0;
    ((Object3D*)(p+0x7c))->Initialize();
}
