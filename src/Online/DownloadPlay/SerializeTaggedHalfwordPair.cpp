#include <globaldefs.h>
ARM
struct Record { unsigned char kind; unsigned char pad; unsigned short a,b; };
// Original: arm9/ov027 @ 0x021DD638; symbol: func_ov027_021dd638; size: 0x84.
extern "C" unsigned char* SerializeTaggedHalfwordPair(Record* p,unsigned char* dest){ unsigned char* out=dest; out++;
*dest=p->kind;
switch(p->kind){
case 4:
out[0]=p->a;
out[1]=(p->a&0xff00)>>8;
out[2]=p->b;
out[3]=(p->b&0xff00)>>8;
out+=4;
break;
case 1:case 2:case 3:case 5:case 6:break;
default:return 0;
}
return out;
}
