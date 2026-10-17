#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
extern "C" unsigned short data_02114e30[];
extern "C" unsigned char data_02114e54[];
// Original: arm9/ov017 @ 0x021AB1A4; symbol: func_ov017_021ab1a4; size: 0xAC.
extern "C" int Graphics_TestNewMaskOrPointOutsideTwoRectangles(unsigned char* p){
 int result=0;
 if(Object_TestNewlySetHalfwordMask(data_02114e30,2))result=1;
 if(data_02114e54[0x55]){
 int x,y;
 ReadSelectedCoordinatePair(data_02114e54,&x,&y);
 if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x18),0,(short)x,(short)y)){
 if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x18),1,(short)x,(short)y))result=1;
 }
 }
 return result;
}
