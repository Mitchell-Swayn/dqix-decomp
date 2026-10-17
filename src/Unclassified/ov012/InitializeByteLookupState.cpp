#include <globaldefs.h>
extern "C" void* memset(void*,int,unsigned);
extern "C" unsigned char data_ov012_0218afbc[];
extern "C" int FindIndexedBinaryKeyByLengthComparison(void*,int);
// Original: arm9/ov012 @ 0x021845F8; symbol: func_ov012_021845f8; size: 0x5C.
extern "C" ARM void InitializeByteLookupState(unsigned char* self) { memset(self+0x18,0,12); *(unsigned*)(self+0x24)=0; *(unsigned short*)(self+0x28)=0; unsigned char* output=self+0x2a; for(int i=0;i<15;++i) *output++=FindIndexedBinaryKeyByLengthComparison(data_ov012_0218afbc+i*5,1); }
