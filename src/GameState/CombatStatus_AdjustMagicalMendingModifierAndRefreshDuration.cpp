#include <globaldefs.h>
ARM
struct State{unsigned char pad[20];unsigned int flags;unsigned char pad18[0x40];unsigned int low:15;signed int counter:3;unsigned int high:14;unsigned char pad5c[0x17];unsigned char mode;unsigned char pad74[0x22];unsigned char byte96;};extern "C" void CombatStatus_ClearMagicalMendingModifier(State*);
// Original: arm9/main @ 0x02087C84; symbol: func_02087c84; size: 0x78.
extern "C" int CombatStatus_AdjustMagicalMendingModifierAndRefreshDuration(State* p,int delta){int value=delta+p->counter;if(value>2)value=2;if(value<-2)value=-2;if(!value){CombatStatus_ClearMagicalMendingModifier(p);return 0;}p->counter=value;p->mode=5;p->byte96=0;p->flags|=0x8000;return p->counter;}
