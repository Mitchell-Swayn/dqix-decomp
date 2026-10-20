#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void Camera_ResetInterpolationRecord(void*);extern "C" void Camera_SetOrbitParameters(void*,const void*);
// Original: arm9/main @ 0x020A2718; symbol: func_020a2718; size: 0x2C.
extern "C" void ResetInterpolationAndDispatchStoredHalfwordValue(unsigned char* p){Camera_ResetInterpolationRecord(p+584);*(int*)(p+544)=*(short*)(p+582);Camera_SetOrbitParameters(p,p+544);}
