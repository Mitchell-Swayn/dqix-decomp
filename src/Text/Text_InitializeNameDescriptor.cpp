#include <globaldefs.h>
ARM
struct Bits{unsigned a:6,b:6,c:6,d:6,e:2,f:1,g:1,h:1,pad:1,i:1,rest:1;};struct Record{unsigned x,y;Bits flags;};extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x020E4B34; symbol: func_020e4b34; size: 0xC0.
extern "C" void Text_InitializeNameDescriptor(Record* p,unsigned x,unsigned y,unsigned a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g,unsigned char h,unsigned char i){memset(p,0,12);p->x=x;p->y=y;p->flags.a=a;p->flags.b=b;p->flags.c=c;p->flags.d=d;p->flags.e=e;p->flags.f=f;p->flags.g=g;p->flags.h=h;p->flags.i=i;}
