#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {void WfcScrollbar_GetPartBounds(int,unsigned short*);int Util_IsActiveCoordinateInsideRectangle(unsigned short*);int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);}
// Original: arm9/ov031 @ 0x02235594; symbol: FindFirstActiveInputRectangle; size: 0x8c.
// Tests rectangles1 through3 using active coordinate, then rectangle4 using input point.
extern "C" int WfcScrollbar_HitTestPart(){unsigned short rect[4];WfcScrollbar_GetPartBounds(1,rect);if(Util_IsActiveCoordinateInsideRectangle(rect))return 1;for(int i=2;i<=3;++i){WfcScrollbar_GetPartBounds(i,rect);if(Util_IsActiveCoordinateInsideRectangle(rect))return i;}WfcScrollbar_GetPartBounds(4,rect);return WfcUtility_IsTouchPressInsideRectangle(rect)?4:0;}
