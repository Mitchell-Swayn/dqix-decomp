#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" unsigned char* data_ov031_0224e69c;
extern "C" char data_ov031_0224a244[];
extern "C" void SetSharedWordPairUnlessStateNine(unsigned int,unsigned int);
typedef void* (*Allocate)(const char*,unsigned int);
// Original: arm9/ov031 @ 0x0221A434; symbol: func_ov031_0221a434; size: 0x98.
extern "C" int Memory_AllocateAndInitializeGlobalRecord(Allocate allocate,void* callback) {
if(data_ov031_0224e69c){SetSharedWordPairUnlessStateNine(9,0xffffa1dc);return 0;}
data_ov031_0224e69c=(unsigned char*)allocate(data_ov031_0224a244,0x1c20);
if(!data_ov031_0224e69c){SetSharedWordPairUnlessStateNine(9,0xffffa1dc);return 0;}
VectorizedMemset(data_ov031_0224e69c,0,0x1c20);
*(Allocate*)data_ov031_0224e69c=allocate;
*(void**)(data_ov031_0224e69c+4)=callback;
return 1;
}
