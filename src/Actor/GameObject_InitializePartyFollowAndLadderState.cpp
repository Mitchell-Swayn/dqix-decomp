#include <globaldefs.h>
extern "C" void GameObject_InitializeLinkedStateAndActionQueue(void*);
extern "C" void InitializeRecordWithEnabledAndPercentDefaults(void*);
struct ResetState {unsigned short flags;char pad2[0x1c6];signed char a,b,c,d,e,f,g;char pad1cf[0x81];unsigned char h,i,j,k,l; signed char m;unsigned short n;char pad258[8];int o,p,q;char tail[1];};
// Original: arm9/main @ 0x02037D10; symbol: func_02037d10; size: 0x78.
extern "C" void GameObject_InitializePartyFollowAndLadderState(ResetState* p) {GameObject_InitializeLinkedStateAndActionQueue(p);p->flags|=0x800;p->d=-1;p->e=0;p->a=-1;p->b=0;p->c=-1;p->f=0;p->g=0;p->h=1;p->i=0;p->j=1;p->k=1;p->l=0;p->p=0;p->o=-1;p->m=-1;p->n=0;p->q=0;InitializeRecordWithEnabledAndPercentDefaults(p->tail);}
