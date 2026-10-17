#include <globaldefs.h>
struct Four{unsigned short a:4,b:4,c:4,d:4;};struct Bits{unsigned a:10,b:10,c:8,d:4;};struct Bits2{unsigned a:10,b:10,c:1,d:1,e:1,f:8,g:1;};struct Object{short ids[5];Four first;Bits second;Bits2 third;short ids2[4];unsigned value;};
// Original: arm9/main @ 0x02071B38; symbol: func_02071b38; size: 0xB0.
extern "C" ARM void InitializeRecordWithInvalidIdArrays(Object* p){p->ids[0]=-1;p->ids[1]=-1;p->ids[2]=-1;p->ids[3]=-1;p->ids[4]=-1;p->first.a=0;p->first.b=0;p->first.c=0;p->first.d=1;p->second.a=0;p->second.b=0;p->second.c=0;p->third.a=0;p->third.b=0;p->third.c=1;p->third.d=0;p->third.e=0;p->third.f=0;p->ids2[0]=-1;p->ids2[1]=-1;p->ids2[2]=-1;p->ids2[3]=-1;p->value=0;}
