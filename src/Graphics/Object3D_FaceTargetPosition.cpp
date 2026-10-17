#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(void*,int);
struct Object{char pad[68];Vector3fix position;};
// Original: arm9/main @ 0x020338D4; symbol: func_020338d4; size: 0x4C.
extern "C" void Object3D_FaceTargetPosition(Object* p,const Vector3fix* target){Vector3fix direction;Vector3fix_Subtract(target,&p->position,&direction);Vector3fix_Normalize(&direction,&direction);Object3D_SetNormalizedAngleAndUpdatePosition(p,fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x,direction.z)));}
