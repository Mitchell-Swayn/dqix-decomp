#include <globaldefs.h>
struct Stats{char pad[0x30];unsigned short a,b,c,d,e;short gap;unsigned x:10;unsigned y:10;unsigned z:10;unsigned rest:2;};struct Out{int pad;unsigned short a,b,c,d,e;short gap;unsigned x:10;unsigned y:10;unsigned z:10;unsigned rest:2;char tail[0x2a];char text[1];};extern "C" void CopyBytesAndTwoScalarFields(void*,const void*);
// Original: arm9/main @ 0x02089494; symbol: func_02089494; size: 0xCC.
extern "C" ARM void CopyStatisticsAndOffsetTextIntoOutputRecord(Out* p,const char* str,Stats* s){p->a=s->a;p->b=s->b;CopyBytesAndTwoScalarFields(p->text,str+9);p->e=s->e;p->c=s->c;p->d=s->d;p->x=(unsigned short)s->x;p->y=(unsigned short)s->y;p->z=(unsigned short)s->z;}
