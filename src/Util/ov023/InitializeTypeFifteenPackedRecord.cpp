#include <globaldefs.h>
ARM
extern "C" void ResetRecordWithInvalidIndex(void*);
struct Record {int pad;unsigned short type,a,b,c;int pad2,value;char pad3[8];int state,x,y,z,extra;short d,e,f;char pad4[4];unsigned char low:4;unsigned char high:4;signed char g,h;unsigned char active;};
// Original: arm9/ov023 @ 0x021FBB64; symbol: func_ov023_021fbb64; size: 0xBC.
extern "C" int InitializeTypeFifteenPackedRecord(Record* p,void* unused,int a,int b,int d,int e,int f,int low,int g,int h,int high){
ResetRecordWithInvalidIndex(p);
p->type=15;p->extra=0;p->a=a;p->b=b;p->c=0;p->value=0;p->state=2;p->x=-0x10000;p->y=-0x3000;p->z=0;
p->d=d;p->e=e;p->f=f;p->low=(unsigned char)low;p->g=g;p->h=h;p->active=0;p->high=(unsigned char)high;
return 1;
}
