#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Motion {char pad0[0x14];unsigned state;char pad1[0x40];unsigned low:21;int delta:3;unsigned high:8;char pad2[0x19];unsigned char timer;char pad3[0x22];unsigned char active;};extern "C" void ClearField14Flag20000AndField58FlagE00000AndBytes75And98(Motion*);extern "C" void ClearField18Flag2AndBytes6CAnd8F(Motion*);extern "C" void ClearField18Flag4AndBytes6DAnd90(Motion*);
// Original: arm9/main @ 0x02087E6C; symbol: func_02087e6c; size: 0x90.
extern "C" int Object_AdjustSignedThreeBit58Field21AndUpdateState(Motion* p,int amount){int delta=amount+p->delta;if(delta>2)delta=2;if(delta< -2)delta=-2;if(!delta){ClearField14Flag20000AndField58FlagE00000AndBytes75And98(p);return 0;}p->delta=delta;p->timer=5;p->active=0;p->state|=0x20000;ClearField18Flag2AndBytes6CAnd8F(p);ClearField18Flag4AndBytes6DAnd90(p);return p->delta;}
