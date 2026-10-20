#include <globaldefs.h>
#include "Graphics/Vector.h"
extern "C" void Camera_SetOrbitParameters(void*,const Vector3fix*);extern "C" void Camera_SetProjectionAngle(void*,int);struct Object{char pad[0x220];Vector3fix value;};
// Original: arm9/main @ 0x020A27CC; symbol: func_020a27cc; size: 0x34.
extern "C" ARM void Object_SetPositionYZDefaultsAndF000Angle(Object* p){p->value.y=0x7999;p->value.z=0xe000;Camera_SetOrbitParameters(p,&p->value);Camera_SetProjectionAngle(p,0xf000);}
