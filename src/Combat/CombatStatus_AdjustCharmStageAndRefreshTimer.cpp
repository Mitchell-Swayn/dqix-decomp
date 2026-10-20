#include <globaldefs.h>
struct Owner {char pad[0x14];unsigned flags;char pad2[0x40];unsigned lower:9; signed amount:3;unsigned upper:20;char pad3[0x15];unsigned char state;char pad4[0x22];unsigned char value;};extern "C" void CombatStatus_ClearCharmStage(Owner*);
// Original: arm9/main @ 0x02087A9C; symbol: func_02087a9c; size: 0x78.
extern "C" int CombatStatus_AdjustCharmStageAndRefreshTimer(Owner* self,int delta) {int amount=self->amount+delta;if(amount>2)amount=2;if(amount< -2)amount=-2;if(amount==0){CombatStatus_ClearCharmStage(self);return 0;}self->amount=amount;self->state=6;self->value=0;self->flags|=0x2000;return self->amount; }
