#include <globaldefs.h>
ARM
struct State{unsigned char pad[20];unsigned int flags;unsigned char pad18[0x40];unsigned int low:15;signed int counter:3;unsigned int high:14;unsigned char pad5c[0x17];unsigned char mode;unsigned char pad74[0x22];unsigned char byte96;};extern "C" void ClearField14Flag8000AndField58Flag38000AndBytes73And96(State*);
// Original: arm9/main @ 0x02087C84; symbol: func_02087c84; size: 0x78.
extern "C" int Object_AdjustSignedThreeBit58Field15AndSetTimer(State* p,int delta){int value=delta+p->counter;if(value>2)value=2;if(value<-2)value=-2;if(!value){ClearField14Flag8000AndField58Flag38000AndBytes73And96(p);return 0;}p->counter=value;p->mode=5;p->byte96=0;p->flags|=0x8000;return p->counter;}
