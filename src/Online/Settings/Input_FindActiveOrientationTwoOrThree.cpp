#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Rect {unsigned short left,top,right,bottom;};
extern "C" void WfcScrollbar_GetPartBounds(unsigned,unsigned short *);
extern "C" int System_IsActiveInputPointWithinRectangle(const Rect *);
// Original: arm9/ov031 @ 0x02235620; symbol: func_ov031_02235620; size: 0x4C.
// Returns the first of orientations 2 and 3 whose bounds contain the active input point.
extern "C" int Input_FindActiveOrientationTwoOrThree() {
 Rect rect;
 int direction=2;
 do {
 WfcScrollbar_GetPartBounds(direction,&rect.left);
 if(System_IsActiveInputPointWithinRectangle(&rect))return direction;
 ++direction;
 }while(direction<=3);
 return 0;
}
