#include <globaldefs.h>
ARM
#pragma optimization_level 2
#pragma optimize_for_size off
extern "C" void* memset(void*,int,unsigned);
struct State { unsigned a[2], b,c,d,e,f; unsigned short g,h,i; unsigned char j,k,l; signed char m,n; };
// Original: arm9/main @ 0x0205A198; symbol: func_0205a198; size: 0x58.
extern "C" void InitializeFixedPointScalesAndInvalidIndices(State* p) { memset((void*)p,0,8); p->b=0;p->c=p->d=0x1000;p->f=0;p->e=0;p->g=0;p->h=0;p->i=0;p->j=0;p->k=0;p->l=0;p->m=-1;p->n=-1; }
