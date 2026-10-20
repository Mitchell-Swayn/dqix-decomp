#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopy16(const void*,void*,unsigned);
struct Output {unsigned char a,b,c,d;char block[20];unsigned short zero1,value1;char block2[52];unsigned short zero2,value2;};
struct Hardware {char pad[2];unsigned char nibble:4;unsigned char rest:4;unsigned char a,b;char pad5[95];unsigned short kind:3;unsigned short flags:13;};
// Original: arm9/main @ 0x020C99C8; symbol: func_020c99c8; size: 0x84.
extern "C" void OS_GetOwnerInfo(Output* out) {
    Hardware* in=(Hardware*)0x027ffc80;
    out->a=in->kind;out->b=in->nibble;out->c=in->a;out->d=in->b;
    out->value1=((unsigned char*)in)[26];out->value2=((unsigned char*)in)[80];
    MIi_CpuCopy16((char*)in+6,out->block,20);
    MIi_CpuCopy16((char*)in+28,out->block2,52);
    out->zero1=0;out->zero2=0;
}
