#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
struct Counter {char pad[6]; unsigned short value;}; struct Limit {char pad[0x32];unsigned short value;}; struct State{char pad[0x130];Counter *counter;Limit *limit;};
// Original: arm9/main @ 0x020482BC; symbol: func_020482bc; size: 0x24.
extern "C" int GameObject_RecoverMPToMaximum(State *s){Counter *c=s->counter;int diff=c->value;unsigned short next=s->limit->value;diff=next-diff;if(diff<=0)diff=0;else c->value=next;return diff;}
