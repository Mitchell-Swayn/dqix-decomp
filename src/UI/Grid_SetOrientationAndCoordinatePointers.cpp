#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205BA68; symbol: func_0205ba68; size: 0x64.
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char* p,int a,int b,int orientation){*(int*)(p+8)=a;*(int*)(p+12)=b;p[16]=orientation;if(!orientation){*(void**)(p+32)=p+8;*(void**)(p+36)=p+12;*(void**)(p+40)=p+24;*(void**)(p+44)=p+28;return;}if(orientation!=1)return;*(void**)(p+32)=p+12;*(void**)(p+36)=p+8;*(void**)(p+40)=p+28;*(void**)(p+44)=p+24;}
