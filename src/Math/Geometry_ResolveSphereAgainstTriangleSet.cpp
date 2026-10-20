#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vec {int x,y,z;};
struct Triangle {Vec a,b,c,normal;};
extern "C" {
void* _ZN8Vector3iaSERKS_(void*,const void*);
void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec*,int,Vec*);
void Vector3fix_Add(const Vec*,const Vec*,Vec*);
void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);
int Geometry_IntersectSegmentWithFrontFacingTriangle(const Vec*,const Vec*,const Vec*,const Vec*,const Vec*,const Vec*,int*,int*,int*,int*);
Vec Vector3fix_ClampPointToTriangleRegions(const Vec*,const Vec*,const Vec*,const Vec*);
int fix32_Sqrt(int);int fix32_Divide(int,int);
int Vector3fix_Distance(const Vec*,const Vec*);
int Vector3fix_InnerProduct(const Vec*,const Vec*);
}
static inline int Square(int v) {return (int)(((long long)v*v+0x800LL)>>12);}
// Original: arm9/main @ 0x020315B8; symbol: func_020315b8; size: 0x420.
extern "C" int Geometry_ResolveSphereAgainstTriangleSet(Triangle* triangles,int count,const Vec* start,int radius,Vec* position,const Vec* target) {
int selected=-1;
int radiusSquared=Square(radius);
_ZN8Vector3iaSERKS_(position,start);
Vec previous=*start;
Vec original=*start;
Vec previousNormal;
for(int pass=0;pass<2;pass++) {
int collisions=0;
int negativeRadius=-radius;
int invalid=-1;
for(int i=0;i<count;i++) {
int changed=0,faceHit=0;
Triangle* tri=triangles+i;
Vec before=*position;
if(tri->normal.y>0x800) continue;
Vec segmentStart,segmentEnd,a,b,c,normal,offset;
_ZN8Vector3iaSERKS_(&segmentStart,position);
_Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&tri->normal,negativeRadius,&offset);
Vector3fix_Add(&segmentStart,&offset,&segmentEnd);
_ZN8Vector3iaSERKS_(&a,&tri->a);
_ZN8Vector3iaSERKS_(&b,&tri->b);
_ZN8Vector3iaSERKS_(&c,&tri->c);
_ZN8Vector3iaSERKS_(&normal,&tri->normal);
int outA,outB,outC,fraction;
int hit=Geometry_IntersectSegmentWithFrontFacingTriangle(&segmentStart,&segmentEnd,&a,&b,&c,&normal,&outA,&outB,&outC,&fraction);
if(hit==1 && pass==0) {
Vec temp;
Vector3fix_Subtract(&segmentEnd,&segmentStart,&temp);
_Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&temp,fraction,&temp);
Vector3fix_Add(&segmentStart,&temp,position);
_Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&normal,radius,&temp);
Vector3fix_Add(position,&temp,position);
changed=1;selected=i;faceHit=1;++collisions;
} else if(hit==invalid && pass>=1) {
Vec point;
_ZN8Vector3iaSERKS_(&point,&(const Vec&)Vector3fix_ClampPointToTriangleRegions(position,&a,&b,&c));
Vec delta;Vector3fix_Subtract(position,&point,&delta);
int distanceSquared=Square(delta.x)+Square(delta.y)+Square(delta.z);
if(distanceSquared<radiusSquared) {
int scale=fix32_Divide(radius,fix32_Sqrt(distanceSquared));
_Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&delta,scale,&delta);
Vector3fix_Add(&point,&delta,position);
changed=1;if(selected==invalid) selected=i;
}}
if(changed) {
_ZN8Vector3iaSERKS_(&normal,&tri->normal);
if(target) {
Vec projected=*target;projected.y=start->y;
if(Vector3fix_Distance(position,&previous)>4) {
int dot=Vector3fix_InnerProduct(&normal,&previousNormal);
if(dot<0xfd7 && dot>0x800) {
Vec fromPrevious,fromPosition,fromOriginal;
Vector3fix_Subtract(&projected,&previous,&fromPrevious);
Vector3fix_Subtract(&projected,position,&fromPosition);
int alignment=Vector3fix_InnerProduct(&fromPrevious,&fromPosition);
int distance=Vector3fix_Distance(&fromPrevious,&fromPosition);
if(alignment<distance*0x4cc) {
Vector3fix_Subtract(&projected,&original,&fromOriginal);
int dotA=Vector3fix_InnerProduct(&fromPrevious,&fromOriginal);
int dotB=Vector3fix_InnerProduct(&fromPosition,&fromOriginal);
if(dotA<0 || dotB<0) {
position->z=target->z;position->x=target->x;return selected;
}
}
}
}
}
if(faceHit || !collisions) _ZN8Vector3iaSERKS_(&previousNormal,&normal);
_ZN8Vector3iaSERKS_(&previous,&before);
}
}
}
return selected;
}
