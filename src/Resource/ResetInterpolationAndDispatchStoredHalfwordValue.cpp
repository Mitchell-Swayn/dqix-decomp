#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void Object_Clear40Bytes(void*);extern "C" void Object_SetVectorComponentsThroughPositionSetter(void*,const void*);
// Original: arm9/main @ 0x020A2718; symbol: func_020a2718; size: 0x2C.
extern "C" void ResetInterpolationAndDispatchStoredHalfwordValue(unsigned char* p){Object_Clear40Bytes(p+584);*(int*)(p+544)=*(short*)(p+582);Object_SetVectorComponentsThroughPositionSetter(p,p+544);}
