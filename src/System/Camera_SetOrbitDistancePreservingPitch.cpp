#include <globaldefs.h>
ARM
#include <System/Matrix.h>
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(void*,int,int,int);
// Original: arm9/main @ 0x0202E808; symbol: func_0202e808; size: 0x50.
extern "C" void Camera_SetOrbitDistancePreservingPitch(unsigned char* object,int value){int ratio=fix32_Divide(value,*(int*)(object+0x78));long long product=(long long)*(int*)(object+0x74)*ratio+0x800;*(int*)(object+0x74)=(int)(product>>12);*(int*)(object+0x78)=value;ComputeRotatedEndpointFromAngleHeightAndLength(object,*(int*)(object+0x70),*(int*)(object+0x74),value);}
