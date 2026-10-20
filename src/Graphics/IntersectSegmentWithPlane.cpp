#include <globaldefs.h>
#include <Graphics/Vector.h>
struct Plane {Vector3fix normal;int distance;};
// Original: arm9/main @ 0x02032090; symbol: func_02032090; size: 0x94.
extern "C" ARM int IntersectSegmentWithPlane(const Vector3fix* a,const Vector3fix* b,const Plane* plane,int* fraction,Vector3fix* out){Vector3fix delta;Vector3fix_Subtract(b,a,&delta);int dot=Vector3fix_InnerProduct(&plane->normal,a);int denom=Vector3fix_InnerProduct(&plane->normal,&delta);int t=(*fraction=fix32_Divide(plane->distance-dot,denom));int result;if(t>=0 && t<=4096){Vector3fixMultiplyScalar(&delta,t,out);Vector3fix_Add(a,out,out);result=1;}else result=0;return result;}
