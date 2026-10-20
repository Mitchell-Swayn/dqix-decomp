#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void InitializeIndexedThreePartRecords(void*);
static inline int RoundedMultiply(int a,int b) { return FIX32_MULTIPLY(a,b); }
struct CubicSegment { int start,duration; int cubic[3],quadratic[3],linear[3],constant[3]; };
struct CubicPath { CubicSegment segments[16]; int count,index,time; int position[3]; int minimumDistance; };
struct Point { int x,y,z; };
// Original: arm9/ov001 @ 0x02156C14; symbol: func_ov001_02156c14; size: 0x4A0.
// Builds duration-weighted cubic segment coefficients with endpoint tangents.
extern "C" void BuildTimedCubicPathCoefficients(CubicPath *path,Point *points,int *durations,int count,int minimumDistance) {
 InitializeIndexedThreePartRecords(path);
 if(count<=0) return;
 path->count=count;
 path->minimumDistance=minimumDistance;
 int i;
 Point padded[18];
 for(i=0;i<path->count;++i) memcpy(&padded[i],&points[i],12);
 memcpy(&padded[path->count],&points[path->count-1],12);
 memcpy(&padded[path->count+1],&points[path->count-1],12);
 path->position[0]=points[0].x;
 path->position[1]=points[0].y;
 path->position[2]=points[0].z;
 for(i=0;i<path->count;++i) {
  if(i==0) {path->segments[i].start=0;path->segments[i].duration=durations[i];}
  else if(i==path->count-1) {path->segments[i].start=path->segments[i-1].start+path->segments[i-1].duration;path->segments[i].duration=0;}
  else {path->segments[i].start=path->segments[i-1].start+path->segments[i-1].duration;path->segments[i].duration=durations[i];}
 }
 for(i=0;i<path->count;++i) {
  for(int axis=0;axis<3;++axis) {
   int first,current,next,after,previous;
   if(axis==0) {current=padded[i].x;next=padded[i+1].x;after=padded[i+2].x;if(i>0)previous=padded[i-1].x;}
   else if(axis==1) {current=padded[i].y;next=padded[i+1].y;after=padded[i+2].y;if(i>0)previous=padded[i-1].y;}
   else {current=padded[i].z;next=padded[i+1].z;after=padded[i+2].z;if(i>0)previous=padded[i-1].z;}
   int second;
   if(i==0) first=next-current;
   else first=fix32_Divide(RoundedMultiply(next-current,path->segments[i-1].duration<<12)+RoundedMultiply(current-previous,path->segments[i].duration<<12),(path->segments[i-1].duration+path->segments[i].duration)<<12);
   if(i==path->count-1) second=after-next;
   else second=fix32_Divide(RoundedMultiply(after-next,path->segments[i].duration<<12)+RoundedMultiply(next-current,path->segments[i+1].duration<<12),(path->segments[i].duration+path->segments[i+1].duration)<<12);
   int nextTwice=RoundedMultiply(next,0x2000);
   int currentTwice=RoundedMultiply(current,0x2000);
   path->segments[i].cubic[axis]=first+(currentTwice-nextTwice)+second;
   int nextThrice=RoundedMultiply(next,0x3000);
   int negativeCurrentThrice=RoundedMultiply(current,-0x3000);
   int firstTwice=RoundedMultiply(first,0x2000);
   path->segments[i].quadratic[axis]=negativeCurrentThrice+nextThrice-firstTwice-second;
   path->segments[i].linear[axis]=first;
   path->segments[i].constant[axis]=current;
  }
 }
}
