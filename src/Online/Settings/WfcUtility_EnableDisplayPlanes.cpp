#include <globaldefs.h>

// Original: arm9/ov031 @ 0x0223CB68; symbol: func_ov031_0223cb68; size: 0x54.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void WfcUtility_EnableDisplayPlanes(int screen,unsigned int planes) {
 if(screen==1) {volatile unsigned int* reg=(volatile unsigned int*)0x04001000; unsigned int previous=(*reg&0x1f00)>>8; unsigned int enabled=planes|previous; *reg=(*reg&~0x1f00)|(enabled<<8);}
 else {volatile unsigned int* reg=(volatile unsigned int*)0x04000000; unsigned int previous=(*reg&0x1f00)>>8; unsigned int enabled=planes|previous; *reg=(*reg&~0x1f00)|(enabled<<8);}
}
