#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020292EC; symbol: func_020292ec; size: 0x98.
extern "C" void Graphics_SubmitFixedPointQuadRegisters(int x,int y,int a,int b,unsigned attr){volatile unsigned* regs=(volatile unsigned*)0x04000444;regs[0]=0;regs[4]=0;regs[11]=x<<12;regs[11]=y<<12;regs[11]=0x3ff000;regs[10]=a<<12;regs[10]=b<<12;regs[10]=4096;regs[47]=1;regs[15]=(unsigned short)attr;regs[18]=0;regs[18]=4096;regs[18]=4096;regs[18]=4096;regs[18]=0x10001000;regs[18]=4096;regs[18]=0x10000000;regs[18]=4096;regs[48]=0;regs[1]=1;}
