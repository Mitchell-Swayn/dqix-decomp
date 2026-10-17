#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void WriteKindAndSetStateFive(void*,unsigned);
// Original: arm9/main @ 0x020887FC; symbol: func_020887fc; size: 0x1C.
extern "C" void Object_SetFlag80AndApplyModeFive(unsigned char* p){*(unsigned*)(p+24)|=128;WriteKindAndSetStateFive(p,5);}
