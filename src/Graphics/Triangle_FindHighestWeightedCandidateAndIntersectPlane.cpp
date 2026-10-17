#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
struct Triangle { Vector3fix a,b,c,d; };
struct Plane { Vector3fix normal; int distance; };
extern "C" int Geometry_IntersectSegmentWithFrontFacingTriangle(void*,void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int*,int*,int*,int*);
extern "C" int IntersectSegmentWithPlane(void*,void*,Plane*,int*,void*);
static inline int roundedProduct(int a,int b) { return (int)(((long long)a*b+0x800LL)>>12); }
// Original: arm9/main @ 0x020319D8; symbol: func_020319d8; size: 0x1AC.
extern "C" int Triangle_FindHighestWeightedCandidateAndIntersectPlane(Triangle* triangles,int count,void* from,void* to,void* result) {
 int best=-1,bestValue;
 int x,y,z,extra,output;
 Plane original;
 Vector3fix edge2,edge1;
 Plane plane;
 for(int i=0;i<count;++i) {
 Triangle* triangle=triangles+i;
 if(triangle->d.y<=0x800&&Geometry_IntersectSegmentWithFrontFacingTriangle(from,to,&triangle->a,&triangle->b,&triangle->c,&triangle->d,&x,&y,&z,&extra)==1) {
 int value=roundedProduct(triangle->a.y,x)+roundedProduct(triangle->b.y,y)+roundedProduct(triangle->c.y,z);
 if(best<0||bestValue<value){bestValue=value;best=i;}
 }
 }
 if(best>=0) {
 Triangle* triangle=triangles+best;
 original.normal=triangle->d;
 original.distance=Vector3fix_InnerProduct(&original.normal,&triangle->a);
 Vector3fix_Subtract(&triangle->b,&triangle->a,&edge1);
 Vector3fix_Subtract(&triangle->c,&triangle->a,&edge2);
 Vector3fix_CrossProduct(&edge1,&edge2,&plane.normal);
 plane.distance=Vector3fix_InnerProduct(&plane.normal,&triangle->a);
 if(!IntersectSegmentWithPlane(from,to,&plane,&output,result))best=-1;
 }
 return best;
}
