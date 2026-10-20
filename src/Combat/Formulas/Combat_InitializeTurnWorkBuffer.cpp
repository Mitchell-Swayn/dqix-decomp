#include <globaldefs.h>
#include <std_library_functions.h>
ARM
// Original: arm9/ov024 @ 0x021EB510; symbol: func_ov024_021eb510; size: 0xC0.
extern "C" void Combat_InitializeTurnWorkBuffer(unsigned char* p){
*(unsigned*)(p+0x10)=0;p[0x6c]=0;*(unsigned*)(p+0x14)=0;*(short*)(p+0x44)=-1;*(unsigned*)(p+0x18)=0;
*(unsigned*)(p+4)=0;*(unsigned*)(p+8)=0;*(unsigned*)(p+12)=0;p[0x6e]=0;p[0x6f]=1;*(float*)(p+0x1c)=1.0f;
p[0x71]=0;p[0x72]=0;p[0x73]=0;p[0x47]=0;p[0x76]=0;p[0x78]=0;p[0x79]=0;p[0x77]=0;p[0x7a]=0;
memset(p+0x48,0,0x20);*(unsigned*)(p+0x68)=0;
memset(p+0x20,-1,8);memset(p+0x28,-1,16);memset(p+0x38,0,4);memset(p+0x3c,0,8);
}
