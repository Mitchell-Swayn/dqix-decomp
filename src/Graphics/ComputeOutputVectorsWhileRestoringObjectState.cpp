#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" void Camera_SetOrbitHeading(void*,int);extern "C" void Camera_SetOrbitParameters(void*,const void*);extern "C" void Camera_UpdateTargetFollowing(void*,int);
// Original: arm9/main @ 0x020A2B38; symbol: func_020a2b38; size: 0xB0.
extern "C" ARM void ComputeOutputVectorsWhileRestoringObjectState(unsigned char* p,Vector3i* a,Vector3i* b,Vector3i* c){Vector3i oldB=*(Vector3i*)(p+16);Vector3i oldC=*(Vector3i*)(p+112);Camera_SetOrbitHeading(p,*(short*)(p+542));*(int*)(p+544)=*(short*)(p+542);Camera_SetOrbitParameters(p,p+544);Camera_UpdateTargetFollowing(p,0);*a=*(Vector3i*)(p+4);*b=*(Vector3i*)(p+16);*c=*(Vector3i*)(p+112);*(Vector3i*)(p+16)=oldB;Camera_SetOrbitParameters(p,&oldC);}
