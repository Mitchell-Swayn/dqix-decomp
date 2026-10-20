#include <globaldefs.h>
ARM
struct Pair{short index,extra;};
struct Entry {
unsigned value;short a,b,c,d,e,f;short g;unsigned char h;unsigned char low:4,high:4;unsigned char low2:2,high2:6;char pad[3];Pair k,l,m,n;short o;unsigned char q,r,s,t;char pad2[2];

};
struct Table;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void DisplayLayout_AppendPart(Table*,const Entry*);
// Original data: arm9/main @ 0x2108ee0; symbol: data_02108ee0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[];
#define PARAM(n) _ZNK6Script9Parameter5ToIntEv(p+(n)*8)
// Original: arm9/main @ 0x0207F158; symbol: func_0207f158; size: 0x350.
extern "C" int DisplayLayoutScript_AppendTypedPart(char* p){
Entry e;e.value=0;e.a=-1;e.b=e.c=0;e.d=e.e=0;e.f=-1;e.g=-1;e.h=0;e.low=10;e.high=0;e.low2=0;e.high2=3;e.k.index=-1;e.l.index=-1;e.m.index=-1;e.n.index=-1;e.o=0;e.q=0;e.r=0;e.s=0;
e.a=PARAM(0);e.b=PARAM(1);e.c=PARAM(2);e.h=PARAM(3);
switch(e.h){
case 0:e.low=(unsigned char)PARAM(4);e.high=(unsigned char)PARAM(5);e.f=PARAM(6);break;
case 1:e.d=PARAM(4);e.e=PARAM(5);e.high=(unsigned char)PARAM(6);break;
case 2:e.low=(unsigned char)PARAM(4);e.high=(unsigned char)PARAM(5);e.f=PARAM(6);e.g=PARAM(7);break;
case 3:e.low=(unsigned char)PARAM(4);e.high=(unsigned char)PARAM(5);e.f=PARAM(6);e.low2=(unsigned char)PARAM(7);e.high2=(unsigned char)PARAM(8);e.g=PARAM(9);break;
case 4:e.low=(unsigned char)PARAM(4);e.high=(unsigned char)PARAM(5);break;
case 5:e.low=(unsigned char)PARAM(4);e.high=(unsigned char)PARAM(5);e.low2=(unsigned char)PARAM(6);e.high2=(unsigned char)PARAM(7);e.g=PARAM(8);break;
}
DisplayLayout_AppendPart((Table*)DisplayLayoutScriptAppendTypedPart_UnknownRoleZeroInitializedStorage[1],&e);return 1;
}
