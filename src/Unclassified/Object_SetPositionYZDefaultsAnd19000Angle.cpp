#include <globaldefs.h>
struct State { char pad[0x220]; int a,b,c; };
extern "C" void Object_SetVectorComponentsThroughPositionSetter(State*,void*); extern "C" void SetAngleAndCacheTrig(State*,unsigned);
// Original: arm9/main @ 0x020A2868; symbol: func_020a2868; size: 0x34.
extern "C" void Object_SetPositionYZDefaultsAnd19000Angle(State* self) { self->b=0xc666; self->c=0xc666+0x2000; Object_SetVectorComponentsThroughPositionSetter(self,&self->a); SetAngleAndCacheTrig(self,0x19000); }
