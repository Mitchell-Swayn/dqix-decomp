#include <globaldefs.h>
ARM
struct Vector { int x,y,z; };
extern "C" void Vector3fix_Subtract(const Vector *,const Vector *,Vector *);
extern "C" void Vector3fix_Normalize(const Vector *,Vector *);
extern "C" int fix32_Atan2(int,int);
int fix32ReduceAngle0To2Pi(int);
// Original: arm9/main @ 0x02032424; symbol: func_02032424; size: 0x48.
extern "C" int Vector3fix_ComputeReverseXZHeading(const Vector *a,const Vector *b) { Vector v; Vector3fix_Subtract(b,a,&v); Vector3fix_Normalize(&v,&v); return fix32ReduceAngle0To2Pi(fix32_Atan2(-v.x,-v.z)); }
