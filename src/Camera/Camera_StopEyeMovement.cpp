#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* Camera_ResetInterpolationRecord(void*);
// Original: arm9/main @ 0x0202EE84; symbol: func_0202ee84; size: 0x10.
extern "C" void* Camera_StopEyeMovement(unsigned char* p){return Camera_ResetInterpolationRecord(p+364);}
