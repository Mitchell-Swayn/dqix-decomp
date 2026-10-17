#include <globaldefs.h>
ARM
struct Flags{unsigned short a:2,b:4,c:3,d:3,e:2,f:1,g:1;};struct ByteFlags{unsigned char a:2,b:1,c:1,d:4;};
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x02088F68; symbol: func_02088f68; size: 0xC4.
extern "C" void Object_ResetPackedCountersFlagsAndTimers(unsigned char* p){*(unsigned*)(p+20)=0;*(unsigned*)(p+24)=8192;p[33]=0;Flags* flags=(Flags*)(p+34);flags->a=0;flags->b=0;flags->c=0;flags->d=0;flags->e=0;p[36]=0;flags->f=0;ByteFlags* b=(ByteFlags*)(p+59);b->c=0;b->d=0;b->b=0;*(short*)(p+50)=-1;*(short*)(p+52)=-1;memset(p+88,0,4);memset(p+92,0,35);memset(p+127,0,35);}
