#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
// Original: arm9/ov031 @ 0x0223D634; symbol: func_ov031_0223d634; size: 0x68.
// Converts x/y/width/height to inclusive bounds and tests the current input point.
extern "C" int IsInputPointWithinOriginSizeRectangle(unsigned short* rectangle){
    if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15)return 0;
    unsigned short bounds[4];
    bounds[0]=rectangle[0];
    bounds[1]=rectangle[1];
    bounds[2]=rectangle[0]+rectangle[2];
    bounds[3]=rectangle[1]+rectangle[3];
    return WfcUtility_IsTouchPressInsideRectangle(bounds);
}
