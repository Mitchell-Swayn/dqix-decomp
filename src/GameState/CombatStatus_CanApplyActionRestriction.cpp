#include <globaldefs.h>
extern "C" {
struct A{char pad[0x14];unsigned int flags;char pad2[10];unsigned short pad3:2;unsigned short mode:4;};
// Original: arm9/main @ 0x02088418; symbol: func_02088418; size: 0x5C.
int CombatStatus_CanApplyActionRestriction(A *p,unsigned int key,int op){unsigned int f=p->flags;if(f&1)return 0;if((f&0x1000000)&&op!=0x1fc&&op!=0x20f)return 0;if(f&8)return 0;if((f&0x80000)&&key==p->mode)return 0;return 1;}
}
