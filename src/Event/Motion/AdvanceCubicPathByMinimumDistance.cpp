#include <globaldefs.h>
#include <System/Matrix.h>
ARM
static inline int RoundedMultiply(int a,int b) { return FIX32_MULTIPLY(a,b); }
struct CubicSegment { int start,duration; int cubic[3],quadratic[3],linear[3],constant[3]; };
struct CubicPath { CubicSegment segments[16]; int count,index,time; int position[3]; int minimumDistance; };
// Original: arm9/ov001 @ 0x021570B4; symbol: func_ov001_021570b4; size: 0x30C.
// Advances cubic fixed-point segments until the position moves the requested minimum distance.
extern "C" int AdvanceCubicPathByMinimumDistance(CubicPath *path) {
 if(path->count<=1) return 1;
 if(path->minimumDistance<=0) return 1;
 do {
  path->time+=0x199;
  if(path->time >= ((path->segments[path->index].start+path->segments[path->index].duration)<<12)) {
   ++path->index;
   if(path->index>=path->count) {
   for(int i=0;i<3;++i) path->position[i]=path->segments[path->count-1].constant[i];
   path->index=path->count-1;
   path->time=(path->segments[path->index].start+path->segments[path->index].duration+100)<<12;
   return 1;
   }
  }
  int t=fix32_Divide(path->time-(path->segments[path->index].start<<12),path->segments[path->index].duration<<12);
  int t2=RoundedMultiply(t,t);
  int t3=RoundedMultiply(t2,t);
  Vector3fix previous,next;
  previous.x=path->position[0];
  next.x=RoundedMultiply(path->segments[path->index].cubic[0],t3)+RoundedMultiply(path->segments[path->index].quadratic[0],t2)+RoundedMultiply(path->segments[path->index].linear[0],t)+path->segments[path->index].constant[0];
  previous.y=path->position[1];
  next.y=RoundedMultiply(path->segments[path->index].cubic[1],t3)+RoundedMultiply(path->segments[path->index].quadratic[1],t2)+RoundedMultiply(path->segments[path->index].linear[1],t)+path->segments[path->index].constant[1];
  previous.z=path->position[2];
  next.z=RoundedMultiply(path->segments[path->index].cubic[2],t3)+RoundedMultiply(path->segments[path->index].quadratic[2],t2)+RoundedMultiply(path->segments[path->index].linear[2],t)+path->segments[path->index].constant[2];
  if(Vector3fix_Distance(&previous,&next)<path->minimumDistance) continue;
  path->position[0]=next.x;path->position[1]=next.y;path->position[2]=next.z;
  return 0;
 } while(1);
}
