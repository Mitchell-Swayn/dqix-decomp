#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(void*,int,int,int);
// Original: arm9/main @ 0x0202E6A8; symbol: func_0202e6a8; size: 0x18.
extern "C" void WriteAngleAndUpdateThreeAngleFields(unsigned char* p,int angle){*(int*)(p+112)=angle;ComputeRotatedEndpointFromAngleHeightAndLength(p,angle,*(int*)(p+116),*(int*)(p+120));}
