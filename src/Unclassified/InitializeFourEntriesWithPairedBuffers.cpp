#include <globaldefs.h>
extern "C" void Object_InitializeFour318ByteRecords(void*);
// Original: arm9/main @ 0x02028894; symbol: func_02028894; size: 0x4C.
extern "C" void InitializeFourEntriesWithPairedBuffers(char* p,char* a,char* b) { Object_InitializeFour318ByteRecords(p); for(int i=0;i<4;i++){ *(char**)(p+i*0x318+16)=a+i*20; *(char**)(p+i*0x318+20)=b+i*20; } }
