#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void InitializeFlagsAndDoublePrecisionConstant(void*);
// Original: arm9/main @ 0x0201F9E8; symbol: func_0201f9e8; size: 0x18.
extern "C" void Object_ResetBytes2And3AndInitializeRecord(unsigned char* p){p[2]=0;p[3]=0;InitializeFlagsAndDoublePrecisionConstant(p);}
