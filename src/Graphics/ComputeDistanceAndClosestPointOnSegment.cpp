#pragma thumb off
#pragma optimization_level 2
#include <Graphics/Vector.h>
#pragma always_inline on
// Original: arm9/main @ 0x02031468; symbol: func_02031468; size: 0x150.
extern "C" int ComputeDistanceAndClosestPointOnSegment(const Vector3fix* start,const Vector3fix* end,const Vector3fix* point,Vector3fix* closest){int distance;int length=Vector3fix_Distance(start,end);distance=Vector3fix_Distance(start,point);if(!length){*closest=*point;return distance;}if(!distance){*closest=*point;return 0;}Vector3fix direction,relative;Vector3fix_Subtract(end,start,&direction);int scalar=fix32_Divide(0x1000,length);Vector3fixMultiplyScalar(&direction,scalar,&direction);Vector3fix_Subtract(point,start,&relative);scalar=fix32_Divide(0x1000,distance);Vector3fixMultiplyScalar(&relative,scalar,&relative);int product=Vector3fix_InnerProduct(&direction,&relative);if(product<=0){*closest=*start;return distance;}int projection=(int)(((long long)distance*product+0x800)>>12);if(length<projection){*closest=*end;return Vector3fix_Distance(point,end);}else{Vector3fixMultiplyScalar(&direction,projection,closest);Vector3fix_Add(closest,start,closest);return Vector3fix_Distance(point,closest);}}
