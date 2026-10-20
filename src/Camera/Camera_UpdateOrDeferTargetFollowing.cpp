#include <globaldefs.h>
ARM
extern "C" int Camera_GetManualControlMode();extern "C" void Camera_UpdateTargetFollowing(void*,int);
// Original: arm9/main @ 0x020A20F0; symbol: func_020a20f0; size: 0x3C.
extern "C" void Camera_UpdateOrDeferTargetFollowing(unsigned char* p){if(Camera_GetManualControlMode()){p[0x244]|=8;return;}if(!*(int*)(p+0x238))return;Camera_UpdateTargetFollowing(p,1);}
