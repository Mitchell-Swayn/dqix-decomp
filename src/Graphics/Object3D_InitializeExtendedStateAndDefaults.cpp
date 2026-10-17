#include <globaldefs.h>
ARM
extern "C" void Object_InitializeAnimationControlDefaults(void*);
struct State {char pad[0x130];unsigned a,b,c,d,e,f,g;short h;short p;unsigned i,j,k,l,m,n,o,q,r,s,t,u,v;char pad184[30];unsigned char active;};
// Original: arm9/main @ 0x020AD59C; symbol: func_020ad59c; size: 0x80.
extern "C" void Object3D_InitializeExtendedStateAndDefaults(State* p) {
    Object_InitializeAnimationControlDefaults(p);
    p->b=0;p->c=0;p->h=0;p->i=0;p->m=0;p->d=0;p->e=0;p->f=491;p->g=204;
    p->j=0;p->k=0;p->l=0;p->n=0;p->o=0;p->q=0;p->s=0;p->t=0;p->u=0;p->r=0;
    p->v=0;p->active=1;p->a=0;
}
