#include <globaldefs.h>
struct Entry{char pad[5];signed char life;char gap[2];short velocity,position;char tail[12];};struct State{char pad[0x550];Entry entries[16];int head,tail;};extern "C" void ZoneContainer_SeparateProjectedMotionEntries(State*,int);
// Original: arm9/main @ 0x02039FEC; symbol: func_02039fec; size: 0xC8.
extern "C" ARM void FloatingNumber_AdvanceAnimations(State* p){int i=p->head;while(i!=p->tail){Entry* e=&p->entries[i];e->position+=e->velocity;e->velocity+=(0x1000-e->position)>>1;e->velocity=(int)(0.8f*(float)e->velocity);--e->life;if(e->life<=0){p->head=i+1;if(p->head>=16)p->head=0;}else if(e->life==34)ZoneContainer_SeparateProjectedMotionEntries(p,i);++i;if(i>=16)i=0;}}
