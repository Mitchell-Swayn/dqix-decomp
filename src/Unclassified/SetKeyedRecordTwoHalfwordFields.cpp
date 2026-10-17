#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInEntryArray(void*,int);
// Original: arm9/main @ 0x020809A0; symbol: func_020809a0; size: 0x24.
extern "C" void SetKeyedRecordTwoHalfwordFields(unsigned char* p,int key,int a,int b){unsigned char* q=FindNonnegativeKeyInEntryArray(p+4,key);if(q){*(short*)(q+10)=a;*(short*)(q+12)=b;}}
