#include <globaldefs.h>
struct Entry { unsigned first;unsigned char a,b,c,flags[4],pad;unsigned values[3];unsigned char other[4]; };
// Original: arm9/main @ 0x0208A9C0; symbol: func_0208a9c0; size: 0x58.
extern "C" void PartyProgress_InitializeConditionContext(Entry* p,unsigned a,unsigned b,unsigned c) {p->a=a;p->b=b;p->c=c;for(int i=0;i<4;i++){p->flags[i]=0xfe;p->other[i]=0;}for(int i=0;i<3;i++)p->values[i]=0;}
