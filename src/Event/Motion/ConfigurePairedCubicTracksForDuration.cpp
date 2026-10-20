#include <globaldefs.h>
#include <System/Matrix.h>
ARM
#pragma opt_dead_assignments off
struct CubicTrack; struct CubicPath; struct Point;
extern "C" void BuildTimedCubicPathCoefficients(CubicPath*,Point*,int*,int,int);
extern "C" int Math_AdvanceCubicTrack(CubicTrack*);
extern "C" void CubicPath_ReadCurrentPosition(void*,unsigned*);
#define I(p,o) (*(int*)((p)+(o)))
// Original: arm9/ov001 @ 0x02157668; symbol: func_ov001_02157668; size: 0x228.
// Configures two position tracks and measures their travelled distance to set per-frame thresholds.
extern "C" int ConfigurePairedCubicTracksForDuration(char *self) {
 if(I(self,0x180)<=0) return 1;
 int durations[16],distances[16];
 int i;
 int total=0;
 for(i=0;i<I(self,0x180)-1;++i) {
  distances[i]=Vector3fix_Distance((Vector3fix*)(self+i*12),(Vector3fix*)(self+(i+1)*12));
  total+=distances[i];
 }
 for(i=0;i<I(self,0x180)-1;++i) durations[i]=I(self,0x184)/(I(self,0x180)-1);
 BuildTimedCubicPathCoefficients((CubicPath*)(self+0x188),(Point*)(self),durations,I(self,0x180),0);
 total=0;
 {
  Vector3fix previous,current;
  for(;;) {
   CubicPath_ReadCurrentPosition(self+0x188,(unsigned*)&previous);
   if(Math_AdvanceCubicTrack((CubicTrack*)(self+0x188))) break;
   CubicPath_ReadCurrentPosition(self+0x188,(unsigned*)&current);
   total+=Vector3fix_Distance(&previous,&current);
  }
 }
 BuildTimedCubicPathCoefficients((CubicPath*)(self+0x188),(Point*)(self),durations,I(self,0x180),fix32_Divide(total,I(self,0x184)<<12));
 total=0;
 for(i=0;i<I(self,0x180)-1;++i) {
  distances[i]=Vector3fix_Distance((Vector3fix*)(self+0xc0+i*12),(Vector3fix*)(self+0xc0+(i+1)*12));
  total+=distances[i];
 }
 for(i=0;i<I(self,0x180)-1;++i) durations[i]=I(self,0x184)/(I(self,0x180)-1);
 BuildTimedCubicPathCoefficients((CubicPath*)(self+0x524),(Point*)(self+0xc0),durations,I(self,0x180),0);
 total=0;
 {
  Vector3fix previous,current;
  for(;;) {
   CubicPath_ReadCurrentPosition(self+0x524,(unsigned*)&previous);
   if(Math_AdvanceCubicTrack((CubicTrack*)(self+0x524))) break;
   CubicPath_ReadCurrentPosition(self+0x524,(unsigned*)&current);
   total+=Vector3fix_Distance(&previous,&current);
  }
 }
 BuildTimedCubicPathCoefficients((CubicPath*)(self+0x524),(Point*)(self+0xc0),durations,I(self,0x180),fix32_Divide(total,I(self,0x184)<<12));
 return 0;
}
