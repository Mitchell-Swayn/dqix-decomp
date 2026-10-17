#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Object_CopyElement0ToElement0AndCopyElement1ToElement1AndCopyElement2ToElement2AndCopyElement3ToElement3(void*,const unsigned short*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x02033F6C; symbol: func_02033f6c; size: 0x10.
extern "C" void SetHalfwordDescriptorOnEmbeddedField114(char* a,const unsigned short* b){Object_CopyElement0ToElement0AndCopyElement1ToElement1AndCopyElement2ToElement2AndCopyElement3ToElement3(a+276,b);}
