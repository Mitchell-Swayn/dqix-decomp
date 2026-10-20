#include <globaldefs.h>
ARM
extern "C" int Math_ConfigureCubicTrackToMatchRequestedDuration(char*);
extern "C" void CubicPath_ActivateHeadingTrackWhenPopulated(void*);
extern "C" void CubicPath_AdvanceTrackAndUpdateHeading(char*,const int*,int*);
// Original: arm9/ov001 @ 0x0215944C; symbol: func_ov001_0215944c; size: 0x60.
// Initializes a cubic track once, updates its heading, and clears initialization when inactive.
extern "C" int CutsceneActor_AdvanceHeadingPathCommand(void*,char* state) {
 if(*(int*)(state+0x48)<=0) {
  Math_ConfigureCubicTrackToMatchRequestedDuration(state+0x11c);
  CubicPath_ActivateHeadingTrackWhenPopulated(state+0x11c);
  *(int*)(state+0x48)=1;
 }
 CubicPath_AdvanceTrackAndUpdateHeading(state+0x11c,(const int*)(state+0x74),(int*)(state+0x84));
 int inactive=*(int*)(state+0x580)==0;
 if(inactive) {*(int*)(state+0x48)=0;return 0;}
 return 1;
}
