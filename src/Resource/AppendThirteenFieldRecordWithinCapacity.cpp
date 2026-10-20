#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 3
struct Entry{short a,b,c,d,e;unsigned short f;unsigned g,h;short i,j,k,l;unsigned m;};struct List{unsigned a;Entry* entries;unsigned short capacity,count;};
// Original: arm9/main @ 0x02071CC8; symbol: func_02071cc8; size: 0x98.
extern "C" void AppendThirteenFieldRecordWithinCapacity(List* p,const Entry* src){unsigned n=p->count;if(p->capacity<=n)return;Entry* dst=p->entries+n;dst->a=src->a;dst->b=src->b;dst->c=src->c;dst->d=src->d;dst->e=src->e;dst->f=src->f;dst->g=src->g;dst->h=src->h;dst->i=src->i;dst->j=src->j;dst->k=src->k;dst->l=src->l;dst->m=src->m;++p->count;}
