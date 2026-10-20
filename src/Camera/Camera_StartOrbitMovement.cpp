#include <globaldefs.h>
ARM
extern "C" {void Camera_RecalculateOrbitAndEye(void*);void InitializeVectorTransitionAndStepValues(void*,void*,int,int,int,int);
// Original: arm9/main @ 0x0202EDF8; symbol: func_0202edf8; size: 0x40.
void Camera_StartOrbitMovement(unsigned char* p,int x,int y,int z,int w){Camera_RecalculateOrbitAndEye(p);InitializeVectorTransitionAndStepValues(p+0x1bc,p+0x70,x,y,z,w);}}
