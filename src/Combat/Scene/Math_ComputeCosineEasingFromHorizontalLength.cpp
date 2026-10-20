#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" int _Z8fix32cosi(int);
// Original: arm9/ov000 @ 0x0216F210; symbol: func_ov000_0216f210; size: 0xA8.
extern "C" int Math_ComputeCosineEasingFromHorizontalLength(unsigned char* p,int* length){
 Vector3fix v=*(Vector3fix*)(p+4);
 v.y=0;
 int distance=Vector3fix_Length(&v);
 *length=distance;
 if(distance<0x8000)return 0;
 if(distance>0x11000)distance=0x11000;
 int ratio=fix32_Divide(distance-0x8000,0x9000);
 int value=0x1000-_Z8fix32cosi(FIX32_MULTIPLY(ratio,0x1922));
 if(value<0)value=0;
 return FIX32_MULTIPLY(value,0x5000);
}
