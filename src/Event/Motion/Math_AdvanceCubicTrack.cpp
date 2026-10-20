#include <globaldefs.h>
ARM
extern "C" int fix32_Divide(int,int);
struct CubicSegment { int start,duration; int a[3],b[3],c[3],d[3]; };
struct CubicTrack { CubicSegment segments[16]; int count,index,time,value[3]; };
static inline int Mul(int a,int b) { return (int)(((long long)a*b+0x800)>>12); }
// Original: arm9/ov001 @ 0x021573C0; symbol: func_ov001_021573c0; size: 0x1B0.
extern "C" int Math_AdvanceCubicTrack(CubicTrack* p) {
 int i;
 if(p->count<=1) return 1;
 p->time+=0x1000;
 if(p->time>=((p->segments[p->index].start+p->segments[p->index].duration)<<12)) {
 p->index++;
 if(p->index>=p->count) {
  for(i=0;i<3;i++) p->value[i]=p->segments[p->count-1].d[i];
  p->index=p->count-1;
  p->time=(p->segments[p->index].start+p->segments[p->index].duration+100)<<12;
  return 1;
 }
 }
 int t=fix32_Divide(p->time-(p->segments[p->index].start<<12),p->segments[p->index].duration<<12);
 int t2=Mul(t,t);
 int t3=Mul(t2,t);
 for(i=0;i<3;i++) p->value[i]=Mul(p->segments[p->index].a[i],t3)+Mul(p->segments[p->index].b[i],t2)+Mul(p->segments[p->index].c[i],t)+p->segments[p->index].d[i];
 return 0;
}
