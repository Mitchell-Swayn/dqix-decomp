#include <globaldefs.h>
ARM
#pragma optimization_level 2
#pragma always_inline on
struct Triple{int words[3];};struct Record{unsigned char a,b,c,d;unsigned short e;short f,g,h;Triple vectors[5];int i,j;short k;unsigned char l,m,n,pad[3];int o,p,q;};struct State{unsigned char pad[0x26c];Record data;};
// Original: arm9/main @ 0x020398B4; symbol: func_020398b4; size: 0xF4.
extern "C" void GameObject_CopyLadderTraversalState(State* p,Record* in){p->data.a=in->a;p->data.b=in->b;p->data.c=in->c;p->data.d=in->d;p->data.e=in->e;p->data.f=in->f;p->data.g=in->g;p->data.h=in->h;p->data.vectors[0]=in->vectors[0];p->data.vectors[1]=in->vectors[1];p->data.vectors[2]=in->vectors[2];p->data.vectors[3]=in->vectors[3];p->data.vectors[4]=in->vectors[4];p->data.i=in->i;p->data.j=in->j;p->data.k=in->k;p->data.l=in->l;p->data.m=in->m;p->data.n=in->n;p->data.o=in->o;p->data.p=in->p;p->data.q=in->q;}
