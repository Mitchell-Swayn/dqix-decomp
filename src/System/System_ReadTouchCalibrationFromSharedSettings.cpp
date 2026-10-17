#include <globaldefs.h>
ARM
struct TPCalibration { short x0,y0,xDotSize,yDotSize; };
extern "C" unsigned long TouchPanel_ComputeTwoPointCalibration(TPCalibration*,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short);
struct CalibrationPair { unsigned short rawX,rawY; unsigned char displayX,displayY; };
struct NvramSettings { unsigned char pad[0x58]; CalibrationPair pairs[2]; };
// Original: arm9/main @ 0x020CD908; symbol: func_020cd908; size: 0x94.
extern "C" int System_ReadTouchCalibrationFromSharedSettings(TPCalibration* out) {
 NvramSettings* settings=(NvramSettings*)0x027ffc80;
 unsigned short x1=settings->pairs[0].rawX,y1=settings->pairs[0].rawY;
 unsigned short x2=settings->pairs[1].rawX,y2=settings->pairs[1].rawY;
 unsigned char dx1=settings->pairs[0].displayX,dy1=settings->pairs[0].displayY;
 unsigned char dx2=settings->pairs[1].displayX,dy2=settings->pairs[1].displayY;
 if((x1==0 && x2==0 && y1==0 && y2==0) || TouchPanel_ComputeTwoPointCalibration(out,x1,y1,dx1,dy1,x2,y2,dx2,dy2)!=0) {
  out->x0=0; out->y0=0; out->xDotSize=0; out->yDotSize=0;
  return 1;
 }
 return 1;
}
