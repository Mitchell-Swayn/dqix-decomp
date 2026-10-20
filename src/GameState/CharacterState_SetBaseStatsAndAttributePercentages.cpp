#include <globaldefs.h>
ARM
struct PackedPosition { unsigned x:10,y:10,z:10,reserved:2; }; struct PositionSource { unsigned pad[2]; PackedPosition a,b,c; };
struct State { char pad[0x91c]; PackedPosition a,b,c; char gap[12]; unsigned char weights[22]; };
extern "C" void *memset(void *,int,unsigned);
// Original: arm9/main @ 0x02083CBC; symbol: func_02083cbc; size: 0x16C.
extern "C" void CharacterState_SetBaseStatsAndAttributePercentages(State *self,const PositionSource *source,const unsigned char *weights) { self->a.x=source->a.x; self->a.y=source->a.y; self->a.z=source->a.z; self->b.x=source->b.x; self->b.y=source->b.y; self->b.z=source->b.z; self->c.x=source->c.x; self->c.y=source->c.y; self->c.z=source->c.z; memset(self->weights,100,22); if(!weights) return; for(int i=0;i<22;++i) self->weights[i]=weights[i]; }
