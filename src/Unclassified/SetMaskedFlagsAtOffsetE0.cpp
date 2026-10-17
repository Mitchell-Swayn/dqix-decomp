#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Object_CopyElement0ToElement0AndCopyElement1ToElement1AndCopyElement2ToElement2AndCopyElement3ToElement3(void*,const void*);
// Original: arm9/main @ 0x02033FA8; symbol: func_02033fa8; size: 0x1C.
extern "C" void SetMaskedFlagsAtOffsetE0(unsigned char* p,const void* source){p[224]|=128;Object_CopyElement0ToElement0AndCopyElement1ToElement1AndCopyElement2ToElement2AndCopyElement3ToElement3(p+284,source);}
