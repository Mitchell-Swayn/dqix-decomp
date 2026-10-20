#include <globaldefs.h>
extern "C" void Selection_InitializeTouchAndDirectionalControls(void*);struct State{unsigned char pad[0x98];unsigned a,b;short x,y,z,w,u,v,s,t;unsigned char flags[9];};
// Original: arm9/main @ 0x0205CFD4; symbol: func_0205cfd4; size: 0x74.
extern "C" ARM void Selection_InitializeDisplayController(State* p){Selection_InitializeTouchAndDirectionalControls(p);p->a=0;p->b=0;p->x=1;p->y=1;p->z=0;p->w=0;p->u=4;p->v=4;p->s=10;p->t=11;p->flags[0]=0;p->flags[1]=0;p->flags[2]=0;p->flags[3]=0;p->flags[4]=0;p->flags[5]=0;p->flags[6]=0;p->flags[7]=10;p->flags[8]=255;}
