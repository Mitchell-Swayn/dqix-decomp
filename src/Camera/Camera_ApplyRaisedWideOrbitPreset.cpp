#include <globaldefs.h>
struct State { char pad[0x220]; int a,b,c; };
extern "C" void Camera_SetOrbitParameters(State*,void*); extern "C" void Camera_SetProjectionAngle(State*,unsigned);
// Original: arm9/main @ 0x020A2868; symbol: func_020a2868; size: 0x34.
extern "C" void Camera_ApplyRaisedWideOrbitPreset(State* self) { self->b=0xc666; self->c=0xc666+0x2000; Camera_SetOrbitParameters(self,&self->a); Camera_SetProjectionAngle(self,0x19000); }
